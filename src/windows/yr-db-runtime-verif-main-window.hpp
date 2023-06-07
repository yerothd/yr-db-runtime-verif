/*
 * yr-db-runtime-verif-main-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_

#include "../../ui_yr-db-runtime-verif-main-window.h"


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

	virtual int ADD_ITEM(QString TIMESTAMPtem,
						 QString SIGNALItem,
						 QString SOURCEItem,
						 QString TARGETItem,
						 QString changed_OR_modified_database_qty_Item,
						 QString A_CPP_FILE_NAME,
						 QString A_CPP_FILE_LINE_NUMBER);

public slots:

	inline virtual void set_connection_DBUS_status(QString message_STATUS)
	{
    	label_display_yr_db_runtime_verifier_connection_STATUS
			->setText(message_STATUS);
	}

protected slots:

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

    QMap<uint, QString> _MAP_dbsqlevent__TO__cppfileinfo;
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
