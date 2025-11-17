#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "../src/gpu/monitor/GPUMonitor.h"
#include "../src/ai/OllamaClient.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setApplicationName("AI Forge Studio");
    
    QQuickStyle::setStyle("Basic");
    
    AIForge::GPUMonitor gpuMonitor;
    gpuMonitor.initialize();
    gpuMonitor.startMonitoring(1000);
    
    AIForge::OllamaClient ollamaClient;
    ollamaClient.checkConnection();
    ollamaClient.fetchModels();
    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gpuMonitor", &gpuMonitor);
    engine.rootContext()->setContextProperty("ollamaClient", &ollamaClient);
    
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
