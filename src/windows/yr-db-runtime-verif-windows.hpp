/*
 * yr-db-runtime-verif-windows.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_
#define _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_

#include <QtCore/QObject>

#include "src/windows/yr-db-runtime-verif-main-window.hpp"


class QString;
class QDesktopWidget;


class YRDBRUNTIMEVERIF_Windows : public QObject
{
	Q_OBJECT

public:

	inline YRDBRUNTIMEVERIF_Windows(QDesktopWidget *desktopWidget)
	:_yrdbruntimeverif_main_Window(0),
	 _desktopWidget(desktopWidget)
	{
	}

	inline virtual ~YRDBRUNTIMEVERIF_Windows()
	{
		delete _yrdbruntimeverif_main_Window;
	}

    void createAll_YRDBRUNTIMEVERIF_Windows();

    void hideAllWindows();


    YRDBRUNTIMEVERIF_MainWindow *_yrdbruntimeverif_main_Window;

private:

	inline YRDBRUNTIMEVERIF_Windows()
	:_yrdbruntimeverif_main_Window(0),
	 _desktopWidget(0)
	{
	}


    //QPoint *_currentPosition;

    QDesktopWidget *_desktopWidget;
};

#endif /* _YR_DB_RUNTIME_VERIF_WINDOWS_HPP_ */
