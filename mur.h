#ifndef MUR_H
#define MUR_H

#include "case.h"

#include <QWidget>
#include <QLabel>


class Mur : public Case
{
    Q_OBJECT
public:
    int classe=3;
    explicit Mur (QWidget *parent = nullptr);
    void setSize() ;


private:
    QLabel *imageLabel;

};

#endif // MUR_H
