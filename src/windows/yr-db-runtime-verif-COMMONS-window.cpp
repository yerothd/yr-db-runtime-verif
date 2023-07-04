/*
 * yr-db-runtime-verif-COMMONS-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "yr-db-runtime-verif-COMMONS-window.hpp"


#include "src/yr-db-runtime-verif-config.hpp"

#include "src/windows/yr-db-runtime-verif-windows.hpp"


void YRDBRUNTIMEVERIF_CommonsWindow::ACTION_EXIT_method()
{
    YRDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YR_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
    	ALL_WINDOWS_INSTANCE->CLOSE_allWindows();
    }

	close();
}
