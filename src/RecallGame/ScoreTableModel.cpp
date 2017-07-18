#include "ScoreTableModel.h"

ScoreTableMode::ScoreTableMode(QObject *parent)
    :QAbstractTableModel(parent)
    ,nCurrentRows(0)
{

}

int ScoreTableMode::rowCount(const QModelIndex & /*parent*/) const
{
   return nCurrentRows;
}

int ScoreTableMode::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

QVariant ScoreTableMode::data(const QModelIndex &index, int role) const
{    
    if (role == Qt::DisplayRole)
    {

     return QString(this->scoresValues[index.row()][index.column()]);

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

#include <iostream>
void ScoreTableMode::loadScores()
{


    QFile scoresFile("../build/GameScores.txt");

    if(!scoresFile.open(QIODevice::ReadOnly))
    {

    }else
    {
        QTextStream in(&scoresFile);

        while(in.atEnd()==false)
        {
            QString line= in.readLine();
            QStringList temp = line.split(" ");
            if(temp.size()!=0)
            {
                this->scoresValues.push_back(temp);
            }
        }
        std::cout<<"items "<<this->scoresValues.size()<<std::endl;
        if(this->scoresValues.size()!=0)
        {
            this->nCurrentRows = this->scoresValues.size();
        }else
        {
            this->nCurrentRows=0;
        }
        scoresFile.close();

    }
}
