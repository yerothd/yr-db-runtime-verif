/*
 * yr-db-runtime-verif-main-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_

#include "../../ui_yr-db-runtime-verif-main-window.h"


#include "src/utils/yr-db-runtime-verif-LOGGING-INFO.hpp"

#include "src/utils/yr-db-runtime-verif-qmap.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


class YR_DB_RUNTIME_VERIF_Monitor;


class YRDBRUNTIMEVERIF_MainWindow : public QMainWindow,
									public Ui_YRDBRUNTIMEVERIF_MainWindow
{
	Q_OBJECT

public:

	YRDBRUNTIMEVERIF_MainWindow();

    inline virtual ~YRDBRUNTIMEVERIF_MainWindow()
    {
    }

    inline virtual void SET_CURRENT_RUNTIME_MONITOR_name(QString A_RUNTIME_MONITOR_name)
    {
    	comboBox_RUNTIME_MONITOR_VERIFIER_TESTER
			->find_AND_SET_CURRENT_INDEX(A_RUNTIME_MONITOR_name);
    }

	virtual int ADD_ITEM(QString TIMESTAMPtem,
						 QString SIGNALItem,
						 QString SOURCEItem,
						 QString TARGETItem,
						 QString changed_OR_modified_database_qty_Item,
						 YRDBRUNTIMEVERIF_Logging_Info &a_logging_info);

	virtual void SET__CURRENT__RUNTIME__MONITOR
		(YR_DB_RUNTIME_VERIF_Monitor *a_current_runtime_monitor_INSTANCE);

	inline virtual YR_DB_RUNTIME_VERIF_Monitor *GET__CURRENT__RUNTIME__MONITOR()
	{
		return _current_runtime_monitor_INSTANCE;
	}


public slots:

	virtual void Set_YRDBRUNTIMEVERIF_Logging_Info(uint row_number,
												   QString logging_info);

	virtual YRDBRUNTIMEVERIF_Logging_Info *Get_YRDBRUNTIMEVERIF_Logging_Info(uint row_number);

	inline virtual void set_connection_DBUS_status(QString message_STATUS)
	{
    	label_display_yr_db_runtime_verifier_connection_STATUS
			->setText(message_STATUS);
	}

protected slots:

	static void SET__foregroundcolor__ON__accepting_state(uint 			row_number,
														  QTableWidget 	*a_table_widget);

	virtual void VIEW_current_RUNTIME_MONITOR();

	virtual void ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item);

	virtual void ACTION_USER_GUIDE_method();

	inline virtual void ACTION_EXIT_method()
	{
		close();
	}

    virtual void about();

    inline virtual void help()
    {
    }

private:

    static const QString QMESSAGE_BOX_STYLE_SHEET;


    YR_DB_RUNTIME_VERIF_Monitor	*_current_runtime_monitor_INSTANCE;

    YRDBRUNTIMEVERIF_QMap 		_MAP_dbsqlevent__TO__cppfileinfo;
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
