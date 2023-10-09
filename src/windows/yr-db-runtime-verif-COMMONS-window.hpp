/*
 * yr-db-runtime-verif-COMMONS-window.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_COMMONS_WINDOW_HPP_
#define _YR_DB_RUNTIME_VERIF_COMMONS_WINDOW_HPP_


#include "src/utils/yr-db-runtime-verif-LOGGING-INFO.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>


class YRDBRUNTIMEVERIF_CommonsWindow : public QMainWindow
{
	Q_OBJECT

public:

	inline YRDBRUNTIMEVERIF_CommonsWindow()
	{
	}

    inline virtual ~YRDBRUNTIMEVERIF_CommonsWindow()
    {
    }

    virtual QToolBar &get_tool_bar() = 0;


signals:

    void SIGNAL_INCREMENT_PROGRESS_BAR(int countSuccess);


public slots:

	inline virtual void yr_show()
	{
		setVisible(true);
	}

	inline virtual void yr_close()
	{
		close();
	}


protected slots:

	virtual void ACTION_EXIT_method();

    inline virtual void help()
    {
    }
};

#endif /* _YR_DB_RUNTIME_VERIF_COMMONS_WINDOW_HPP_ */
