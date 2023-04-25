#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H

#include "graphe.h"

class GrapheNonOriente : public Graphe
{
public:
    // A revenir dessus
    GrapheNonOriente(const vector<vector<Sommet>>& matrice, int n, int m);
    GrapheNonOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    void rang(vector<int>& rang) override;
    bool codagePrufer (vector <int> & prufer);
};







#endif // GRAPHENONORIENTE_H
