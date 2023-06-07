/*
 * yr-db-runtime-verif-MONITOR.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_ABSTRACT_ENTITY_HPP_
#define _YR_DB_RUNTIME_VERIF_ABSTRACT_ENTITY_HPP_


#include "src/include/yr-db-runtime-verif-definition-oo-class-operators.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include "src/DBUS/YR_DBUS_COMMON.hpp"


#include "src/yr_sd_runtime_verif/utils/YR_CPP_UTILS.hpp"


#include "src/yr_sd_runtime_verif/YR_CPP_MONITOR.hpp"


#include <QtCore/QTimer>

#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>

#include <QtCore/QObject>

#include <QtCore/QString>


class QTimer;

class YR_CPP_MONITOR;

class YR_DB_RUNTIME_VERIF_Logger;


/**
 * THIS CLASS MUST ALSO INHERITS FROM 'YR_CPP_MONITOR'
 * SO method 'bool DO_VERIFY_AND_or_CHECK_ltl_PROPERTY()'
 * COULD PERFORM effective runtime check !
 */
class YR_DB_RUNTIME_VERIF_Monitor : public YR_CPP_MONITOR
{
	Q_OBJECT

public:

    YEROTH_CLASS_OPERATORS

	YR_DB_RUNTIME_VERIF_Monitor();

    YR_DB_RUNTIME_VERIF_Monitor(QString 					RUNTIME_MONITOR_NAME,
    							YR_DB_RUNTIME_VERIF_Logger 	*aLogger);

    YR_DB_RUNTIME_VERIF_Monitor(YR_DB_RUNTIME_VERIF_Logger *aLogger);

    virtual ~YR_DB_RUNTIME_VERIF_Monitor();

    virtual bool YR_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION
					(YR_CPP_MONITOR_EDGE *an_EDGE_leading_TO_error_FINAL_state = 0);

	virtual void TRACE_SUT_LOG_EVENT_complement_info_ON_ACCEPTING_STATE
					(YR_CPP_MONITOR_EDGE &an_EDGE_leading_TO_error_FINAL_state);

	virtual void TRACE_SUT_LOG_EVENT(YR_DB_RUNTIME_VERIF_Monitor &a_runtime_monitor,
							 	 	 uint 						 cur_command,
									 QString 					 &in0,
									 QString 					 CHANGED_RECORD_DB_QTY);

    inline virtual void YR_TRIGGERED_EVENT_LOGGING(const QString A_METHOD_CALLED,
                                                   const QString AN_EVENT,
                                                   bool 		 A_RETURNED_VALUE)
    {
        qDebug() << QString("%1; triggered event: ")
        				.arg(A_METHOD_CALLED)
                 << AN_EVENT
				 << " ["
				 << DB_BOOL_TO_STRING(A_RETURNED_VALUE)
				 << "]";
    }

    inline virtual YR_DB_RUNTIME_VERIF_Logger *get_logger()
    {
        return _logger;
    }

public Q_SLOTS:

    virtual bool YR_slot_refresh_INSERT_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_SELECT_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_UPDATE_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_DELETE_DB_MYSQL(QString in0, uint in1);

    /**
     * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
     * LOGIC CHECK AFTER A STATE EVENT (or system event)
     * could be achieved by the runtime monitor system !
     *
     * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
     * METHOD !
     */
    virtual bool DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(QString 	sql_table_ADDED_with_file_AND_line_number,
                                                     uint 		sql_record_qty_MODIFIED,
                                                     YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER
                                                     	 cur_SQL_command = YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND);


protected:

    YR_DB_RUNTIME_VERIF_Logger 	*_logger;

    YR_DBUS_COMMON 				*_dbus_client;
};


#endif /* _YR_DB_RUNTIME_VERIF_ABSTRACT_ENTITY_HPP_ */
