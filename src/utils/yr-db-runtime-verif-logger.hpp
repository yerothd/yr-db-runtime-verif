/*
 * yr-db-runtime-verif-logger.hpp
 *
 *      Author: Dr.-Ing. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _SRC_YR_DB_RUNTIME_VERIF_LOGGER_HPP_
#define _SRC_YR_DB_RUNTIME_VERIF_LOGGER_HPP_

#include <QtCore/QString>

class QDebug;
class QFile;

class YR_DB_RUNTIME_VERIF_Logger
{
public:

    typedef enum _YEROTH_LOG_LEVEL
    {
        YEROTH_DEBUG = 0,
        YEROTH_LOG,
        YEROTH_WARN
    } YEROTH_LOG_LEVEL;

    YR_DB_RUNTIME_VERIF_Logger(QString cppClassName,
                               YEROTH_LOG_LEVEL logLevel = YEROTH_LOG);

    ~YR_DB_RUNTIME_VERIF_Logger();

    void debug(const char *cppMethodName, const char *msg = "");

    void debug(const char *cppMethodName, QString msg);

    void log(const char *cppMethodName, const char *msg = "");

    void log(const char *cppMethodName, QString msg);

    YR_DB_RUNTIME_VERIF_Logger &operator<< (const char *s);
    YR_DB_RUNTIME_VERIF_Logger &operator<< (QString s);
    YR_DB_RUNTIME_VERIF_Logger &operator<< (bool s);
    YR_DB_RUNTIME_VERIF_Logger &operator<< (int s);
    YR_DB_RUNTIME_VERIF_Logger &operator<< (char s);
    YR_DB_RUNTIME_VERIF_Logger &operator<< (QByteArray s);

    inline void *operator   new[](size_t size)
    {
        return malloc(size);
    }

    inline void *operator   new (size_t size)
    {
        return malloc(size);
    }

    inline void operator   delete[](void *ptr)
    {
        free(ptr);
    }

    inline void operator   delete[](void *ptr, size_t)
    {
        free(ptr);
    }

    inline void operator   delete (void *ptr)
    {
        free(ptr);
    }

    inline void operator   delete (void *ptr, size_t)
    {
        free(ptr);
    }

private:

    YEROTH_LOG_LEVEL _logLevel;

    QString _cppClassName;

    QDebug *_qDebug;
    QFile *_logFile;
};


#endif //_SRC_YR_DB_RUNTIME_VERIF_LOGGER_HPP_
