/*
 * yr-db-runtime-verif-config.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef SRC_YEROTH_ALERT_CONFIG_HPP_
#define SRC_YEROTH_ALERT_CONFIG_HPP_

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>

#include <QtWidgets/QMessageBox>

class YerenConfig
{
public:

    static QString _db_type;

    static QString _db_name;

    static QString _db_ip_address;

    static QString _db_user_name;

    static QString _db_user_pwd;

    static QString _db_connection_options;

    static QString YEROTH_ERP_3_0_PROPERTIES_CONFIGURATION_FOLDER;

    static QString YEROTH_ERP_3_0_HOME_FOLDER;

    static QString YR_DB_RUNTIME_VERIF_HOME_FOLDER;


    static void initYerenConfig(QString initCfg)
    {
        QFile file(initCfg);

        if (!file.open(QFile::ReadOnly))
        {
            QString errMsg("yr-db-runtime-verif: YerenConfig::initYerenConfig");
            errMsg.
            append(" ne peut pas ouvrir pour lecture le fichier ").append
            (initCfg).append(". ) !\n\n"
                             "Contacter DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU\n"
                             "\t(YEROTHERP30@GMAIL.COM)\n\n"
                             "Cliquer sur 'Cancel' pour terminer yeren");
            QMessageBox::critical(0, "yr-db-runtime-verif",
                                  FROM_UTF8_STRING(errMsg),
                                  QMessageBox::Cancel);

            exit(4);
        }

        QTextStream init_cfg(&file);
        QString line;
        QStringList list;

        do
        {
            line = init_cfg.readLine();
            list = line.split("=");
            //qDebug() << "++ line: " << line << "\n";
            if ("db_type" == list.at(0))
            {
                YerenConfig::_db_type = list.at(1).trimmed();
                // qDebug() << "++ db_type = " << YerenConfig::_db_type << "\n";
            }
            if ("db_name" == list.at(0))
            {
                YerenConfig::_db_name = list.at(1).trimmed();
                //qDebug() << "++ db_name = " << YerenConfig::_db_name << "\n";
            }
            else if ("db_ip_address" == list.at(0))
            {
                YerenConfig::_db_ip_address = list.at(1).trimmed();
                //qDebug() << "++ db_ip_address = " << YerenConfig::_db_ip_address << "\n";
            }
            else if ("db_user_name" == list.at(0))
            {
                YerenConfig::_db_user_name = list.at(1).trimmed();
                //qDebug() << "++ db_user_name = " << YerenConfig::_db_user_name << "\n";
            }
            else if ("db_user_pwd" == list.at(0))
            {
                YerenConfig::_db_user_pwd = list.at(1).trimmed();
                //qDebug() << "++ db_user_pwd = " << YerenConfig::_db_user_pwd << "\n";
            }
            else if ("db_connection_options" == list.at(0))
            {
                YerenConfig::_db_connection_options = list.at(1).trimmed();
                //qDebug() << "++ db_connection_options = " <<YerenConfig::_ db_connection_options << "\n";
            }
        }
        while (!line.isNull());
    }
};

#endif /* SRC_YEROTH_ALERT_CONFIG_HPP_ */
