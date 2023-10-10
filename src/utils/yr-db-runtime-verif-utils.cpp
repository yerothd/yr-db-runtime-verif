/*
 * yr-db-runtime-verif-utils.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-utils.hpp"


#include "src/process/yr-db-runtime-verif-PROCESS.hpp"


#include <QtCore/QDebug>
#include <QtCore/QDate>
#include <QtCore/QBuffer>

#include <QtGui/QPainter>

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtWidgets/QLabel>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "yr-db-runtime-verif-logger.hpp"

QString YR_DB_RUNTIME_VERIF_Utils::_mainWorkingDirectory("");

QString YR_DB_RUNTIME_VERIF_Utils::_logFileName("yr-db-runtime-verif.log");

QString YR_DB_RUNTIME_VERIF_Utils::temporaryFilesDir("/tmp");

const QString YR_DB_RUNTIME_VERIF_Utils::EMPTY_STRING("");

const QString YR_DB_RUNTIME_VERIF_Utils::USERS("users");
const QString YR_DB_RUNTIME_VERIF_Utils::TITRES("titres");
const QString YR_DB_RUNTIME_VERIF_Utils::LOCALISATIONS("localisations");
const QString YR_DB_RUNTIME_VERIF_Utils::CATEGORIES("categories");
const QString YR_DB_RUNTIME_VERIF_Utils::CLIENTS("clients");
const QString YR_DB_RUNTIME_VERIF_Utils::FOURNISSEURS("fournisseurs");
const QString YR_DB_RUNTIME_VERIF_Utils::ALERTES("alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::CONDITIONS_ALERTES("conditions_alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::COURRIERS_ALERTES("courriers_alertes");
const QString YR_DB_RUNTIME_VERIF_Utils::STOCKS("stocks");
const QString YR_DB_RUNTIME_VERIF_Utils::STOCKS_VENDU("stocks_vendu");



const QRegExp YR_DB_RUNTIME_VERIF_Utils::EMPTY_SPACE_REGEXP("\\s");

const QLocale YR_DB_RUNTIME_VERIF_Utils::englishLocale(QLocale(QLocale::English, QLocale::Zambia));



const QString YR_DB_RUNTIME_VERIF_Utils::DATE_FORMAT("dd.MM.yyyy");

const QString YR_DB_RUNTIME_VERIF_Utils::DB_DATE_FORMAT("yyyy-MM-dd");


const QString YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT_WITH_MILLISECONDS(FORMAT_TIME_WITH_MS);

const QString YR_DB_RUNTIME_VERIF_Utils::TIME_FORMAT("HH:mm:ss");


const QString YR_DB_RUNTIME_VERIF_Utils::LOCALHOST("localhost");

const QString YR_DB_RUNTIME_VERIF_Utils::LOCALHOST_IP_ADDRESS("127.0.0.1");


const QString YR_DB_RUNTIME_VERIF_Utils::STRING_OUI("oui");

const QString YR_DB_RUNTIME_VERIF_Utils::STRING_NON("non");


const unsigned int YR_DB_RUNTIME_VERIF_Utils::FACTURE_PETIT_NOM_ARTICLE_MAX_CHARS(12);


const unsigned int YR_DB_RUNTIME_VERIF_Utils::STRING_MAX_CHARS(18);


const QString YR_DB_RUNTIME_VERIF_Utils::INFERIEUR_OU_EGAL("<=");

const QString YR_DB_RUNTIME_VERIF_Utils::SUPERIEUR(">");


const QString YR_DB_RUNTIME_VERIF_Utils::UTILISATEUR_NON_EXISTANT("unknown user");


const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_CLIENT("yr.db-runtime.verif");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_CLIENT_OBJECT("/");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_SERVER("com.yeroth-erp.server");

const QString YR_DB_RUNTIME_VERIF_Utils::JH_NISSI_SERVER_OBJECT("/");



QString YR_DB_RUNTIME_VERIF_Utils::EN_template_EVENT_LOG_TEX_document("");

const QString YR_DB_RUNTIME_VERIF_Utils::FILE_YR_DB_RUNTIME_VERIF_EVENT_LOG_PDF_TEMPLATE_EN(":EN_template_EVENT_LOG_TEX_document.tex");



const QString YR_DB_RUNTIME_VERIF_Utils::CSV_FILE_SEPARATION_SEMI_COLON_STRING_CHAR(";");


const QChar YR_DB_RUNTIME_VERIF_Utils::SLASH_CHAR('/');



void YR_DB_RUNTIME_VERIF_Utils::
        getCurrentSimplifiedDateWITHmilliseconds(QString 	 &date_IN_OUT,
                                                 const QDate &aDate)
{
    date_IN_OUT.append(QString("%1 at %2")
                        .arg(aDate.toString("dd-MM-yyyy"),
                             CURRENT_TIME_WITH_MILLISECONDS));

    date_IN_OUT = YR_DB_RUNTIME_VERIF_Utils::LATEX_IN_OUT_handleForeignAccents(date_IN_OUT);
}


void YR_DB_RUNTIME_VERIF_Utils::getCurrentLocaleDate(QString 		&date_IN_OUT,
                                                     const QDate 	&aDate)
{
    QString d(YR_DB_RUNTIME_VERIF_Utils::englishLocale.toString(aDate));

    int firstCommaIndex = d.indexOf(",", 0);

    d.replace(firstCommaIndex, 1, " ");

    date_IN_OUT.append(", ").append(d);

    date_IN_OUT = YR_DB_RUNTIME_VERIF_Utils::LATEX_IN_OUT_handleForeignAccents(date_IN_OUT);
}


QString YR_DB_RUNTIME_VERIF_Utils::getUniquePrefixFileInTemporaryFilesDir(QString aPrefixFileName)
{
    return QString("%1/%2.").arg(YR_DB_RUNTIME_VERIF_Config::temporaryFilesDir,
                                 FILE_NAME_WITH_CURRENT_DATE_AND_TIME(aPrefixFileName));
}


void YR_DB_RUNTIME_VERIF_Utils::
        handleTexTableItemText(int 	            texTableColumnCount,
                               QString 		    &texTable_IN_OUT,
                               int 			    itemTextColumnPosition,
                               const QString    &itemText,
                               QTableWidgetItem *an_item_widget /* = 0 */)
{
	QString resultItemText(YR_DB_RUNTIME_VERIF_Utils::LATEX_IN_OUT_handleForeignAccents(itemText));

	if (!resultItemText.isEmpty())
	{
        if (0 != an_item_widget)
        {
            QString result_item_text_COLORED = resultItemText;

            if (an_item_widget->background().color() == Qt::darkMagenta)
            {
                result_item_text_COLORED = QString("\\colorbox{purplish}{%1}")
                                             .arg(result_item_text_COLORED);
            }

            if (an_item_widget->foreground().color() == Qt::green)
            {
                result_item_text_COLORED = QString("\\textcolor{yerothColorGreen}{%1}")
                                             .arg(result_item_text_COLORED);
            }
            else
            {
                if (an_item_widget->background().color() == Qt::darkMagenta)
                {
                    result_item_text_COLORED = QString("\\textcolor{white}{%1}")
                                                 .arg(result_item_text_COLORED);
                }
                else
                {
                    result_item_text_COLORED = QString("\\textcolor{black}{%1}")
                                                 .arg(result_item_text_COLORED);
                }
            }

            texTable_IN_OUT.append(result_item_text_COLORED);

        }
        else
        {
            texTable_IN_OUT.append(resultItemText);
        }
	}

	if (itemTextColumnPosition < texTableColumnCount - 1)
	{
		texTable_IN_OUT.append(" &");
	}
	else
	{
		texTable_IN_OUT.append(" \\\\").append("\n");
	}
}


