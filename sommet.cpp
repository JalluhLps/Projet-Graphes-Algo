#include "sommet.h"

Sommet::Sommet() : cle{0}
{}

Sommet::Sommet(int cle) : cle{cle}
{}

int Sommet::getCle() const
{
    return cle;
}

void Sommet::setCle(int newKey)
{
    this->cle = newKey ;
}
