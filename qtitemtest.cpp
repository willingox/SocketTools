#include "qtitemtest.h"

qtitemtest::qtitemtest(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant qtitemtest::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex qtitemtest::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex qtitemtest::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int qtitemtest::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int qtitemtest::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant qtitemtest::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
