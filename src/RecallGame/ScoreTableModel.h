#ifndef SCORETABLEMODEL_H
#define SCORETABLEMODEL_H

#include <QAbstractTableModel>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QVector>

/*! class ScoreTableModel that is used to costruct the model of the score table view */
class ScoreTableModel:public QAbstractTableModel
{
    Q_OBJECT
protected:
    int nCurrentRows;/**< A integer value of the amount of rows */
    QVector<QStringList> scoresValues;/**< A QVector object of QStringLists thar stores the scores data values */

public:
    /**
        @brief default constructor for this class
        @details this method constructs and initialize the members of this class
        @param QObject A pointer to QObject that is used as parent
        @return no return value for this method
    */
    ScoreTableModel(QObject *parent);
    /**
        @brief virtual int function rowCount that returns the amount of rows for the model
        @details this function initialize the amount of rows.
        @param parent The index of the value (row,column)
        @return amount of rows
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    /**
        @brief virtual int function columnCount that returns the amount of columns for the model
        @details this function initialize the amount of columns.
        @param parent The index of the value (row,column)
        @return amount of columns
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    /**
        @brief virtual QVariant function data that returns data values to be display
        @details this function initialize current data to be displayed on the table view
        @param index The index of the value (row,column)
        @param role The integer value of role diplay
        @return QVariant value is returned and put in a specfic model index (row,column)
    */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    /**
        @brief virtual QVariant function headerData that returns data headers values to be display
        @details this function initialize current headerdata to be displayed in the columnsCount columns
        @param section The section of the model
        @param orientation the orientation of the columns
        @param role the role to display headerdata
        @return the QVariant data for the given role and section in the header with the specified orientation.
    */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    /**
        @brief loadScores
        @details This method reads from scores file and fill the data to be displayed
        @return no return value for this method
    */
    void loadScores(const QString appLocation);

};

#endif // SCORETABLEMODEL_H
