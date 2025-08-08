#include "mainwindow.h"

#include <QtGui/qguiapplication.h>
#include <QtCore/QRect>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    setWindowTitle("学习Qt6");
    resize(800, 600);
    centerOnScreen();
}

MainWindow::~MainWindow() = default;


void MainWindow::centerOnScreen() {
    if (const QScreen *s = screen()) {
        const QRect availableGeometry = s->availableGeometry();
        const QRect frame = frameGeometry();
        move(availableGeometry.center() - frame.center());
    }
}
