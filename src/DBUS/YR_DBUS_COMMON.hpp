/*
 * YR_DBUS_COMMON.hpp
 *
 *
 *      Author: Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, PhD (ABD)
 */


#ifndef YR_DBUS_COMMON_HPP_
#define YR_DBUS_COMMON_HPP_

#include <QtCore/QObject>


#include "src/yr_sd_runtime_verif/YR_CPP_MONITOR_EDGE.hpp"


class YR_DB_RUNTIME_VERIF_Monitor;



class YR_DBUS_COMMON : public QObject
{
	Q_OBJECT

public:

	inline YR_DBUS_COMMON(YR_DB_RUNTIME_VERIF_Monitor *A_RUNTIME_MONITOR)
	:_LAST_trace_SQL_event_log_GUI_row_number(0),
	 _A_RUNTIME_MONITOR(A_RUNTIME_MONITOR)
	{
	}

	virtual inline ~YR_DBUS_COMMON()
	{
	}


public Q_SLOTS:

    virtual bool YR_slot_refresh_INSERT_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_SELECT_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_UPDATE_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_DELETE_DB_MYSQL(QString in0, uint in1);

Q_SIGNALS:

    void YR_VERIFIED();


public:

	void TRACE_SUT_LOG_EVENT_complement_info_ON_ACCEPTING_STATE
					(YR_CPP_MONITOR_EDGE &an_EDGE_leading_TO_error_FINAL_state);

	void TRACE_SUT_LOG_EVENT(YR_DB_RUNTIME_VERIF_Monitor &a_runtime_monitor,
							 uint 						 cur_command,
							 QString 					 &in0,
							 QString 					 CHANGED_RECORD_DB_QTY);


	int _LAST_trace_SQL_event_log_GUI_row_number;

    YR_DB_RUNTIME_VERIF_Monitor *_A_RUNTIME_MONITOR;
};


#define DBUS_CURRENT_TIME_WITH_MILLISECONDS QTime::currentTime().toString("HH:mm:ss:zzz")


#endif // YR_DBUS_COMMON_HPP_
