#include "mur.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

Mur :: Mur (QWidget *parent): Case(parent){

}

void Mur::setSize()
{
    int taille = 50;
    // Régler la taille du widget Mur
    setFixedSize(taille, taille);
    setImagePath(":/Mur/Mur.jpg");
}




