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



QString YRDBRUNTIMEVERIF_SetupWindow::YR_LINE_EDIT_PDF_FULL_PATH_READER("/usr/bin/evince");



YRDBRUNTIMEVERIF_SetupWindow::YRDBRUNTIMEVERIF_SetupWindow()
{
	setupUi(this);

	setFixedSize(width(), height());



	lineEdit_pdf_reader_full_path
        ->setText(YRDBRUNTIMEVERIF_SetupWindow::YR_LINE_EDIT_PDF_FULL_PATH_READER);



    pushButton_choose_pdfReader->enable(this, SLOT(ON_choose_path_pdfReader()));


	pushButton_SAVE_parameters->enable(this, SLOT(ON_pushButton_SAVE_parameters_PRESSED()));



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


void YRDBRUNTIMEVERIF_SetupWindow::ON_choose_path_pdfReader()
{
    QString pdfReaderFilePath =
    		QFileDialog::getOpenFileName(this,
    									 QObject::tr("select a full path to a Pdf reader"),
										 QString::null,
										 QString::null);

    if (!pdfReaderFilePath.isEmpty())
    {
        lineEdit_pdf_reader_full_path->setText(pdfReaderFilePath);
    }
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


void YRDBRUNTIMEVERIF_SetupWindow::ON_pushButton_SAVE_parameters_PRESSED()
{
    QString msgEnregistrer = QObject::tr("Save current settings ?");

    if (QMessageBox::Ok ==
            QMessageBox::question(this,
                                  QObject::tr("save current YR-DB-RUNTIME-VERIF GUI settings"),
                                  msgEnregistrer,
                                  QMessageBox::Cancel,
                                  QMessageBox::Ok))
    {
        YRDBRUNTIMEVERIF_SetupWindow::YR_LINE_EDIT_PDF_FULL_PATH_READER =
        lineEdit_pdf_reader_full_path->text();
    }
}



