#include "arete.h"

Arete::Arete(int s, int t, double p) : s{s}, t{t}, poids{p}
{}

int Arete::getS() const
{
    return s;
}

int Arete::getT() const
{
    return t;
}

int Arete::getPoids() const
{
    return poids;
}


