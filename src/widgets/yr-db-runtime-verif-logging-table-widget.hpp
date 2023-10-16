/*
 * yr-db-runtime-verif-logging-table-widget.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_
#define _YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_


#include "src/utils/yr-db-runtime-verif-qmap.hpp"

#include <QtWidgets/QTableWidget>


class YRDBRUNTIMEVERIF_TableWidget : public QTableWidget
{
	Q_OBJECT

public:

	YRDBRUNTIMEVERIF_TableWidget(QWidget *parent = 0);

	inline virtual ~YRDBRUNTIMEVERIF_TableWidget()
	{
	}

	void setQStandardItemFlags(Qt::ItemFlags &flags);

	void setQStandardItemFlags(QTableWidgetItem &anItem,
							   Qt::ItemFlags 	&flags);

	inline uint getMaxSize()
	{
		return _mapListIdxToElement_db_ID.getMaxSize();
	}

	void setMaxSize(uint MAX_SIZE);

	virtual void resize_columns_AND_rows_to_contents();

	int ADD_ITEM_3(QString Source_file__line_number);

	int ADD_ITEM_2(QString Source_file__line_number);

	int ADD_ITEM_1(QString Precondition__Or__POST_CONDITION);

	int ADD_ITEM(QString TIMESTAMPtem,
				 QString SIGNALItem,
				 QString SOURCEItem,
				 QString TARGETItem,
				 QString changed_OR_modified_database_qty_Item);


public slots:

    virtual inline void Set_CURRENTLY_filtered(bool is_currently_filtered)
    {
        _IS_CURRENTLY_FILTERED = is_currently_filtered;
    }


    virtual inline bool  IS_CURRENTLY_filtered()
    {
        return _IS_CURRENTLY_FILTERED;
    }


    virtual void CLEAR_FILTERING();


    virtual uint FILTER_ITEM(const QString &SIGNALItem_TEXT,
                             bool exact_sql_event_query);


    virtual uint FILTER__SUT_SOURCE__ITEM(const QString &SUT_SOURCEItem_TEXT);


    virtual inline uint FILTER_ITEM(const QString &SIGNALItem_TEXT)
    {
        FILTER_ITEM(SIGNALItem_TEXT, false);
    }



public:

	static const unsigned int TIME_STAMP_COLUMN;

	static const unsigned int SIGNAL_COLUMN;

	static const unsigned int SOURCE_COLUMN;

	static const unsigned int TARGET_COLUMN;

	static const unsigned int changed_or_MODIFIED_database_QTY_COLUMN;


private:

	static const uint MAX_TABLE_WIDGET_ROW_COUNT;


	bool    _IS_CURRENTLY_FILTERED;


    int _curRow;

    Qt::ItemFlags _myQStandardItemFlags;

    YRDBRUNTIMEVERIF_QMap _mapListIdxToElement_db_ID;


	QTableWidgetItem *_TIMESTAMPtem;

	QTableWidgetItem *_SIGNALItem;

	QTableWidgetItem *_SOURCEItem;

	QTableWidgetItem *_TARGETItem;

	QTableWidgetItem *_changed_OR_modified_database_qty_Item;
};

#endif //_YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_
