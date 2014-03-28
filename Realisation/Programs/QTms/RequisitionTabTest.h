
#define REQUISITIONTABTEST_H

#include "Util.h"
#include "RequisitionTab.h"
#include "LogisticDao.h"

class QLineEdit;

class QTextEdit;

/**
 * @brief The RequisitionTabTest class teste les fonctionalites classiques de
 * l'onglet Requisition.
 */

class RequisitionTabTest : public RequisitionTab
{
    Q_OBJECT

public:
    explicit RequisitionTabTest(QWidget* parent = 0);

    ~RequisitionTabTest();
private slots:
    void loadCss();

    void testCountryCode();

    void testId();

    void testOrigin();

    void testDestination();

    void testRequesterName();

    void testProjectManager();

    void testFinanceOfficer();

    void testLogistics();

    void testGlobalFleetBase();

    void initTestCase();

    void cleanupTestCase();


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

    LogisticDao dao;
};

