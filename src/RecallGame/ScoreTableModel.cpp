#include "ScoreTableModel.h"

ScoreTableMode::ScoreTableMode(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int ScoreTableMode::rowCount(const QModelIndex & /*parent*/) const
{
   return 18;
}

int ScoreTableMode::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

QVariant ScoreTableMode::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("Fila%1, Columna%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
    }
    return QVariant();
}

QVariant ScoreTableMode::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Player");
            case 1:
                return QString("Max Dificulty/Level");
            case 2:
                return QString("Score");
            }
        }
    }
    return QVariant();
}
