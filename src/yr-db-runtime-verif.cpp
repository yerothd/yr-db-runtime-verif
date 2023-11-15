/*
 * yr-db-runtime-verif.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "YRruntimeverification_adaptor.h"


//############ USER'S RUNTIME MONITOR HEADER RELATED IMPORTS ############

#include "src/include/yr-db-runtime-verif-MONITOR.hpp"

//yr-USER-RUNTIME-MONITOR-RELATED-IMPORTS
//#######################################################################

#include "src/utils/yr-db-runtime-verif-CONFIG.hpp"

#include "src/utils/yr-db-runtime-verif-database.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"


#include <QtCore/QVector>
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



    YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE =
        QString(std::getenv("YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE")).trimmed();


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



    qDebug() << "yr-db-runtime-verif.cpp | main | PROPERTY FILE YR-DB-RUNTIME-VERIF.properties absolute file path: "
             << YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE
             << "\n";

    YR_DB_RUNTIME_VERIF_Config::init_YR_DB_RUNTIME_VERIF_Config
            (YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);



    QString initCfg(QString("%1/%2")
    				.arg(YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_HOME_FOLDER,
    					 "yr-db-runtime-verif-database-connection.properties"));

    qDebug() << "yr-db-runtime-verif.cpp | main | yr-db-runtime-verif-database-connection.properties absolute file path: "
             << initCfg
             << "\n";



    YR_DB_RUNTIME_VERIF_Config::init_YR_DB_RUNTIME_VERIF_Config(initCfg);

    YerothERPDatabase database(YR_DB_RUNTIME_VERIF_Config::_db_type);


    //qDebug() << "++ database.toString(): " << database.toString();

    text_init_cfg.append(database.db_type());

    if (!database.open())
    {
        QString errMsg(QObject::tr("yr-db-runtime-verif couldn't connect to database!\n\n"));

        errMsg.append(QObject::tr("DATABASE SERVER: %1.\n\n"
                              	  "Last error message (%2).\n\n"
                              	  "Please contact PROF. DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
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



    QFile file_EN_template_EVENT_LOG_TEX(YR_DB_RUNTIME_VERIF_Utils::FILE_YR_DB_RUNTIME_VERIF_EVENT_LOG_PDF_TEMPLATE_EN);

    YR_DB_RUNTIME_VERIF_Utils::YEROTH_READ_FILE_CONTENT(file_EN_template_EVENT_LOG_TEX,
                                                        YR_DB_RUNTIME_VERIF_Utils::EN_template_EVENT_LOG_TEX_document);




    //##################### RUNTIME MONITOR DECLARATION INSTANTIATION #####################

    QVector<YR_DB_RUNTIME_VERIF_Monitor *> user_defined_Runtime_Monitors;

    //yr-USER-RUNTIME-MONITOR-DECLARATION-INSTANTIATION
    //######################################################################################



    QDBusConnection connection = QDBusConnection::systemBus();

    QString systemYerothService =
        YR_DB_RUNTIME_VERIF_Config::YR_DB_RUNTIME_VERIF_SYSTEM_dbus_service_name;



    QString current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus;

    YR_DB_RUNTIME_VERIF_Monitor *A_USER_DEFINED_RT_MONITOR = 0;


    bool couldRegisterService = false;

    bool couldRegisterObject = false;


    int rt_monitor_Vector_SIZE = user_defined_Runtime_Monitors.size();


    for (uint k = 0; k < rt_monitor_Vector_SIZE; ++k)
    {
        A_USER_DEFINED_RT_MONITOR = user_defined_Runtime_Monitors.at(k);

        if (0 != A_USER_DEFINED_RT_MONITOR)
        {
            current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus =
                QString("/%1")
                 .arg(A_USER_DEFINED_RT_MONITOR->get_RUNTIME_MONITOR_NAME());

            if (!connection.registerObject(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus,
                                           A_USER_DEFINED_RT_MONITOR))
            {
                QDEBUG_STRINGS_OUTPUT_1(QString("Could not register '%1' object")
                                        .arg(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus));

                QDEBUG_STRINGS_OUTPUT_1(QString("Last error: %1")
                                        .arg(QDBusError::errorString(connection.lastError().type())));

                                        couldRegisterObject = false;
            }
            else
            {
                all_windows._yrdbruntimeverif_main_Window
                    ->user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES
                        .insert(A_USER_DEFINED_RT_MONITOR->get_RUNTIME_MONITOR_NAME(),
                                 A_USER_DEFINED_RT_MONITOR);


                QDEBUG_STRINGS_OUTPUT_1(QString("Could register '%1' object")
                                        .arg(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus));

                couldRegisterObject = true;
            }
        }
    }


    // REGISTERING DBUS SERVICE ON system bus !

    if (!connection.registerService(systemYerothService))
    {
        QDEBUG_STRINGS_OUTPUT_1(QString("Could not Register '%1' SERVICE")
                                .arg(systemYerothService));

        QDEBUG_STRINGS_OUTPUT_1(QString("Last error: %1")
                                .arg(connection.lastError().message()));

        couldRegisterService = false;
    }
    else
    {
        QDEBUG_STRINGS_OUTPUT_1(QString("Could register '%1' SERVICE")
                                .arg(systemYerothService));

        couldRegisterService = true;
    }



    //########################### GRAPHICAL USER INTERFACE STATUS CODE ###########################
    if (couldRegisterService && couldRegisterObject)
    {
    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QString("YR-DB-RUNTIME-VERIF: this console is registered to the system d-bus as service: '%1'.")
					.arg(systemYerothService));

        qDebug() << "STARTING YR-DB-RUNTIME-VERIF !";
    }
    else
    {
    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QObject::tr("YR-DB-RUNTIME-VERIF: this console IS NOT REGISTERED TO SYSTEM D-BUS."),
				 true);
    }
    //############################################################################################



    return app.exec();
}
