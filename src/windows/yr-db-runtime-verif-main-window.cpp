/*
 * yr-db-runtime-verif-main-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main-window.hpp"


//verification related.
#include "src/include/yr-db-runtime-verif-MONITOR.hpp"

#include "src/utils/yr-db-runtime-verif-CONFIG.hpp"

#include "src/windows/yr-db-runtime-verif-windows.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include "src/process/yr-db-runtime-verif-PROCESS.hpp"


const QString YRDBRUNTIMEVERIF_MainWindow::QMESSAGE_BOX_STYLE_SHEET =
		QString("QMessageBox {background-color: rgb(%1);}"
                "QMessageBox QLabel {color: rgb(%2);}")
			.arg("47,67,67",
				 "02,160,70");


YRDBRUNTIMEVERIF_MainWindow::YRDBRUNTIMEVERIF_MainWindow()
:_pushButton_lecteur_de_code_barres_JUST_CLICKED(false),
 _CURRENT_runtime_monitor_name_Filtered(false),
 _visible_ERROR_row_counter(0),
 _visible_row_counter(0),
 _Last_SelectedRow_Row_INDEX(0),
 _current_runtime_monitor_INSTANCE(0)
{
    setupUi(this);

    setFixedSize(width(), height());


    pushButton_lecteur_de_code_barres
        ->setVisible(false);


    _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
        .insert(tableWidget_LOGGING,
                0);

    _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
        .insert(tableWidget_LOGGING_ERROR_EVENT,
                0);


	toolBar_mainWindow_YR_DB_RUNTIME_VERIF
		->setStyleSheet(QMESSAGE_BOX_STYLE_SHEET);


    actionVIEW_RUNTIME_monitor->setVisible(false);

    actionPRINT_event_log_excerpt_till_selected_SQL_event->setVisible(false);

    actionPRINT_event_log_FULL->setVisible(false);

    action_save_to_csv_format_sheet->setVisible(false);

    actionExport_as_CSV_till_selected_SQL_event->setVisible(false);

    actionSet_current_selected_SQL_event_as_filter_and_search->setVisible(false);



    comboBox_global_filtering->addItem("");
    comboBox_global_filtering->addItem("sql event log");
    comboBox_global_filtering->addItem("source");



    comboBox_SQL_event_filtering->addItem("");
    comboBox_SQL_event_filtering->addItem("DELETE");
    comboBox_SQL_event_filtering->addItem("UPDATE");
    comboBox_SQL_event_filtering->addItem("SELECT");
    comboBox_SQL_event_filtering->addItem("INSERT");


    setCurrentRuntimeMonitorNameVisible(false);



    checkBox_ALL_STATE_SAFETY_PROPERTIES->setVisible(false);


    comboBox_RUNTIME_MONITOR_NAME->yr__setEditable(false);



    lineEdit_SQL_event_filtering
        ->setPlaceholderText(QString("Enter \"source\" or \"SQL event\" for filtering"));


    lineEdit_SQL_event_filtering->setAlignment(Qt::AlignHCenter);

    lineEdit_FILTERING_COUNT->setAlignment(Qt::AlignHCenter);


    tableWidget_LOGGING_2->setMaxSize(1);
    tableWidget_LOGGING_4->setMaxSize(1);
    tableWidget_LOGGING_PRECONDITIONS->setMaxSize(1);
    tableWidget_LOGGING_postconditions->setMaxSize(1);
    tableWidget_LOGGING_guarded_condition_expression->setMaxSize(1);
    tableWidget_LOGGING_SQL_recovery_executed_query->setMaxSize(1);


    tableWidget_LOGGING_4->setVisible(false);
    tableWidget_LOGGING_PRECONDITIONS->setVisible(false);
    tableWidget_LOGGING_postconditions->setVisible(false);
    tableWidget_LOGGING_guarded_condition_expression->setVisible(false);
    tableWidget_LOGGING_SQL_recovery_executed_query->setVisible(false);


    setCurrentRuntimeMonitorNameVisible(false);


    connect(checkBox_ALL_STATE_SAFETY_PROPERTIES,
            SIGNAL(stateChanged(int)),
            this,
            SLOT(handle_checkBox_ALL_STATE_SAFETY_PROPERTIES_State_CHANGED(int)));


    connect(tabWidget_SQL_ERROR_EVENT_LOGGING,
            SIGNAL(currentChanged(int)),
            this,
            SLOT(handle_current_tab_changed(int)));


    connect(action_save_to_csv_format_sheet,
            SIGNAL(triggered()),
            this,
            SLOT(export_csv_file()));


    connect(actionExport_as_CSV_till_selected_SQL_event,
            SIGNAL(triggered()),
            this,
            SLOT(ON_action_export_as_CSV_till_selected_SQL_event()));


    connect(actionSet_current_selected_SQL_event_as_filter_and_search,
            SIGNAL(triggered()),
            this,
            SLOT(ON_action_set_current_selected_SQL_event_as_filter_and_search()));


    connect(pushButton_lecteur_de_code_barres,
    		SIGNAL(clicked()),
			this,
            SLOT(ON_QTABLEWIDGET_ERROR_ITEM_pressed()));


    connect(pushButton_reset_filtering,
    		SIGNAL(clicked()),
			this,
            SLOT(ON_BUTON_Reset_pressed()));

    connect(pushButton_filter,
    		SIGNAL(clicked()),
			this,
            SLOT(ON_BUTON_Filter_pressed()));


    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));


    connect(actionCONFIGURATION_panel_window,
    		SIGNAL(triggered()),
			this,
            SLOT(ON_Configfuration_panel_window_trigerred()));


    connect(actionVIEW_RUNTIME_monitor,
    		SIGNAL(triggered()),
			this,
            SLOT(YR_on_progress_bar__VIEW_current_RUNTIME_MONITOR()));



    connect(actionPRINT_event_log_excerpt_till_selected_SQL_event,
    		SIGNAL(triggered()),
			this,
            SLOT(yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt_till_selected_SQL_event()));


    connect(actionPRINT_event_log_FULL,
    		SIGNAL(triggered()),
			this,
            SLOT(yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt()));



    // USEFUL TO UPDATE sql event information WHEN
    // actions from context menu are called from a cell.
    connect(tableWidget_LOGGING_ERROR_EVENT,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(setLast_SelectedRow_Row_ID(const QModelIndex &)));

    connect(tableWidget_LOGGING_ERROR_EVENT,
            SIGNAL(pressed(const QModelIndex &)),
            this,
            SLOT(setLast_SelectedRow_Row_ID(const QModelIndex &)));



    connect(tableWidget_LOGGING,
            SIGNAL(clicked(const QModelIndex &)),
            this,
            SLOT(setLast_SelectedRow_Row_ID(const QModelIndex &)));

    connect(tableWidget_LOGGING,
            SIGNAL(pressed(const QModelIndex &)),
            this,
            SLOT(setLast_SelectedRow_Row_ID(const QModelIndex &)));


    /*
     * USEFUL TO UPDATE sql event information WHEN
     * 'QtableWidget::selectRow' IS CALLED.
     */
    connect(tableWidget_LOGGING_ERROR_EVENT,
    		SIGNAL(itemChanged(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *)));

    connect(tableWidget_LOGGING_ERROR_EVENT,
    		SIGNAL(itemClicked(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *)));

    connect(tableWidget_LOGGING_ERROR_EVENT,
    		SIGNAL(itemPressed(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *)));



    connect(tableWidget_LOGGING,
    		SIGNAL(itemChanged(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));

    connect(tableWidget_LOGGING,
    		SIGNAL(itemClicked(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));

    connect(tableWidget_LOGGING,
    		SIGNAL(itemPressed(QTableWidgetItem *)),
			this,
            SLOT(ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *)));



    connect(comboBox_global_filtering,
    		SIGNAL(currentTextChanged(const QString &)),
			this,
            SLOT(RESET_comboBox_SQL_event_filtering(const QString &)));

    connect(comboBox_SQL_event_filtering,
    		SIGNAL(currentTextChanged(const QString &)),
			this,
            SLOT(ON_QTABLEWIDGET_FILTER_ITEM_selected(const QString &)));



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


void YRDBRUNTIMEVERIF_MainWindow::SELECT_row(uint a_row_selected)
{
    tableWidget_LOGGING_ERROR_EVENT->selectRow(a_row_selected);

    _pushButton_lecteur_de_code_barres_JUST_CLICKED = true;

    pushButton_lecteur_de_code_barres->click();
}


void YRDBRUNTIMEVERIF_MainWindow::SET_CURRENT_RUNTIME_MONITOR_name(QString A_RUNTIME_MONITOR_name)
{
    if (!A_RUNTIME_MONITOR_name.isEmpty())
    {
        comboBox_RUNTIME_MONITOR_NAME_Logging
            ->find_AND_SET_CURRENT_INDEX(A_RUNTIME_MONITOR_name.trimmed());
    }
}


void YRDBRUNTIMEVERIF_MainWindow::SET_CURRENT_RUNTIME_MONITOR_name_ERROR_Logging(QString A_RUNTIME_MONITOR_name)
{
    if (!A_RUNTIME_MONITOR_name.isEmpty())
    {
        comboBox_RUNTIME_MONITOR_NAME
            ->find_AND_SET_CURRENT_INDEX(A_RUNTIME_MONITOR_name.trimmed());
    }
}


int YRDBRUNTIMEVERIF_MainWindow::
				ADD_ERROR_ITEM(QString                        TIMESTAMPtem,
                               QString                        SIGNALItem,
                               QString                        SOURCEItem,
                               QString                        TARGETItem,
                               QString                        changed_OR_modified_database_qty_Item,
                               YRDBRUNTIMEVERIF_Logging_Info  &a_logging_info)
{
    ++_visible_ERROR_row_counter;

    if (_visible_ERROR_row_counter >= 2999)
    {
        _visible_ERROR_row_counter = 1;
    }


    int last_ERROR_current_row_nr =
        tableWidget_LOGGING_ERROR_EVENT
            ->ADD_ITEM(TIMESTAMPtem,
                       SIGNALItem,
                       SOURCEItem,
                       TARGETItem,
                       changed_OR_modified_database_qty_Item);


	QString logging_info = a_logging_info.toString();


	_MAP_dbsqlERRORevent__TO__cppfileinfo.yr_insert_item(last_ERROR_current_row_nr,
                                                         logging_info);

    set_SQL_current_recovered_query_string
        (a_logging_info.RECOVERY_SQL_string__ON_ERROR__accepting_state,
         a_logging_info.timestamp);


    tableWidget_LOGGING_ERROR_SOURCE_LOCATION
        ->ADD_ITEM_2(QString("%1:%2")
                     .arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
                          a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));


	return last_ERROR_current_row_nr;
}


