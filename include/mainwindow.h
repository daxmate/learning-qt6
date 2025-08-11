//
// Created by 张超 on 8/11/25.
//

#ifndef LEARNING_QT6_MAINWINDOW_H
#define LEARNING_QT6_MAINWINDOW_H
#include "ui_mainwindow.h"
#include "lesson_model.h"

namespace Ui {
    class MainWindow;
};

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override = default;

private:
    std::unique_ptr<Ui::MainWindow> ui;
    QSharedPointer<QStringList> lessonData;
    LessonModel *lessonModel;
};
#endif //LEARNING_QT6_MAINWINDOW_H
