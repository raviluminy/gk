#ifndef STAFFTABTEST_H
#define STAFFTABTEST_H
#include "Util.h"
#include "StaffTab.h"

class QLineEdit;

class QTextEdit;


class StaffTabTest : public StaffTab
{
        Q_OBJECT
public:
    explicit StaffTabTest(QWidget* parent = 0);
    ~StaffTabTest();
private slots:

    void loadCss();

    void testId();

    void testLastName();

    void testFirstName();

    void testFix();

    void testMobil();

    void testEmail();

    void testAddress();

    void testCategoty();

    void testNumber();

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

#endif // STAFFTABTEST_H