int YRDBRUNTIMEVERIF_MainWindow::
				ADD_ITEM(QString                        TIMESTAMPtem,
						 QString                        SIGNALItem,
						 QString                        SOURCEItem,
						 QString                        TARGETItem,
						 QString                        changed_OR_modified_database_qty_Item,
						 YRDBRUNTIMEVERIF_Logging_Info  &a_logging_info)
{
    handle_current_tab_changed(tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex());

    ++_visible_row_counter;

    if (_visible_row_counter >= 2999)
    {
        _visible_row_counter = 1;
    }

    int last_current_row_nr =
        tableWidget_LOGGING->ADD_ITEM(TIMESTAMPtem,
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
        QString current_runtime_monitor_NAME =
            _current_runtime_monitor_INSTANCE->get_RUNTIME_MONITOR_NAME();

    	actionVIEW_RUNTIME_monitor
			->setText(QString("view runtime monitor (%1)")
						.arg(current_runtime_monitor_NAME));
    }
}


void YRDBRUNTIMEVERIF_MainWindow::
	Set_YRDBRUNTIMEVERIF_Logging_Info(uint      row_number,
									  QString   logging_info)
{
	_MAP_dbsqlERRORevent__TO__cppfileinfo.insert(row_number, logging_info);

	YRDBRUNTIMEVERIF_Logging_Info a_logging_info(logging_info);

	if (a_logging_info.IS_ERROR_EVENT_LOGGING())
	{
	    {
            QString non_error_log_event_COMBOBOX_info =
                _MAP_dbsqlevent__TO__cppfileinfo.value(row_number);

            YRDBRUNTIMEVERIF_Logging_Info a_logging_NON_ERROR_combobox_info
                (non_error_log_event_COMBOBOX_info);

            // WE PUT THIS EVENT ERROR INFORMATION to true so to
            //actualize it, AND WE REPLACE ITS OLD VALUE IN THE
            //MAP "_MAP_dbsqlevent__TO__cppfileinfo".
            a_logging_NON_ERROR_combobox_info.SET_IS_ERROR_EVENT(true);

            _MAP_dbsqlevent__TO__cppfileinfo
                .yr_insert_item(row_number,
                                a_logging_NON_ERROR_combobox_info.toString());

            comboBox_RUNTIME_MONITOR_NAME_Logging->setVisible(true);

            comboBox_RUNTIME_MONITOR_NAME_Logging
                ->find_AND_SET_CURRENT_INDEX(a_logging_NON_ERROR_combobox_info.A_RUNTIME_MONITOR_name);
        }


        //Call ADD_ITEM here so to complement logging information
        //on an accepting error state.

        YRDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
            YR_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

        if (0 != ALL_WINDOWS_INSTANCE)
        {
            ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window
                ->ADD_ERROR_ITEM(a_logging_info.timestamp,
                                 a_logging_info.an_SQL_event_TOKEN,
                                 a_logging_info.A_SUT_string_unique_ID,
                                 "YR-DB-RUNTIME-VERIF",
                                 a_logging_info.changed_record_db_quantity,
                                 a_logging_info);
        }


        QTableWidgetItem *a_qtable_widget_item = tableWidget_LOGGING_4->item(0, 1);

		if (0 != a_qtable_widget_item)
		{
			a_qtable_widget_item->setForeground(Qt::red);
		}
	}


    tableWidget_LOGGING_4->setVisible(true);
    tableWidget_LOGGING_PRECONDITIONS->setVisible(true);
    tableWidget_LOGGING_postconditions->setVisible(true);
    tableWidget_LOGGING_guarded_condition_expression->setVisible(true);


    RUNTIME_MONITOR_name_TO_PRINT_DOT = a_logging_info.A_RUNTIME_MONITOR_name;


    if (RUNTIME_MONITOR_name_TO_PRINT_DOT.isEmpty())
    {
        actionVIEW_RUNTIME_monitor
        ->setText(QString("NO runtime monitor to visualize in PDF form"));

        actionVIEW_RUNTIME_monitor->setVisible(false);
    }
    else
    {
        actionVIEW_RUNTIME_monitor
        ->setText(QString("view runtime monitor (%1)")
                  .arg(RUNTIME_MONITOR_name_TO_PRINT_DOT));

        actionVIEW_RUNTIME_monitor->setVisible(true);
    }

    // 3. Runtime monitor name is set on the main window
    // only for SQL events that lead to an accepting
    // error state.
    SET_CURRENT_RUNTIME_MONITOR_name_ERROR_Logging(a_logging_info.A_RUNTIME_MONITOR_name);


    setCurrentRuntimeMonitorNameVisible(true);


	tableWidget_LOGGING_4
		->ADD_ITEM_3(QString("%1:%2:%3")
					.arg(a_logging_info.A_PREVIOUS_STATE,
						 a_logging_info.AN_ACCEPTING_STATE,
						 a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));


    tableWidget_LOGGING_PRECONDITIONS
        ->ADD_ITEM_1(a_logging_info.A_TRANSITION_precondition);

    tableWidget_LOGGING_postconditions
        ->ADD_ITEM_1(a_logging_info.A_TRANSITION_postcondition);


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


bool YRDBRUNTIMEVERIF_MainWindow::export_csv_file()
{
    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item =
                                    Get_CURRENT_QTable_WIDGET();

    if (0 == current_QTable_Widget_Item)
    {
        return false;
    }


    return
        YR_DB_RUNTIME_VERIF_Utils::SAVE_AS_csv_file(*this,
                                                    *current_QTable_Widget_Item,
                                                    "sql-event-log-listing-csv-format",
                                                    "SQL event log csv export");
}


bool YRDBRUNTIMEVERIF_MainWindow::
        set_SQL_current_recovered_query_string(QString SQL_QUERY_STRING,
                                               QString TIMESTAMP /* = "" */)
{
    bool result = !SQL_QUERY_STRING.isEmpty();

    tableWidget_LOGGING_SQL_recovery_executed_query
        ->setVisible(result);

    //TODO: switch 'CURRENT_TIME_WITH_MILLISECONDS' with
    //passed "TIMESTAMP" parameter later when implemented.
    tableWidget_LOGGING_SQL_recovery_executed_query
		->ADD_ITEM_2(SQL_QUERY_STRING,
                     TIMESTAMP);

    return result;
}


void YRDBRUNTIMEVERIF_MainWindow::set_CURRENT_TABWIDGET_ACTION_visible(bool a_value)
{
    actionVIEW_RUNTIME_monitor->setVisible(a_value);

    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        checkBox_ALL_STATE_SAFETY_PROPERTIES->setVisible(a_value);


        tableWidget_LOGGING_ERROR_EVENT->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_ERROR_SOURCE_LOCATION->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_PRECONDITIONS->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_postconditions->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_guarded_condition_expression->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_SQL_recovery_executed_query->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_4->resize_columns_AND_rows_to_contents();
    }


    if (1 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        tableWidget_LOGGING->resize_columns_AND_rows_to_contents();

        tableWidget_LOGGING_2->resize_columns_AND_rows_to_contents();


        actionVIEW_RUNTIME_monitor->setVisible(false);
    }


    actionPRINT_event_log_excerpt_till_selected_SQL_event->setVisible(a_value);

    actionPRINT_event_log_FULL->setVisible(a_value);

    action_save_to_csv_format_sheet->setVisible(a_value);

    actionExport_as_CSV_till_selected_SQL_event->setVisible(a_value);

    actionSet_current_selected_SQL_event_as_filter_and_search->setVisible(a_value);
}


