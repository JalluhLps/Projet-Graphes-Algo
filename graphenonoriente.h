#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H

#include "graphe.h"
#include <string>

class GrapheNonOriente : public Graphe
{
public:
    GrapheNonOriente();
    GrapheNonOriente(const vector<vector<Sommet>>& matrice, int n, int m);
    GrapheNonOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    // Méthodes virtuelles
    bool lireGraphe(std::string nomFic) override;
    void rang(vector<int>& rang) override;
    bool codagePrufer (vector <int> & prufer) override;
    bool calculDistance (int racine, vector<int> &dist) override;
};

#endif // GRAPHENONORIENTE_H
