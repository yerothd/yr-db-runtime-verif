/*
 * yr-db-runtime-verif-CONFIG.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-CONFIG.hpp"


//##################### QMAINWINDOW RELATED IMPORTS #####################

#include "src/windows/yr-db-runtime-verif-windows.hpp"

//#######################################################################


#include "src/utils/yr-db-runtime-verif-database.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"


#include <QtCore/QDebug>



QString YR_DB_RUNTIME_VERIF_Config::_db_type("");

QString YR_DB_RUNTIME_VERIF_Config::_db_name("");

QString YR_DB_RUNTIME_VERIF_Config::_db_ip_address("");

QString YR_DB_RUNTIME_VERIF_Config::_db_user_name("");

QString YR_DB_RUNTIME_VERIF_Config::_db_user_pwd("");

QString YR_DB_RUNTIME_VERIF_Config::_db_connection_options("");


QString YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir("/tmp");


QString YR_DB_RUNTIME_VERIF_Config::pathToLatexSystemRootFolder("/usr/bin");


const QString YR_DB_RUNTIME_VERIF_Config::__pathToPdfReader("/usr/bin/evince");

QString YR_DB_RUNTIME_VERIF_Config::pathToPdfReader("/usr/bin/evince");


QString YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_CONFIGURATION_FILE_SEPARATION_OPERATOR("=");


QString YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE("");

QString YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_TEMPORARY_FOLDER("/tmp");

QString YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_SYSTEM_dbus_service_name("yr.db-runtime.verif");

QString YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER("/tmp");


YRDBRUNTIMEVERIF_Windows *YR_DB_RUNTIME_VERIF_Config::ALL_WINDOWS(0);



void YR_DB_RUNTIME_VERIF_Config::init_YR_DB_RUNTIME_VERIF_Config(QString initCfg)
{
    QFile file(initCfg);

    if (!file.open(QFile::ReadOnly))
    {
        return;
    }

    QTextStream init_cfg(&file);
    QString line;
    QStringList list;

    do
    {
        line = init_cfg.readLine();

        list = line.split(YR_DB_RUNTIME_VERIF_CONFIGURATION_FILE_SEPARATION_OPERATOR);
        //qDebug() << "++ line: " << line << "\n";

        if ("db_type" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_type = list.at(1).trimmed();
            // qDebug() << "++ db_type = " << db_type << "\n";
        }
        if ("db_name" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_name = list.at(1).trimmed();

            //qDebug() << "++ db_name = " << db_name << "\n";
        }
        else if ("db_ip_address" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_ip_address = list.at(1).trimmed();
            //qDebug() << "++ db_ip_address = " << db_ip_address << "\n";
        }
        else if ("db_user_name" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_user_name = list.at(1).trimmed();
            //qDebug() << "++ db_user_name = " << db_user_name << "\n";
        }
        else if ("db_user_pwd" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_user_pwd = list.at(1).trimmed();
            //qDebug() << "++ db_user_pwd = " << db_user_pwd << "\n";
        }
        else if ("db_connection_options" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::_db_connection_options = list.at(1).trimmed();
            //qDebug() << "++ db_connection_options = " << db_connection_options << "\n";
        }
        else if ("parameter_full_path_pdf_reader" == list.at(0))
        {
            YR_DB_RUNTIME_VERIF_Config::pathToPdfReader = list.at(1).trimmed();
            //qDebug() << "++ parameter_full_path_pdf_reader = "
            //         <<  YR_DB_RUNTIME_VERIF_Config::pathToPdfReader << "\n";
        }
    }
    while (!line.isNull());
}


void YR_DB_RUNTIME_VERIF_Config::save_YR_DB_RUNTIME_VERIF_Config()
{
    QFile file (YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);

    QDEBUG_STRINGS_OUTPUT_2("YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE",
                            YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);

    if (!file.open(QFile::WriteOnly))
    {
        return;
    }

    QTextStream textStream(&file);

    textStream << QString("parameter_full_path_pdf_reader=%1\n")
                    .arg(YR_DB_RUNTIME_VERIF_Config::pathToPdfReader);

    file.close();
}
