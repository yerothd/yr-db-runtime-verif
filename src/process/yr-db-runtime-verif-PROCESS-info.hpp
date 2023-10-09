/*
 * yr-db-runtime-verif-PROCESS-info.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_
#define _YR_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_


#include "src/process/yr-db-runtime-verif-PROCESS.hpp"


#include <QtCore/QString>


class YR_DB_RUNTIME_VERIF_Utils;
class YR_DB_RUNTIME_VERIF_Logger;

class YRDBRUNTIMEVERIF_ProcessInfo
{
public:


    inline YRDBRUNTIMEVERIF_ProcessInfo()
    {
    }

    inline ~YRDBRUNTIMEVERIF_ProcessInfo()
    {
    }

    static bool CHECK_WHETHER_DAEMON_PROCESS_IS_RUNNING(QString a_daemon_process_ID_STR,
    													QString executable_full_path,
    													YR_DB_RUNTIME_VERIF_Logger *logger = 0);
};


#endif /* _YR_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_ */
