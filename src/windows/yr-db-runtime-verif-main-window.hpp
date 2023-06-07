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

public slots:

	virtual void Set_YRDBRUNTIMEVERIF_Logging_Info(uint row_number, QString logging_info);

	virtual YRDBRUNTIMEVERIF_Logging_Info *Get_YRDBRUNTIMEVERIF_Logging_Info(uint row_number);

	inline virtual void set_connection_DBUS_status(QString message_STATUS)
	{
    	label_display_yr_db_runtime_verifier_connection_STATUS
			->setText(message_STATUS);
	}

protected slots:

	virtual void ON_QTABLEWIDGET_ITEM_pressed(QTableWidgetItem *aQTable_widget_item);

	virtual void ACTION_USER_GUIDE_method();

	inline virtual void ACTION_EXIT_method()
	{
		close();
	}

    inline virtual void about()
    {
    }

    inline virtual void help()
    {
    }

private:

    YRDBRUNTIMEVERIF_QMap _MAP_dbsqlevent__TO__cppfileinfo;
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
