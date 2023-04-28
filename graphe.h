#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <string>
#include "chainon.h"
#include "sommet.h"
#include <stack>
using std::stack;

using std::vector;

class Graphe
{
public:
    Graphe(const vector<vector<Sommet>>& matrice, int n, int m);
    Graphe(const vector<Sommet>& fs, const vector<int>& aps, int n, int m);
    Graphe(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m);

    // Méthodes classiques
    bool ecrireGraphe(std::string nomFic);

    // Méthodes virtuelles pures
    virtual bool lireGraphe(std::string nomFic) = 0;
    virtual void rang(vector<int>& rang) = 0;
    virtual bool calculDistance (int racine, vector<int>& dist) = 0;
    virtual bool codagePrufer (vector <int>& prufer) = 0;
    virtual void tarjan(int u, vector<int>& indices, vector<int>& low, stack<int>& pile, vector<bool>& dans_pile, vector<vector<int>>& composantes)=0;
    virtual vector<vector<int>> trouverGrapheReduit(vector<vector<int>>& graphe)=0;
    virtual vector<vector<int>> trouverCFC()=0;
    virtual void trouver_bases(vector<vector<int>>& graphe_reduit, vector<vector<int>>& composantes)=0;
protected:
    void matrice2FsAps();
    void matrice2Liste();
    void fsAps2Matrice();
    void fsAps2Liste();
    void liste2Matrice();
    void liste2FsAps();

    vector<vector<Sommet>> matrice; // tab 2D de la matrice d'adjacence du graphe
    vector<Sommet> fs; // tab fs du graphe (sommets du graphe)
    vector<int> aps; // tab aps contient les indices dans le tab fs
    vector<Chainon> listePrincipale;
    vector<Chainon> listeSecondaire;
    int n; //nbre de sommets
    int m; //nbre d'arêtes
};

#endif // GRAPHE_H
