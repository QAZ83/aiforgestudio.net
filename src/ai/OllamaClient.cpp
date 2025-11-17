#include "OllamaClient.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace AIForge {

OllamaClient::OllamaClient(QObject *parent)
    : QObject(parent), m_network(new QNetworkAccessManager(this)) {}

void OllamaClient::checkConnection() {
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    QNetworkReply *reply = m_network->get(req);
    
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        m_connected = (reply->error() == QNetworkReply::NoError);
        emit connectedChanged();
        reply->deleteLater();
    });
}

void OllamaClient::fetchModels() {
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    QNetworkReply *reply = m_network->get(req);
    
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonArray models = doc.object()["models"].toArray();
            m_models.clear();
            for (const auto &m : models) {
                m_models << m.toObject()["name"].toString();
            }
            emit modelsChanged();
        }
        reply->deleteLater();
    });
}

void OllamaClient::generate(const QString &model, const QString &prompt) {
    QJsonObject json;
    json["model"] = model;
    json["prompt"] = prompt;
    json["stream"] = false;
    
    QNetworkRequest req(QUrl(m_baseUrl + "/api/generate"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QNetworkReply *reply = m_network->post(req, QJsonDocument(json).toJson());
    
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QString response = doc.object()["response"].toString();
            emit responseReceived(response);
        } else {
            emit errorOccurred(reply->errorString());
        }
        reply->deleteLater();
    });
}

} // namespace AIForge
