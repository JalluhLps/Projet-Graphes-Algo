#include "graphe.h"

Graphe::Graphe(const vector<vector<Sommet>>& mat) : matrice{mat}, actif{MAT}
{}

Graphe::Graphe(const vector<Sommet>& fs, const vector<Sommet>& aps) : fs{fs}, aps{aps}, actif{FS}
{}

Graphe::Graphe(const vector<Chainon>& lp, const vector<Chainon>& ls) : listePrincipale{lp}, listeSecondaire{ls}, actif{LISTE}
{}

bool Graphe::isMatrice() const
{
    return actif == MAT;
}

bool Graphe::isFsAps() const
{
    return actif == FS;
}

bool Graphe::isListe() const
{
    return actif == LISTE;
}

