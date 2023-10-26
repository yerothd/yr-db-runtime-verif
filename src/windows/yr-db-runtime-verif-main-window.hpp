/*
 * yr-db-runtime-verif-main-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_

#include "../../ui_yr-db-runtime-verif-main-window.h"


#include "src/widgets/yr-db-runtime-verif-progress-bar.hpp"

#include "src/windows/yr-db-runtime-verif-COMMONS-window.hpp"

#include "src/utils/yr-db-runtime-verif-qmap.hpp"


#include <QtGui/QContextMenuEvent>

#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


class YR_DB_RUNTIME_VERIF_Monitor;


class YRDBRUNTIMEVERIF_MainWindow : public YRDBRUNTIMEVERIF_CommonsWindow,
									public Ui_YRDBRUNTIMEVERIF_MainWindow
{
	Q_OBJECT


public:

	YRDBRUNTIMEVERIF_MainWindow();

    inline virtual ~YRDBRUNTIMEVERIF_MainWindow()
    {
    }

    inline virtual QToolBar &get_tool_bar()
    {
    	return *toolBar_mainWindow_YR_DB_RUNTIME_VERIF;
    }


    virtual void SELECT_row(uint a_row_selected);


    virtual inline void SET_CURRENT_RUNTIME_MONITOR_name(QString A_RUNTIME_MONITOR_name)
    {
        (!A_RUNTIME_MONITOR_name.isEmpty()) ?
            comboBox_RUNTIME_MONITOR_NAME_Logging->find_AND_SET_CURRENT_INDEX(A_RUNTIME_MONITOR_name.trimmed()) :
            NO_OPERATION;
    }


    virtual inline QString GET_CURRENT_RUNTIME_MONITOR_name()
    {
        return comboBox_RUNTIME_MONITOR_NAME->currentText();
    }


	virtual int ADD_ERROR_ITEM(QString                        TIMESTAMPtem,
                               QString                        SIGNALItem,
                               QString                        SOURCEItem,
                               QString                        TARGETItem,
                               QString                        changed_OR_modified_database_qty_Item,
                               YRDBRUNTIMEVERIF_Logging_Info  &a_logging_info);


	virtual int ADD_ITEM(QString                        TIMESTAMPtem,
						 QString                        SIGNALItem,
						 QString                        SOURCEItem,
						 QString                        TARGETItem,
						 QString                        changed_OR_modified_database_qty_Item,
						 YRDBRUNTIMEVERIF_Logging_Info  &a_logging_info);


	virtual void SET__CURRENT__RUNTIME__MONITOR
		(YR_DB_RUNTIME_VERIF_Monitor *a_current_runtime_monitor_INSTANCE);


	inline virtual YR_DB_RUNTIME_VERIF_Monitor *GET__CURRENT__RUNTIME__MONITOR()
	{
		return _current_runtime_monitor_INSTANCE;
	}


public slots:

	virtual void Set_YRDBRUNTIMEVERIF_Logging_Info(uint     row_number,
												   QString  logging_info);


	virtual YRDBRUNTIMEVERIF_Logging_Info *Get_YRDBRUNTIMEVERIF_Logging_Info(uint row_number);


	virtual void set_connection_DBUS_status(QString	message_STATUS,
											bool 	error_not_connected = false);


protected slots:

    bool export_csv_file();


    virtual bool set_SQL_current_recovered_query_string(QString SQL_QUERY_STRING,
                                                        QString TIMESTAMP = "");


    void set_CURRENT_TABWIDGET_ACTION_visible(bool a_value);


    virtual void filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS();


    virtual void UN__filter_All_RUNTIME_monitor__ERROR__SQL__EVENTS();


    void handle_checkBox_ALL_STATE_SAFETY_PROPERTIES_State_CHANGED(int aState);


    int GET_QTABLEWIDGET_CURRENT_ROW_TO_Select(int current_index);


    void handle_current_tab_changed(int current_index);


	static void SET__foregroundcolor__ON__accepting_state(uint 			row_number,
														  QTableWidget 	*a_table_widget,
														  QColor        a_color_to_SET = Qt::green);


    virtual inline void YR_on_progress_bar__VIEW_current_RUNTIME_MONITOR()
    {
        YR_DB_RUNTIME_VERIF_ProgressBar(this)(this,
                                              &YRDBRUNTIMEVERIF_MainWindow::VIEW_current_RUNTIME_MONITOR);
    }


	virtual void *VIEW_current_RUNTIME_MONITOR();


    virtual void setLast_SelectedRow_Row_ID(const QModelIndex &a_model_CELL_index);


	virtual void get_PRINT_OUT_TexTableString(QTableWidget  &current_QTable_Widget_Item,
                                              QString       &texTable_IN_OUT,
                                              int           row_MAX_TO_GO_export = -1);


    inline virtual void yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt_till_selected_SQL_event()
    {
        YR_DB_RUNTIME_VERIF_ProgressBar(this)(this,
                                              &YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt_till_selected_SQL_event);
    }


    virtual bool PRINT_event_log_excerpt_till_selected_SQL_event();


    virtual void yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt(int a_row_FOR_pdf_printing_max = -1);


    inline virtual void *PRINT_event_log_excerpt__POINTER_PARAMETER(int *a_row_FOR_pdf_printing_max)
    {
        (0 != a_row_FOR_pdf_printing_max) ?
                PRINT_event_log_excerpt(*a_row_FOR_pdf_printing_max) :
                PRINT_event_log_excerpt();
    }


    virtual bool PRINT_event_log_excerpt(int a_row_FOR_pdf_printing_max = -1);


	virtual void ON_Configfuration_panel_window_trigerred();


    virtual bool ON_action_export_as_CSV_till_selected_SQL_event();


	virtual void ON_action_set_current_selected_SQL_event_as_filter_and_search();


	virtual void SOFT_Reset_selected();


	virtual void ON_BUTON_Reset_pressed(bool soft = false);


    virtual void ON_BUTON_Filter_pressed();


	virtual void ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item);


	/*
	 * aQTable_widget_item is set to zero ('0') when the
	 * hidden button "pushButton_lecteur_de_code_barres"
	 * for showing SQL recovered query string
	 * is only shown by now.
     */
	virtual void ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *aQTable_widget_item = 0);


    //for combobox "comboBox_global_filtering"
    virtual void RESET_comboBox_SQL_event_filtering();


    virtual void RESET_comboBox_SQL_event_filtering(const QString &a_SQL_event_item);


    //for combobox "comboBox_global_filtering"
    virtual inline void RESET_comboBox_global_filtering()
    {
        comboBox_global_filtering->setCurrentIndex(0);
    }


    virtual inline void RESET_comboBox_global_filtering(const QString &a_SQL_event_item)
    {
        RESET_comboBox_global_filtering();
    }


    //for combobox "comboBox_SQL_event_filtering"
	virtual void ON_QTABLEWIDGET_FILTER_ITEM_selected(const QString &a_SQL_event_item);


    //for QLinedEdit "lineEdit_SQL_event_filtering"
    virtual void ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(const QString &a_SourceSUT__OR__SQLEvent__Text);



	virtual void ACTION_USER_GUIDE_method();


    inline virtual void about()
    {
    	QMessageBox::information(toolBar_mainWindow_YR_DB_RUNTIME_VERIF,
    							 "ABOUT THIS SOFTWARE (YR-DB-RUNTIME-VERIF)",
    							 QObject::tr("DEVELOPED by PROF. DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU."
                                             "\n\nAcknowledgments:\n"
                                             "1. Jan Peleska, VERIFIED SYSTEMS INTERNATIONAL GmbH\n"
                                             "2. Jan Peleska, UNIVERSITY OF BREMEN, BREMEN, GERMANY\n\n"
                                             "3. Patrick Lam, WATFORM, THE UNIVERSITY OF WATERLOO, ON, CANADA\n\n"
                                             "4. The Qt Company\n"));
    }


