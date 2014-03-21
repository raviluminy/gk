#ifndef WAYBILLTABTEST_H
#define WAYBILLTABTEST_H

#include "Util.h"
#ifdef TEST_GUI_WAYBILL_TAB

#include "WaybillTab.h"

class QLineEdit;

class QTextEdit;

/**
 * @brief The WaybillTabTest class teste les fonctionalites classiques de
 * l'onglet Waybill.
 */
class WaybillTabTest : public WaybillTab {

	Q_OBJECT

public:

	explicit WaybillTabTest(QWidget* parent = 0);

	~WaybillTabTest();

private slots:

	void testCountryCode();

	void testId();

	void testPlannedLoading();

	void testPlannedReception();

	void testPlannedTransport();

	void testRealLoading();

	void testRealReception();

	void testRealTransport();

#if 0
	void testStatus();
#endif

	void testStatusComment();

	void testTransportRegistrationNo();

	void testTransportVehicle();

	void testWarehouse();

private:

	/**
	 * Il faut apprendre a mutualiser son code Antho ;-)
	 * @brief lineEditTest
	 * @param tested
	 * @param entry
	 * @param expected
	 */
	void lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected);

	/**
	 * Meme remarque que precedemment...
	 * @brief textEditTest
	 * @param tested
	 * @param entry
	 * @param expected
	 */
	void textEditTest(QTextEdit* tested, const QString& entry, const QString& expected);

};

#endif // TEST_GUI_WAYBILL_TAB

#endif // WAYBILLTABTEST_H