void YRDBRUNTIMEVERIF_MainWindow::filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS()
{
    ON_BUTON_Reset_pressed();


    uint Filtered_Cell_Count = 0;


    QString A_Current_RUNTIME_monitor_Name = GET_CURRENT_RUNTIME_MONITOR_name();


    QString a_CURRENT_LOGGING_INFO;


    uint TIMESTAMP_column_number = 0;


    QTableWidgetItem *a_qwidget_item = 0;


    for (int row_number = 0;
         row_number < tableWidget_LOGGING_ERROR_EVENT->rowCount();
         ++row_number)
    {
        a_qwidget_item =
            tableWidget_LOGGING_ERROR_EVENT->item(row_number,
                                                  TIMESTAMP_column_number);

        if (0 != a_qwidget_item)
        {
            a_CURRENT_LOGGING_INFO = _MAP_dbsqlERRORevent__TO__cppfileinfo
                                                .value(a_qwidget_item->row());

            YRDBRUNTIMEVERIF_Logging_Info a_CURRENT_logging_info(a_CURRENT_LOGGING_INFO);

            if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseSensitive(a_CURRENT_logging_info.A_RUNTIME_MONITOR_name,
                                                                 A_Current_RUNTIME_monitor_Name))
            {
                ++Filtered_Cell_Count;

                a_qwidget_item->setBackground(Qt::darkMagenta);
            }
        }
    }

    if (Filtered_Cell_Count > 0)
    {
        set_CURRENT_runtime_monitor_name_Filtered(true);

        tableWidget_LOGGING_ERROR_EVENT->Set_CURRENTLY_filtered(true);
    }
}


