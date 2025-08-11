//
// Created by 张超 on 8/11/25.
//
#include "../include/lesson_model.h"

LessonModel::LessonModel(const QSharedPointer<QStringList> list, QObject *parent) : m_list(list),
    QAbstractListModel(parent) {
}

int LessonModel::rowCount(const QModelIndex &parent) const {
    return m_list->size();
}

QVariant LessonModel::data(const QModelIndex &index, const int role) const {
    if (!m_list || !index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        if (const int row = index.row(); row >= 0 && row < m_list->size())
            return m_list->at(row);
    }
    return QVariant();
}
