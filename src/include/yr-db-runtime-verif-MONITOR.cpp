/*
 * yr-db-runtime-verif-MONITOR.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "yr-db-runtime-verif-MONITOR.hpp"

#include "src/utils/yr-db-runtime-verif-logger.hpp"



YR_DB_RUNTIME_VERIF_Monitor::YR_DB_RUNTIME_VERIF_Monitor():YR_CPP_MONITOR(),
    _logger(0),
    _dbus_client(0)
{
    static bool
    FIRST_TIME_CALL = true;

    if (FIRST_TIME_CALL)
    {
        YR_CPP_UTILS();

        FIRST_TIME_CALL = false;
    }

    _dbus_client = new YR_DBUS_COMMON(this);
}


YR_DB_RUNTIME_VERIF_Monitor::YR_DB_RUNTIME_VERIF_Monitor(QString RUNTIME_MONITOR_NAME,
														 YR_DB_RUNTIME_VERIF_Logger *aLogger)
:YR_CPP_MONITOR(RUNTIME_MONITOR_NAME),
 _logger(aLogger),
 _dbus_client(0)
{
    static bool FIRST_TIME_CALL = true;

    if (FIRST_TIME_CALL)
    {
        YR_CPP_UTILS();

        FIRST_TIME_CALL = false;
    }

    _dbus_client = new YR_DBUS_COMMON(this);
}


YR_DB_RUNTIME_VERIF_Monitor::YR_DB_RUNTIME_VERIF_Monitor(YR_DB_RUNTIME_VERIF_Logger *aLogger):YR_CPP_MONITOR(),
    _logger(aLogger),
    _dbus_client(0)
{
    static bool
    FIRST_TIME_CALL = true;

    if (FIRST_TIME_CALL)
    {
        YR_CPP_UTILS();

        FIRST_TIME_CALL = false;
    }

    _dbus_client = new YR_DBUS_COMMON(this);
}


YR_DB_RUNTIME_VERIF_Monitor::~YR_DB_RUNTIME_VERIF_Monitor()
{
    if (0 != _dbus_client)
    {
        delete _dbus_client;
    }
}


bool
YR_DB_RUNTIME_VERIF_Monitor::YR_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION
()
{
    qDebug() <<
             "//** YR_DB_RUNTIME_VERIF_Monitor::YR_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION **//";

    return false;
}


bool YR_DB_RUNTIME_VERIF_Monitor::YR_slot_refresh_INSERT_DB_MYSQL(QString in0,
                                                                  uint in1)
{
    if (0 != _dbus_client)
    {
        return _dbus_client->YR_slot_refresh_INSERT_DB_MYSQL(in0, in1);
    }

    return false;
}


bool YR_DB_RUNTIME_VERIF_Monitor::YR_slot_refresh_SELECT_DB_MYSQL(QString in0,
                                                                  uint in1)
{
    if (0 != _dbus_client)
    {
        return _dbus_client->YR_slot_refresh_SELECT_DB_MYSQL(in0, in1);
    }

    return false;
}


bool YR_DB_RUNTIME_VERIF_Monitor::YR_slot_refresh_UPDATE_DB_MYSQL(QString in0,
                                                                  uint in1)
{
    if (0 != _dbus_client)
    {
        return _dbus_client->YR_slot_refresh_UPDATE_DB_MYSQL(in0, in1);
    }

    return false;
}


bool YR_DB_RUNTIME_VERIF_Monitor::YR_slot_refresh_DELETE_DB_MYSQL(QString in0,
                                                                  uint in1)
{
    if (0 != _dbus_client)
    {
        return _dbus_client->YR_slot_refresh_DELETE_DB_MYSQL(in0, in1);
    }

    return false;
}


/**
 * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
 * LOGIC CHECK AFTER A STATE EVENT (or system event)
 * could be achieved by the runtime monitor system !
 *
 * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
 * METHOD !
 */
bool YR_DB_RUNTIME_VERIF_Monitor::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(QString
                                                                      sql_table_ADDED_with_file_AND_line_number,
                                                                      uint
                                                                      sql_record_qty_MODIFIED,
                                                                      YR_CPP_UTILS::
                                                                      SQL_CONSTANT_IDENTIFIER
                                                                      cur_SQL_command
                                                                      /* = YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::SQL_COMMAND_UNDEFINED */
                                                                     )
{
    if (0 != _logger)
    {
        _logger->
        log
        ("YR_DB_RUNTIME_VERIF_Monitor::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY");
    }

    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
                    sql_table_ADDED_with_file_AND_line_number.split(";",
                                                                    Qt::KeepEmptyParts);

    QString sql_table_name =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(0);
    QString CPP_FILE_NAME =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(1);
    QString cpp_line_number =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(2);

    qDebug() <<
             "YR_DB_RUNTIME_VERIF_Monitor::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY() \n" <<
             "\t [C++_STMT " << QString("(%1.%2)[%3,%4] at %5:%6]").
             arg(YR_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
                 value(cur_SQL_command), sql_table_name,
                 QString::number(cur_SQL_command),
                 QString::number(sql_record_qty_MODIFIED), CPP_FILE_NAME,
                 cpp_line_number);

    /*
     * SKELETON THAT COULD BE A starting
     * code FOR A VERIFYING method OVERIDING
     * THIS method !
     *
     switch(cur_SQL_command)
     {
     case YR_CPP_UTILS::INSERT:
     break;

     case YR_CPP_UTILS::SELECT:
     break;

     case YR_CPP_UTILS::UPDATE:
     break;

     case YR_CPP_UTILS::DELETE:
     break;

     default:
     break;
     }
     */

    return false;
}