void YRDBRUNTIMEVERIF_MainWindow::UN__filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS()
{
    QString A_Current_RUNTIME_monitor_Name = GET_CURRENT_RUNTIME_MONITOR_name();


    QString a_CURRENT_LOGGING_INFO;


    uint TIMESTAMP_column_number = 0;


    QTableWidgetItem *a_qwidget_item = 0;


    for (int row_number = 0;
         row_number < tableWidget_LOGGING_ERROR_EVENT->rowCount();
         ++row_number)
    {
        a_qwidget_item =
            tableWidget_LOGGING_ERROR_EVENT->item(row_number,
                                                  TIMESTAMP_column_number);

        if (0 != a_qwidget_item)
        {
            a_CURRENT_LOGGING_INFO = _MAP_dbsqlERRORevent__TO__cppfileinfo
                                                .value(a_qwidget_item->row());

            YRDBRUNTIMEVERIF_Logging_Info a_CURRENT_logging_info(a_CURRENT_LOGGING_INFO);

            if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseSensitive(a_CURRENT_logging_info.A_RUNTIME_MONITOR_name,
                                                                 A_Current_RUNTIME_monitor_Name))
            {
                a_qwidget_item->setBackground(Qt::black);
            }
        }
    }


    set_CURRENT_runtime_monitor_name_Filtered(false);
}


void YRDBRUNTIMEVERIF_MainWindow::
        handle_checkBox_ALL_STATE_SAFETY_PROPERTIES_State_CHANGED(int a_state)
{
    if (Qt::Checked == a_state)
    {
        filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS();
    }
    else
    {
        UN__filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS();
    }
}


int YRDBRUNTIMEVERIF_MainWindow::
        GET_QTABLEWIDGET_CURRENT_ROW_TO_Select(int current_index)
{
    int current_row_TO_SELECT = 0;

    const QModelIndex *a_Last_SelectedRow_Row_INDEX = 0;

    switch (current_index)
    {
    case 0:

        a_Last_SelectedRow_Row_INDEX =
            _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
                .value(tableWidget_LOGGING_ERROR_EVENT);

        if (0 != a_Last_SelectedRow_Row_INDEX)
        {
            current_row_TO_SELECT = a_Last_SelectedRow_Row_INDEX->row();
        }

        break;

    case 1:

        a_Last_SelectedRow_Row_INDEX =
            _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
                .value(tableWidget_LOGGING);

        if (0 != a_Last_SelectedRow_Row_INDEX)
        {
            current_row_TO_SELECT = a_Last_SelectedRow_Row_INDEX->row();
        }

        break;

    default:
        break;
    }

    return current_row_TO_SELECT;
}


void YRDBRUNTIMEVERIF_MainWindow::handle_current_tab_changed(int current_index)
{
    int current_row_TO_SELECT =
        GET_QTABLEWIDGET_CURRENT_ROW_TO_Select(current_index);

    switch (current_index)
    {
    case 0:

        //also clears qtablewidget filtering
        ON_BUTON_Reset_pressed();

        if (_visible_ERROR_row_counter > 0)
        {
            set_CURRENT_TABWIDGET_ACTION_visible(true);

            SELECT_row(current_row_TO_SELECT);
        }
        else
        {
            set_CURRENT_TABWIDGET_ACTION_visible(false);
        }
        break;


    case 1:

        //also clears qtablewidget filtering
        ON_BUTON_Reset_pressed();

        if (_visible_row_counter > 0)
        {
            set_CURRENT_TABWIDGET_ACTION_visible(true);

            tableWidget_LOGGING->selectRow(current_row_TO_SELECT);
        }
        else
        {
            set_CURRENT_TABWIDGET_ACTION_visible(false);
        }
        break;


    default:
        break;
    }
}


void YRDBRUNTIMEVERIF_MainWindow::
		SET__foregroundcolor__ON__accepting_state(uint 			row_number,
												  QTableWidget 	*a_table_widget,
												  QColor        a_color_to_SET /* = Qt::green */)
{
	if (0 != a_table_widget)
	{
		QTableWidgetItem *a_qwidget_item = 0;

		for (int k = 0; k < a_table_widget->columnCount(); ++k)
		{
			a_qwidget_item = a_table_widget->item(row_number, k);

			if (0 != a_qwidget_item)
			{
				a_qwidget_item->setForeground(a_color_to_SET);
			}
		}
	}
}


void *YRDBRUNTIMEVERIF_MainWindow::VIEW_current_RUNTIME_MONITOR()
{
    YR_DB_RUNTIME_VERIF_Monitor *a_to_print_DOT_FORMAT_runtime_monitor =
        user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES
            .value(RUNTIME_MONITOR_name_TO_PRINT_DOT);

    emit SIGNAL_INCREMENT_PROGRESS_BAR(30);

	if (0 != a_to_print_DOT_FORMAT_runtime_monitor)
	{
		QString DOT_FORMAT =
				a_to_print_DOT_FORMAT_runtime_monitor
                    ->print_TO_dot_FILE(YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir,
                                        RUNTIME_MONITOR_name_TO_PRINT_DOT,
                                        true,
                                        true,
                                        true);

        emit SIGNAL_INCREMENT_PROGRESS_BAR(90);
	}
}


