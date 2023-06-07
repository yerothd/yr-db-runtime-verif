/*
 * yr-db-runtime-verif-main-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main-window.hpp"


#include <QtCore/QProcess>



YRDBRUNTIMEVERIF_MainWindow::YRDBRUNTIMEVERIF_MainWindow()
{
    setupUi(this);

    setFixedSize(width(), height());



    connect(tableWidget_LOGGING,
    		SIGNAL(itemPressed(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));


    connect(actionExit,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_EXIT_method()));


    connect(actionUserGuide_PDF,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_USER_GUIDE_method()));


	setVisible(true);
}


int YRDBRUNTIMEVERIF_MainWindow::
				ADD_ITEM(QString TIMESTAMPtem,
						 QString SIGNALItem,
						 QString SOURCEItem,
						 QString TARGETItem,
						 QString changed_OR_modified_database_qty_Item,
						 QString A_CPP_FILE_NAME,
						 QString A_CPP_FILE_LINE_NUMBER)
{

	int last_current_row_nr
			= tableWidget_LOGGING->ADD_ITEM(TIMESTAMPtem,
										 	SIGNALItem,
											SOURCEItem,
											TARGETItem,
											changed_OR_modified_database_qty_Item);

	QString SOURCE_FILE__line_number = QString("%1:%2")
										.arg(A_CPP_FILE_NAME,
											 A_CPP_FILE_LINE_NUMBER);


	_MAP_dbsqlevent__TO__cppfileinfo.yr_insert_item(last_current_row_nr,
												  	SOURCE_FILE__line_number);


	tableWidget_LOGGING_2->ADD_ITEM(SOURCE_FILE__line_number);


	return last_current_row_nr;
}


void YRDBRUNTIMEVERIF_MainWindow::
		ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item)
{
	if (0 != aQTable_widget_item)
	{
		QString SOURCE_FILE__line_number =
				_MAP_dbsqlevent__TO__cppfileinfo.value(aQTable_widget_item->row());

		tableWidget_LOGGING_2->ADD_ITEM(SOURCE_FILE__line_number);
	}
	else
	{
		tableWidget_LOGGING_2->ADD_ITEM(QString("no source file info:-1"));
	}
}


void YRDBRUNTIMEVERIF_MainWindow::ACTION_USER_GUIDE_method()
{
	QStringList progArguments;

	QProcess aProcess;

	progArguments << "/usr/share/doc/yr-db-runtime-verif/YEROTH_QVGE.pdf";

	aProcess.startDetached("/usr/bin/evince",
						   progArguments);
}


