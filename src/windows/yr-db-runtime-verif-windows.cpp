/*
 * yr-db-runtime-verif-windows.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "src/windows/yr-db-runtime-verif-windows.hpp"


void YRDBRUNTIMEVERIF_Windows::createAll_YRDBRUNTIMEVERIF_Windows()
{
	_yrdbruntimeverif_main_Window = new YRDBRUNTIMEVERIF_MainWindow;

	_yrdbruntimeverif_main_Window->show();
}