void YRDBRUNTIMEVERIF_MainWindow::
        setLast_SelectedRow_Row_ID(const QModelIndex &a_model_CELL_index)
{
    _Last_SelectedRow_Row_INDEX = &a_model_CELL_index;

    switch(tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        case 0:

            _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
                .insert(tableWidget_LOGGING_ERROR_EVENT,
                        &a_model_CELL_index);
            break;


        case 1:
            _qtabwidget_logging__To__LAST_SELECTED_row_INDEX
                .insert(tableWidget_LOGGING,
                        &a_model_CELL_index);
            break;
    }
}


void YRDBRUNTIMEVERIF_MainWindow::get_PRINT_OUT_TexTableString(QTableWidget  &current_QTable_Widget_Item,
                                                               QString       &texTable_IN_OUT,
                                                               int           row_MAX_TO_GO_export /* = -1 */)
{
    texTable_IN_OUT.append("\\begin{table*}[!htbp]\n"
                           "\\centering\n"
                           "\\resizebox{\\textwidth}{!}{\n"
                           "\\begin{tabular}"
                           "{|l|c|c|c|c|c|} \\hline");

    texTable_IN_OUT.append(" & & & & &			    \\\\ \n"
                           "\\textbf{ID}	        & 	 \n"
                           "\\textbf{time stamp}	& 	 \n"
                           "\\textbf{sql event log}	& 	 \n"
                           "\\textbf{source}	    & 	 \n"
                           "\\textbf{target} 	    & 	 \n"
                           "\\textbf{changed qty}   \\\\ \n"
                           "& & & & &				\\\\ \\hline \\hline \n");


	int rowCount = current_QTable_Widget_Item.rowCount();

	int columnCount = current_QTable_Widget_Item.columnCount();



    int MAX_TABLE_MODDEL_ROW_COUNT__to_export = rowCount;

	if (row_MAX_TO_GO_export > -1)
	{
        MAX_TABLE_MODDEL_ROW_COUNT__to_export = row_MAX_TO_GO_export;
	}



	bool color_this_row_grey = true;


	int LINE_COUNT_PER_PDF_PAGE = 41;


	QString cell_text;


    int TABLE_COUNT = qFloor(rowCount / LINE_COUNT_PER_PDF_PAGE);

    int current_table_count = 0;

	int current_pdf_page_line_count = 0;

	uint Visual_ID_counter = 0;

	//Tex table body
	for (int i = 0;
         i < MAX_TABLE_MODDEL_ROW_COUNT__to_export && current_pdf_page_line_count <= LINE_COUNT_PER_PDF_PAGE;
         ++i)
	{
        color_this_row_grey = (0 == i%2);

        if (color_this_row_grey)
        {
            texTable_IN_OUT.append(QString("\\rowcolor{yerothColorGray}"));
        }
        else
        {
            texTable_IN_OUT.append(QString("\\rowcolor{white}"));
        }


        //We add a cell for row numbering wioth an ID number.
        {
            ++Visual_ID_counter;

            QTableWidgetItem *an_item_ID = new QTableWidgetItem(QString::number(Visual_ID_counter));

            if (0 != an_item_ID)
            {
                YR_DB_RUNTIME_VERIF_Utils::handleTexTableItemText(columnCount,
                                                                  texTable_IN_OUT,
                                                                  0,
                                                                  an_item_ID->text());
            }
        }


        for (int j = 0; j < columnCount; ++j)
        {
            QTableWidgetItem *an_item = 0;

            an_item = current_QTable_Widget_Item.item(i, j);

            if (0 != an_item)
            {
                if (j != 4)
                {
                    cell_text = an_item->text();
                }
                else
                {
                    cell_text = GET_NUM_STRING(an_item->text().toDouble());

                }
            }

            YR_DB_RUNTIME_VERIF_Utils::handleTexTableItemText(columnCount,
                                                              texTable_IN_OUT,
                                                              j,
                                                              cell_text,
                                                              an_item);
        }

        if (i < rowCount - 1)
        {
            texTable_IN_OUT.append("\\hline\n");
        }


        ++current_pdf_page_line_count;


        if (LINE_COUNT_PER_PDF_PAGE - 1 == current_pdf_page_line_count)
        {
            current_pdf_page_line_count = 0;

            if (current_table_count < TABLE_COUNT)
            {
                texTable_IN_OUT.append("\\hline\n"
                                       "\\end{tabular}}\n"
                                       "\\end{table*}\n");

                texTable_IN_OUT.append("\\newpage\n");

                texTable_IN_OUT.append("\\begin{table*}[!htbp]\n"
                                       "\\centering\n"
                                       "\\resizebox{\\textwidth}{!}{\n"
                                       "\\begin{tabular}"
                                       "{|l|c|c|c|c|c|} \\hline");

                texTable_IN_OUT.append(" & & & & &		            \\\\ \n"
                                       "\\textbf{ID}			    & 	 \n"
                                       "\\textbf{time stamp}        & 	 \n"
                                       "\\textbf{sql event log}	    & 	 \n"
                                       "\\textbf{source}	        & 	 \n"
                                       "\\textbf{target} 	        & 	 \n"
                                       "\\textbf{changed qty}		\\\\ \n"
                                       "& & & & &			\\\\ \\hline \\hline \n");
            }

            ++current_table_count;

            if (current_table_count > 0)
            {
                LINE_COUNT_PER_PDF_PAGE = 57;
            }
        }

    } //for-i


    texTable_IN_OUT.append("\\hline\n"
                           "\\end{tabular}}\n"
                           "\\end{table*}\n");

}


void YRDBRUNTIMEVERIF_MainWindow::yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt(int a_row_FOR_pdf_printing_max /* = -1*/)
{
    int p = a_row_FOR_pdf_printing_max;

    YR_DB_RUNTIME_VERIF_ProgressBar(this)(this,
                                          &p,
                                          &YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt__POINTER_PARAMETER);
}


bool YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt_till_selected_SQL_event()
{
    int a_row_FOR_pdf_printing_max = -1;

    if (0 != _Last_SelectedRow_Row_INDEX)
    {
        a_row_FOR_pdf_printing_max = _Last_SelectedRow_Row_INDEX->row() + 1;
    }
    else
    {
        a_row_FOR_pdf_printing_max = -1;
    }

    return PRINT_event_log_excerpt(a_row_FOR_pdf_printing_max);
}


