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
:_visible_row_counter(0),
 _SHOW_ONLY_SQL_EVENT_ERRORS(true),
 _Last_SelectedRow_Row_INDEX(0),
 _current_runtime_monitor_INSTANCE(0)
{
    setupUi(this);

    setFixedSize(width(), height());


	toolBar_mainWindow_YR_DB_RUNTIME_VERIF
		->setStyleSheet(QMESSAGE_BOX_STYLE_SHEET);


    actionVIEW_RUNTIME_monitor->setVisible(false);

    actionPRINT_event_log_excerpt_till_selected_SQL_event->setVisible(false);

    actionPRINT_event_log_FULL->setVisible(false);

    action_save_to_csv_format_sheet->setVisible(false);

    actionExport_as_CSV_till_selected_SQL_event->setVisible(false);

    actionSet_current_selected_SQL_event_as_filter_and_search->setVisible(false);

    actionStop_logging_only_error_SQL_events_shown->setVisible(false);

    actionStart_log_of_ALL_SQL_events->setVisible(true);;



    comboBox_global_filtering->addItem("");
    comboBox_global_filtering->addItem("sql event log");
    comboBox_global_filtering->addItem("source");



    comboBox_SQL_event_filtering->addItem("");
    comboBox_SQL_event_filtering->addItem("DELETE");
    comboBox_SQL_event_filtering->addItem("UPDATE");
    comboBox_SQL_event_filtering->addItem("SELECT");
    comboBox_SQL_event_filtering->addItem("INSERT");


    setCurrentRuntimeMonitorNameVisible(false);


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


    tableWidget_LOGGING_4->setVisible(false);
    tableWidget_LOGGING_PRECONDITIONS->setVisible(false);
    tableWidget_LOGGING_postconditions->setVisible(false);
    tableWidget_LOGGING_guarded_condition_expression->setVisible(false);

    setCurrentRuntimeMonitorNameVisible(false);


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


    connect(actionStart_log_of_ALL_SQL_events,
            SIGNAL(triggered()),
            this,
            SLOT(ON_actionStart_log_of_ALL_SQL_events()));


    connect(actionStop_logging_only_error_SQL_events_shown,
            SIGNAL(triggered()),
            this,
            SLOT(ON_actionStop_logging_only_error_SQL_events_shown()));



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
            SLOT(VIEW_current_RUNTIME_MONITOR()));



    connect(actionPRINT_event_log_excerpt_till_selected_SQL_event,
    		SIGNAL(triggered()),
			this,
            SLOT(yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt_till_selected_SQL_event()));


    connect(actionPRINT_event_log_FULL,
    		SIGNAL(triggered()),
			this,
            SLOT(PRINT_event_log_excerpt()));



    // USEFUL TO UPDATE sql event information WHEN
    // actions from context menu are called from a cell.
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
    connect(tableWidget_LOGGING,
    		SIGNAL(itemChanged(QTableWidgetItem *)),
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


int YRDBRUNTIMEVERIF_MainWindow::
				ADD_ITEM(QString                        TIMESTAMPtem,
						 QString                        SIGNALItem,
						 QString                        SOURCEItem,
						 QString                        TARGETItem,
						 QString                        changed_OR_modified_database_qty_Item,
						 YRDBRUNTIMEVERIF_Logging_Info  &a_logging_info,
						 bool                           SHOW_ERROR_FIRST_events_NOT_SHOWN_ALREADY /* = false */)
{
    if (_visible_row_counter > 0)
    {
        actionVIEW_RUNTIME_monitor->setVisible(true);

        actionPRINT_event_log_excerpt_till_selected_SQL_event->setVisible(true);

        actionPRINT_event_log_FULL->setVisible(true);

        action_save_to_csv_format_sheet->setVisible(true);

        actionExport_as_CSV_till_selected_SQL_event->setVisible(true);

        actionSet_current_selected_SQL_event_as_filter_and_search->setVisible(true);
    }
    else
    {
        actionVIEW_RUNTIME_monitor->setVisible(false);

        actionPRINT_event_log_excerpt_till_selected_SQL_event->setVisible(false);

        actionPRINT_event_log_FULL->setVisible(false);

        action_save_to_csv_format_sheet->setVisible(false);

        actionExport_as_CSV_till_selected_SQL_event->setVisible(false);

        actionSet_current_selected_SQL_event_as_filter_and_search->setVisible(false);
    }


    int last_current_row_nr = 0;

    if (SHOW_ERROR_FIRST_events_NOT_SHOWN_ALREADY ||
        !_SHOW_ONLY_SQL_EVENT_ERRORS)
    {
        ++_visible_row_counter;

        if (_visible_row_counter >= 2999)
        {
            _visible_row_counter = 1;
        }

        last_current_row_nr =
            tableWidget_LOGGING->ADD_ITEM(TIMESTAMPtem,
                                          SIGNALItem,
                                          SOURCEItem,
                                          TARGETItem,
                                          changed_OR_modified_database_qty_Item);
    }


	QString logging_info = a_logging_info.toString();


	_MAP_dbsqlevent__TO__cppfileinfo.yr_insert_item(last_current_row_nr,
												  	logging_info);

    if (SHOW_ERROR_FIRST_events_NOT_SHOWN_ALREADY ||
        !_SHOW_ONLY_SQL_EVENT_ERRORS)
    {
        tableWidget_LOGGING_2
            ->ADD_ITEM_2(QString("%1:%2")
                            .arg(a_logging_info.A_CPP_SOURCE_FILE_NAME,
                                 a_logging_info.A_CPP_SOURCE_FILE_LINE_NUMBER));
    }


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
	Set_YRDBRUNTIMEVERIF_Logging_Info(uint row_number,
									  QString logging_info)
{
	_MAP_dbsqlevent__TO__cppfileinfo.insert(row_number, logging_info);

	YRDBRUNTIMEVERIF_Logging_Info a_logging_info(logging_info);

	if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
			("True", a_logging_info.AN_ACCEPTING_STATE_is_error_state_VALUE))
	{
        //TODO: Call ADD_ITEM here so to complement logging information
        //on an accepting error state.
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
    YR_DB_RUNTIME_VERIF_Monitor *a_to_print_DOT_FORMAT_runtime_monitor =
        user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES
            .value(RUNTIME_MONITOR_name_TO_PRINT_DOT);


	if (0 != a_to_print_DOT_FORMAT_runtime_monitor)
	{
		QString DOT_FORMAT =
				a_to_print_DOT_FORMAT_runtime_monitor->print_TO_dot_FILE(true);
	}
}


void YRDBRUNTIMEVERIF_MainWindow::setCurrentRuntimeMonitorNameVisible(bool aVisibleValue)
{
    tableWidget_LOGGING_2->setVisible(aVisibleValue);

    label_RUNTIME_MONITOR_VERIFIER_TESTER->setVisible(aVisibleValue);

    comboBox_RUNTIME_MONITOR_NAME->setVisible(aVisibleValue);
}


void YRDBRUNTIMEVERIF_MainWindow::get_PRINT_OUT_TexTableString(QString &texTable_IN_OUT,
                                                               int     row_MAX_TO_GO_export /* = -1 */)
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


	int rowCount = tableWidget_LOGGING->rowCount();

	int columnCount = tableWidget_LOGGING->columnCount();



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

            an_item = tableWidget_LOGGING->item(i, j);

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

    PRINT_event_log_excerpt(a_row_FOR_pdf_printing_max);
}


bool YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt(int a_row_FOR_pdf_printing_max /* = -1 */)
{
//	QDEBUG_STRING_OUTPUT_1("YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt");

	if (tableWidget_LOGGING->rowCount() <= 0)
	{
		QMessageBox::information(this,
				QObject::tr("Event log printing"),
				QObject::tr("No event log data to print out !"));

		return false;
	}


	QString EN_template_EVENT_LOG__tex_table;


	QString EN_template_EVENT_LOG__TexDocument =
        YR_DB_RUNTIME_VERIF_Utils::EN_template_EVENT_LOG_TEX_document;

	//QString factureDate(infoEntreprise.getVille_LATEX());

	//YR_DB_RUNTIME_VERIF_Utils::getCurrentSimplifiedDate(factureDate);


	get_PRINT_OUT_TexTableString(EN_template_EVENT_LOG__tex_table,
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

	return false;
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
    if (tableWidget_LOGGING->rowCount() <= 0)
    {
        return ;
    }

    int current_row = tableWidget_LOGGING->currentRow();

    static const uint SIGNALItem_COLUMN = 1;

    QString current_selected_SQL_event_text;

    QTableWidgetItem *an_item =
        tableWidget_LOGGING->item(current_row,
                                  SIGNALItem_COLUMN);

    if (0 != an_item)
    {
        current_selected_SQL_event_text = an_item->text();

        comboBox_global_filtering->find_AND_SET_CURRENT_INDEX(QString("sql event log"));

        lineEdit_SQL_event_filtering->setText(current_selected_SQL_event_text);

        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(current_selected_SQL_event_text);
    }
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_actionStart_log_of_ALL_SQL_events()
{
    _SHOW_ONLY_SQL_EVENT_ERRORS = false;

    actionStart_log_of_ALL_SQL_events->setVisible(false);

    actionStop_logging_only_error_SQL_events_shown->setVisible(true);
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_actionStop_logging_only_error_SQL_events_shown()
{
    _SHOW_ONLY_SQL_EVENT_ERRORS = true;

    actionStart_log_of_ALL_SQL_events->setVisible(true);

    actionStop_logging_only_error_SQL_events_shown->setVisible(false);
}


void YRDBRUNTIMEVERIF_MainWindow::SOFT_Reset_selected()
{
    lineEdit_SQL_event_filtering->clear();

    lineEdit_FILTERING_COUNT->clear();

    tableWidget_LOGGING->CLEAR_FILTERING();
}


void YRDBRUNTIMEVERIF_MainWindow::ON_BUTON_Reset_pressed()
{
    comboBox_global_filtering->setCurrentIndex(0);

    comboBox_SQL_event_filtering->setCurrentIndex(0);

    lineEdit_SQL_event_filtering->clear();

    lineEdit_FILTERING_COUNT->clear();

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


        QString CURRENT_RUNTIME_MONITOR_name__to__display_Now;


		if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive
				("True", a_logging_info.A_SQL_EVENT_LOG_guarded_condition_expression_VALUE))
		{
		    tableWidget_LOGGING_4->setVisible(true);
		    tableWidget_LOGGING_PRECONDITIONS->setVisible(true);
		    tableWidget_LOGGING_postconditions->setVisible(true);
            tableWidget_LOGGING_guarded_condition_expression->setVisible(true);

            setCurrentRuntimeMonitorNameVisible(true);


            // 3. Runtime monitor name is set on the main window
            // only for SQL events that lead to an accepting
            // error state.
            CURRENT_RUNTIME_MONITOR_name__to__display_Now =
                a_logging_info.A_RUNTIME_MONITOR_name;


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
            CURRENT_RUNTIME_MONITOR_name__to__display_Now.clear();


		    tableWidget_LOGGING_4->setVisible(false);
		    tableWidget_LOGGING_PRECONDITIONS->setVisible(false);
		    tableWidget_LOGGING_postconditions->setVisible(false);
		    tableWidget_LOGGING_guarded_condition_expression->setVisible(false);

		    setCurrentRuntimeMonitorNameVisible(false);
		}



        RUNTIME_MONITOR_name_TO_PRINT_DOT = CURRENT_RUNTIME_MONITOR_name__to__display_Now;



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



        // 4. Runtime monitor name is set on the main window
        // only for SQL events that lead to an accepting
        // error state.
        SET_CURRENT_RUNTIME_MONITOR_name(CURRENT_RUNTIME_MONITOR_name__to__display_Now);



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
		tableWidget_LOGGING_2->ADD_ITEM_2(QString("no source file info:-1"));
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
    lineEdit_SQL_event_filtering->clear();

    if (a_SQL_event_item.isEmpty())
    {
        SOFT_Reset_selected();

        return ;
    }

    RESET_comboBox_global_filtering();

    //PREVIOUS COMMAND CLEARS resets of "comboBox_SQL_event_filtering"
    comboBox_SQL_event_filtering->find_AND_SET_CURRENT_INDEX(a_SQL_event_item);

    uint MATCHED_search = tableWidget_LOGGING->FILTER_ITEM(a_SQL_event_item);

    lineEdit_FILTERING_COUNT->setText(QString::number(MATCHED_search));
}


void YRDBRUNTIMEVERIF_MainWindow::
        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(const QString &a_SourceSUT__OR__SQLEvent__Text)
{
    if (a_SourceSUT__OR__SQLEvent__Text.isEmpty())
    {
        return ;
    }


    tableWidget_LOGGING->CLEAR_FILTERING();

    RESET_comboBox_SQL_event_filtering();

    //THE PREVIOUS COMMAND CLEARS content of "lineEdit_SQL_event_filtering"
    lineEdit_SQL_event_filtering->setText(a_SourceSUT__OR__SQLEvent__Text);


    uint MATCHED_search = 0;

    if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(comboBox_global_filtering->currentText(),
                                                           QString("source")))
    {
        MATCHED_search = tableWidget_LOGGING->FILTER__SUT_SOURCE__ITEM(a_SourceSUT__OR__SQLEvent__Text);
    }
    else if (YR_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(comboBox_global_filtering->currentText(),
                                                                QString("sql event log")))
    {
        MATCHED_search = tableWidget_LOGGING->FILTER_ITEM(a_SourceSUT__OR__SQLEvent__Text,
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


void YRDBRUNTIMEVERIF_MainWindow::
        contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);


    if (_visible_row_counter > 0)
    {
        menu.addAction(actionExport_as_CSV_till_selected_SQL_event);

        menu.addAction(actionPRINT_event_log_FULL);

        menu.addAction(actionPRINT_event_log_excerpt_till_selected_SQL_event);

        menu.addAction(action_save_to_csv_format_sheet);

        menu.addAction(actionSet_current_selected_SQL_event_as_filter_and_search);
    }


    menu.addAction(actionStop_logging_only_error_SQL_events_shown);

    menu.addAction(actionStart_log_of_ALL_SQL_events);

    menu.exec(event->globalPos());
}


