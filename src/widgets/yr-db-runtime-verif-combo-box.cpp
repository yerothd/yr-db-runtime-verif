/*
 * yr-db-runtime-verif-combo-box.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-combo-box.hpp"


#include <QtCore/QDebug>

#include <QtSql/QSqlQuery>


YRDBRUNTIMEVERIF_ComboBox::YRDBRUNTIMEVERIF_ComboBox(QWidget *parent)
:QComboBox(parent)
{
    setLineEdit(new QLineEdit);

    lineEdit()->setReadOnly(true);

    lineEdit()->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
}


void YRDBRUNTIMEVERIF_ComboBox::clearField()
{
    QComboBox::clear();
}


void YRDBRUNTIMEVERIF_ComboBox::yr__setEditable(bool editable)
{
    QLineEdit *a_qline_edit = lineEdit();

    if (editable && 0 != a_qline_edit)
    {
        a_qline_edit->setReadOnly(false);
    }

    setEditable(editable);
}


void YRDBRUNTIMEVERIF_ComboBox::find_AND_SET_CURRENT_INDEX(const QString &a_text_TO_FIND_IN)
{
    int ret_find = findText(a_text_TO_FIND_IN);

    if (-1 != ret_find)
    {
        setCurrentIndex(ret_find);
    }
    else
    {
        addItem(a_text_TO_FIND_IN);

        find_AND_SET_CURRENT_INDEX(a_text_TO_FIND_IN);
    }
}


void YRDBRUNTIMEVERIF_ComboBox::addItems(const QStringList &texts)
{
    QStringList new_texts(texts);

    new_texts.sort();

    QComboBox::addItems(new_texts);
}



