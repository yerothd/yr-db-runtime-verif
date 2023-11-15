/*
 * yr-db-runtime-verif-database.cpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-database.hpp"


#include "src/utils/yr-db-runtime-verif-utils.hpp"



QString YRDBRUNTIMEVERIF_Database::_db_type("");

QString YRDBRUNTIMEVERIF_Database::_db_name("");

QString YRDBRUNTIMEVERIF_Database::_db_ip_address("");

QString YRDBRUNTIMEVERIF_Database::_db_user_name("");

QString YRDBRUNTIMEVERIF_Database::_db_user_pwd("");

QString YRDBRUNTIMEVERIF_Database::_db_connection_options("");



const QString YRDBRUNTIMEVERIF_Database::YR_DB_RUNTIME_VERIF("yr_db_runtime_verif");

const QString YRDBRUNTIMEVERIF_Database::MYSQL("MySQL");



YRDBRUNTIMEVERIF_Database::YRDBRUNTIMEVERIF_Database(QString dbType)
{
    if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
            (dbType, YRDBRUNTIMEVERIF_Database::MYSQL))
    {
        qDebug() <<
                 "yr-db-runtime-verif | YRDBRUNTIMEVERIF_Database::YRDBRUNTIMEVERIF_Database | database type: QMYSQL \n";
        _database = QSqlDatabase::addDatabase("QMYSQL");
    }

    this->set_db_type(dbType);
    this->set_db_name(YR_DB_RUNTIME_VERIF_Config::_db_name);
    this->set_db_ip_address(YR_DB_RUNTIME_VERIF_Config::_db_ip_address);
    this->set_db_user_name(YR_DB_RUNTIME_VERIF_Config::_db_user_name);
    this->set_db_user_pwd(YR_DB_RUNTIME_VERIF_Config::_db_user_pwd);
    this->set_db_connection_options(YR_DB_RUNTIME_VERIF_Config::_db_connection_options);
}

void YRDBRUNTIMEVERIF_Database::set_db_name(QString db_name)
{
    _db_name = db_name;
    _database.setDatabaseName(_db_name);
}

void YRDBRUNTIMEVERIF_Database::set_db_ip_address(QString db_ip_address)
{
    _db_ip_address = db_ip_address;
    _database.setHostName(_db_ip_address);
}

void YRDBRUNTIMEVERIF_Database::set_db_user_name(QString db_user_name)
{
    _db_user_name = db_user_name;
    _database.setUserName(_db_user_name);
}

void YRDBRUNTIMEVERIF_Database::set_db_user_pwd(QString db_user_pwd)
{
    _db_user_pwd = db_user_pwd;
    _database.setPassword(_db_user_pwd);
}

void YRDBRUNTIMEVERIF_Database::set_db_connection_options(QString db_connection_options)
{
    _db_connection_options = db_connection_options;
    _database.setConnectOptions(_db_connection_options);

}

QString YRDBRUNTIMEVERIF_Database::toString() const
{
    QString ret;

    if (_database.isValid())
    {
        ret.append(QString("db_type: %1\n"
                           "db_name: %2\n"
                           "db_ip_address: %3\n"
                           "db_connection_options: %4").arg(_db_type,
                                                            _database.databaseName
                                                            (),
                                                            _database.hostName
                                                            (),
                                                            _database.connectOptions
                                                            ()));
    }
    else
    {
        ret.append(QString("db_type: %1\n"
                           "db_name: %2\n"
                           "db_ip_address: %3\n"
                           "db_connection_options: %4").arg(_db_type,
                                                            YRDBRUNTIMEVERIF_Database::_db_name,
                                                            YRDBRUNTIMEVERIF_Database::_db_ip_address,
                                                            YRDBRUNTIMEVERIF_Database::_db_connection_options));
    }

    return ret;
}
