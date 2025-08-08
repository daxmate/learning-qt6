#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QRect>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
    ui->setupUi(this);
    centerOnScreen();

    auto connectButton = [this](const QPushButton *button, const QString &direction) {
        connect(button, &QPushButton::clicked, this, [this, direction]() {
            onMoveWin(direction, 10);
        });
    };
    connectButton(ui->up_btn, "up");
    connectButton(ui->down_btn, "down");
    connectButton(ui->left_btn, "left");
    connectButton(ui->right_btn, "right");
}

MainWindow::~MainWindow() = default;


void MainWindow::centerOnScreen() {
    if (const QScreen *s = screen()) {
        const QRect availableGeometry = s->availableGeometry();
        const QRect frame = frameGeometry();
        move(availableGeometry.center() - frame.center());
    }
}

void MainWindow::onMoveWin(const QString &direction, const int distance) {
    const auto rect = QApplication::primaryScreen()->availableGeometry();
    auto newPos = pos();
    if (direction == "left") {
        newPos.rx() = std::max(0, newPos.x() - distance);
    } else if (direction == "right") {
        newPos.rx() = std::min(rect.right() - width(), newPos.x() + distance);
    } else if (direction == "up") {
        newPos.ry() = std::max(0, newPos.y() - distance);
    } else if (direction == "down") {
        newPos.ry() = std::min(rect.bottom() - height(), newPos.y() + distance);
    }

    move(newPos);
}