bool YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt(int a_row_FOR_pdf_printing_max /* = -1 */)
{
//	QDEBUG_STRING_OUTPUT_1("YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt");

    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item =
                                    Get_CURRENT_QTable_WIDGET();


    if (0 == current_QTable_Widget_Item)
    {
        QMessageBox::information(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
                                 QObject::tr("NO QTABLEWIDGET existing now"),
                                 QObject::tr("No event log data to print out !"));

        return false;
    }


	if (current_QTable_Widget_Item->rowCount() <= 0)
	{
		QMessageBox::information(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
				QObject::tr("Event log printing"),
				QObject::tr("No event log data to print out !"));

		return false;
	}


	QString EN_template_EVENT_LOG__tex_table;


	QString EN_template_EVENT_LOG__TexDocument =
        YR_DB_RUNTIME_VERIF_Utils::EN_template_EVENT_LOG_TEX_document;

	//QString factureDate(infoEntreprise.getVille_LATEX());

	//YR_DB_RUNTIME_VERIF_Utils::getCurrentSimplifiedDate(factureDate);


	get_PRINT_OUT_TexTableString(*current_QTable_Widget_Item,
                                 EN_template_EVENT_LOG__tex_table,
                                 a_row_FOR_pdf_printing_max);


	//qDebug() << EN_template_EVENT_LOG__tex_table;


	emit SIGNAL_INCREMENT_PROGRESS_BAR(18);


    EN_template_EVENT_LOG__TexDocument.append(EN_template_EVENT_LOG__tex_table)
                                      .append("\n")
                                      .append("\\end{document}");


	emit SIGNAL_INCREMENT_PROGRESS_BAR(50);


    EN_template_EVENT_LOG__TexDocument
        .replace("YRDBRUNTIMEVERIFSUBJECT",
                 "SQL Event log Excerpt");



    QString current_date;


    YR_DB_RUNTIME_VERIF_Utils::getCurrentSimplifiedDateWITHmilliseconds(current_date);


    EN_template_EVENT_LOG__TexDocument.replace("YRDBRUNTIMEVERIFPAPERSPEC", "a4paper");
    EN_template_EVENT_LOG__TexDocument.replace("YRDBRUNTIMEVERIFDATE", current_date);
    EN_template_EVENT_LOG__TexDocument.replace("YRDBRUNTIMEVERIFPRINTTIME", CURRENT_TIME_WITH_MILLISECONDS);



	emit SIGNAL_INCREMENT_PROGRESS_BAR(70);


    QString prefixFileName;

    prefixFileName.append(YR_DB_RUNTIME_VERIF_Utils::getUniquePrefixFileInTemporaryFilesDir("yr-db-runtime-verif-EVENT-LOG-"));
	//qDebug() << "++\n" << EN_template_EVENT_LOG__TexDocument;

	QFile tmpLatexFile(prefixFileName + "tex");

	if (tmpLatexFile.open(QFile::WriteOnly))
	{
		tmpLatexFile.write(EN_template_EVENT_LOG__TexDocument.toUtf8());
	}

	tmpLatexFile.close();

	QString pdfReceiptFileName = YRDBRUNTIMEVERIF_Process::compileLatex(prefixFileName);

	if (!pdfReceiptFileName.isEmpty())
	{
		YRDBRUNTIMEVERIF_Process::startPdfViewerProcess(pdfReceiptFileName);
	}

	emit SIGNAL_INCREMENT_PROGRESS_BAR(98);

	return true;
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


bool YRDBRUNTIMEVERIF_MainWindow::ON_action_export_as_CSV_till_selected_SQL_event()
{
    int a_row = -1;

    if (0 != _Last_SelectedRow_Row_INDEX)
    {
        a_row = _Last_SelectedRow_Row_INDEX->row() + 1;
    }
    else
    {
        a_row = -1;
    }

    return
        YR_DB_RUNTIME_VERIF_Utils::SAVE_AS_csv_file(*this,
                                                    *tableWidget_LOGGING,
                                                    "sql-event-log-listing-csv-format",
                                                    "SQL event log csv export",
                                                    a_row);
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_action_set_current_selected_SQL_event_as_filter_and_search()
{
    //THE USER MUST MANUALLY UNCHECKED "checkBox_ALL_STATE_SAFETY_PROPERTIES"
    //before any other search filtering could occur here.
    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex() &&
        checkBox_ALL_STATE_SAFETY_PROPERTIES->isChecked())
    {
        QMessageBox::warning(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
                             QObject::tr("(1) A RUNTIME MONITOR is selected"),
                             QObject::tr("FIRST UNCHECKED checkbox near combobox \"runtime monitor name\" !"));

        ON_BUTON_Reset_pressed(true);

        return ;
    }


    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item =
                                    Get_CURRENT_QTable_WIDGET();


    if (0 == current_QTable_Widget_Item)
    {
        return;
    }


    if (current_QTable_Widget_Item->rowCount() <= 0)
    {
        return ;
    }


    int current_row = current_QTable_Widget_Item->currentRow();


    static const uint SIGNALItem_COLUMN = 1;


    QString current_selected_SQL_event_text;


    QTableWidgetItem *an_item =
        current_QTable_Widget_Item->item(current_row,
                                         SIGNALItem_COLUMN);

    if (0 != an_item)
    {
        current_selected_SQL_event_text = an_item->text();

        comboBox_global_filtering->find_AND_SET_CURRENT_INDEX(QString("sql event log"));

        lineEdit_SQL_event_filtering->setText(current_selected_SQL_event_text);

        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(current_selected_SQL_event_text);
    }
}


void YRDBRUNTIMEVERIF_MainWindow::SOFT_Reset_selected()
{
    lineEdit_SQL_event_filtering->clear();

    lineEdit_FILTERING_COUNT->clear();


    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item = Get_CURRENT_QTable_WIDGET();

    if (0 != current_QTable_Widget_Item)
    {
        current_QTable_Widget_Item->CLEAR_FILTERING();
    }
}


void YRDBRUNTIMEVERIF_MainWindow::ON_BUTON_Reset_pressed(bool soft /* = false */)
{
    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item =
                                        Get_CURRENT_QTable_WIDGET();

    comboBox_global_filtering->setCurrentIndex(0);

    comboBox_SQL_event_filtering->setCurrentIndex(0);

    lineEdit_SQL_event_filtering->clear();

    lineEdit_FILTERING_COUNT->clear();

    if (!soft)
    {
        if (0 != current_QTable_Widget_Item)
        {
            current_QTable_Widget_Item->CLEAR_FILTERING();
        }
    }
}


void YRDBRUNTIMEVERIF_MainWindow::ON_BUTON_Filter_pressed()
{
    //THE USER MUST MANUALLY UNCHECKED "checkBox_ALL_STATE_SAFETY_PROPERTIES"
    //before any other search filtering could occur here.
    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex() &&
        checkBox_ALL_STATE_SAFETY_PROPERTIES->isChecked())
    {
        QMessageBox::warning(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
                             QObject::tr("(2) A RUNTIME MONITOR is selected"),
                             QObject::tr("FIRST UNCHECKED checkbox near combobox \"runtime monitor name\" !"));

        ON_BUTON_Reset_pressed(true);

        return ;
    }


    ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(lineEdit_SQL_event_filtering->text().trimmed());
}


