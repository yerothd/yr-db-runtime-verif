/*
 * yr-db-runtime-verif-main.hpp
 *
 */

#ifndef _YR_DB_VERIF_RUNTIME_MONITOR_YR_DB_RUNTIME_VERIF_Main_HPP_
#define _YR_DB_VERIF_RUNTIME_MONITOR_YR_DB_RUNTIME_VERIF_Main_HPP_

#include "include/yr-db-runtime-verif-MONITOR.hpp"

#include "yr_sd_runtime_verif/utils/YR_CPP_UTILS.hpp"

#include "yr_sd_runtime_verif/YR_CPP_MONITOR_object.hpp"


#include <QtCore/QDebug>


class YR_CPP_MONITOR;


class YR_DB_RUNTIME_VERIF_Main:public YR_DB_RUNTIME_VERIF_Monitor
{
Q_OBJECT public:

    static void YR_CALL_BACK_final_state(YR_CPP_MONITOR_STATE *
                                         a_cal_back_function);

    YR_DB_RUNTIME_VERIF_Main();

    YR_DB_RUNTIME_VERIF_Main(YR_DB_RUNTIME_VERIF_Logger *logger);

    virtual ~ YR_DB_RUNTIME_VERIF_Main();

public slots:
    /**
     * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
     * LOGIC CHECK AFTER A STATE EVENT (or system event)
     * could be achieved by the runtime monitor system !
     *
     * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
     * METHOD !
     */

    virtual bool DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(QString
                                                     sql_table_ADDED_with_file_AND_line_number,
                                                     uint
                                                     sql_record_qty_MODIFIED,
                                                     YR_CPP_UTILS::
                                                     SQL_CONSTANT_IDENTIFIER
                                                     cur_SQL_command =
                                                                     YR_CPP_UTILS::
                                                                     SQL_CONSTANT_IDENTIFIER::
                                                                     UNDEFINED_SQL_COMMAND);


    void YR_SQL_SELECT_STOCKS();

    void YR_SQL_select_DEPARTEMENTS_PRODUITS();

private:

    YR_CPP_MONITOR *_a_runtime_monitor;
};


#endif /* _YR_DB_VERIF_RUNTIME_MONITOR_YR_DB_RUNTIME_VERIF_Main_HPP_ */
