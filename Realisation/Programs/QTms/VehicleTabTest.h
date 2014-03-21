#ifndef VEHICLETABTEST_H
#define VEHICLETABTEST_H
#include "Util.h"
#include "VehicleTab.h"

class QLineEdit;

class QTextEdit;

class VehicleTabTest : public VehicleTab{
    Q_OBJECT
public:
    explicit VehicleTabTest(QWidget* parent = 0);
    ~VehicleTabTest();

private slots:

    void loadCss();

    void testVehiculeRegistration();

    void testVehicule();

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

#endif // VEHICLETABTEST_H