void YRDBRUNTIMEVERIF_MainWindow::
		ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item)
{
	if (0 != aQTable_widget_item                            &&
        1 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
	{
		QString LOGGING_INFO = _MAP_dbsqlevent__TO__cppfileinfo.value(aQTable_widget_item->row());

		YRDBRUNTIMEVERIF_Logging_Info a_logging_info(LOGGING_INFO);

		tableWidget_LOGGING_2
			->ADD_ITEM_2(QString("%1:%2")
							.arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
								 a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));


        if (a_logging_info.IS_ERROR_EVENT_LOGGING())
        {
            comboBox_RUNTIME_MONITOR_NAME_Logging->setVisible(true);
        }
        else
        {
            comboBox_RUNTIME_MONITOR_NAME_Logging->setVisible(false);
        }


        SET_CURRENT_RUNTIME_MONITOR_name(a_logging_info.A_RUNTIME_MONITOR_name);
	}
	else
	{
		tableWidget_LOGGING_2->ADD_ITEM_2(QString("no source file info:-1"));
	}
}


void YRDBRUNTIMEVERIF_MainWindow::
		ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *aQTable_widget_item /* = 0 */)
{
    QString LOGGING_INFO;

    if (0 != aQTable_widget_item)
    {
        if (_pushButton_lecteur_de_code_barres_JUST_CLICKED)
        {
            _pushButton_lecteur_de_code_barres_JUST_CLICKED = false;

            int current_row_BE_PRESSED_with_a_hidden_button =
                GET_QTABLEWIDGET_CURRENT_ROW_TO_Select(0);

            LOGGING_INFO =
                _MAP_dbsqlERRORevent__TO__cppfileinfo
                    .value(current_row_BE_PRESSED_with_a_hidden_button);

            YRDBRUNTIMEVERIF_Logging_Info a_logging_info(LOGGING_INFO);

            set_SQL_current_recovered_query_string
                (a_logging_info.RECOVERY_SQL_string__ON_ERROR__accepting_state,
                 a_logging_info.timestamp);
        }
        else
        {
            set_SQL_current_recovered_query_string("", "");
        }


        if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
        {
            LOGGING_INFO = _MAP_dbsqlERRORevent__TO__cppfileinfo
                                .value(GET_QTABLEWIDGET_CURRENT_ROW_TO_Select(0));

            YRDBRUNTIMEVERIF_Logging_Info a_logging_info(LOGGING_INFO);

            if (is_CURRENT_runtime_monitor_name_Filtered())
            {
                if (!YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseSensitive(a_logging_info.A_RUNTIME_MONITOR_name,
                                                                      GET_CURRENT_RUNTIME_MONITOR_name()))
                {
                    return ;
                }
            }


            tableWidget_LOGGING_ERROR_SOURCE_LOCATION
                ->ADD_ITEM_2(QString("%1:%2")
                             .arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
                                  a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));

            set_SQL_current_recovered_query_string
                (a_logging_info.RECOVERY_SQL_string__ON_ERROR__accepting_state,
                 a_logging_info.timestamp);


            tableWidget_LOGGING_4->setVisible(true);
            tableWidget_LOGGING_PRECONDITIONS->setVisible(true);
            tableWidget_LOGGING_postconditions->setVisible(true);
            tableWidget_LOGGING_guarded_condition_expression->setVisible(true);


            setCurrentRuntimeMonitorNameVisible(true);


            YRDBRUNTIMEVERIF_MainWindow::
                SET__foregroundcolor__ON__accepting_state(aQTable_widget_item->row(),
                        tableWidget_LOGGING_ERROR_EVENT,
                        Qt::white);

            //tableWidget_LOGGING_2 ONLY HAS A SINGLE ROW !
            YRDBRUNTIMEVERIF_MainWindow::
                SET__foregroundcolor__ON__accepting_state(tableWidget_LOGGING_ERROR_SOURCE_LOCATION->currentRow(),
                        tableWidget_LOGGING_ERROR_SOURCE_LOCATION);


            RUNTIME_MONITOR_name_TO_PRINT_DOT = a_logging_info.A_RUNTIME_MONITOR_name;


            if (RUNTIME_MONITOR_name_TO_PRINT_DOT.isEmpty())
            {
                actionVIEW_RUNTIME_monitor
                    ->setText(QString("NO runtime monitor to visualize in PDF form"));

                actionVIEW_RUNTIME_monitor->setVisible(false);
            }
            else
            {
                actionVIEW_RUNTIME_monitor
                    ->setText(QString("view runtime monitor (%1)")
                               .arg(RUNTIME_MONITOR_name_TO_PRINT_DOT));

                actionVIEW_RUNTIME_monitor->setVisible(true);
            }


            // 5. Runtime monitor name is set on the main window
            // only for SQL events that lead to an accepting
            // error state.
            SET_CURRENT_RUNTIME_MONITOR_name_ERROR_Logging(RUNTIME_MONITOR_name_TO_PRINT_DOT);


            tableWidget_LOGGING_4
                ->ADD_ITEM_3(QString("%1:%2:%3")
                             .arg(a_logging_info.A_PREVIOUS_STATE,
                                  a_logging_info.AN_ACCEPTING_STATE,
                                  a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE));


            tableWidget_LOGGING_PRECONDITIONS
                ->ADD_ITEM_1(a_logging_info.A_TRANSITION_precondition);


            tableWidget_LOGGING_postconditions
                ->ADD_ITEM_1(a_logging_info.A_TRANSITION_postcondition);


            tableWidget_LOGGING_guarded_condition_expression
                ->ADD_ITEM_2(QString("%1:%2")
                             .arg(a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression,
                                  a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression_VALUE));
        }
        else
        {
            tableWidget_LOGGING_ERROR_SOURCE_LOCATION
                ->ADD_ITEM_2(QString("no source file info:-1"));
        }
    }

}