bool YR_DB_RUNTIME_VERIF_Utils::GREP_YEROTH_FILE_CONTENT(const QString &file_full_path,
                                                         const QString &EXECUTABLE_full_path,
                                                         const QString &keyword_IN)
{
	QStringList progArguments;

	progArguments << keyword_IN << file_full_path;

	QProcess GREP_PROCESS;


	bool checkProcessFinished =
            YRDBRUNTIMEVERIF_Process::startAndWaitForFinished(
                                    GREP_PROCESS,
                                    "/bin/grep",
                                    progArguments,
                                    1000);

	if (checkProcessFinished)
	{
		QString checkAlertDeamonProcessOutput(
				GREP_PROCESS.readAllStandardOutput().trimmed());

		return checkAlertDeamonProcessOutput.contains(EXECUTABLE_full_path);
	}

	return false;
}


void YR_DB_RUNTIME_VERIF_Utils::YEROTH_READ_FILE_CONTENT(QFile   &file,
                                                         QString &fileContentVar)
{
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		QString line;
		do
		{
			line = stream.readLine().trimmed();
			fileContentVar.append(line).append("\n");
		} while (!line.isNull());
		file.close();
	}
}


void YR_DB_RUNTIME_VERIF_Utils::YEROTH_CREATE_FOLDER(const QString &aFullPathDir)
{
    QFileInfo aFullPathDirInfo(aFullPathDir);

    if (!aFullPathDirInfo.exists())
    {
        qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                 << QString("Folder '%1' does not exist !").arg(aFullPathDir);

        QDir tempFileDir;

        if (tempFileDir.mkpath(aFullPathDir))
        {
            qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                     << QString("Created folder '%1' !").arg(aFullPathDir);
        }
        else
        {
            qDebug() << "[YR_DB_RUNTIME_VERIF_Utils] YEROTH_CREATE_FOLDER"
                     << QString("Could not Create folder '%1' !").arg(aFullPathDir);
        }
    }
}


