/*
 * yr-db-runtime-verif-main-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-main-window.hpp"


#include <QtCore/QProcess>



YRDBRUNTIMEVERIF_MainWindow::YRDBRUNTIMEVERIF_MainWindow()
{
    setupUi(this);

    setFixedSize(width(), height());



    connect(actionExit,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_EXIT_method()));


    connect(actionUserGuide_PDF,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_USER_GUIDE_method()));


	setVisible(true);
}


void YRDBRUNTIMEVERIF_MainWindow::ACTION_USER_GUIDE_method()
{
	QStringList progArguments;

	QProcess aProcess;

	progArguments << "/usr/share/doc/yr-db-runtime-verif/YEROTH_QVGE.pdf";

	aProcess.startDetached("/usr/bin/evince",
						   progArguments);
}



