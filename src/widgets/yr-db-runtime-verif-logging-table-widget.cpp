/*
 * yr-db-runtime-verif-logging-table-widget.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-logging-table-widget.hpp"


#include "src/utils/yr-db-runtime-verif-utils.hpp"


const uint YRDBRUNTIMEVERIF_TableWidget::MAX_TABLE_WIDGET_ROW_COUNT = 1000;


const unsigned int YRDBRUNTIMEVERIF_TableWidget::TIME_STAMP_COLUMN(0);

const unsigned int YRDBRUNTIMEVERIF_TableWidget::SIGNAL_COLUMN(1);

const unsigned int YRDBRUNTIMEVERIF_TableWidget::SOURCE_COLUMN(2);

const unsigned int YRDBRUNTIMEVERIF_TableWidget::TARGET_COLUMN(3);

const unsigned int YRDBRUNTIMEVERIF_TableWidget::changed_or_MODIFIED_database_QTY_COLUMN(4);



YRDBRUNTIMEVERIF_TableWidget::YRDBRUNTIMEVERIF_TableWidget(QWidget *parent /* = 0 */)
:QTableWidget(parent),
 _TIMESTAMPtem(0),
 _SIGNALItem(0),
 _SOURCEItem(0),
 _TARGETItem(0),
 _changed_OR_modified_database_qty_Item(0)
{
    _curRow = 0;

    _myQStandardItemFlags = Qt::ItemIsSelectable | Qt::ItemIsEnabled;


    setQStandardItemFlags(_myQStandardItemFlags);


    setFrameShadow(QFrame::Plain);

    setSelectionBehavior(QAbstractItemView::SelectRows);

    setSelectionMode(QAbstractItemView::SingleSelection);

    setEditTriggers(QAbstractItemView::NoEditTriggers);


    setMaxSize(MAX_TABLE_WIDGET_ROW_COUNT);


    resizeColumnsToContents();
}


void YRDBRUNTIMEVERIF_TableWidget::setQStandardItemFlags(Qt::ItemFlags &flags)
{
    QTableWidgetItem *curItem = 0;

    for (int i = 0; i < rowCount(); ++i)
    {
        for (int j = 0; j < columnCount(); ++j)
        {
            curItem = item(i, j);

            if (0 != curItem)
            {
            	curItem->setTextAlignment(Qt::AlignHCenter);
                curItem->setFlags(flags);
            }
        }
    }
}


void YRDBRUNTIMEVERIF_TableWidget::setQStandardItemFlags(QTableWidgetItem &anItem,
						   	   	   	   	   	   	   	     Qt::ItemFlags 	&flags)
{
	anItem.setTextAlignment(Qt::AlignHCenter);
	anItem.setFlags(flags);
}


void YRDBRUNTIMEVERIF_TableWidget::setMaxSize(uint MAX_SIZE)
{
	setRowCount(MAX_SIZE);

	_mapListIdxToElement_db_ID.setMaxSize(MAX_SIZE);
}


/*
 * THIS METHOS IS meant to be only called by
 * class 'YRDBRUNTIMEVERIF_MainWindow.tableWidget_LOGGING_4'.
 */
int YRDBRUNTIMEVERIF_TableWidget::ADD_ITEM_3(QString Source_file__line_number)
{
	static bool first_time_call = true;

	if (first_time_call)
	{
		setMaxSize(1);

		first_time_call = false;
	}

	_curRow = 0;

    setRowCount(1);

    QList<QString> source_file__line_number_LIST = Source_file__line_number.split(':');

    QString A_PREVIOUS_STATE = source_file__line_number_LIST.at(0);

    QString AN_ACCEPTING_STATE = source_file__line_number_LIST.at(1);

    QString AN_ACCEPTING_STATE_is_error_state_VALUE = source_file__line_number_LIST.at(2);


    _TIMESTAMPtem = new QTableWidgetItem(A_PREVIOUS_STATE);
    _SIGNALItem = new QTableWidgetItem(AN_ACCEPTING_STATE);
    _SOURCEItem = new QTableWidgetItem(AN_ACCEPTING_STATE_is_error_state_VALUE);

    _mapListIdxToElement_db_ID.yr_insert_item(_curRow, Source_file__line_number);

    unsigned idx = 0;

    //Each call to setItem triggers a call to YerothPointDeVenteWindow::handleQteChange
    setItem(_curRow, idx++, _TIMESTAMPtem);
    setItem(_curRow, idx++, _SIGNALItem);
    setItem(_curRow, idx++, _SOURCEItem);

    setQStandardItemFlags(*_TIMESTAMPtem, _myQStandardItemFlags);
    setQStandardItemFlags(*_SIGNALItem, _myQStandardItemFlags);
    setQStandardItemFlags(*_SOURCEItem, _myQStandardItemFlags);

    selectRow(_curRow);

    resizeColumnsToContents();

    return _curRow;
}


