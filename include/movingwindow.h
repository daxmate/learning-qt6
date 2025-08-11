#pragma once
#include <QWidget>
#include <memory>
#include <QAbstractButton>


namespace Ui {
    class MovingWindow;
}

class MovingWindow : public QWidget {
    Q_OBJECT

public:
    explicit MovingWindow(QWidget *parent = 0);

    ~MovingWindow() override;

private:
    std::unique_ptr<Ui::MovingWindow> ui;

private slots:
    void onMoveWin(const QAbstractButton *directionButton, int distance = 50);
};
