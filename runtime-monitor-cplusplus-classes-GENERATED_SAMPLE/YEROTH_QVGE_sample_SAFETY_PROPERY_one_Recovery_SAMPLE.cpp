/*
* YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE.cpp
*
*/

#include "YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE.hpp"


#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>


#include "utils/yr-db-runtime-verif-logger.hpp"

#include "yr_sd_runtime_verif/YR_CPP_MONITOR.hpp"
#include "yr_sd_runtime_verif/YR_CPP_MONITOR_STATE.hpp"
#include "yr_sd_runtime_verif/YR_CPP_MONITOR_EDGE.hpp"


void YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE::YR_CALL_BACK_final_state(YR_CPP_MONITOR 			*a_runtime_monitor,
        YR_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state)
{
    if (0 != a_runtime_monitor)
    {
        ( (YR_DB_RUNTIME_VERIF_Monitor *) a_runtime_monitor)
        ->YR_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION(an_EDGE_leading_TO_error_FINAL_state);
    }
}



YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE::YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE()
    :YR_DB_RUNTIME_VERIF_Monitor()
{
    set_RUNTIME_MONITOR_NAME("YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE");


    YR_CPP_MONITOR_EDGE *a_last_edge_1 = create_yr_monitor_edge ("YR", "E");
    a_last_edge_1->get_SOURCE_STATE()->set_START_STATE(*this, true);
    a_last_edge_1->get_TARGET_STATE()->set_ERROR_STATE(true);
    a_last_edge_1->get_SOURCE_STATE()->set_PRE_CONDITION_notIN("YR_ASSET_cat", "categories.nom_categorie");
    a_last_edge_1->get_TARGET_STATE()->set_POST_CONDITION_IN("YR_ASSET_cat", "stocks.categorie");

    set_Recovery_action(a_last_edge_1->get_SOURCE_STATE(),
                        a_last_edge_1->get_TARGET_STATE());



    YR_CPP_notinset_inset_TRACE_expression *a_last_edge_1_GUARDED_CONDITION
        = new YR_CPP_notinset_inset_TRACE_expression(true,
                "'DELETE.categories.YR_ASSET_cat'",
                "YR");

    a_last_edge_1->set_GUARDED_CONDITION(a_last_edge_1_GUARDED_CONDITION);


    YR_CPP_MONITOR_EVENT *a_last_edge_event_1 = a_last_edge_1->set_EDGE_EVENT("'SELECT.stocks'");

    //print_TO_dot_FILE();

    YR_register_set_final_state_CALLBACK_FUNCTION(&YR_CALL_BACK_final_state);
}


YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE::YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE(YR_DB_RUNTIME_VERIF_Logger *logger)
    :YR_DB_RUNTIME_VERIF_Monitor(logger)
{
    set_RUNTIME_MONITOR_NAME("YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE");


    YR_CPP_MONITOR_EDGE *a_last_edge_1 = create_yr_monitor_edge ("YR", "E");
    a_last_edge_1->get_SOURCE_STATE()->set_START_STATE(*this, true);
    a_last_edge_1->get_TARGET_STATE()->set_ERROR_STATE(true);
    a_last_edge_1->get_SOURCE_STATE()->set_PRE_CONDITION_notIN("YR_ASSET_cat", "categories.nom_categorie");
    a_last_edge_1->get_TARGET_STATE()->set_POST_CONDITION_IN("YR_ASSET_cat", "stocks.categorie");

    set_Recovery_action(a_last_edge_1->get_SOURCE_STATE(),
                        a_last_edge_1->get_TARGET_STATE());



    YR_CPP_notinset_inset_TRACE_expression *a_last_edge_1_GUARDED_CONDITION
        = new YR_CPP_notinset_inset_TRACE_expression(true,
                "'DELETE.categories.YR_ASSET_cat'",
                "YR");

    a_last_edge_1->set_GUARDED_CONDITION(a_last_edge_1_GUARDED_CONDITION);


    YR_CPP_MONITOR_EVENT *a_last_edge_event_1 = a_last_edge_1->set_EDGE_EVENT("'SELECT.stocks'");

    //print_TO_dot_FILE();

    YR_register_set_final_state_CALLBACK_FUNCTION(&YR_CALL_BACK_final_state);
}


/**
* THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
* LOGIC CHECK AFTER A STATE EVENT (or system event)
* could be achieved by the runtime monitor system !
*
* A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
* METHOD !
*/
bool YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(
    QString sql_table_ADDED_with_file_AND_line_number,
    uint	sql_record_qty_MODIFIED,
    YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER cur_SQL_command
    /* = YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND */)
{
    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
        sql_table_ADDED_with_file_AND_line_number.split(";", Qt::KeepEmptyParts);

    QString sql_table_name = sql_table_ADDED_with_file_AND_line_number_LIST.at(0);

    QString CPP_FILE_NAME = sql_table_ADDED_with_file_AND_line_number_LIST.at(1);

    QString cpp_line_number = sql_table_ADDED_with_file_AND_line_number_LIST.at(2);


    qDebug() << "\t "
             << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]").
             arg(YR_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
                 value(cur_SQL_command), sql_table_name,
                 QString::number(cur_SQL_command),
                 QString::number(sql_record_qty_MODIFIED), CPP_FILE_NAME,
                 cpp_line_number);


    switch(cur_SQL_command)
    {
    case YR_CPP_UTILS::INSERT:
        break;

    case YR_CPP_UTILS::SELECT:

        if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(sql_table_name, "stocks"))
        {
            return YR_SQL_SELECT_stocks();
        }

        break;

    case YR_CPP_UTILS::UPDATE:
        break;

    case YR_CPP_UTILS::DELETE:
        break;

    default:

        break;
    }

    return false;
}


bool YEROTH_QVGE_sample_SAFETY_PROPERY_one_Recovery_SAMPLE::YR_SQL_SELECT_stocks()
{
    return YR_trigger_an_edge_event("'SELECT.stocks'");
}

