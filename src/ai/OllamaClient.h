#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace AIForge {

class OllamaClient : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(QStringList models READ models NOTIFY modelsChanged)
    
public:
    explicit OllamaClient(QObject *parent = nullptr);
    
    bool connected() const { return m_connected; }
    QStringList models() const { return m_models; }
    
    Q_INVOKABLE void checkConnection();
    Q_INVOKABLE void fetchModels();
    Q_INVOKABLE void generate(const QString &model, const QString &prompt);
    
signals:
    void connectedChanged();
    void modelsChanged();
    void responseReceived(const QString &text);
    void errorOccurred(const QString &error);
    
private:
    QNetworkAccessManager *m_network;
    bool m_connected = false;
    QStringList m_models;
    QString m_baseUrl = "http://localhost:11434";
};

} // namespace AIForge
