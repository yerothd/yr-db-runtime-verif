/*
 * yr-db-runtime-verif-setup-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_

#include "../../ui_yr-db-runtime-verif-setup-window.h"


#include "src/utils/yr-db-runtime-verif-LOGGING-INFO.hpp"

#include "src/utils/yr-db-runtime-verif-qmap.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


class YR_DB_RUNTIME_VERIF_Monitor;


class YRDBRUNTIMEVERIF_SetupWindow : public QMainWindow,
									 public Ui_YRDBRUNTIMEVERIF_SetupWindow
{
	Q_OBJECT

public:

	YRDBRUNTIMEVERIF_SetupWindow();

    inline virtual ~YRDBRUNTIMEVERIF_SetupWindow()
    {
    }


public slots:

	inline virtual void yr_show()
	{
		setVisible(true);
	}

	inline virtual void yr_close()
	{
		close();
	}

	virtual void set_connection_DBUS_status(QString	message_STATUS,
											bool 	error_not_connected = false);

protected slots:

	virtual void ON_actionRETURN_TO_console_trigerred();

	inline virtual void ACTION_EXIT_method()
	{
		yr_close();
	}

    inline virtual void help()
    {
    }
};

#endif /* _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_ */
