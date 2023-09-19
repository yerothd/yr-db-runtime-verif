/*
 * yr-db-runtime-verif-push-button.hpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_PUSH_BUTTON_HPP_
#define _YR_DB_RUNTIME_VERIF_PUSH_BUTTON_HPP_


#include <QtWidgets/QPushButton>


class YRDBRUNTIMEVERIF_QPushButton : public QPushButton
{
    Q_OBJECT

public:

    inline YRDBRUNTIMEVERIF_QPushButton(QWidget *w)
    :QPushButton(w)
    {
    }

    virtual inline ~YRDBRUNTIMEVERIF_QPushButton()
    {
    }

    inline void enable(const QObject *receiver, const char *f)
    {
        QObject::connect(this,
                         SIGNAL(clicked()),
                         receiver,
                         f,
                         Qt::UniqueConnection);
    }

    inline void disable(const QObject *receiver)
    {
        QObject::disconnect(this,
                            SIGNAL(clicked()),
                            receiver,
                            0);
    }
};


#endif /* _YR_DB_RUNTIME_VERIF_PUSH_BUTTON_HPP_ */
