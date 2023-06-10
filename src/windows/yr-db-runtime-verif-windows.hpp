/*
 * yr-db-runtime-verif-windows.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_
#define _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_

#include <QtCore/QObject>


#include "src/windows/yr-db-runtime-verif-setup-window.hpp"
#include "src/windows/yr-db-runtime-verif-main-window.hpp"


class QString;
class QDesktopWidget;


class YRDBRUNTIMEVERIF_Windows : public QObject
{
	Q_OBJECT

public:

	inline YRDBRUNTIMEVERIF_Windows(QDesktopWidget *desktopWidget)
	:_yrdbruntimeverif_setup_Window(0),
	 _yrdbruntimeverif_main_Window(0),
	 _desktopWidget(desktopWidget)
	{
	}

	virtual ~YRDBRUNTIMEVERIF_Windows();

	virtual void createAll_YRDBRUNTIMEVERIF_Windows();

	virtual void CLOSE_allWindows();


    YRDBRUNTIMEVERIF_SetupWindow *_yrdbruntimeverif_setup_Window;

    YRDBRUNTIMEVERIF_MainWindow *_yrdbruntimeverif_main_Window;

private:

	inline YRDBRUNTIMEVERIF_Windows()
	:_yrdbruntimeverif_setup_Window(0),
	 _yrdbruntimeverif_main_Window(0),
	 _desktopWidget(0)
	{
	}


    //QPoint *_currentPosition;

    QDesktopWidget *_desktopWidget;
};

#endif /* _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_ */
