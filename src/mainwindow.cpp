#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QRect>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
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
