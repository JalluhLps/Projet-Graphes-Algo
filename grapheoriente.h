#ifndef GRAPHEORIENTE_H
#define GRAPHEORIENTE_H

#include <vector>
#include <stack>
#include "graphe.h"
#include<string>
using std::stack;

class GrapheOriente : public Graphe
{
public:
    GrapheOriente(const vector<vector<Sommet>>& matrice, int n, int m);
    GrapheOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    GrapheOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    // Méthodes classiques
    void djikstra (vector<vector<int>>& p, int s, vector<int>& d, vector<int>& pr);
    void tarjan(int u, vector<int>& indices, vector<int>& low, stack<int>& pile, vector<bool>& dans_pile, vector<vector<int>>& composantes) override;
    vector<vector<int>> trouverCFC() override;
    vector<vector<int>> trouverGrapheReduit(vector<vector<int>>& graphe) override;
    void trouver_bases(vector<vector<int>>& graphe_reduit, vector<vector<int>>& composantes) override;
    // Méthodes virtuelles
    bool lireGraphe(std::string nomFic) override;
    void rang(vector<int>& rang) override;
    bool codagePrufer (vector <int> & prufer) override;
    bool calculDistance (int racine, vector<int> &dist) override;
private:
    void tarjanVisite(int u, vector<int>& rang, std::stack<int>& pile, vector<int>& profondeur, vector<int>& bas, vector<bool>& dansPile, int& num);
};

#endif // GRAPHEORIENTE_H
