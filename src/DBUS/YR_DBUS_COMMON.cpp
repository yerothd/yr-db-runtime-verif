/*
 * YR_DBUS_COMMON.cpp
 *
 *
 *      Author: Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, PhD (ABD)
 */


#include "YR_DBUS_COMMON.hpp"


#include "src/include/yr-db-runtime-verif-MONITOR.hpp"


void YR_DBUS_COMMON::TRACE_SYSTEM_LOG_EVENT(YR_DB_RUNTIME_VERIF_Monitor &a_runtime_monitor,
											uint 						cur_command,
											QString 					&in0)
{
	QString sql_table_ADDED_with_file_AND_line_number = in0;

    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
        sql_table_ADDED_with_file_AND_line_number.split(";", Qt::KeepEmptyParts);

    QString sql_table_name = sql_table_ADDED_with_file_AND_line_number_LIST.at(0);

    QString a_trace_log_EVENT_TOKEN =
    		QString("'%1.%2'")
    			.arg(YR_CPP_UTILS::_DB_STMT_verification_ToUserViewString
    					.value(cur_command),
					 sql_table_name);

//    QDEBUG_STRING_OUTPUT_2("a_trace_log_EVENT_TOKEN", a_trace_log_EVENT_TOKEN);

    a_runtime_monitor.TRACE_LOG_current_RECEIVED_EVENT_TOKEN(a_trace_log_EVENT_TOKEN);
}


bool YR_DBUS_COMMON::YR_slot_refresh_INSERT_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
    	YR_DBUS_COMMON::TRACE_SYSTEM_LOG_EVENT(*_A_RUNTIME_MONITOR,
    										   YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::INSERT,
											   in0);

        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR
							->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                  in1,
                                                                  YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::INSERT);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_SELECT_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
    	YR_DBUS_COMMON::TRACE_SYSTEM_LOG_EVENT(*_A_RUNTIME_MONITOR,
    										   YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::SELECT,
											   in0);

        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR
							->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                  in1,
                                                                  YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::SELECT);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_UPDATE_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
    	YR_DBUS_COMMON::TRACE_SYSTEM_LOG_EVENT(*_A_RUNTIME_MONITOR,
    										   YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UPDATE,
											   in0);

        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR
							->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                  in1,
                                                                  YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UPDATE);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_DELETE_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
    	YR_DBUS_COMMON::TRACE_SYSTEM_LOG_EVENT(*_A_RUNTIME_MONITOR,
    										   YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::DELETE,
											   in0);

        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR
							->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                  in1,
                                                                  YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::DELETE);

        return verification_check_RESULT;
    }

    return false;
}
