//
// Created by 张超 on 8/11/25.
//
#include "mainwindow.h"
#include "../include/lesson_model.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(std::make_unique<Ui::MainWindow>()),
                                          lessonData(QSharedPointer<QStringList>::create()) {
    ui->setupUi(this);
    lessonData->append("hellworld");
    lessonModel = new LessonModel(lessonData, this);
    ui->listView->setModel(lessonModel);
}
