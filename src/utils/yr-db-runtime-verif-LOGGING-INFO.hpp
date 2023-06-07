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

	inline virtual QString toString()
	{
		return QString("%1:%2:%3:%4:%5:%6:%7")
				.arg(A_RUNTIME_MONITOR_name,
					 A_CPP_SOURCE_FILE_NAME,
					 A_CPP_SOURCE_FILE_LINE_NUMBER,
					 A_SQL_EVENT_LOG_guarded_condition_expression,
					 A_SQL_EVENT_LOG_guarded_condition_expression_VALUE,
					 AN_ACCEPTING_STATE,
					 AN_ACCEPTING_STATE_is_error_state_VALUE);
	}


	QString A_RUNTIME_MONITOR_name;

	QString A_CPP_SOURCE_FILE_NAME;

	QString A_CPP_SOURCE_FILE_LINE_NUMBER;

	QString A_SQL_EVENT_LOG_guarded_condition_expression;

	QString A_SQL_EVENT_LOG_guarded_condition_expression_VALUE;

	QString AN_ACCEPTING_STATE;

	QString AN_ACCEPTING_STATE_is_error_state_VALUE;

};






#endif /* _YR_DB_RUNTIME_VERIF_LOGGING_INFO_HPP_ */