/*
 * THIS METHOS IS meant to be only called by
 * class 'YRDBRUNTIMEVERIF_MainWindow.tableWidget_LOGGING_2'.
 */
int YRDBRUNTIMEVERIF_TableWidget::ADD_ITEM_2(QString Source_file__line_number)
{
	static bool first_time_call = true;

	if (first_time_call)
	{
		setMaxSize(1);

		first_time_call = false;
	}

	_curRow = 0;

    setRowCount(1);

    QList<QString> source_file__line_number_LIST = Source_file__line_number.split(':');

    QString Source_file = source_file__line_number_LIST.at(0);

    QString line_number = source_file__line_number_LIST.at(1);


    _TIMESTAMPtem = new QTableWidgetItem(Source_file);
    _SIGNALItem = new QTableWidgetItem(line_number);

    _mapListIdxToElement_db_ID.yr_insert_item(_curRow, Source_file__line_number);

    unsigned idx = 0;

    //Each call to setItem triggers a call to YerothPointDeVenteWindow::handleQteChange
    setItem(_curRow, idx++, _TIMESTAMPtem);
    setItem(_curRow, idx++, _SIGNALItem);

    setQStandardItemFlags(*_TIMESTAMPtem, _myQStandardItemFlags);
    setQStandardItemFlags(*_SIGNALItem, _myQStandardItemFlags);

    selectRow(_curRow);

    resizeColumnsToContents();

    return _curRow;
}


int YRDBRUNTIMEVERIF_TableWidget::ADD_ITEM(QString TIMESTAMPtem,
										   QString SIGNALItem,
		   	   	   	   	   	   	   	   	   QString SOURCEItem,
										   QString TARGETItem,
										   QString changed_OR_modified_database_qty_Item)
{
    setRowCount(_curRow + 1);

    TIMESTAMPtem.truncate(50);
    SIGNALItem.truncate(50);
    SOURCEItem.truncate(50);
    TARGETItem.truncate(50);
    changed_OR_modified_database_qty_Item.truncate(50);

    _TIMESTAMPtem = new QTableWidgetItem(TIMESTAMPtem);
    _SIGNALItem = new QTableWidgetItem(SIGNALItem);
    _SOURCEItem = new QTableWidgetItem(SOURCEItem);
    _TARGETItem = new QTableWidgetItem(TARGETItem);


    _changed_OR_modified_database_qty_Item =
    		new QTableWidgetItem(changed_OR_modified_database_qty_Item);

    _mapListIdxToElement_db_ID.yr_insert_item(_curRow, SIGNALItem);

    unsigned idx = 0;

    //Each call to setItem triggers a call to YerothPointDeVenteWindow::handleQteChange
    setItem(_curRow, idx++, _TIMESTAMPtem);
    setItem(_curRow, idx++, _SIGNALItem);
    setItem(_curRow, idx++, _SOURCEItem);
    setItem(_curRow, idx++, _TARGETItem);
    setItem(_curRow, idx++, _changed_OR_modified_database_qty_Item);

    setQStandardItemFlags(*_TIMESTAMPtem, _myQStandardItemFlags);
    setQStandardItemFlags(*_SIGNALItem, _myQStandardItemFlags);
    setQStandardItemFlags(*_SOURCEItem, _myQStandardItemFlags);
    setQStandardItemFlags(*_TARGETItem, _myQStandardItemFlags);
    setQStandardItemFlags(*_changed_OR_modified_database_qty_Item, _myQStandardItemFlags);

    selectRow(_curRow);

    resizeColumnsToContents();

    int lastCurRow = _curRow;

    if (_curRow <= getMaxSize())
    {
    	++_curRow;
    }
    else
    {
    	_curRow = 0;
    }

    return lastCurRow;
}


uint YRDBRUNTIMEVERIF_TableWidget::FILTER_ITEM(const QString &SIGNALItem_TEXT)
{
    uint MATCHED_search = 0;


    QString searched_SIGNALItem_TEXT =
        QString("'%1")
            .arg(SIGNALItem_TEXT);


    int row_size = rowCount();

    int column_size = columnCount();


    static const uint SIGNALItem_COLUMN= 1;


    QTableWidgetItem *current_signal_item = 0;

    QString current_signal_item_TEXT;


    for (uint row = 0; row < row_size; ++row)
    {
        current_signal_item = item(row, SIGNALItem_COLUMN);

        if (0 != current_signal_item)
        {
            current_signal_item_TEXT = current_signal_item->text();

            if (!current_signal_item_TEXT.startsWith(searched_SIGNALItem_TEXT))
            {
                current_signal_item->setBackground(Qt::black);
            }
            else
            {
                ++MATCHED_search;

                current_signal_item->setBackground(Qt::red);
            }
        }

    }//for

    resizeColumnsToContents();


    return MATCHED_search;
}



