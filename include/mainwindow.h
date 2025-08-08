#pragma once
#include <QMainWindow>
#include <memory>

namespace Ui {
    class MainWindow;
}

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow() override;

private:
    void centerOnScreen();

    std::unique_ptr<Ui::MainWindow> ui;

private slots:
    void onMoveWin(const QString &direction, int distance = 10);
};