int
YR_DB_RUNTIME_VERIF_Utils::start_PROCESS_AND_GET_PROCESS_output_AS_QSTRING
(const QString &program_executable_location_full_path,
 const QStringList &program_executable_args,
 QString &program_output_IN_OUT)
{
    program_output_IN_OUT.clear();

    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

//    qDebug() << "program_executable_location_full_path: " << program_executable_location_full_path;
//    qDebug() << "program_executable_args: " << program_executable_args;

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    program_output_IN_OUT.append(A_YEROTH_PROCESS.
                                 readAllStandardOutput().trimmed());

    return program_output_IN_OUT.size();
}


int
YR_DB_RUNTIME_VERIF_Utils::

start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const QString &
                                                program_executable_location_full_path,
                                                const QString &
                                                output_file_full_path,
                                                const QStringList &
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


bool YR_DB_RUNTIME_VERIF_Utils::GZIP_YEROTH_FILE(const QString &
                                                 program_working_directory_full_path,
                                                 const QString &file_full_path)
{
    QStringList gzipPROG_ARGS;

    gzipPROG_ARGS.append(file_full_path);

    int file_size =
                    YR_DB_RUNTIME_VERIF_Utils::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
                    ("/usr/bin/gzip",
                     program_working_directory_full_path,
                     QString("%1.gz").arg(file_full_path),
                     gzipPROG_ARGS);
    return (file_size >= 0);
}


QString YR_DB_RUNTIME_VERIF_Utils::generateSqlLike__AS_IS(QString sqlTableColumn,
                                                          QString searchStr)
{
    QString result;

    searchStr.replace("'", "''");

    result.append(sqlTableColumn).append(QString(" LIKE '%1'").
                                         arg(searchStr));
    return result;
}


QString YR_DB_RUNTIME_VERIF_Utils::generateSqlLike(QString sqlTableColumn,
                                                   QString searchStr)
{
    QString result;

    searchStr.replace("'", "''");

    result.append(sqlTableColumn).append(" LIKE '%").append(searchStr).
    append("%' ");

    return result;
}


bool YR_DB_RUNTIME_VERIF_Utils::execQuery(const QString &strQuery,
                                          YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    QSqlQuery query;
    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
    }

    return success;
}


int YR_DB_RUNTIME_VERIF_Utils::execQuery(QSqlQuery &query,
                                         const QString &strQuery,
                                         YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}


