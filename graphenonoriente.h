#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H

#include "graphe.h"
#include "arete.h"

class GrapheNonOriente : public Graphe
{
public:
    GrapheNonOriente(const vector<vector<Sommet>>& matrice, int n, int m);
    GrapheNonOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    // Méthodes classiques
    vector<Arete> kruskal();

    // Méthodes virtuelles
    void rang(vector<int>& rang) override;
    bool codagePrufer (vector <int> & prufer) override;
    bool calculDistance (int racine, vector<int> &dist) override;
private:
    int trouverParent(int s, vector<int>& parents);

    vector<Arete> aretes; // Pour Kruskal tab des arêtes du graphe
};

#endif // GRAPHENONORIENTE_H
