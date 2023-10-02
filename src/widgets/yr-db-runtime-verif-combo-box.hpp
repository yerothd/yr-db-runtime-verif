/*
 * yr-db-runtime-verif-combo-box.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_COMBO_BOX_HPP_
#define _YR_DB_RUNTIME_VERIF_COMBO_BOX_HPP_


#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include <QtWidgets/QComboBox>

#include <QtWidgets/QLineEdit>


class YRDBRUNTIMEVERIF_ComboBox : public QComboBox
{
	Q_OBJECT

public:

	YRDBRUNTIMEVERIF_ComboBox(QWidget *parent);

    inline ~YRDBRUNTIMEVERIF_ComboBox()
    {
    }

    void clearField();

    inline void resetYerothComboBox()
    {
        setCurrentIndex(0);
    }

    inline virtual bool contains(const QString &a_text)
    {
        return (-1 != findText(a_text));
    }

    inline QString currentText() const
    {
        return QComboBox::currentText().trimmed();
    }

    virtual void yr__setEditable(bool editable);

    inline virtual bool isReadOnly()
    {
        return lineEdit()->isReadOnly();
    }

    inline bool isEmpty()
    {
        return currentText().isEmpty();
    }

    void find_AND_SET_CURRENT_INDEX(const QString &a_text_TO_FIND_IN);

    inline void yeroth_remove_item(const QString &text)
    {
        removeItem(findText(text));
    }

    virtual void addItems(const QStringList &texts);
};


#endif /* _YR_DB_RUNTIME_VERIF_COMBO_BOX_HPP_ */
