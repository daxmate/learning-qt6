//
// Created by 张超 on 8/11/25.
//

#ifndef LEARNING_QT6_LESSON_MODEL_H
#define LEARNING_QT6_LESSON_MODEL_H
#include <QAbstractListModel>

class LessonModel final : public QAbstractListModel {
    Q_OBJECT

public:
    explicit LessonModel(const QSharedPointer<QStringList> list, QObject *parent = nullptr);


    ~LessonModel() override = default;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private:
    QSharedPointer<QStringList> m_list;
};

#endif //LEARNING_QT6_LESSON_MODEL_H
