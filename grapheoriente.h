#ifndef GRAPHEORIENTE_H
#define GRAPHEORIENTE_H

#include <vector>
#include <stack>
#include "graphe.h"

class GrapheOriente : public Graphe
{
public:
    // A revenir dessus
    GrapheOriente(const vector<vector<Sommet>>& matrice, int n, int m);
    GrapheOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    GrapheOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    void rang(vector<int>& rang) override;
    bool calculDistance (int racine, vector<int> &dist) override;
private:
    void tarjanVisite(int u, vector<int>& rang, std::stack<int>& pile, vector<int>& profondeur, vector<int>& bas, vector<bool>& dansPile, int& num);
};

#endif // GRAPHEORIENTE_H