protected:

    virtual YRDBRUNTIMEVERIF_TableWidget *Get_CURRENT_QTable_WIDGET();


    virtual void setCurrentRuntimeMonitorNameVisible(bool aVisibleValue);


    virtual inline void set_CURRENT_runtime_monitor_name_Filtered(bool a_bool_value)
    {
        _CURRENT_runtime_monitor_name_Filtered = a_bool_value;
    }

    virtual inline bool is_CURRENT_runtime_monitor_name_Filtered()
    {
        return _CURRENT_runtime_monitor_name_Filtered;
    }


    virtual void contextMenuEvent(QContextMenuEvent *event);


public:

    static const QString QMESSAGE_BOX_STYLE_SHEET;

    QMap<QString, YR_DB_RUNTIME_VERIF_Monitor *> user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES;


private:

    bool                        _pushButton_lecteur_de_code_barres_JUST_CLICKED;

    bool                        _CURRENT_runtime_monitor_name_Filtered;

    uint                        _visible_ERROR_row_counter;

    uint                        _visible_row_counter;

    QString                     RUNTIME_MONITOR_name_TO_PRINT_DOT;

    const QModelIndex           *_Last_SelectedRow_Row_INDEX;

    YR_DB_RUNTIME_VERIF_Monitor	*_current_runtime_monitor_INSTANCE;

    /**
     * This is  used to keep selected row acroos
     * "tabWidget_SQL_ERROR_EVENT_LOGGING" QTABLEWIDGET.
     */
    QMap<YRDBRUNTIMEVERIF_TableWidget *, const QModelIndex *>
        _qtabwidget_logging__To__LAST_SELECTED_row_INDEX;

    YRDBRUNTIMEVERIF_QMap 		_MAP_dbsqlevent__TO__cppfileinfo;

    YRDBRUNTIMEVERIF_QMap 		_MAP_dbsqlERRORevent__TO__cppfileinfo;
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
