#ifndef PROVIDERTABTEST_H
#define PROVIDERTABTEST_H
#include "Util.h"
#include "ProviderTab.h"

class QLineEdit;

class QTextEdit;

class ProviderTabTest : public ProviderTab
{
    Q_OBJECT
public:
    explicit ProviderTabTest(QWidget* parent = 0);
    ~ProviderTabTest();
private slots:

    void loadCss();

    void testWaybillCountryCode();

    void testWaybillId();

    void testWaybillTransportVehicle();

    void testWaybillTransportRegistration();

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

};

#endif // PROVIDERTABTEST_H
