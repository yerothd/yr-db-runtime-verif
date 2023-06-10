/*
 * yr-db-runtime-verif-setup-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "src/windows/yr-db-runtime-verif-setup-window.hpp"


#include "src/yr-db-runtime-verif-config.hpp"

#include "src/windows/yr-db-runtime-verif-windows.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


YRDBRUNTIMEVERIF_SetupWindow::YRDBRUNTIMEVERIF_SetupWindow()
{
	setupUi(this);

	setFixedSize(width(), height());


    connect(actionExit,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_EXIT_method()));

    connect(actionRETURN_TO_console,
    		SIGNAL(triggered()),
			this,
            SLOT(ON_actionRETURN_TO_console_trigerred()));
}


void YRDBRUNTIMEVERIF_SetupWindow::
		set_connection_DBUS_status(QString  message_STATUS,
								   bool 	error_not_connected /* = false */)
{

}


void YRDBRUNTIMEVERIF_SetupWindow::ON_actionRETURN_TO_console_trigerred()
{
    YRDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YR_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window->yr_show();
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_setup_Window->yr_close();
    }
}



