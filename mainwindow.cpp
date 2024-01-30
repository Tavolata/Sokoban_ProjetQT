#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mur.h"
#include "cible.h"
#include "personnage.h"
#include "case.h"


#include <QDebug>
#include <QList>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            tableau[i][j] = nullptr;
            tableau[i][j] = new Case(this);
            tableau[i][j]->setCoordinates(i*(taille), j*(taille));
            tableau[i][j]->setSize();
            tableau[i][j]->setParent(this);
            tableau[i][j]->show();
        }
    }

    p = new Personnage(52,52);


}


void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);

    p->dessiner(&painter);
}

void MainWindow::puisjemedeplacer(const int x, const int y){

    if (tableau[x][y]->classe==1) {
        p->deplacer(x,y);

    }
    else if (tableau[x][y]->classe==2){
        p->deplacer(x,y);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {

    int taille = 50;

    switch(event->key())
    {
    case Qt::Key_S :
    {
        puisjemedeplacer(p->getX()-taille, p->getY());
        break;
    }
    case Qt::Key_F :
    {
        puisjemedeplacer(p->getX()+taille,p->getY());
        break;
    }
    case Qt::Key_C :
    {
        puisjemedeplacer(p->getX(),p->getY()+taille);
        break;
    }
    case Qt::Key_E :
    {
        puisjemedeplacer(p->getX(),p->getY()-taille);
        break;
    }
    }

    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}



