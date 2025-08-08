#pragma once
#include <QMainWindow>

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow() override;
private:
    void centerOnScreen();
};
