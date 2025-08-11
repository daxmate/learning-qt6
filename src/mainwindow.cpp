#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QRect>
#include <QtGui/QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
    ui->setupUi(this);

    connect(ui->moveButtons, &QButtonGroup::buttonClicked, this,
            [this](const QAbstractButton *btn) { onMoveWin(btn, 50); });
}

MainWindow::~MainWindow() = default;


void MainWindow::onMoveWin(const QAbstractButton *directionButton, const int distance) {
    const auto rect = QApplication::primaryScreen()->availableGeometry();
    auto newPos = pos();
    if (directionButton->objectName() == "leftButton") {
        newPos.rx() = std::max(0, newPos.x() - distance);
    } else if (directionButton->objectName() == "rightButton") {
        newPos.rx() = std::min(rect.right() - frameGeometry().width(), newPos.x() + distance);
    } else if (directionButton->objectName() == "upButton") {
        newPos.ry() = std::max(0, newPos.y() - distance);
    } else if (directionButton->objectName() == "downButton") {
        newPos.ry() = std::min(rect.bottom() - frameGeometry().height(), newPos.y() + distance);
    } else if (directionButton->objectName() == "centerButton") {
        newPos.rx() = rect.center().x() - width() / 2;
        newPos.ry() = rect.center().y() - height() / 2;
    }
    move(newPos);
}
