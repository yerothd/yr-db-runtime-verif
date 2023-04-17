/*
 * YR_CPP_in_TRACE_expression.HPP
 *
 *      Author: DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_CPP_in_TRACE_expression_HPP_
#define _YR_CPP_in_TRACE_expression_HPP_


#include "YR_CPP_expression.HPP"


class YR_CPP_MONITOR_TRACE_EVENT;

class YR_CPP_MONITOR_EVENT;


/**
 * E.G.: select_event IN trace(d)
 */

class YR_CPP_in_TRACE_expression : public YR_CPP_expression
{
public:

	YR_CPP_in_TRACE_expression()
	:_left_value_database_event(0)
	{
	}

	virtual ~YR_CPP_in_TRACE_expression()
	{
	}

	virtual bool evaluate_expression(YR_CPP_MONITOR_TRACE_EVENT &_right_value_database_TRACE_events);

protected:

	YR_CPP_MONITOR_EVENT 		*_left_value_database_event;


private:

};



#endif // _YR_CPP_in_TRACE_expression_HPP_
