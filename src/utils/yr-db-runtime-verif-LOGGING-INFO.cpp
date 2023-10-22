/*
 * yr-db-runtime-verif-LOGGING-INFO.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "yr-db-runtime-verif-LOGGING-INFO.hpp"


#include <cstdlib>

#include <QtCore/QStringList>
#include <QtCore/QString>


YRDBRUNTIMEVERIF_Logging_Info::YRDBRUNTIMEVERIF_Logging_Info(QString LOGGING_INFO)
{
	QStringList string_logging_info_LIST = LOGGING_INFO.split('*', Qt::KeepEmptyParts);

	A_RUNTIME_MONITOR_name = string_logging_info_LIST.value(0);

	A_CPP_SOURCE_FILE_NAME = string_logging_info_LIST.value(1);

	A_CPP_SOURCE_FILE_LINE_NUMBER = string_logging_info_LIST.value(2);

	A_SQL_EVENT_LOG_guarded_condition_expression = string_logging_info_LIST.value(3);

	A_SQL_EVENT_LOG_guarded_condition_expression_VALUE = string_logging_info_LIST.value(4);

	A_TRANSITION_precondition = string_logging_info_LIST.value(5);

	A_TRANSITION_postcondition = string_logging_info_LIST.value(6);

	A_PREVIOUS_STATE = string_logging_info_LIST.value(7);

	AN_ACCEPTING_STATE = string_logging_info_LIST.value(8);

	A_SUT_string_unique_ID = string_logging_info_LIST.value(9);

    AN_ACCEPTING_STATE_is_error_state_VALUE = string_logging_info_LIST.value(10);

    an_SQL_event_TOKEN= string_logging_info_LIST.value(11);

    changed_record_db_quantity = string_logging_info_LIST.value(12);

    timestamp = string_logging_info_LIST.value(13);

    RECOVERY_SQL_string__ON_ERROR__accepting_state
        = string_logging_info_LIST.value(14);
}


QString YRDBRUNTIMEVERIF_Logging_Info::toString()
{
	QString result1 =
			QString("%1*%2*%3*%4*%5*%6*%7*%8*%9")
				.arg(A_RUNTIME_MONITOR_name,
					 A_CPP_SOURCE_FILE_NAME,
					 A_CPP_SOURCE_FILE_LINE_NUMBER,
					 A_SQL_EVENT_LOG_guarded_condition_expression,
					 A_SQL_EVENT_LOG_guarded_condition_expression_VALUE,
					 A_TRANSITION_precondition,
					 A_TRANSITION_postcondition,
					 A_PREVIOUS_STATE,
					 AN_ACCEPTING_STATE);

	return
		QString("%1*%2*%3*%4*%5*%6*%7")
			.arg(result1,
                 A_SUT_string_unique_ID,
				 AN_ACCEPTING_STATE_is_error_state_VALUE,
				 an_SQL_event_TOKEN,
				 changed_record_db_quantity,
                 timestamp,
                 RECOVERY_SQL_string__ON_ERROR__accepting_state);
}