int YR_DB_RUNTIME_VERIF_Utils::execQuery(QSqlQuery &query,
                                         YR_DB_RUNTIME_VERIF_Logger *logger)
{
    //qDebug() << "[YR_DB_RUNTIME_VERIF_Utils][execQuery]";

    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(DB_BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.
                    lastError().text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}


int YR_DB_RUNTIME_VERIF_Utils::getNextIdFromTable(const QString &tableName)
{
    //qDebug() << "[YerenUtils::getLastIdFromTable()] : next id from table '" << tableName << "'";
    QString strQuery("SELECT id FROM ");
    strQuery.append(tableName);

    QSqlQuery query(strQuery);
    QSqlRecord rec = query.record();

    if (query.last())
    {
        int lastId = query.value(0).toInt();
        ++lastId;
        //qDebug() << "\t next id 1: " << lastId;
        return lastId;
    }

    return 0;
}


bool YR_DB_RUNTIME_VERIF_Utils::SAVE_AS_csv_file(QMainWindow    &aCallingWindow,
                                                 QTableView     &aTableView,
                                                 const QString  &csvFileName,
                                                 const QString  &strMessage,
                                                 int            row_MAX_TO_GO_export /* = -1 */)
{
	QAbstractItemModel *tableModel = aTableView.model();

	if (0 == tableModel)
	{
		return false;
	}


	int tableModelRowCount = tableModel->rowCount();

	int tableModelColumnCount = tableModel->columnCount();


	if (tableModelRowCount <= 0  ||
	    tableModelColumnCount <= 0)
	{
		QMessageBox::information(&aCallingWindow,
                                 QObject::tr("No CSV data"),
                                 QObject::tr("No CSV data to save out !"));
		return false;
	}


	QString csvFileContent;

	QHeaderView *a_calling_window_qheaderview = aTableView.horizontalHeader();

	if (0 == a_calling_window_qheaderview)
	{
		QMessageBox::information(&aCallingWindow,
                                 QObject::tr("Bad deployment"),
                                 QObject::tr("Table bad deployment !"));

		return false;
	}


	QVariant anItem;

	QString anItemText;

	for (int k = 0; k < a_calling_window_qheaderview->count(); ++k)
	{
		anItem = tableModel->headerData(k, Qt::Horizontal);

		if (anItem.isValid())
		{
			anItemText = anItem.toString();

			csvFileContent.append(QString("\"%1\"%2 ")
                                    .arg(anItemText,
                                         YR_DB_RUNTIME_VERIF_Utils::CSV_FILE_SEPARATION_SEMI_COLON_STRING_CHAR));
		}
	}


	csvFileContent.remove(csvFileContent.size() - 2, 2).append("\n");



	int MAX_TABLE_MODDEL_ROW_COUNT__to_export = tableModelRowCount;


	if (row_MAX_TO_GO_export > -1)
	{
        MAX_TABLE_MODDEL_ROW_COUNT__to_export = row_MAX_TO_GO_export;
	}


	QMap<int, QVariant> item_data;

	for (unsigned int j = 0; j < MAX_TABLE_MODDEL_ROW_COUNT__to_export; ++j)
	{
		for (unsigned int k = 0; k < tableModelColumnCount; ++k)
		{
			item_data = tableModel->itemData(tableModel->index(j, k));

            anItemText = item_data.value(Qt::DisplayRole).toString();

            csvFileContent
                .append(QString("\"%1\"%2 ")
                         .arg(anItemText,
                              YR_DB_RUNTIME_VERIF_Utils::CSV_FILE_SEPARATION_SEMI_COLON_STRING_CHAR));
		}

		csvFileContent.remove(csvFileContent.size() - 2, 2).append("\n");
	}


	QString yerothStocksListingCSVFileName
				(QString("%1/%2")
					.arg(YR_DB_RUNTIME_VERIF_Utils::temporaryFilesDir,
						 csvFileName));


	yerothStocksListingCSVFileName =
				FILE_NAME_USERID_CURRENT_TIME(yerothStocksListingCSVFileName);


        yerothStocksListingCSVFileName
            = QFileDialog::getSaveFileName(&aCallingWindow,
                             	 	 	   "Type in a '.csv' file name ",
										   yerothStocksListingCSVFileName,
										   QString("%1 \"*.csv\" (*.csv)")
                                             .arg(strMessage));


    yerothStocksListingCSVFileName.append(".csv");

    QFile tmpFile(yerothStocksListingCSVFileName);

	if (tmpFile.open(QFile::WriteOnly))
	{
		tmpFile.write(csvFileContent.toUtf8());
	}

	tmpFile.close();

	return true;
}


QString YR_DB_RUNTIME_VERIF_Utils::LATEX_IN_OUT_handleForeignAccents(const QString &texText_in)
{
	if (texText_in.isEmpty())
	{
		return YR_DB_RUNTIME_VERIF_Utils::EMPTY_STRING;
	}

	QString tempText(texText_in);

	tempText = tempText.isEmpty() ? "\"\"" : tempText.replace(EMPTY_SPACE_REGEXP, "\\ ");

	tempText.replace("º", "\\textdegree");
	tempText.replace("#", "\\#");
	tempText.replace("_", "\\_");
	tempText.replace("%", "\\%");
	tempText.replace("&", "\\&");
	tempText.replace("$", "\\$");

	tempText.replace(QString::fromUtf8("ç"), "\\c{c}");
	tempText.replace(QString::fromUtf8("è"), "\\`e");
	tempText.replace(QString::fromUtf8("é"), "\\'e");
	tempText.replace(QString::fromUtf8("ê"), "\\^e");
	tempText.replace(QString::fromUtf8("à"), "\\`a");
	tempText.replace(QString::fromUtf8("â"), "\\^a");
	tempText.replace(QString::fromUtf8("ô"), "\\^o");
	tempText.replace(QString::fromUtf8("î"), "\\^i");
	tempText.replace(QString::fromUtf8("û"), "\\^u");
	tempText.replace(QString::fromUtf8("È"), "\\`E");
	tempText.replace(QString::fromUtf8("É"), "\\'E");
	tempText.replace(QString::fromUtf8("Ê"), "\\^E");
	tempText.replace(QString::fromUtf8("À"), "\\`A");
	tempText.replace(QString::fromUtf8("Â"), "\\^A");
	tempText.replace(QString::fromUtf8("Ô"), "\\^O");
	tempText.replace(QString::fromUtf8("Î"), "\\^I");
	tempText.replace(QString::fromUtf8("Û"), "\\^U");

	return tempText;
}


bool YR_DB_RUNTIME_VERIF_Utils::start_db_transaction()
{
    return false;
}


bool YR_DB_RUNTIME_VERIF_Utils::rollback_db_transaction()
{
    return false;
}


bool YR_DB_RUNTIME_VERIF_Utils::commit_db_transaction()
{
    return false;
}


QString YR_DB_RUNTIME_VERIF_Utils::get_text(const QVariant &qv)
{
    QString retStr;

    switch (qv.type())
    {
    case QVariant::UInt:
        return QString::number(qv.toUInt());

    case QVariant::Int:
        return QString::number(qv.toInt());

    case QVariant::Double:
        return QString::number(qv.toDouble(), 'f', 2);

    case QVariant::ULongLong:
        return QString::number(qv.toULongLong());

    case QVariant::LongLong:
        return QString::number(qv.toLongLong());

    case QVariant::Char:
        retStr = QString(qv.toChar());
        break;

    case QVariant::String:
        retStr = QString(qv.toString());
        break;

    case QVariant::Bool:
        retStr.append(qv.toBool());
        break;

    case QVariant::Date:
        retStr = DATE_TO_STRING(qv.toDate());
        break;

    case QVariant::Time:
        retStr = TIME_TO_STRING(qv.toTime());
        break;

    default:
        retStr = QString(qv.type());
        break;
    }

    return YR_DB_RUNTIME_VERIF_Utils::prepareSqlStr(retStr);
}
