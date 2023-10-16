/*
 * yr-db-runtime-verif-qmap.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_QMAP_HPP_
#define _YR_DB_RUNTIME_VERIF_QMAP_HPP_


#include <cstdlib>

#include <QtCore/QObject>
#include <QtCore/QMap>


class YRDBRUNTIMEVERIF_QMap : public QMap<uint, QString>
{
public:

	inline YRDBRUNTIMEVERIF_QMap()
	:QMap<uint, QString>(),
	 _current_IDX(0),
	 _max_elements_SIZE(70000)
	{
	}

	inline virtual ~YRDBRUNTIMEVERIF_QMap()
	{
	}

	inline virtual uint getMaxSize()
	{
		return _max_elements_SIZE;
	}

	virtual void setMaxSize(uint MAX_SIZE);

	virtual void yr_insert_item(uint 	a_yr_key,
								QString a_yr_value);

private:

	uint _current_IDX = 0;

	uint _max_elements_SIZE;
};

#endif //_YR_DB_RUNTIME_VERIF_QMAP_HPP_
