/*
 * yr-db-runtime-verif-LOGGING-INFO.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_
#define _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_


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

};



#endif /* _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_ */
