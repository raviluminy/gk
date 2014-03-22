#ifndef WAYBILLTABTEST_H
#define WAYBILLTABTEST_H

#include "Util.h"
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
    void loadCss();

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


	void testStatusComment();
#endif
	void testTransportRegistrationNo();

	void testTransportVehicle();

	void testWarehouse();

    void cleanupTestCase();

    void initTestCase();

private:

	/**
	 * @brief lineEditTest
	 * @param tested
	 * @param entry
	 * @param expected
	 */
	void lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected);

	/**
	 * @brief textEditTest
	 * @param tested
	 * @param entry
	 * @param expected
	 */
	void textEditTest(QTextEdit* tested, const QString& entry, const QString& expected);

};

#endif // WAYBILLTABTEST_H
