#ifndef REQUISITIONTEST_H
#define REQUISITIONTEST_H

#include "Util.h"
#include "requisition.h"
#include "LogisticDao.h"


/**
 * @brief  requisitionTest teste la couche de DAO de réquisition.
 */
class requisitionTest : public QObject
{
    Q_OBJECT
public:
     explicit requisitionTest(QWidget* parent = 0);
    ~requisitionTest();
private slots:
    void testGetRequisition();

    void testGetList();

    void cleanupTestCase();

    void initTestCase();

public:
    Requisition *req = NULL;
    QVector <Requisition *> *requisitionList = NULL;
private :
    LogisticDao dao;
};

#endif // REQUISITIONTEST_H
