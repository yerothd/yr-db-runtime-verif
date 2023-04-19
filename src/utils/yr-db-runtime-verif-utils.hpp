/*
 * yr-db-runtime-verif-utils.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _SRC_YR_DB_RUNTIME_VERIF_UTILS_HPP_
#define _SRC_YR_DB_RUNTIME_VERIF_UTILS_HPP_

#include "yr-db-runtime-verif-definition-format-date-time.hpp"

#include <QtCore/QRegExp>
#include <QtCore/QCryptographicHash>
#include <QtCore/QLocale>
#include <QtCore/QDate>
#include <QtCore/QDir>

#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtGui/QStandardItemModel>
#include <QtWidgets/QComboBox>
#include <QtGui/QIntValidator>
#include <QtGui/QDoubleValidator>
#include <QtWidgets/QTableWidget>

#include <QtSql/QSqlTableModel>

class YR_DB_RUNTIME_VERIF_Logger;

class QSqlTableModel;
class QStandardItemModel;
class QTableWidget;
class QString;
class QWidget;
class QMainWindow;
class QLabel;
class QComboBox;
class QRegExp;
class QLocale;
class QProcess;

class YerenWindows;
class YerenLineEdit;
class YerenSqlTableModel;



class YR_DB_RUNTIME_VERIF_Utils:public QObject
{
Q_OBJECT public:

    inline YR_DB_RUNTIME_VERIF_Utils()
    {
    }

    virtual ~ YR_DB_RUNTIME_VERIF_Utils()
    {
    }

    inline static void setLogFileName(QString logFileName)
    {
        _logFileName = logFileName;
    }

    inline static QString getLogFileName()
    {
        return _logFileName;
    }

    inline static bool isEqualCaseSensitive(const QString &str1,
                                            const QString &str2)
    {
        return (0 == str1.compare(str2, Qt::CaseSensitive));
    }

    inline static bool isEqualCaseInsensitive(const QString &str1,
                                              const QString &str2)
    {
        return (0 == str1.compare(str2, Qt::CaseInsensitive));
    }

    inline static QString prepareSqlStr(QString aStr)
    {
        return aStr.replace("'", "''");
    }

    inline static QString getFileNameWithDateANDCurrentTime(const QString &
                                                            fileName)
    {
        return QString("%1%2%3").arg(fileName,
                                     QDate::
                                     currentDate().toString("-yyyyMMdd"),
                                     QTime::
                                     currentTime().toString("_HHmmss"));
    }

    static void YEROTH_CREATE_FOLDER(const QString &aFullPathDir);

    static int start_PROCESS_AND_GET_PROCESS_output_AS_QSTRING(const QString &
                                                               program_executable_location_full_path,
                                                               const
                                                               QStringList &
                                                               program_executable_args,
                                                               QString &
                                                               program_output_IN_OUT);

    /**
     * Returns the size of the output file created
     * by execution of the program 'program' !
     */
    inline static int start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const
                                                                      QString &
                                                                      program_executable_location_full_path,
                                                                      const
                                                                      QString &
                                                                      program_working_directory_full_path,
                                                                      const
                                                                      QString &
                                                                      output_file_name,
                                                                      const
                                                                      QStringList
                                                                      &
                                                                      program_executable_args)
    {
        return
                        YR_DB_RUNTIME_VERIF_Utils::
                        start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
                        (program_executable_location_full_path,
                         QString("%1/%2").arg(program_working_directory_full_path,
                                              output_file_name), program_executable_args);
    }

    /**
     * Returns the size of the output file created
     * by execution of the program 'program' !
     */
    static int start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const QString &
                                                               program_executable_location_full_path,
                                                               const QString &
                                                               output_file_full_path,
                                                               const
                                                               QStringList &
                                                               program_executable_args);

    static bool GZIP_YEROTH_FILE(const QString &
                                 program_working_directory_full_path,
                                 const QString &file_full_path);

    static QString generateSqlLike__AS_IS(QString sqlTableColumn,
                                          QString searchStr);

    static QString generateSqlLike(QString sqlTableColumn, QString searchStr);

    inline static QString generateSqlLike(const char *sqlTableColumn,
                                          QString searchStr)
    {
        return YR_DB_RUNTIME_VERIF_Utils::
               generateSqlLike(QString(sqlTableColumn), searchStr);
    }

    inline static QString generateSqlIs(QString sqlTableColumn,
                                        QString searchStr)
    {
        return QString("%1 = \'%2\'").arg(sqlTableColumn,
                                          searchStr.replace("'", "''"));
    }

    inline static QString generateSqlIs(const char *sqlTableColumn,
                                        QString searchStr)
    {
        return YR_DB_RUNTIME_VERIF_Utils::generateSqlIs(QString(sqlTableColumn),
                                                        searchStr);
    }

    inline static void qDebugStrings(const QString &firstString,
                                     const QStringList &aStringList)
    {
        qDebug() << QString("++ %1: ").arg(firstString) << aStringList;
    }

    inline static void qDebugStrings(const QString &firstString,
                                     const QString &secondString = "")
    {
        qDebug() << QString("++ %1: %2").arg(firstString, secondString);
    }

    static bool execQuery(const QString &strQuery,
                          YR_DB_RUNTIME_VERIF_Logger *logger = 0);

    static int execQuery(QSqlQuery &query, const QString &strQuery,
                         YR_DB_RUNTIME_VERIF_Logger *logger = 0);

    static int execQuery(QSqlQuery &query,
                         YR_DB_RUNTIME_VERIF_Logger *logger = 0);

    static QString get_text(const QVariant &qv);

    static int getNextIdFromTable(const QString &tableName);

    static bool start_db_transaction();

    static bool rollback_db_transaction();

    static bool commit_db_transaction();

    inline static QByteArray md5Hash(QString data)
    {
        return QCryptographicHash::hash(data.toLatin1(),
                                        QCryptographicHash::Md5);
    }

    static const QString EMPTY_STRING;

    static const QString USERS;
    static const QString TITRES;
    static const QString LOCALISATIONS;
    static const QString CATEGORIES;
    static const QString CLIENTS;
    static const QString FOURNISSEURS;
    static const QString ALERTES;
    static const QString CONDITIONS_ALERTES;
    static const QString COURRIERS_ALERTES;
    static const QString STOCKS;
    static const QString STOCKS_VENDU;

    static const QString DATE_FORMAT;

    static const QString TIME_FORMAT_WITH_MILLISECONDS;

    static const QString TIME_FORMAT;

    static const QString DB_DATE_FORMAT;

    static const QString APROPOS_MSG;

    static const QString APPLICATION_NAME;

    static const QString LOCALHOST;

    static const QString LOCALHOST_IP_ADDRESS;

    static const QString STRING_OUI;

    static const QString STRING_NON;

    static const unsigned int FACTURE_PETIT_NOM_ARTICLE_MAX_CHARS;

    static const unsigned int STRING_MAX_CHARS;

    static const QString INFERIEUR_OU_EGAL;
    static const QString SUPERIEUR;

    static const QString UTILISATEUR_NON_EXISTANT;

    static const QString JH_NISSI_CLIENT;

    static const QString JH_NISSI_CLIENT_OBJECT;

    static const QString JH_NISSI_SERVER;

    static const QString JH_NISSI_SERVER_OBJECT;

    static const QChar SLASH_CHAR;

