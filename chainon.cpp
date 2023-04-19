#include "chainon.h"

Chainon::Chainon(int cle) : Sommet{cle}, lpSuiv{nullptr}, lsSuiv{nullptr}
{}

Chainon* Chainon::getLpSuivant() const
{
    return lpSuiv;
}

Chainon* Chainon::getLsSuivant() const
{
    return lsSuiv;
}

