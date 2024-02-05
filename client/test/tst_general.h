#ifndef TST_GENERAL_H
#define TST_GENERAL_H

#include <QObject>

class General : public QObject
{
    Q_OBJECT

public:
    General();
    ~General();

private slots:
    void test_case1();

};

#endif // TST_GENERAL_H
