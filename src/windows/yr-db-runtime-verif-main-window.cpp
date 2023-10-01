/*
 * yr-db-runtime-verif-main-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main-window.hpp"

//verification related.
#include "src/include/yr-db-runtime-verif-MONITOR.hpp"

#include "src/yr-db-runtime-verif-config.hpp"

#include "src/windows/yr-db-runtime-verif-windows.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include <QtCore/QProcess>


const QString YRDBRUNTIMEVERIF_MainWindow::QMESSAGE_BOX_STYLE_SHEET =
		QString("QMessageBox {background-color: rgb(%1);}"
                "QMessageBox QLabel {color: rgb(%2);}")
			.arg("47,67,67",
				 "02,160,70");


YRDBRUNTIMEVERIF_MainWindow::YRDBRUNTIMEVERIF_MainWindow()
:_current_runtime_monitor_INSTANCE(0)
{
    setupUi(this);

    setFixedSize(width(), height());


	toolBar_mainWindow_YR_DB_RUNTIME_VERIF
		->setStyleSheet(QMESSAGE_BOX_STYLE_SHEET);


    comboBox_SQL_event_filtering->setLineEdit(new QLineEdit);

	comboBox_SQL_event_filtering->lineEdit()->setReadOnly(true);

    comboBox_SQL_event_filtering->lineEdit()
        ->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);


    comboBox_SQL_event_filtering->addItem("");
    comboBox_SQL_event_filtering->addItem("DELETE");
    comboBox_SQL_event_filtering->addItem("UPDATE");
    comboBox_SQL_event_filtering->addItem("SELECT");
    comboBox_SQL_event_filtering->addItem("INSERT");


    lineEdit_SQL_event_filtering->setAlignment(Qt::AlignHCenter);

    lineEdit_nombre_de_resultats->setAlignment(Qt::AlignHCenter);


    tableWidget_LOGGING_2->setMaxSize(1);
    tableWidget_LOGGING_4->setMaxSize(1);
    tableWidget_LOGGING_PRECONDITIONS_postconditions->setMaxSize(1);
    tableWidget_LOGGING_guarded_condition_expression->setMaxSize(1);


    tableWidget_LOGGING_4->setVisible(false);
    tableWidget_LOGGING_PRECONDITIONS_postconditions->setVisible(false);
    tableWidget_LOGGING_guarded_condition_expression->setVisible(false);



    connect(pushButton_reset_filtering,
    		SIGNAL(clicked()),
			this,
            SLOT(ON_BUTON_Reset_pressed()));


    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));


    connect(actionCONFIGURATION_panel_window,
    		SIGNAL(triggered()),
			this,
            SLOT(ON_Configfuration_panel_window_trigerred()));

    connect(actionVIEW_RUNTIME_monitor,
    		SIGNAL(triggered()),
			this,
            SLOT(VIEW_current_RUNTIME_MONITOR()));

    /*
     * USEFUL TO UPDATE sql event information WHEN
     * 'QtableWidget::selectRow' IS CALLED.
     */
    connect(tableWidget_LOGGING,
    		SIGNAL(itemChanged(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));

    connect(tableWidget_LOGGING,
    		SIGNAL(itemPressed(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));


    connect(comboBox_SQL_event_filtering,
    		SIGNAL(currentTextChanged(const QString &)),
			this,
            SLOT(ON_QTABLEWIDGET_FILTER_ITEM_selected(const QString &)));


    connect(lineEdit_SQL_event_filtering,
    		SIGNAL(textChanged(const QString &)),
			this,
            SLOT(ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(const QString &)));


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


void YRDBRUNTIMEVERIF_MainWindow
		::SET__CURRENT__RUNTIME__MONITOR
			(YR_DB_RUNTIME_VERIF_Monitor *a_current_runtime_monitor_INSTANCE)
{
	_current_runtime_monitor_INSTANCE = a_current_runtime_monitor_INSTANCE;

    if (0 != _current_runtime_monitor_INSTANCE)
    {
    	actionVIEW_RUNTIME_monitor
			->setText(QString("view runtime monitor (%1)")
						.arg(_current_runtime_monitor_INSTANCE
								->get_RUNTIME_MONITOR_NAME()));
    }
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


    tableWidget_LOGGING_4->setVisible(true);
    tableWidget_LOGGING_PRECONDITIONS_postconditions->setVisible(true);
    tableWidget_LOGGING_guarded_condition_expression->setVisible(true);


	tableWidget_LOGGING_4
		->ADD_ITEM_3(QString("%1:%2:%3")
					.arg(a_logging_info.A_PREVIOUS_STATE,
						 a_logging_info.AN_ACCEPTING_STATE,
						 a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));

	tableWidget_LOGGING_PRECONDITIONS_postconditions
		->ADD_ITEM_2(QString("%1:%2")
						.arg(a_logging_info.A_TRANSITION_precondition,
							 a_logging_info.A_TRANSITION_postcondition));

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


void YRDBRUNTIMEVERIF_MainWindow::set_connection_DBUS_status(QString message_STATUS,
															 bool 	 error_not_connected /* = false*/)
{
	if (!error_not_connected)
	{
		label_display_yr_db_runtime_verifier_connection_STATUS
			->setStyleSheet(QString("color: rgb(%1);")
								.arg("255,255,255"));
	}
	else
	{
		label_display_yr_db_runtime_verifier_connection_STATUS
			->setStyleSheet(QString("color: rgb(%1);")
								.arg("255,48,48"));
	}

	label_display_yr_db_runtime_verifier_connection_STATUS
		->setText(message_STATUS);
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
				a_qwidget_item->setForeground(Qt::green);
			}
		}
	}
}


