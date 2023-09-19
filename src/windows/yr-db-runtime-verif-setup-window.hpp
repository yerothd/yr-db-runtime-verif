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

    inline virtual QToolBar &get_tool_bar()
    {
    	return *toolBar_SetupWindow_YR_DB_RUNTIME_VERIF;
    }


public slots:

	virtual void set_connection_DBUS_status(QString	message_STATUS,
											bool 	error_not_connected = false);

protected slots:

    virtual void ON_choose_path_pdfReader();

    virtual void ON_actionRETURN_TO_console_trigerred();


	virtual void ON_pushButton_SAVE_parameters_PRESSED();


public:

    static QString YR_LINE_EDIT_PDF_FULL_PATH_READER;

};

#endif /* _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_ */
