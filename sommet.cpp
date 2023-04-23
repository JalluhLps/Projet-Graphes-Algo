#include "sommet.h"

Sommet::Sommet() : cle{0}
{}

Sommet::Sommet(int cle) : cle{cle}
{}

int Sommet::getCle() const
{
    return cle;
}
