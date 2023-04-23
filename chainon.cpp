#include "chainon.h"

Chainon::Chainon(int cle) : Sommet{cle}, lpSuiv{nullptr}, lsSuiv{nullptr}
{}

void Chainon::setLpSuivant(Chainon* c)
{
    lpSuiv = c;
}

void Chainon::setLsSuivant(Chainon* c)
{
    lsSuiv = c;
}

Chainon* Chainon::getLpSuivant() const
{
    return lpSuiv;
}

Chainon* Chainon::getLsSuivant() const
{
    return lsSuiv;
}

