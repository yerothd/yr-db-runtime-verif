/*
 * yr-db-runtime-verif-logging-table-widget.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_
#define _YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_



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

	int ADD_ITEM(QString TIMESTAMPtem,
				 QString SIGNALItem,
				 QString SOURCEItem,
				 QString TARGETItem,
				 QString changed_OR_modified_database_qty_Item);


	static const unsigned int TIME_STAMP_COLUMN;

	static const unsigned int SIGNAL_COLUMN;

	static const unsigned int SOURCE_COLUMN;

	static const unsigned int TARGET_COLUMN;

	static const unsigned int changed_or_MODIFIED_database_QTY_COLUMN;


private:

	static const uint MAX_TABLE_WIDGET_ROW_COUNT;

    int _curRow;

    Qt::ItemFlags _myQStandardItemFlags;

    QMap<int, QString> _mapListIdxToElement_db_ID;


	QTableWidgetItem *_TIMESTAMPtem;

	QTableWidgetItem *_SIGNALItem;

	QTableWidgetItem *_SOURCEItem;

	QTableWidgetItem *_TARGETItem;

	QTableWidgetItem *_changed_OR_modified_database_qty_Item;
};

#endif //_YR_DB_RUNTIME_VERIF_LOGGING_TABLE_WIDGET_HPP_
