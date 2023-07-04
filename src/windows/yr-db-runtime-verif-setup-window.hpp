/*
 * yr-db-runtime-verif-setup-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_

#include "../../ui_yr-db-runtime-verif-setup-window.h"


#include "src/windows/yr-db-runtime-verif-COMMONS-window.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


class YRDBRUNTIMEVERIF_SetupWindow : public YRDBRUNTIMEVERIF_CommonsWindow,
									 public Ui_YRDBRUNTIMEVERIF_SetupWindow
{
	Q_OBJECT

public:

	YRDBRUNTIMEVERIF_SetupWindow();

    inline virtual ~YRDBRUNTIMEVERIF_SetupWindow()
    {
    }


public slots:

	virtual void set_connection_DBUS_status(QString	message_STATUS,
											bool 	error_not_connected = false);

protected slots:

	virtual void ON_actionRETURN_TO_console_trigerred();

};

#endif /* _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_ */
