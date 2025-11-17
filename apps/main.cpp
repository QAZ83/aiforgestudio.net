#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow w;
    w.setWindowTitle("AI Forge Studio");
    w.resize(1280, 720);
    w.show();
    return app.exec();
}