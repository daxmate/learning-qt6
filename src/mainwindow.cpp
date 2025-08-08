#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QRect>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
    ui->setupUi(this);
    centerOnScreen();
    connect(ui->up_btn, SIGNAL(clicked()), this, SLOT(onMoveWin()));
    connect(ui->down_btn, SIGNAL(clicked()), this, SLOT(onMoveWin()));
    connect(ui->left_btn, SIGNAL(clicked()), this, SLOT(onMoveWin()));
    connect(ui->right_btn, SIGNAL(clicked()), this, SLOT(onMoveWin()));
}

MainWindow::~MainWindow() = default;


void MainWindow::centerOnScreen() {
    if (const QScreen *s = screen()) {
        const QRect availableGeometry = s->availableGeometry();
        const QRect frame = frameGeometry();
        move(availableGeometry.center() - frame.center());
    }
}

void MainWindow::onMoveWin(int distance) {
    if (const QString &direction = sender()->objectName(); direction == QString("up").append("_btn")) {
        move(x(), y() - distance);
    } else if (direction == QString("down").append("_btn")) {
        move(x(), y() + distance);
    } else if (direction == QString("left").append("_btn")) {
        move(x() - distance, y());
    } else if (direction == QString("right").append("_btn")) {
        move(x() + distance, y());
    }
}