//for combobox "comboBox_global_filtering"
void YRDBRUNTIMEVERIF_MainWindow::RESET_comboBox_SQL_event_filtering()
{
    comboBox_SQL_event_filtering->setCurrentIndex(0);

    QString lineEdit_SQL_event_filtering__CURRENT_text =
                lineEdit_SQL_event_filtering->text();

    SOFT_Reset_selected();

    //THE PREVIOUS COMMAND CLEARS content of "lineEdit_SQL_event_filtering"
    lineEdit_SQL_event_filtering->setText(lineEdit_SQL_event_filtering__CURRENT_text);
}


void YRDBRUNTIMEVERIF_MainWindow::
        RESET_comboBox_SQL_event_filtering(const QString &a_SQL_event_item)
{
    comboBox_SQL_event_filtering->setCurrentIndex(0);

    QString lineEdit_SQL_event_filtering__CURRENT_text =
                lineEdit_SQL_event_filtering->text();

    SOFT_Reset_selected();

    //THE PREVIOUS COMMAND CLEARS content of "lineEdit_SQL_event_filtering"
    lineEdit_SQL_event_filtering->setText(lineEdit_SQL_event_filtering__CURRENT_text);
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_QTABLEWIDGET_FILTER_ITEM_selected(const QString &a_SQL_event_item)
{
    //THE USER MUST MANUALLY UNCHECKED "checkBox_ALL_STATE_SAFETY_PROPERTIES"
    //before any other search filtering could occur here.
    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex() &&
        checkBox_ALL_STATE_SAFETY_PROPERTIES->isChecked())
    {
        QMessageBox::warning(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
                             QObject::tr("A RUNTIME MONITOR is selected"),
                             QObject::tr("FIRST UNCHECKED checkbox near combobox \"runtime monitor name\" !"));

        ON_BUTON_Reset_pressed(true);

        return ;
    }


    lineEdit_SQL_event_filtering->clear();

    if (a_SQL_event_item.isEmpty())
    {
        SOFT_Reset_selected();

        return ;
    }


    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item = Get_CURRENT_QTable_WIDGET();

    if (0 == current_QTable_Widget_Item)
    {
        return;
    }


    RESET_comboBox_global_filtering();


    //PREVIOUS COMMAND CLEARS resets of "comboBox_SQL_event_filtering"
    comboBox_SQL_event_filtering->find_AND_SET_CURRENT_INDEX(a_SQL_event_item);


    uint MATCHED_search = current_QTable_Widget_Item->FILTER_ITEM(a_SQL_event_item);


    lineEdit_FILTERING_COUNT->setText(QString::number(MATCHED_search));
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(const QString &a_SourceSUT__OR__SQLEvent__Text)
{
    if (a_SourceSUT__OR__SQLEvent__Text.isEmpty())
    {
        return ;
    }


    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item =
                                        Get_CURRENT_QTable_WIDGET();

    if (0 == current_QTable_Widget_Item)
    {
        return;
    }


    current_QTable_Widget_Item->CLEAR_FILTERING();


    RESET_comboBox_SQL_event_filtering();


    //THE PREVIOUS COMMAND CLEARS content of "lineEdit_SQL_event_filtering"
    lineEdit_SQL_event_filtering->setText(a_SourceSUT__OR__SQLEvent__Text);


    uint MATCHED_search = 0;

    if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(comboBox_global_filtering->currentText(),
                                                           QString("source")))
    {
        MATCHED_search = current_QTable_Widget_Item->FILTER__SUT_SOURCE__ITEM(a_SourceSUT__OR__SQLEvent__Text);
    }
    else if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(comboBox_global_filtering->currentText(),
                                                                QString("sql event log")))
    {
        MATCHED_search = current_QTable_Widget_Item->FILTER_ITEM(a_SourceSUT__OR__SQLEvent__Text,
                                                                 true);
    }


    lineEdit_FILTERING_COUNT->setText(QString::number(MATCHED_search));
}


void YRDBRUNTIMEVERIF_MainWindow::ACTION_USER_GUIDE_method()
{
	QStringList progArguments;

	QProcess aProcess;

	progArguments << "/usr/share/doc/yr-db-runtime-verif/YEROTH_QVGE.pdf";

    YRDBRUNTIMEVERIF_Process::startDetached
            (aProcess,
             YR_DB_RUNTIME_VERIF_Config::pathToPdfReader,
             progArguments);
}


YRDBRUNTIMEVERIF_TableWidget* YRDBRUNTIMEVERIF_MainWindow::Get_CURRENT_QTable_WIDGET()
{
    YRDBRUNTIMEVERIF_TableWidget *current_QTable_Widget_Item = 0;

    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        current_QTable_Widget_Item = tableWidget_LOGGING_ERROR_EVENT;
    }
    else if (1 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        current_QTable_Widget_Item = tableWidget_LOGGING;
    }


    return current_QTable_Widget_Item;
}


void YRDBRUNTIMEVERIF_MainWindow::setCurrentRuntimeMonitorNameVisible(bool aVisibleValue)
{
    tableWidget_LOGGING_ERROR_SOURCE_LOCATION->setVisible(aVisibleValue);

    label_RUNTIME_MONITOR_VERIFIER_TESTER->setVisible(aVisibleValue);

    comboBox_RUNTIME_MONITOR_NAME->setVisible(aVisibleValue);
}


void YRDBRUNTIMEVERIF_MainWindow::
        contextMenuEvent(QContextMenuEvent *event)
{
    uint VISIBLE_unique_row_count = 0;


    if (0 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        VISIBLE_unique_row_count = _visible_ERROR_row_counter;
    }
    else if (1 == tabWidget_SQL_ERROR_EVENT_LOGGING->currentIndex())
    {
        VISIBLE_unique_row_count = _visible_row_counter;
    }


    if (VISIBLE_unique_row_count > 0)
    {
        QMenu menu(this);
        menu.addAction(actionExport_as_CSV_till_selected_SQL_event);
        menu.addAction(actionPRINT_event_log_FULL);
        menu.addAction(actionPRINT_event_log_excerpt_till_selected_SQL_event);
        menu.addAction(action_save_to_csv_format_sheet);
        menu.addAction(actionSet_current_selected_SQL_event_as_filter_and_search);
        menu.exec(event->globalPos());
    }
}