void YRDBRUNTIMEVERIF_MainWindow::VIEW_current_RUNTIME_MONITOR()
{
	if (0 != _current_runtime_monitor_INSTANCE)
	{
		QString DOT_FORMAT =
				_current_runtime_monitor_INSTANCE->print_TO_dot_FILE(true);
	}
}


void YRDBRUNTIMEVERIF_MainWindow::ON_Configfuration_panel_window_trigerred()
{
    YRDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YR_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_setup_Window->yr_show();
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window->yr_close();
    }
}


void YRDBRUNTIMEVERIF_MainWindow::ON_BUTON_Reset_pressed()
{
    lineEdit_SQL_event_filtering->clear();

    comboBox_SQL_event_filtering->setCurrentIndex(0);

    tableWidget_LOGGING->CLEAR_FILTERING();
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
		    tableWidget_LOGGING_4->setVisible(true);
		    tableWidget_LOGGING_PRECONDITIONS_postconditions->setVisible(true);
		    tableWidget_LOGGING_guarded_condition_expression->setVisible(true);

			YRDBRUNTIMEVERIF_MainWindow::
				SET__foregroundcolor__ON__accepting_state(aQTable_widget_item->row(),
														  tableWidget_LOGGING);

			//tableWidget_LOGGING_2 ONLY HAS A SINGLE ROW !
			YRDBRUNTIMEVERIF_MainWindow::
				SET__foregroundcolor__ON__accepting_state(tableWidget_LOGGING_2->currentRow(),
														  tableWidget_LOGGING_2);
		}
		else
		{
		    tableWidget_LOGGING_4->setVisible(false);
		    tableWidget_LOGGING_PRECONDITIONS_postconditions->setVisible(false);
		    tableWidget_LOGGING_guarded_condition_expression->setVisible(false);
		}


		tableWidget_LOGGING_4
			->ADD_ITEM_3(QString("%1:%2:%3")
						.arg(a_logging_info.A_PREVIOUS_STATE,
							 a_logging_info.AN_ACCEPTING_STATE,
							 a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));

		tableWidget_LOGGING_PRECONDITIONS_postconditions
			->ADD_ITEM_2(QString("%1:%2")
							.arg(a_logging_info.A_TRANSITION_precondition,
								 a_logging_info.A_TRANSITION_postcondition));

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


void YRDBRUNTIMEVERIF_MainWindow::
        ON_QTABLEWIDGET_FILTER_ITEM_selected(const QString &a_SQL_event_item)
{
    uint MATCHED_search = tableWidget_LOGGING->FILTER_ITEM(a_SQL_event_item);

    lineEdit_nombre_de_resultats->setText(QString::number(MATCHED_search));
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(const QString &a_SQL_event_item)
{
    comboBox_SQL_event_filtering->setCurrentIndex(0);

    uint MATCHED_search = tableWidget_LOGGING->FILTER_ITEM(a_SQL_event_item,
                                                          true);

    lineEdit_nombre_de_resultats->setText(QString::number(MATCHED_search));
}


void YRDBRUNTIMEVERIF_MainWindow::ACTION_USER_GUIDE_method()
{
	QStringList progArguments;

	QProcess aProcess;

	progArguments << "/usr/share/doc/yr-db-runtime-verif/YEROTH_QVGE.pdf";

	aProcess.startDetached(YRDBRUNTIMEVERIF_SetupWindow::YR_LINE_EDIT_PDF_FULL_PATH_READER,
						   progArguments);
}



