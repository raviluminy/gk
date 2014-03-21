#ifndef STATUSWIDGETGROUPTEST_H
#define STATUSWIDGETGROUPTEST_H

#include "Util.h"
#include "StatusWidgetGroup.h"

class QLineEdit;

class QTextEdit;

/**
 * @brief The StatusWidgetGroupTest class teste les fonctionalites classiques du champ
 * status.
 */
class StatusWidgetGroupTest : public StatusWidgetGroup
{
        Q_OBJECT
public:
    explicit StatusWidgetGroupTest(QWidget* parent = 0);
    ~StatusWidgetGroupTest();

private slots:

    void loadCss();

    void testComment();

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

#endif // STATUSWIDGETGROUPTEST_H
