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


    virtual void SET_CURRENT_RUNTIME_MONITOR_name(QString A_RUNTIME_MONITOR_name);


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


	static void SET__foregroundcolor__ON__accepting_state(uint 			row_number,
														  QTableWidget 	*a_table_widget,
														  QColor        a_color_to_SET = Qt::green);


	virtual void VIEW_current_RUNTIME_MONITOR();

    virtual void setCurrentRuntimeMonitorNameVisible(bool aVisibleValue);

    virtual inline void setLast_SelectedRow_Row_ID(const QModelIndex &a_model_CELL_index)
    {
        _Last_SelectedRow_Row_INDEX = &a_model_CELL_index;
    }


	virtual void get_PRINT_OUT_TexTableString(QTableWidget  &current_QTable_Widget_Item,
                                              QString       &texTable_IN_OUT,
                                              int           row_MAX_TO_GO_export = -1);


    inline virtual void yr_PRINT_with_PROGRESS_BAR_ON__event_log_excerpt_till_selected_SQL_event()
    {
        YR_DB_RUNTIME_VERIF_ProgressBar(this)(this,
                                              &YRDBRUNTIMEVERIF_MainWindow::PRINT_event_log_excerpt_till_selected_SQL_event);
    }


    virtual bool PRINT_event_log_excerpt_till_selected_SQL_event();


    virtual bool PRINT_event_log_excerpt(int a_row_FOR_pdf_printing_max = -1);


	virtual void ON_Configfuration_panel_window_trigerred();


    virtual bool ON_action_export_as_CSV_till_selected_SQL_event();


	virtual void ON_action_set_current_selected_SQL_event_as_filter_and_search();


	virtual void SOFT_Reset_selected();


	virtual void ON_BUTON_Reset_pressed();


	virtual inline void ON_BUTON_Filter_pressed()
	{
        ON_QTABLEWIDGET_FILTER_ITEM_Exact_GIVEN(lineEdit_SQL_event_filtering->text().trimmed());
	}


	virtual void ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item);


	virtual void ON_QTABLEWIDGET_ERROR_ITEM_pressed(QTableWidgetItem *aQTable_widget_item);


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
        comboBox_global_filtering->setCurrentIndex(0);
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

    virtual void contextMenuEvent(QContextMenuEvent *event);


public:

    static const QString QMESSAGE_BOX_STYLE_SHEET;

    QMap<QString, YR_DB_RUNTIME_VERIF_Monitor *> user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES;


private:


    uint                        _visible_ERROR_row_counter;

    uint                        _visible_row_counter;

    QString                     RUNTIME_MONITOR_name_TO_PRINT_DOT;

    const QModelIndex           *_Last_SelectedRow_Row_INDEX;

    YR_DB_RUNTIME_VERIF_Monitor	*_current_runtime_monitor_INSTANCE;

    YRDBRUNTIMEVERIF_QMap 		_MAP_dbsqlevent__TO__cppfileinfo;

    YRDBRUNTIMEVERIF_QMap 		_MAP_dbsqlERRORevent__TO__cppfileinfo;
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
