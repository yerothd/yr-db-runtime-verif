/*
 * yr-db-runtime-verif-main.hpp
 *
 *      Author: PROF. DR.--ING. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main.hpp"


#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>


#include "utils/yr-db-runtime-verif-logger.hpp"

#include "yr_sd_runtime_verif/YR_CPP_MONITOR.hpp"
#include "yr_sd_runtime_verif/YR_CPP_MONITOR_STATE.hpp"
#include "yr_sd_runtime_verif/YR_CPP_MONITOR_EDGE.hpp"



void YR_DB_RUNTIME_VERIF_Main::YR_CALL_BACK_final_state(YR_CPP_MONITOR_STATE *
                                                        a_cal_back_function)
{
    YR_DB_RUNTIME_VERIF_Monitor::
    YR_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION();
}


YR_DB_RUNTIME_VERIF_Main::YR_DB_RUNTIME_VERIF_Main():_a_runtime_monitor(0),
    YR_DB_RUNTIME_VERIF_Monitor
    ()
{
    _a_runtime_monitor =
                    YR_CPP_MONITOR::CREATE_MONITOR("YR_DB_RUNTIME_VERIF_Main");

    if (0 != _a_runtime_monitor)
    {
        YR_CPP_MONITOR_EDGE *
        a_last_edge_0 = _a_runtime_monitor->create_yr_monitor_edge("D", "E");

        a_last_edge_0->get_END_STATE()->set_FINAL_STATE(true);

        a_last_edge_0->get_START_STATE()->set_PRE_CONDITION_notIN("YR_ASSET",
                                                                  "departements_produits.nom_departement_produit");

        a_last_edge_0->get_END_STATE()->set_POST_CONDITION_IN("YR_ASSET",
                                                              "stocks.nom_departement_produit");

        _a_runtime_monitor->
        YR_register_set_final_state_CALLBACK_FUNCTION
        (&YR_CALL_BACK_final_state);

        YR_CPP_MONITOR_EVENT *
        a_last_edge_event_0 =
                        a_last_edge_0->set_EDGE_EVENT("select.departements_produits");
    }
}


YR_DB_RUNTIME_VERIF_Main::YR_DB_RUNTIME_VERIF_Main(YR_DB_RUNTIME_VERIF_Logger *logger):_a_runtime_monitor(0),
    YR_DB_RUNTIME_VERIF_Monitor
    (logger)
{
    _a_runtime_monitor =
                    YR_CPP_MONITOR::CREATE_MONITOR("YR_DB_RUNTIME_VERIF_Main");

    if (0 != _a_runtime_monitor)
    {
        YR_CPP_MONITOR_EDGE *
        a_last_edge_0 = _a_runtime_monitor->create_yr_monitor_edge("D", "E");

        a_last_edge_0->get_END_STATE()->set_FINAL_STATE(true);

        a_last_edge_0->get_START_STATE()->set_PRE_CONDITION_notIN("YR_ASSET",
                                                                  "departements_produits.nom_departement_produit");

        a_last_edge_0->get_END_STATE()->set_POST_CONDITION_IN("YR_ASSET",
                                                              "stocks.nom_departement_produit");

        _a_runtime_monitor->
        YR_register_set_final_state_CALLBACK_FUNCTION
        (&YR_CALL_BACK_final_state);

        YR_CPP_MONITOR_EVENT *
        a_last_edge_event_0 =
                        a_last_edge_0->set_EDGE_EVENT("select.departements_produits");
    }
}


YR_DB_RUNTIME_VERIF_Main::~YR_DB_RUNTIME_VERIF_Main()
{
    if (0 != _a_runtime_monitor)
    {
        delete _a_runtime_monitor;
    }
}


/**
 * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
 * LOGIC CHECK AFTER A STATE EVENT (or system event)
 * could be achieved by the runtime monitor system !
 *
 * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
 * METHOD !
 */
bool
YR_DB_RUNTIME_VERIF_Main::

DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(QString
                                    sql_table_ADDED_with_file_AND_line_number,
                                    uint sql_record_qty_MODIFIED,
                                    YR_CPP_UTILS::
                                    SQL_CONSTANT_IDENTIFIER cur_SQL_command
                                    /* = YR_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND */
                                   )
{
    bool aRetValue = false;

    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
                    sql_table_ADDED_with_file_AND_line_number.split(";",
                                                                    Qt::KeepEmptyParts);

    QString sql_table_name =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(0);
    QString CPP_FILE_NAME =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(1);
    QString cpp_line_number =
                    sql_table_ADDED_with_file_AND_line_number_LIST.at(2);


    qDebug() << "\t [C++_STMT "
             << QString("(%1.%2)[%3,%4] at %5:%6]").
             arg(YR_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
                 value(cur_SQL_command), sql_table_name,
                 QString::number(cur_SQL_command),
                 QString::number(sql_record_qty_MODIFIED), CPP_FILE_NAME,
                 cpp_line_number);


    switch (cur_SQL_command)
    {
    case YR_CPP_UTILS::INSERT:
        break;

    case YR_CPP_UTILS::SELECT:

        if (YR_DB_RUNTIME_VERIF_Utils::
                isEqualCaseInsensitive(sql_table_name, "departements_produits"))
        {
            YR_SQL_select_DEPARTEMENTS_PRODUITS();
        }
        else if (YR_DB_RUNTIME_VERIF_Utils::
                 isEqualCaseInsensitive(sql_table_name, "stocks"))
        {
            YR_SQL_SELECT_STOCKS();
        }

        break;

    case YR_CPP_UTILS::UPDATE:
        break;

    case YR_CPP_UTILS::DELETE:
        break;

    default:

        break;
    }

    return aRetValue;
}


void YR_DB_RUNTIME_VERIF_Main::YR_SQL_SELECT_STOCKS()
{
    if (0 != _a_runtime_monitor)
    {
        _a_runtime_monitor->YR_trigger_an_edge_event("select.stocks", true);
    }
}


void YR_DB_RUNTIME_VERIF_Main::YR_SQL_select_DEPARTEMENTS_PRODUITS()
{
    if (0 != _a_runtime_monitor)
    {
        _a_runtime_monitor->
        YR_trigger_an_edge_event("select.departements_produits", true);
    }
}
