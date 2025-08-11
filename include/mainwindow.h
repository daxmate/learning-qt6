#pragma once
#include <QMainWindow>
#include <memory>
#include <QAbstractButton>


namespace Ui {
    class MainWindow;
}

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow() override;

private:
    std::unique_ptr<Ui::MainWindow> ui;

private slots:
    void onMoveWin(const QAbstractButton *directionButton, int distance = 50);
};
