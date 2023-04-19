/*
 * YR_DBUS_COMMON.hpp
 *
 *
 *      Author: Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU, PhD (ABD)
 */


#ifndef YR_DBUS_COMMON_HPP_
#define YR_DBUS_COMMON_HPP_


#include <QtCore/QObject>



class YR_DB_RUNTIME_VERIF_Monitor;



class YR_DBUS_COMMON:public QObject
{
Q_OBJECT public:
    YR_DBUS_COMMON(YR_DB_RUNTIME_VERIF_Monitor *A_RUNTIME_MONITOR);

    virtual ~ YR_DBUS_COMMON();

public Q_SLOTS:
    virtual bool YR_slot_refresh_INSERT_DB_MYSQL(QString in0,
                                                 uint in1);

    virtual bool YR_slot_refresh_SELECT_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_UPDATE_DB_MYSQL(QString in0, uint in1);

    virtual bool YR_slot_refresh_DELETE_DB_MYSQL(QString in0, uint in1);

Q_SIGNALS:
    void YR_VERIFIED();


protected:

    YR_DB_RUNTIME_VERIF_Monitor *_A_RUNTIME_MONITOR;

};


#endif // YR_DBUS_COMMON_HPP_
