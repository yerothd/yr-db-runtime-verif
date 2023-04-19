/*
 * YR_DBUS_COMMON.cpp
 *
 *
 *      Author: Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, PhD (ABD)
 */


#include "YR_DBUS_COMMON.hpp"


#include "src/include/yr-db-runtime-verif-MONITOR.hpp"



YR_DBUS_COMMON::YR_DBUS_COMMON(YR_DB_RUNTIME_VERIF_Monitor *A_RUNTIME_MONITOR):_A_RUNTIME_MONITOR
    (A_RUNTIME_MONITOR)
{

}


YR_DBUS_COMMON::~YR_DBUS_COMMON()
{

}


bool YR_DBUS_COMMON::YR_slot_refresh_INSERT_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                                in1,
                                                                                YR_CPP_UTILS::
                                                                                SQL_CONSTANT_IDENTIFIER::
                                                                                INSERT);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_SELECT_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                                in1,
                                                                                YR_CPP_UTILS::
                                                                                SQL_CONSTANT_IDENTIFIER::
                                                                                SELECT);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_UPDATE_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                                in1,
                                                                                YR_CPP_UTILS::
                                                                                SQL_CONSTANT_IDENTIFIER::
                                                                                UPDATE);

        return verification_check_RESULT;
    }

    return false;
}


bool YR_DBUS_COMMON::YR_slot_refresh_DELETE_DB_MYSQL(QString in0, uint in1)
{
    if (0 != _A_RUNTIME_MONITOR)
    {
        bool verification_check_RESULT =
                        _A_RUNTIME_MONITOR->DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(in0,
                                                                                in1,
                                                                                YR_CPP_UTILS::
                                                                                SQL_CONSTANT_IDENTIFIER::
                                                                                DELETE);

        return verification_check_RESULT;
    }

    return false;
}
