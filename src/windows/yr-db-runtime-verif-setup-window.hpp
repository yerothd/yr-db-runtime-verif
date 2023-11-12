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


    virtual void yr_show();


    inline virtual QToolBar &get_tool_bar()
    {
    	return *toolBar_SetupWindow_YR_DB_RUNTIME_VERIF;
    }


public slots:

    virtual void ON_STOP__logging__SUT_ACTIONS();


    virtual void ON_START__logging__SUT_ACTIONS();


    virtual void Set_A_SUT_comboBox_SUT_identification(QString &a_sut_identification)
    {
        comboBox_SUT_identification
            ->find_AND_SET_CURRENT_INDEX(a_sut_identification.trimmed());
    }


	virtual void set_connection_DBUS_status(QString	message_STATUS,
											bool 	error_not_connected = false);


protected slots:

    virtual void ON_choose_path_pdfReader();


    virtual void ON_actionRETURN_TO_console_trigerred();


    virtual void ON_pushButton_Reset_parameters_PRESSED();


	virtual void ON_pushButton_SAVE_parameters_PRESSED();
};

#endif /* _YR_DB_RUNTIME_VERIF_SETUP_WINDOW_HPP_ */