private:

    static QString _mainWorkingDirectory;
    static QString _logFileName;
};

#define YEROTH_DELETE_FREE_POINTER_NOW(P) \
    { \
        if (0 != P) \
        { \
            delete P; \
        } \
    }

/**
 * Macros to facilitate the use of YR_DB_RUNTIME_VERIF_Utils static methods
 */

#define FILE_NAME_WITH_CURRENT_DATE_AND_TIME(F) YR_DB_RUNTIME_VERIF_Utils::getFileNameWithDateANDCurrentTime(F)

#define SET_APPLICATION_STYLE QApplication::setStyle( new QCDEStyle );

#define QDEBUG_STRINGS_OUTPUT_1(X) YR_DB_RUNTIME_VERIF_Utils::qDebugStrings(X, "")

#define QDEBUG_STRINGS_OUTPUT_2_N(X, Y) YR_DB_RUNTIME_VERIF_Utils::qDebugStrings(X, QString::number(Y))

#define QDEBUG_STRINGS_OUTPUT_2(X, Y) YR_DB_RUNTIME_VERIF_Utils::qDebugStrings(X, Y)

#define QDEBUG_STRINGS_OUTPUT_QSTRINGLIST(X, Y) YR_DB_RUNTIME_VERIF_Utils::qDebugStrings(X, Y)

#define BOOL_TO_STRING(B) (B ? "True" : "False")

//Get the value of an QSqlRecord when given as value R
#define GET_SQL_RECORD_DATA(R,V) YR_DB_RUNTIME_VERIF_Utils::get_text(R.value(V))

//Get the MD5 hash of value X
#define MD5_HASH(X) YR_DB_RUNTIME_VERIF_Utils::md5Hash(X)

//Precondition: X is of type QString and has latin accents.
#define FROM_UTF8_STRING(X) QString::fromUtf8(X.toStdString().c_str())

