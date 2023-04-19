/*
 * yr-db-runtime-verif-logger.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-logger.hpp"

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include <QtCore/QDebug>
#include <QtCore/QFile>

//#define YEROTH_DEBUG_LOG

YR_DB_RUNTIME_VERIF_Logger::YR_DB_RUNTIME_VERIF_Logger(QString cppClassName, YEROTH_LOG_LEVEL logLevel):_logLevel(logLevel),
    _cppClassName(cppClassName),
    _qDebug(0), _logFile(0)
{
    _logFile = new QFile(YR_DB_RUNTIME_VERIF_Utils::getLogFileName());
    _qDebug = new QDebug(_logFile);
    if (!_logFile->open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug() << "[YerenLogger][YerenLogger] "
                 << "Could not create file " << YR_DB_RUNTIME_VERIF_Utils::
                 getLogFileName();
    }
}

YR_DB_RUNTIME_VERIF_Logger::~YR_DB_RUNTIME_VERIF_Logger()
{
    delete _logFile;
    delete _qDebug;
}

void YR_DB_RUNTIME_VERIF_Logger::debug(const char *cppMethodName, const char *msg)
{
    *_qDebug <<
             QString("DEBUG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                      CURRENT_TIME, _cppClassName,
                                                      cppMethodName).toStdString().
             c_str() << msg << "\n";

#ifdef YEROTH_DEBUG_LOG
    qDebug() <<
             QString("DEBUG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                      CURRENT_TIME, _cppClassName,
                                                      cppMethodName).toStdString().
             c_str() << msg;
#endif
}

void YR_DB_RUNTIME_VERIF_Logger::debug(const char *cppMethodName, QString msg)
{
    *_qDebug <<
             QString("DEBUG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                      CURRENT_TIME, _cppClassName,
                                                      cppMethodName).toStdString().
             c_str() << msg << "\n";

#ifdef YEROTH_DEBUG_LOG
    qDebug() <<
             QString("DEBUG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                      CURRENT_TIME, _cppClassName,
                                                      cppMethodName).toStdString().
             c_str() << msg;
#endif
}

void YR_DB_RUNTIME_VERIF_Logger::log(const char *cppMethodName, const char *msg)
{
    *_qDebug <<
             QString("LOG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                    CURRENT_TIME, _cppClassName,
                                                    cppMethodName).toStdString().
             c_str() << msg << "\n";

#ifdef YEROTH_DEBUG_LOG
    qDebug() <<
             QString("LOG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                    CURRENT_TIME, _cppClassName,
                                                    cppMethodName).toStdString().
             c_str() << msg;
#endif
}

void YR_DB_RUNTIME_VERIF_Logger::log(const char *cppMethodName, const QString msg)
{
    *_qDebug <<
             QString("LOG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                    CURRENT_TIME, _cppClassName,
                                                    cppMethodName).toStdString().
             c_str() << msg << "\n";

#ifdef YEROTH_DEBUG_LOG
    qDebug() <<
             QString("LOG | %1 %2 | %3 | %4 |").arg(GET_CURRENT_STRING_DATE,
                                                    CURRENT_TIME, _cppClassName,
                                                    cppMethodName).toStdString().
             c_str() << msg;
#endif
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (const
                                                                    char *s)
{
    *_qDebug << s;
    return *this;
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (QString
                                                                    s)
{
    *_qDebug << s;
    return *this;
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (bool s)
{
    *_qDebug << s;
    return *this;
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (int s)
{
    *_qDebug << s;
    return *this;
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (char s)
{
    *_qDebug << s;
    return *this;
}

YR_DB_RUNTIME_VERIF_Logger &YR_DB_RUNTIME_VERIF_Logger::operator<< (QByteArray s)
{
    *_qDebug << s;
    return *this;
}
