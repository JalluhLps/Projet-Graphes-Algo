#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include "chainon.h"
#include "sommet.h"

using std::vector;

class Graphe
{
public:
    Graphe(const vector<vector<Sommet>>& matrice);
    Graphe(const vector<Sommet>& fs, const vector<Sommet>& aps);
    Graphe(const vector<Chainon>& lp, const vector<Chainon>& ls);

    enum Etat {MAT, FS, LISTE};

    bool isMatrice() const; // true en mode matrice
    bool isFsAps() const;
    bool isListe() const;


    bool calculDistance (int racine, vector<int> &dist );
private:
    vector<vector<Sommet>> matrice; // tab 2D de la matrice d'adjacence du graphe
    vector<Sommet> fs; // tab fs du graphe
    vector<Sommet> aps; // tab aps du graphe

    /** Faudrait vérifier par contre si ces tabs garde des sommets ou seulement des entiers */

    vector<Chainon> listePrincipale;
    vector<Chainon> listeSecondaire;

    Etat actif; // A supposer qu'un seul état est utilisé à la fois
};

#endif // GRAPHE_H
