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



//##################### QMAINWINDOW RELATED IMPORTS #####################

#include "src/windows/yr-db-runtime-verif-windows.hpp"

//#######################################################################



#include "utils/yr-db-runtime-verif-logger.hpp"


const QString MYSQL("MySQL");


class YR_DB_RUNTIME_VERIF_ALERT_PERIOD_TIME;

QString text_init_cfg("");


int main(int argc, char *argv[])
{
    qDebug() << "yr-db-runtime-verif | yr-db-runtime-verif.cpp | main. started"
             << "\n";


    QApplication app(argc, argv);


    //########################### GRAPHICAL USER INTERFACE SETUP CODE ###########################
    QApplication::setWindowIcon(QIcon(":yr-db-runtime-verif-images/LOGO-icon.png"));

    QApplication::setStyle(QStyleFactory::create("cde"));


    YRDBRUNTIMEVERIF_Windows all_windows(app.desktop());

    all_windows.createAll_YRDBRUNTIMEVERIF_Windows();

    YR_DB_RUNTIME_VERIF_Config::SET_ALL_WINDOWS_instance(&all_windows);

    QToolBar &atoolBar = all_windows._yrdbruntimeverif_main_Window->get_tool_bar();
    //############################################################################################



    YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER =
                    QString(std::getenv("YR_DB_RUNTIME_VERIF_HOME_FOLDER")).trimmed();


    qDebug() << "yr-db-runtime-verif.cpp | main | YR-DB-RUNTIME-VERIF HOME FOLDER: "
             << YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER;


    if (YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER.isEmpty())
    {
        QString errMsg
        	("Environment variable YR_DB_RUNTIME_VERIF_HOME_FOLDER isn't set ! \n\n");

        errMsg.append("PLEASE TRY logging out AND THEN logging in. \n\n"
        			  "In case yr-db-runtime-verif is still not functional,\n"
        			  "please contact DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU: "
                      "'yeroth.d@gmail.com'.");

        QMessageBox::critical(&atoolBar,
        					  "yr-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg),
							  QMessageBox::Cancel);
    }


    QString logFileName(YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER);

    logFileName.append("/yr-db-runtime-verif.log");

    qDebug() << "yr-db-runtime-verif.cpp | main | yr-db-runtime-verif home folder: "
    		 << YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER;

    YR_DB_RUNTIME_VERIF_Utils::setLogFileName(logFileName);

    qDebug() << "yr-db-runtime-verif.cpp | main | log file name: "
             << logFileName;

    YR_DB_RUNTIME_VERIF_Logger logger(YR_DB_RUNTIME_VERIF_Utils::getLogFileName());


    QString initCfg(QString("%1/%2")
    				.arg(YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER,
    					 "yr-db-runtime-verif-database-connection.properties"));


    qDebug() << "yr-db-runtime-verif.cpp | main | yr-db-runtime-verif-database-connection.properties absolute file path: "
             << initCfg << "\n";


    YR_DB_RUNTIME_VERIF_Config::init_YR_DB_RUNTIME_VERIF_Config(initCfg);

    YerothERPDatabase database(YR_DB_RUNTIME_VERIF_Config::_db_type);

    //qDebug() << "++ database.toString(): " << database.toString();

    text_init_cfg.append(database.db_type());

    if (!database.open())
    {
        QString errMsg(QObject::tr("La connection de yr-db-runtime-verif "
                                       "à la base de données ne peut être établiée!\n\n"));

        errMsg.append(QObject::tr("DATABASE SERVER: %1.\n\n"
                              	  "Last error message (%2).\n\n"
                              	  "Please contact DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
                              	  "\t(yeroth.d@gmail.com)\n")
        				.arg(database.db_ip_address(),
        					 database.lastError().text()));

        logger.log("main",
                   QString("last database (host: %1) error: %2")
				   	   .arg(database.db_ip_address(),
				   			database.lastError().text()));

        QMessageBox::critical(&atoolBar,
                              "yr-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg),
							  QMessageBox::Cancel);
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
        qDebug() << QString("++ could not register '%1' object")
        				.arg("/YR_DB_RUNTIME_VERIF_Main");

        qDebug() << "++ last error: "
                 << QDBusError::errorString(connection.lastError().type());

        couldRegisterObject = false;
    }
    else
    {
        qDebug() << QString("could register '%1' object")
        				.arg("/YR_DB_RUNTIME_VERIF_Main");

        couldRegisterObject = true;
    }


    if (!connection.registerService(systemYerothService))
    {
        qDebug() << QString("could not register '%1' service")
        				.arg(systemYerothService);

        qDebug() << "++ last error: " << connection.lastError();

        couldRegisterService = false;
    }
    else
    {
        qDebug() << QString("could register '%1' service")
        				.arg(systemYerothService);

        couldRegisterService = true;
    }

    //########################### GRAPHICAL USER INTERFACE STATUS CODE ###########################
    if (couldRegisterService && couldRegisterObject)
    {
    	all_windows._yrdbruntimeverif_main_Window
			->SET__CURRENT__RUNTIME__MONITOR(&YR_DB_RUNTIME_VERIF_instance);

    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QString("YR-DB-RUNTIME-VERIF: this console registered to system d-bus as service: '%1'.")
					.arg(systemYerothService));

        qDebug() << "STARTING YR-DB-RUNTIME-VERIF !";
    }
    else
    {
    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QObject::tr("YR-DB-RUNTIME-VERIF: this console NOT REGISTERED TO SYSTEM D-BUS."),
				 true);
    }
    //############################################################################################



    return app.exec();
}
