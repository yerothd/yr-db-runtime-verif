/*
 * yr-db-runtime-verif-qmap.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-qmap.hpp"


#include "src/utils/yr-db-runtime-verif-utils.hpp"



void YRDBRUNTIMEVERIF_QMap::setMaxSize(uint MAX_SIZE)
{
	QMap<uint, QString>::clear();

	_current_IDX = 0;

	_max_elements_SIZE = MAX_SIZE;
}


void YRDBRUNTIMEVERIF_QMap::yr_insert_item(uint 	a_yr_key,
										   QString 	a_yr_value)
{
	if (_current_IDX >= _max_elements_SIZE)
	{
		_current_IDX = 0;

		QMap<uint, QString>::const_iterator map_begin = QMap<uint, QString>::constBegin();

		QMap<uint, QString>::insert(map_begin,
							 	 	a_yr_key,
									a_yr_value);

		++_current_IDX;
	}
	else
	{
		QMap<uint, QString>::insert(a_yr_key, a_yr_value);

		++_current_IDX;
	}

//	QDEBUG_STRINGS_OUTPUT_2_N("_max_elements_SIZE", _max_elements_SIZE);
//	QDEBUG_STRINGS_OUTPUT_2_N("size()", size());
//
//	assert (size() <= _max_elements_SIZE);
}


