/*
 * yr-db-runtime-verif-progress-bar.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#ifndef _YR_DB_RUNTIME_VERIF_PROGRESS_BAR_HPP_
#define _YR_DB_RUNTIME_VERIF_PROGRESS_BAR_HPP_

#include "src/utils/yr-db-runtime-verif-utils.hpp"

#include <QtCore/qmath.h>

#include <QtWidgets/QProgressBar>


class YRDBRUNTIMEVERIF_CommonsWindow;


class YR_DB_RUNTIME_VERIF_ProgressBar : public QProgressBar
{
	Q_OBJECT

public:

    YR_DB_RUNTIME_VERIF_ProgressBar(YRDBRUNTIMEVERIF_CommonsWindow *aYerothParentWindow);

    inline virtual ~YR_DB_RUNTIME_VERIF_ProgressBar()
    {
    }

    template <class classType, typename parameterType, typename returnType>
    inline void operator()(classType 		*erpStockImport,
                           parameterType 	*aParamValue_ONE,
                           parameterType 	*aParamValue_TWO,
                           returnType(classType::*func)(parameterType *,
                                                        parameterType *),
                           returnType 		*aRetValue = 0,
						   unsigned int 	progressBarMaximum = 100)
    {
        call_funtion_with_progress_bar_updates(erpStockImport,
                                               aParamValue_ONE,
                                               aParamValue_TWO,
                                               func,
                                               aRetValue,
                                               progressBarMaximum);
    }

    template <class classType, typename parameterType, typename returnType>
    inline void operator()(classType 		*erpStockImport,
                           parameterType 	*aParamValue,
                           returnType(classType::*func)(parameterType *),
                           returnType 		*aRetValue = 0,
						   unsigned int 	progressBarMaximum = 100)
    {
        call_funtion_with_progress_bar_updates(erpStockImport,
                                               aParamValue,
                                               func,
                                               aRetValue,
                                               progressBarMaximum);
    }

    template <class classType, typename returnType>
    inline void operator()(classType 		*erpStockImport,
                           returnType(classType::*func)(),
                           returnType 		*aRetValue = 0,
                           unsigned int 	progressBarMaximum = 100)
    {
        call_funtion_with_progress_bar_updates(erpStockImport,
                                               func,
                                               aRetValue,
                                               progressBarMaximum);
    }


public slots:

    inline void SLOT_UPDATE_PROGRESS_BAR_VALUE(int v = 1)
    {
        setValue(v + 2);
    }


protected:

    template <class classType, typename parameterType, typename returnType>
    void call_funtion_with_progress_bar_updates(classType 		*erpStockImport,
                                                parameterType 	*aParamValue_ONE,
                                                parameterType 	*aParamValue_TWO,
                                                returnType(classType::*func)(parameterType *, parameterType *),
                                                returnType 		*aRetValue,
                                                unsigned int 	progressBarMaximum);


    template <class classType, typename parameterType, typename returnType>
    void call_funtion_with_progress_bar_updates(classType 		*erpStockImport,
                                                parameterType 	*aParamValue,
                                                returnType(classType::*func)(parameterType *),
                                                returnType 		*aRetValue,
                                                unsigned int	progressBarMaximum);


    template < class classType, typename returnType >
    void call_funtion_with_progress_bar_updates(classType 		*erpStockImport,
                                                returnType(classType::*func)(),
												returnType 		*aRetValue,
                                                unsigned int	progressBarMaximum);

private:

    bool _setup;
};


/*
 * MUST STAY IN HEADER FILE !
 */
template <class classType, typename parameterType, typename returnType>
void YR_DB_RUNTIME_VERIF_ProgressBar::
		call_funtion_with_progress_bar_updates(classType 		*aClassInstanceRef,
											   parameterType 	*aParamValue_ONE,
											   parameterType 	*aParamValue_TWO,
											   returnType(classType::*func)(parameterType *, parameterType *),
											   returnType 		*aRetValue,
											   unsigned int 	progressBarMaximum)
{
    if (0 == aParamValue_ONE || 0 == aParamValue_TWO)
    {
        return;
    }

    if (!_setup)
    {
        connect(aClassInstanceRef,
                SIGNAL(SIGNAL_INCREMENT_PROGRESS_BAR(int)),
                this,
				SLOT(SLOT_UPDATE_PROGRESS_BAR_VALUE(int)));

        _setup = true;
    }

    setMaximum(progressBarMaximum);

    setVisible(true);

    returnType retValue = (aClassInstanceRef->*func)(aParamValue_ONE, aParamValue_TWO);

    setVisible(false);

    if (0 != aRetValue)
    {
        *aRetValue = retValue;
    }
}



/*
 * MUST STAY IN HEADER FILE !
 */
template <class classType, typename parameterType, typename returnType>
void YR_DB_RUNTIME_VERIF_ProgressBar::call_funtion_with_progress_bar_updates(classType 		*aClassInstanceRef,
        													   parameterType 	*aParamValue,
															   returnType (classType::*func)(parameterType *),
															   returnType 		*aRetValue,
															   unsigned int 	progressBarMaximum)
{
    if (!_setup)
    {
        connect(aClassInstanceRef,
                SIGNAL(SIGNAL_INCREMENT_PROGRESS_BAR(int)),
                this,
				SLOT(SLOT_UPDATE_PROGRESS_BAR_VALUE(int)));

        _setup = true;
    }

    setMaximum(progressBarMaximum);

    setVisible(true);

    returnType retValue = (aClassInstanceRef->*func)(aParamValue);

    setVisible(false);

    if (0 != aRetValue)
    {
        *aRetValue = retValue;
    }
}


/*
 * MUST STAY IN HEADER FILE !
 */
template <class classType, typename returnType>
void YR_DB_RUNTIME_VERIF_ProgressBar::call_funtion_with_progress_bar_updates(classType 	*aClassInstanceRef,
                                                               returnType (classType::*func)(),
                                                               returnType 	* aRetValue,
                                                               unsigned int progressBarMaximum)
{
    if (!_setup)
    {
        connect(aClassInstanceRef,
                SIGNAL(SIGNAL_INCREMENT_PROGRESS_BAR(int)),
                this,
				SLOT(SLOT_UPDATE_PROGRESS_BAR_VALUE(int)));

        _setup = true;
    }

    setMaximum(progressBarMaximum);

    setVisible(true);

    returnType retValue = (aClassInstanceRef->*func)();

    setVisible(false);

    if (0 != aRetValue)
    {
        *aRetValue = retValue;
    }
}


#endif /* _YR_DB_RUNTIME_VERIF_PROGRESS_BAR_HPP_ */
