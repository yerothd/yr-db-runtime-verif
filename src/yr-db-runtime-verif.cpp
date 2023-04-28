/*
 * yr-db-runtime-verif.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "YRruntimeverification_adaptor.h"

#include "yr-db-runtime-verif-main.hpp"

#include "yr-db-runtime-verif-config.hpp"

#include "yr-db-runtime-verif-database.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"


#include <QtCore/QList>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QCryptographicHash>

#include <QtDBus/QDBusServiceWatcher>

#include <QtNetwork/QNetworkInterface>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>

#include <unistd.h>

#include "utils/yr-db-runtime-verif-logger.hpp"


const QString MYSQL("MySQL");


class YR_DB_RUNTIME_VERIF_ALERT_PERIOD_TIME;

QString text_init_cfg("");


int main(int argc, char *argv[])
{
    qDebug() << "yr-db-runtime-verif | yr-db-runtime-verif.cpp | main. started"
             << "\n";

    //sleep(30);

    QApplication app(argc, argv);

    YR_DB_RUNTIME_VERIF_Config::YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER =
                    QString(std::
                            getenv
                            ("YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER")).trimmed();

    YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER =
                    QString(std::getenv("YR_DB_RUNTIME_VERIF_HOME_FOLDER")).trimmed();

    YR_DB_RUNTIME_VERIF_Config::YEROTH_ERP_3_0_HOME_FOLDER =
                    QString(std::getenv("YEROTH_ERP_3_0_HOME_FOLDER")).trimmed();


    qDebug() << "yr-db-runtime-verif.cpp | main | YEROTH-PGI-3.0 HOME FOLDER: "
             << YR_DB_RUNTIME_VERIF_Config::YEROTH_ERP_3_0_HOME_FOLDER;


    if (YR_DB_RUNTIME_VERIF_Config::YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER.isEmpty())
    {
        QString
        errMsg
        ("La variable d'environement YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER n'a pas de valeur ! \n\n");
        errMsg.append("Contacter DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
                      "\t(yeroth.d@gmail.com)\n\n"
                      "Cliquer sur 'Cancel' pour terminer yr-db-runtime-verif");
        QMessageBox::critical(0, "yr-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg), QMessageBox::Cancel);
        exit(1);
    }


    if (YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER.isEmpty())
    {
        QString
        errMsg
        ("La variable d'environement YR_DB_RUNTIME_VERIF_HOME_FOLDER n'a pas de valeur ! \n\n");
        errMsg.append("Contacter DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
                      "\t(yeroth.d@gmail.com)\n\n"
                      "Cliquer sur 'Cancel' pour terminer yr-db-runtime-verif");
        QMessageBox::critical(0, "yr-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg), QMessageBox::Cancel);
        exit(1);
    }


    QString logFileName(YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER);
    logFileName.append("/yr-db-runtime-verif.log");

    qDebug() <<
             "yr-db-runtime-verif.cpp | main | yr-db-runtime-verif home folder: " <<
             YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER;

    YR_DB_RUNTIME_VERIF_Utils::setLogFileName(logFileName);

    qDebug() << "yr-db-runtime-verif.cpp | main | log file name: "
             << logFileName;

    YR_DB_RUNTIME_VERIF_Logger logger(YR_DB_RUNTIME_VERIF_Utils::
                                      getLogFileName());



    QString
    initCfg(QString("%1/%2").arg
            (YR_DB_RUNTIME_VERIF_Config::YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER,
             "yeroth-erp-3-0.properties"));

    qDebug() <<
             "yr-db-runtime-verif.cpp | main | yeroth-erp-3-0.properties absolute file path: "
             << initCfg << "\n";

    YR_DB_RUNTIME_VERIF_Config::init_YR_DB_RUNTIME_VERIF_Config(initCfg);

    YerothERPDatabase database(YR_DB_RUNTIME_VERIF_Config::_db_type);

    //qDebug() << "++ database.toString(): " << database.toString();

    text_init_cfg.append(database.db_type());

    if (!database.open())
    {
        QString errMsg(QObject::trUtf8("La connection de yr-db-runtime-verif "
                                       "à la base de données ne peut être établiée!\n\n"));

        errMsg.append(QString("Serveur de base de données: %1.\n\n"
                              "Dernière erreur (%2).\n\n"
                              "Contacter DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
                              "\t(yeroth.d@gmail.com)\n\n"
                              "Cliquer sur 'Cancel' pour terminer YEROTH-PGI-3.0").arg
                      (database.db_ip_address(),
                       database.lastError().text()));

        logger.log("main",
                   QString("last database (host: %1) error: %2").arg
                   (database.db_ip_address(), database.lastError().text()));

        QMessageBox::critical(0,
                              "yr-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg), QMessageBox::Cancel);
        exit(4);
    }

    //qDebug() << "yr-db-runtime-verif.cpp | main | Database connection could be opened successfully";
    //logger << "[yr-db-runtime-verif.cpp][main] Database connection could be opened successfully"
    //         << "\n";


    YR_DB_RUNTIME_VERIF_Main YR_DB_RUNTIME_VERIF_instance(&logger);

    new IYRruntimeverificationAdaptor(&YR_DB_RUNTIME_VERIF_instance);





    QDBusConnection connection = QDBusConnection::systemBus();

    QString systemYerothService = "yr.db-runtime.verif";


    bool couldRegisterService = false;

    bool couldRegisterObject = false;


    if (!connection.registerObject("/YR_DB_RUNTIME_VERIF_Main",
                                   &YR_DB_RUNTIME_VERIF_instance))
    {
        qDebug() << QString("++ could not register '%1' object").
                 arg("/YR_DB_RUNTIME_VERIF_Main");

        qDebug() << "++ last error: "
                 << QDBusError::errorString(connection.lastError().type());

        couldRegisterObject = false;
    }
    else
    {
        qDebug() << QString("could register '%1' object").
                 arg("/YR_DB_RUNTIME_VERIF_Main");

        couldRegisterObject = true;
    }


    if (!connection.registerService(systemYerothService))
    {
        qDebug() << QString("could not register '%1' service").
                 arg(systemYerothService);

        qDebug() << "++ last error: " << connection.lastError();

        couldRegisterService = false;
    }
    else
    {
        qDebug() << QString("could register '%1' service").
                 arg(systemYerothService);

        couldRegisterService = true;
    }

    if (couldRegisterService && couldRegisterObject)
    {
        qDebug() << "STARTING YR-DB-RUNTIME-VERIF !";
    }

    return app.exec();
}
