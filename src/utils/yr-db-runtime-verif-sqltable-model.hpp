/*
 * yr-db-runtime-verif-sqltable-model.hpp
 *
 *      Author: Dr.-Ing. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_SQLTABLE_MODEL_HPP_
#define _YR_DB_RUNTIME_VERIF_SQLTABLE_MODEL_HPP_

#include <QtCore/QStringList>

#include <QtSql/QSqlRelationalTableModel>


class QMainWindow;
class YR_DB_RUNTIME_VERIF_Logger;


enum YerothSqlQueryType
{
    OR = 0,
    AND = 1
};


class YR_DB_RUNTIME_VERIF_SqlTableModel:public QSqlTableModel
{
public:

    YR_DB_RUNTIME_VERIF_SqlTableModel();

    YR_DB_RUNTIME_VERIF_SqlTableModel(const QSqlQuery &aQSqlQuery);

    YR_DB_RUNTIME_VERIF_SqlTableModel(const QString &sqlTableName,
                                      bool setTableName = true);

    ~YR_DB_RUNTIME_VERIF_SqlTableModel();

    inline bool isFromQSqlQuery()
    {
        return _fromQSqlQuery;
    }

    virtual int yeroth_RESET_specify_filter_FROM_SELECT_STATEMENT(const QString
                                                                  & filter);

    virtual int yeroth_specify_filter_FROM_SELECT_STATEMENT(const QString &
                                                            filter);

    inline virtual void yerothSetFilter_WITH_where_clause(const QString &
                                                          filter)
    {
        QSqlTableModel::setFilter(filter.trimmed());
    }

    inline void changeEditStrategy(QSqlTableModel::EditStrategy strategy)
    {
        setEditStrategy(strategy);
    }

    int Is_SearchQSqlTable(QString tableColumn, QString searchTerm);

    int _Is_SearchQSqlTable(enum YerothSqlQueryType,
                            QString tableColumn,
                            QStringList &searchTermsList);

    inline int OR_Is_SearchQSqlTable(QString tableColumn,
                                     QStringList &searchTermsList)
    {
        return _Is_SearchQSqlTable(OR, tableColumn, searchTermsList);
    }

    inline int AND_Is_SearchQSqlTable(QString tableColumn,
                                      QStringList &searchTermsList)
    {
        return _Is_SearchQSqlTable(AND, tableColumn, searchTermsList);
    }

    int Like_SearchQSqlTable(QString tableColumn, QString searchTerm);

    int _Like_SearchQSqlTable(enum YerothSqlQueryType,
                              QString tableColumn,
                              QStringList &searchTermsList);

    inline int OR_Like_SearchQSqlTable(QString tableColumn,
                                       QStringList &searchTermsList)
    {
        return _Like_SearchQSqlTable(OR, tableColumn, searchTermsList);
    }

    inline int AND_Like_SearchQSqlTable(QString tableColumn,
                                        QStringList &searchTermsList)
    {
        return _Like_SearchQSqlTable(AND, tableColumn, searchTermsList);
    }

    bool insertNewRecord(QSqlRecord &record, QMainWindow *parent = 0);

//      bool updateRecord(QSqlRecord &record);

    bool updateRecord(unsigned row, QSqlRecord &record);

    /*inline bool removeRow(int row)
       {
       return  removeRow(row);
       } */

    void resetFilter();

    inline QString sqlTableName()
    {
        return _sqlTableName;
    }

    inline void yerothSetQuery(const QSqlQuery &query)
    {
        QSqlTableModel::setQuery(query);
    }

    int easySelect();

    bool yerothSetSort(int column, Qt::SortOrder order);

    int yerothSetQueryRowCount(const QString &STRING_aSqlQuery);

    bool yerothSetQuery(const QString &aSqlQuery);

    inline QString yerothSelectStatement()
    {
        return QSqlTableModel::selectStatement();
    }

private:

    const QString _sqlTableName;

    YR_DB_RUNTIME_VERIF_Logger *_logger;

    bool _fromQSqlQuery;
};

#endif /* _YR_DB_RUNTIME_VERIF_SQLTABLE_MODEL_HPP_ */
