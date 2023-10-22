/*
 * yr-db-runtime-verif-LOGGING-INFO.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_
#define _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_


#include "src/utils/yr-db-runtime-verif-utils.hpp"


#include <cstdlib>

#include <QtCore/QStringList>
#include <QtCore/QString>


class YRDBRUNTIMEVERIF_Logging_Info
{
public:

	inline YRDBRUNTIMEVERIF_Logging_Info()
	{
	}

	YRDBRUNTIMEVERIF_Logging_Info(QString LOGGING_INFO);

	inline virtual ~YRDBRUNTIMEVERIF_Logging_Info()
	{
	}

	inline virtual bool IS_ERROR_EVENT_LOGGING()
	{
		return (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
                    ("True", A_SQL_EVENT_LOG_guarded_condition_expression_VALUE));
	}

	virtual QString toString();


	QString A_RUNTIME_MONITOR_name;

	QString A_SUT_string_unique_ID;

	QString A_CPP_SOURCE_FILE_NAME;

	QString A_CPP_SOURCE_FILE_LINE_NUMBER;

	QString A_SQL_EVENT_LOG_guarded_condition_expression;

	QString A_SQL_EVENT_LOG_guarded_condition_expression_VALUE;

	QString A_TRANSITION_precondition;

	QString A_TRANSITION_postcondition;

	QString A_PREVIOUS_STATE;

	QString AN_ACCEPTING_STATE;

	QString AN_ACCEPTING_STATE_is_error_state_VALUE;

	QString an_SQL_event_TOKEN;

	QString changed_record_db_quantity;

    QString timestamp;

    QString RECOVERY_SQL_string__ON_ERROR__accepting_state;
};



#endif /* _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_ */
