#ifndef SCORETABLEMODEL_H
#define SCORETABLEMODEL_H

#include <QAbstractTableModel>

class ScoreTableMode:public QAbstractTableModel
{
    Q_OBJECT
public:
    ScoreTableMode(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    int nCurrentRows;

};

#endif // SCORETABLEMODEL_H
