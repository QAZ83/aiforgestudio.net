#pragma once

#include <QObject>
#include <QString>
#include <QTimer>
#include <memory>

namespace AIForge {

class GPUMonitor : public QObject {
    Q_OBJECT
    Q_PROPERTY(float temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(float utilization READ utilization NOTIFY utilizationChanged)
    Q_PROPERTY(float memoryUsed READ memoryUsed NOTIFY memoryUsedChanged)
    Q_PROPERTY(float memoryTotal READ memoryTotal NOTIFY memoryTotalChanged)
    Q_PROPERTY(QString gpuName READ gpuName NOTIFY gpuNameChanged)
    Q_PROPERTY(float powerUsage READ powerUsage NOTIFY powerUsageChanged)
    Q_PROPERTY(float fanSpeed READ fanSpeed NOTIFY fanSpeedChanged)
    Q_PROPERTY(int cudaCores READ cudaCores CONSTANT)
    Q_PROPERTY(QString driverVersion READ driverVersion CONSTANT)

public:
    explicit GPUMonitor(QObject *parent = nullptr);
    ~GPUMonitor();

    // Property getters
    float temperature() const { return m_temperature; }
    float utilization() const { return m_utilization; }
    float memoryUsed() const { return m_memoryUsed; }
    float memoryTotal() const { return m_memoryTotal; }
    QString gpuName() const { return m_gpuName; }
    float powerUsage() const { return m_powerUsage; }
    float fanSpeed() const { return m_fanSpeed; }
    int cudaCores() const { return m_cudaCores; }
    QString driverVersion() const { return m_driverVersion; }

    // Public methods
    Q_INVOKABLE bool initialize();
    Q_INVOKABLE void startMonitoring(int intervalMs = 1000);
    Q_INVOKABLE void stopMonitoring();
    Q_INVOKABLE bool isNVMLAvailable() const { return m_nvmlInitialized; }

signals:
    void temperatureChanged();
    void utilizationChanged();
    void memoryUsedChanged();
    void memoryTotalChanged();
    void gpuNameChanged();
    void powerUsageChanged();
    void fanSpeedChanged();
    void errorOccurred(const QString &error);

private slots:
    void updateStats();

private:
    void cleanup();
    bool initializeNVML();
    void queryGPUStats();

    // GPU Stats
    float m_temperature = 0.0f;
    float m_utilization = 0.0f;
    float m_memoryUsed = 0.0f;
    float m_memoryTotal = 0.0f;
    QString m_gpuName = "Unknown";
    float m_powerUsage = 0.0f;
    float m_fanSpeed = 0.0f;
    int m_cudaCores = 0;
    QString m_driverVersion = "Unknown";

    // NVML
    bool m_nvmlInitialized = false;
    void* m_nvmlDevice = nullptr; // nvmlDevice_t
    
    // Update timer
    QTimer* m_updateTimer = nullptr;
};

} // namespace AIForge
