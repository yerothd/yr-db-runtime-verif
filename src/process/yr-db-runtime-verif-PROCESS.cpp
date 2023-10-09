/*
 * yr-db-runtime-verif-PROCESS.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */


#include "yr-db-runtime-verif-PROCESS.hpp"

#include "src/windows/yr-db-runtime-verif-windows.hpp"

#include "src/process/yr-db-runtime-verif-PROCESS-info.hpp"


#include <QtCore/QThread>

#include <QtWidgets/QMessageBox>



bool YRDBRUNTIMEVERIF_Process::_yeroth_YR_DB_RUNTIME_VERIF_ProcessFilesSet(false);



QProcess *YRDBRUNTIMEVERIF_Process::_yr_db_runtime_verif_PROCESS(new QProcess);

QProcess *YRDBRUNTIMEVERIF_Process::_alertDeamonProcess(new QProcess);


bool YRDBRUNTIMEVERIF_Process::STOP_yr_db_runtime_verif()
{
	if (!_yeroth_YR_DB_RUNTIME_VERIF_ProcessFilesSet)
	{
		_yr_db_runtime_verif_PROCESS->setStandardErrorFile("/dev/null");

		_yr_db_runtime_verif_PROCESS->setStandardOutputFile("/dev/null");

		_yeroth_YR_DB_RUNTIME_VERIF_ProcessFilesSet = true;
	}

	QString msg;

	QStringList progArguments;

	progArguments << "/usr/bin/systemctl";

	progArguments << "stop";

	progArguments << "yr-db-runtime-verif";

	//We don't start this process with 'startDetached' so
	//the following call to function 'check_alert_daemon_process()'
	//works fine.

	YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(*_yr_db_runtime_verif_PROCESS,
											  "lxqt-sudo",
											  progArguments,
											  60000);

	return _yr_db_runtime_verif_PROCESS->waitForFinished(5000);
}


int YRDBRUNTIMEVERIF_Process::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const
                                                                      QString &
                                                                      program_executable_location_full_path,
                                                                      const
                                                                      QString &
                                                                      output_file_full_path,
                                                                      const
                                                                      QStringList
                                                                      &
                                                                      program_executable_args)
{
    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    QFile tmpFile(output_file_full_path);

    if (tmpFile.open(QFile::WriteOnly))
    {
        tmpFile.write(A_YEROTH_PROCESS.readAllStandardOutput().trimmed());
    }
    else
    {
        return -1;
    }

    int output_file_size = tmpFile.size();

    tmpFile.close();

    return output_file_size;
}


QString YRDBRUNTIMEVERIF_Process::compileLatex(QString prefixFileName)
{
    QStringList progArguments;

    progArguments << "-interaction";

    progArguments << "nonstopmode";

    progArguments << QString("%1tex").arg(prefixFileName);

    YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(YR_DB_RUNTIME_VERIF_Config::
                                              pathToPdfLatex(), progArguments,
                                              -1);

    QThread::sleep(0.3);

    YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(YR_DB_RUNTIME_VERIF_Config::
                                              pathToPdfLatex(), progArguments,
                                              -1);

    QThread::sleep(0.3);

    progArguments.clear();

    QString pdfResultFile = QString("%1pdf").arg(prefixFileName);

    return pdfResultFile;
}


QString YRDBRUNTIMEVERIF_Process::compileWITH_LUATEX_Latex(QString prefixFileName)
{
    QStringList progArguments;

    progArguments << "-interaction";

    progArguments << "nonstopmode";

    progArguments << QString("%1tex").arg(prefixFileName);

    YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(YR_DB_RUNTIME_VERIF_Config::
                                              pathToLualatex(), progArguments,
                                              -1);
    progArguments.clear();

    QString pdfResultFile = QString("%1pdf").arg(prefixFileName);

    return pdfResultFile;
}


QString YRDBRUNTIMEVERIF_Process::startPdfViewerProcess(QString aPDFFileName)
{
    QStringList progArguments(aPDFFileName);

    QProcess::startDetached(YR_DB_RUNTIME_VERIF_Config::pathToPdfReader,
                            progArguments, YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir);

    return aPDFFileName;
}


bool YRDBRUNTIMEVERIF_Process::startDetached(QProcess &aProcess,
                                     QString programFileAbsolutePath,
                                     QStringList programArguments)
{
    aProcess.setWorkingDirectory(YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir);

//    QDEBUG_STRING_OUTPUT_2("startDetached; programFileAbsolutePath",
//    					   programFileAbsolutePath);
//
//    qDebug() << "startDetached; programArguments"
//    		 << programArguments;

    return aProcess.startDetached(programFileAbsolutePath, programArguments);
}


bool YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(QProcess &aProcess,
                                               QString programFileAbsolutePath,
                                               QStringList programArguments,
                                               int waitForFinished)
{
    aProcess.setWorkingDirectory(YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir);

//    QDEBUG_STRING_OUTPUT_2("startAndWaitForFinished; programFileAbsolutePath",
//    					   programFileAbsolutePath);
//
//    qDebug() << "startAndWaitForFinished; programArguments"
//    		 << programArguments;

    aProcess.start(programFileAbsolutePath, programArguments);

    return aProcess.waitForFinished(waitForFinished);
}


bool YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(QString programFileAbsolutePath,
                                               QStringList programArguments,
                                               int waitForFinished)
{
    QProcess aProcess;

    aProcess.setWorkingDirectory(YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir);

    aProcess.start(programFileAbsolutePath, programArguments);

    return aProcess.waitForFinished(waitForFinished);
}