#define FROM_UTF8_STRING_FROM_CHAR(X) QString::fromUtf8(QObject::tr(X).toStdString().c_str())

#define GENERATE_SQL_LIKE_STMT(COLUMN, SEARCH_STR) \
    YR_DB_RUNTIME_VERIF_Utils::generateSqlLike(COLUMN, SEARCH_STR)

#define GENERATE_SQL_IS_STMT(COLUMN, SEARCH_STR) \
    YR_DB_RUNTIME_VERIF_Utils::generateSqlIs(COLUMN, SEARCH_STR)

#define GENERATE_SQL_IS_NOT_EMPTY(COLUMN) \
    YR_DB_RUNTIME_VERIF_Utils::generateSqlIsNotEmpty(COLUMN)

#define GENERATE_SQL_IS_EMPTY(COLUMN) \
    YR_DB_RUNTIME_VERIF_Utils::generateSqlIsEmpty(COLUMN)

#define GET_CURRENT_DATE QDate::currentDate()

#define YEROTH_ERP_3_0_START_DATABASE_TRANSACTION YR_DB_RUNTIME_VERIF_Utils::start_db_transaction()

#define YEROTH_ERP_3_0_ROLLBACK_DATABASE_TRANSACTION YR_DB_RUNTIME_VERIF_Utils::rollback_db_transaction()

#define YEROTH_ERP_3_0_COMMIT_DATABASE_TRANSACTION YR_DB_RUNTIME_VERIF_Utils::commit_db_transaction()

#define POURCENTAGE_YEROTH_GET_VALUE(X, TOTAL) ( (0 == TOTAL) ? 0 : ((X / TOTAL) * 100.0) )

#define GET_CURRENT_DATE_YEAR QString::number((QDate::currentDate().year() != 0) ? QDate::currentDate().year() : 2020)

#define GET_CURRENT_STRING_DATE QDate::currentDate().toString(YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT)

#define CURRENT_TIME_WITH_MILLISECONDS QTime::currentTime().toString(YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT_WITH_MILLISECONDS)

#define CURRENT_TIME QTime::currentTime().toString(YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT)

#define FILE_NAME_USERID_CURRENT_TIME(F) YR_DB_RUNTIME_VERIF_Utils::getFileNameWithUserIDAndCurrentTime(F)

#define DATE_TO_STRING(D) D.toString(YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT)

#define GET_DATE_FROM_STRING(D) QDate::fromString(D, YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT)

#define TIME_TO_STRING(D) D.toString(YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT)

#define DATE_TO_DB_FORMAT_STRING(D) D.toString(YR_DB_RUNTIME_VERIF_Utils::DB_DATE_FORMAT)

#define SET_DATE_TO_STRING(D) D.toString(YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT)


#define POPULATE_COMBOBOX(C, T, F)  YR_DB_RUNTIME_VERIF_Utils::populateComboBox(*C, T, F)

#define POPULATE_COMBOBOX_MISSING(C, ACONTENT, TABLENAME, FIELD)  YR_DB_RUNTIME_VERIF_Utils::populateComboBoxMissing(*C, ACONTENT, TABLENAME, FIELD)

#ifdef YEROTH_FRANCAIS_LANGUAGE
#define GET_NUM_STRING(NUM) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.toString(NUM)
#define GET_DOUBLE_STRING(NUM) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.toString(NUM, 'f', 2)
#define GET_DOUBLE_STRING_P(NUM, P) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.toString(NUM, 'f', P)
#define GET_CURRENCY_STRING_NUM(NUM) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.toString(NUM, 'f', 2).append(" FCFA")
#define GET_CURRENCY_STRING_NUM_P(NUM, P) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.toString(NUM, 'f', P).append(" FCFA")

#define GET_MONTH_NAME_LOCALIZED(M) YR_DB_RUNTIME_VERIF_Utils::frenchLocale.monthName(M)
#endif

#ifdef YEROTH_ENGLISH_LANGUAGE
#define GET_NUM_STRING(NUM) YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(NUM)
#define GET_DOUBLE_STRING(NUM) YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(NUM, 'f', 2)
#define GET_DOUBLE_STRING_P(NUM, P) YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(NUM, 'f', P)
#define GET_CURRENCY_STRING_NUM(NUM) YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(NUM, 'f', 2).append(" FCFA")
#define GET_CURRENCY_STRING_NUM_P(NUM, P) YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(NUM, 'f', P).append(" FCFA")

#define GET_MONTH_NAME_LOCALIZED(M) YR_DB_RUNTIME_VERIF_Utils::englishLocale.monthName(M)
#endif

#endif /* _SRC_YR_DB_RUNTIME_VERIF_UTILS_HPP_ */
