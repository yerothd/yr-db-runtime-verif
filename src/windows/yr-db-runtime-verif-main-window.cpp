/*
 * yr-db-runtime-verif-main-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main-window.hpp"


#include "src/utils/yr-db-runtime-verif-utils.hpp"

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
						 YRDBRUNTIMEVERIF_Logging_Info &a_logging_info)
{

	int last_current_row_nr
			= tableWidget_LOGGING->ADD_ITEM(TIMESTAMPtem,
										 	SIGNALItem,
											SOURCEItem,
											TARGETItem,
											changed_OR_modified_database_qty_Item);

	QString logging_info = a_logging_info.toString();


	_MAP_dbsqlevent__TO__cppfileinfo.yr_insert_item(last_current_row_nr,
												  	logging_info);


	tableWidget_LOGGING_2
		->ADD_ITEM_2(QString("%1:%2")
						.arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
							 a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));


	return last_current_row_nr;
}


void YRDBRUNTIMEVERIF_MainWindow::
	Set_YRDBRUNTIMEVERIF_Logging_Info(uint row_number,
									  QString logging_info)
{
	_MAP_dbsqlevent__TO__cppfileinfo.insert(row_number, logging_info);

	YRDBRUNTIMEVERIF_Logging_Info a_logging_info(logging_info);

	if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
			("True", a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE))
	{
		QTableWidgetItem *a_qtable_widget_item = tableWidget_LOGGING_4->item(0, 1);

		if (0 != a_qtable_widget_item)
		{
			a_qtable_widget_item->setForeground(Qt::red);
		}
	}


	tableWidget_LOGGING_4
		->ADD_ITEM_3(QString("%1:%2:%3")
					.arg(a_logging_info.A_PREVIOUS_STATE,
						 a_logging_info.AN_ACCEPTING_STATE,
						 a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));


	tableWidget_LOGGING_guarded_condition_expression
		->ADD_ITEM_2(QString("%1:%2")
						.arg(a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression,
							 a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression_VALUE));


	//tableWidget_LOGGING_2 ONLY HAS A SINGLE ROW !
	YRDBRUNTIMEVERIF_MainWindow::
		SET__foregroundcolor__ON__accepting_state(tableWidget_LOGGING_2->currentRow(),
												  tableWidget_LOGGING_2);

	YRDBRUNTIMEVERIF_MainWindow::
		SET__foregroundcolor__ON__accepting_state(row_number,
												  tableWidget_LOGGING);
}


YRDBRUNTIMEVERIF_Logging_Info *YRDBRUNTIMEVERIF_MainWindow::
	Get_YRDBRUNTIMEVERIF_Logging_Info(uint row_number)
{
	YRDBRUNTIMEVERIF_Logging_Info *a_logging_info_SAVED = 0;

	if (_MAP_dbsqlevent__TO__cppfileinfo.contains(row_number))
	{
		QString a_QSTRING_saved_logging_info = _MAP_dbsqlevent__TO__cppfileinfo.value(row_number);

		a_logging_info_SAVED = new YRDBRUNTIMEVERIF_Logging_Info(a_QSTRING_saved_logging_info);
	}

	return a_logging_info_SAVED;
}


void YRDBRUNTIMEVERIF_MainWindow::
		SET__foregroundcolor__ON__accepting_state(uint 			row_number,
												  QTableWidget 	*a_table_widget)
{
	if (0 != a_table_widget)
	{
		QTableWidgetItem *a_qwidget_item = 0;

		for (int k = 0; k < a_table_widget->columnCount(); ++k)
		{
			a_qwidget_item = a_table_widget->item(row_number, k);

			if (0 != a_qwidget_item)
			{
//				QDEBUG_STRINGS_OUTPUT_2_N("row_number", row_number);
//				a_qwidget_item->setForeground(Qt::green);
				a_qwidget_item->setForeground(Qt::blue);
			}
		}
	}
}


void YRDBRUNTIMEVERIF_MainWindow::
		ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item)
{
	if (0 != aQTable_widget_item)
	{
		QString LOGGING_INFO = _MAP_dbsqlevent__TO__cppfileinfo.value(aQTable_widget_item->row());

		YRDBRUNTIMEVERIF_Logging_Info a_logging_info(LOGGING_INFO);

		tableWidget_LOGGING_2
			->ADD_ITEM_2(QString("%1:%2")
							.arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
								 a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));


		if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
				("True", a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression_VALUE))
		{
			//tableWidget_LOGGING_2 ONLY HAS A SINGLE ROW !
			YRDBRUNTIMEVERIF_MainWindow::
				SET__foregroundcolor__ON__accepting_state(tableWidget_LOGGING_2->currentRow(),
														  tableWidget_LOGGING_2);
		}


		tableWidget_LOGGING_4
			->ADD_ITEM_3(QString("%1:%2:%3")
						.arg(a_logging_info.A_PREVIOUS_STATE,
							 a_logging_info.AN_ACCEPTING_STATE,
							 a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));

		tableWidget_LOGGING_guarded_condition_expression
			->ADD_ITEM_2(QString("%1:%2")
						.arg(a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression,
							 a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression_VALUE));
	}
	else
	{
		tableWidget_LOGGING_2->ADD_ITEM_2(QString("no source file info:-1"));
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


