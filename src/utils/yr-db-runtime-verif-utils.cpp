/*
 * yr-db-runtime-verif-utils.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-utils.hpp"


#include <QtCore/QDebug>
#include <QtCore/QDate>
#include <QtCore/QBuffer>
#include <QtCore/QProcess>

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "yr-db-runtime-verif-logger.hpp"

QString YR_DB_RUNTIME_VERIF_Utils::_mainWorkingDirectory("");

QString YR_DB_RUNTIME_VERIF_Utils::_logFileName("yr-db-runtime-verif.log");

const QString YR_DB_RUNTIME_VERIF_Utils::EMPTY_STRING("");

const QString YR_DB_RUNTIME_VERIF_Utils::USERS("users");
const QString YR_DB_RUNTIME_VERIF_Utils::TITRES("titres");
const QString YR_DB_RUNTIME_VERIF_Utils::LOCALISATIONS("localisations");
const QString YR_DB_RUNTIME_VERIF_Utils::CATEGORIES("categories");
const QString YR_DB_RUNTIME_VERIF_Utils::CLIENTS("clients");
const QString YR_DB_RUNTIME_VERIF_Utils::FOURNISSEURS("fournisseurs");
const QString YR_DB_RUNTIME_VERIF_Utils::ALERTES("alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::CONDITIONS_ALERTES("conditions_alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::COURRIERS_ALERTES("courriers_alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::STOCKS("stocks");
const QString YR_DB_RUNTIME_VERIF_Utils::STOCKS_VENDU("stocks_vendu");

const QString YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT("dd.MM.yyyy");

const QString
YR_DB_RUNTIME_VERIF_Utils::
TIME_FORMAT_WITH_MILLISECONDS(FORMAT_TIME_WITH_MS);

const QString YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT("HH:mm:ss");

const QString YR_DB_RUNTIME_VERIF_Utils::DB_DATE_FORMAT("yyyy-MM-dd");

const QString YR_DB_RUNTIME_VERIF_Utils::LOCALHOST("localhost");

const QString YR_DB_RUNTIME_VERIF_Utils::LOCALHOST_IP_ADDRESS("127.0.0.1");

const QString YR_DB_RUNTIME_VERIF_Utils::STRING_OUI("oui");

const QString YR_DB_RUNTIME_VERIF_Utils::STRING_NON("non");

const unsigned int YR_DB_RUNTIME_VERIF_Utils::FACTURE_PETIT_NOM_ARTICLE_MAX_CHARS(12);

const unsigned int YR_DB_RUNTIME_VERIF_Utils::STRING_MAX_CHARS(18);

const QString YR_DB_RUNTIME_VERIF_Utils::INFERIEUR_OU_EGAL("<=");

const QString YR_DB_RUNTIME_VERIF_Utils::SUPERIEUR(">");

const QString YR_DB_RUNTIME_VERIF_Utils::UTILISATEUR_NON_EXISTANT("unknown user");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_CLIENT("yr.db-runtime.verif");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_CLIENT_OBJECT("/");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_SERVER("com.yeroth-erp.server");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_SERVER_OBJECT("/");

const QChar YR_DB_RUNTIME_VERIF_Utils::SLASH_CHAR('/');


void YR_DB_RUNTIME_VERIF_Utils::YEROTH_CREATE_FOLDER(const QString &aFullPathDir)
{
    QFileInfo aFullPathDirInfo(aFullPathDir);

    if (!aFullPathDirInfo.exists())
    {
        qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                 << QString("Folder '%1' does not exist !").arg(aFullPathDir);

        QDir tempFileDir;

        if (tempFileDir.mkpath(aFullPathDir))
        {
            qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                     << QString("Created folder '%1' !").arg(aFullPathDir);
        }
        else
        {
            qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                     << QString("Could not Create folder '%1' !").arg(aFullPathDir);
        }
    }
}


int
YR_DB_RUNTIME_VERIF_Utils::start_PROCESS_AND_GET_PROCESS_output_AS_QSTRING
(const QString &program_executable_location_full_path,
 const QStringList &program_executable_args,
 QString &program_output_IN_OUT)
{
    program_output_IN_OUT.clear();

    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

//    qDebug() << "program_executable_location_full_path: " << program_executable_location_full_path;
//    qDebug() << "program_executable_args: " << program_executable_args;

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    program_output_IN_OUT.append(A_YEROTH_PROCESS.
                                 readAllStandardOutput().trimmed());

    return program_output_IN_OUT.size();
}


int
YR_DB_RUNTIME_VERIF_Utils::

start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const QString &
                                                program_executable_location_full_path,
                                                const QString &
                                                output_file_full_path,
                                                const QStringList &
                                                program_executable_args)
{
    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    QFile tmpFile(output_file_full_path);

    if (tmpFile.open(QFile::WriteOnly))
    {
        tmpFile.write(A_YEROTH_PROCESS.readAllStandardOutput().trimmed());
    }
    else
    {
        return -1;
    }

    int output_file_size = tmpFile.size();

    tmpFile.close();

    return output_file_size;
}


bool YR_DB_RUNTIME_VERIF_Utils::GZIP_YEROTH_FILE(const QString &
                                                 program_working_directory_full_path,
                                                 const QString &file_full_path)
{
    QStringList gzipPROG_ARGS;

    gzipPROG_ARGS.append(file_full_path);

    int file_size =
                    YR_DB_RUNTIME_VERIF_Utils::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
                    ("/usr/bin/gzip",
                     program_working_directory_full_path,
                     QString("%1.gz").arg(file_full_path),
                     gzipPROG_ARGS);
    return (file_size >= 0);
}


QString YR_DB_RUNTIME_VERIF_Utils::generateSqlLike__AS_IS(QString sqlTableColumn,
                                                          QString searchStr)
{
    QString result;

    searchStr.replace("'", "''");

    result.append(sqlTableColumn).append(QString(" LIKE '%1'").
                                         arg(searchStr));
    return result;
}


QString YR_DB_RUNTIME_VERIF_Utils::generateSqlLike(QString sqlTableColumn,
                                                   QString searchStr)
{
    QString result;

    searchStr.replace("'", "''");

    result.append(sqlTableColumn).append(" LIKE '%").append(searchStr).
    append("%' ");

    return result;
}


bool YR_DB_RUNTIME_VERIF_Utils::execQuery(const QString &strQuery,
                                          YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    QSqlQuery query;
    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
    }

    return success;
}


int YR_DB_RUNTIME_VERIF_Utils::execQuery(QSqlQuery &query,
                                         const QString &strQuery,
                                         YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}


int YR_DB_RUNTIME_VERIF_Utils::execQuery(QSqlQuery &query,
                                         YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}


int YR_DB_RUNTIME_VERIF_Utils::getNextIdFromTable(const QString &tableName)
{
    //qDebug() << "[YerenUtils::getLastIdFromTable()] : next id from table '" << tableName << "'";
    QString strQuery("SELECT id FROM ");
    strQuery.append(tableName);

    QSqlQuery query(strQuery);
    QSqlRecord rec = query.record();

    if (query.last())
    {
        int lastId = query.value(0).toInt();
        ++lastId;
        //qDebug() << "\t next id 1: " << lastId;
        return lastId;
    }

    return 0;
}


bool YR_DB_RUNTIME_VERIF_Utils::start_db_transaction()
{
    return false;
}


bool YR_DB_RUNTIME_VERIF_Utils::rollback_db_transaction()
{
    return false;
}


bool YR_DB_RUNTIME_VERIF_Utils::commit_db_transaction()
{
    return false;
}


QString YR_DB_RUNTIME_VERIF_Utils::get_text(const QVariant &qv)
{
    QString retStr;

    switch (qv.type())
    {
    case QVariant::UInt:
        return QString::number(qv.toUInt());

    case QVariant::Int:
        return QString::number(qv.toInt());

    case QVariant::Double:
        return QString::number(qv.toDouble(), 'f', 2);

    case QVariant::ULongLong:
        return QString::number(qv.toULongLong());

    case QVariant::LongLong:
        return QString::number(qv.toLongLong());

    case QVariant::Char:
        retStr = QString(qv.toChar());
        break;

    case QVariant::String:
        retStr = QString(qv.toString());
        break;

    case QVariant::Bool:
        retStr.append(qv.toBool());
        break;

    case QVariant::Date:
        retStr = DATE_TO_STRING(qv.toDate());
        break;

    case QVariant::Time:
        retStr = TIME_TO_STRING(qv.toTime());
        break;

    default:
        retStr = QString(qv.type());
        break;
    }

    return YR_DB_RUNTIME_VERIF_Utils::prepareSqlStr(retStr);
}
