/*
 * YR_CPP_MONITOR_GUARDED_CONDITION.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_CPP_MONITOR_GUARDED_CONDITION_HPP_
#define _YR_CPP_MONITOR_GUARDED_CONDITION_HPP_


#include "utils/YR_CPP_UTILS.hpp"

#include "YR_CPP_MONITOR_object.hpp"


#include <QtCore/QString>


class YR_CPP_MONITOR_GUARDED_CONDITION:public YR_CPP_MONITOR_object
{
Q_OBJECT public:


protected:

    bool _GUARDED_CONDITION;


private:

    QString _end_state;

    QString _start_state;

};



#endif //_YR_CPP_MONITOR_GUARDED_CONDITION_HPP_
