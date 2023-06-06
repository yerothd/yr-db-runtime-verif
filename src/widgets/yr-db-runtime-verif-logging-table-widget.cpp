/*
 * yr-db-runtime-verif-logging-table-widget.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-logging-table-widget.hpp"


const uint YRDBRUNTIMEVERIF_TableWidget::MAX_TABLE_WIDGET_ROW_COUNT = 22;


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

    setEditTriggers(QAbstractItemView::CurrentChanged);

    setSelectionBehavior(QAbstractItemView::SelectRows);

    setSelectionMode(QAbstractItemView::SingleSelection);


	setRowCount(MAX_TABLE_WIDGET_ROW_COUNT);
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


int YRDBRUNTIMEVERIF_TableWidget::ADD_ITEM(QString TIMESTAMPtem,
										   QString SIGNALItem,
		   	   	   	   	   	   	   	   	   QString SOURCEItem,
										   QString TARGETItem,
										   QString changed_OR_modified_database_qty_Item)
{
    setRowCount(_curRow + 1);

    _TIMESTAMPtem = new QTableWidgetItem(TIMESTAMPtem);
    _SIGNALItem = new QTableWidgetItem(SIGNALItem);
    _SOURCEItem = new QTableWidgetItem(SOURCEItem);
    _TARGETItem = new QTableWidgetItem(TARGETItem);


    _changed_OR_modified_database_qty_Item =
    		new QTableWidgetItem(changed_OR_modified_database_qty_Item);

    _mapListIdxToElement_db_ID.insert(_curRow, SIGNALItem);

    unsigned idx = 0;

    //Each call to setItem triggers a call to YerothPointDeVenteWindow::handleQteChange
    setItem(_curRow, idx++, _TIMESTAMPtem);
    setItem(_curRow, idx++, _SIGNALItem);
    setItem(_curRow, idx++, _SOURCEItem);
    setItem(_curRow, idx++, _TARGETItem);
    setItem(_curRow, idx++, _changed_OR_modified_database_qty_Item);

    _TIMESTAMPtem->setFlags(_myQStandardItemFlags);
    _SIGNALItem->setFlags(_myQStandardItemFlags);
    _SOURCEItem->setFlags(_myQStandardItemFlags);
    _TARGETItem->setFlags(_myQStandardItemFlags);
    _changed_OR_modified_database_qty_Item->setFlags(_myQStandardItemFlags);

    selectRow(_curRow);

    resizeColumnsToContents();

    int lastCurRow = _curRow;

    if (_curRow < MAX_TABLE_WIDGET_ROW_COUNT)
    {
    	++_curRow;
    }
    else
    {
    	_curRow = 0;
    }

    return lastCurRow;
}
