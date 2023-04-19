#ifndef CHAINON_H
#define CHAINON_H

#include "sommet.h"

class Chainon : public Sommet /** C'est un type de sommet spécial utiliser pour les 'lp' et les 'ls' */
{
public:
    Chainon(int cle);
    Chainon* getLpSuivant() const;
    Chainon* getLsSuivant() const;
private:
    Chainon* lpSuiv;
    Chainon* lsSuiv;
};

#endif // CHAINON_H
