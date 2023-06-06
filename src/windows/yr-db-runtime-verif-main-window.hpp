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

protected slots:

    inline virtual void about()
    {
    }

    inline virtual void help()
    {
    }
};

#endif /* _YR_DB_RUNTIME_VERIF_MAIN_WINDOW_HPP_ */
