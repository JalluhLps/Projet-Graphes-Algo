#include "grapheoriente.h"
#include <fstream>
GrapheOriente::GrapheOriente(const vector<vector<Sommet>>& mat, int n, int m) : Graphe{mat, n, m}
{}

GrapheOriente::GrapheOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m) : Graphe{fs, aps, n, m}
{}

GrapheOriente::GrapheOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m) : Graphe{lp, ls, n, m}
{}

void GrapheOriente::rang(vector<int>& rang) // Algorithme de Tarjan
{
    std::stack<int> pile;
    vector<int> profondeur(n+1, -1);
    vector<int> bas(n+1, -1);
    vector<bool> dansPile(n+1, false);
    int num = 0;

    for (int i = 1; i <= n; i++)
    {
        if (profondeur[i] == -1)
        {
            tarjanVisite(i, rang, pile, profondeur, bas, dansPile, num);
        }
    }
}

void GrapheOriente::tarjanVisite(int u, vector<int>& rang, std::stack<int>& pile, vector<int>& profondeur, vector<int>& bas,
                                 vector<bool>& dansPile, int& num)
{
    profondeur[u] = num;
    bas[u] = num;
    num++;
    pile.push(u);
    dansPile[u] = true;

    for (int i = aps[u]; i < aps[u+1]; i++) {
        int v = fs[i].getCle();
        if (profondeur[v] == -1) {
            tarjanVisite(v, rang, pile, profondeur, bas, dansPile, num);
            bas[u] = std::min(bas[u], bas[v]);
        }
        else if (dansPile[v]) {
            bas[u] = std::min(bas[u], profondeur[v]);
        }
    }

    if (bas[u] == profondeur[u]) {
        int v;
        do {
            v = pile.top();
            pile.pop();
            dansPile[v] = false;
            rang[v] = bas[u];
        } while (u != v);
    }
}

bool GrapheOriente::calculDistance (int racine, vector<int> &dist)
{
    return false;
}

bool GrapheOriente::codagePrufer (vector <int> & prufer)
{
    return false;
}

void GrapheOriente::djikstra ( vector<vector<int>>& p, int s, vector<int>& d, vector<int>& pr) // p matrice des poids,d matrice distance, pr matrice predecesseurs, s
{
    int n = aps[0];
    pr.resize(n+1);
    d.resize(n+1);
    vector<int> inS(n+1); // inS[i] = 0 ou 1, pour dire quels sont les sommets qui restent a traiter
    // Initialisation des tableaux d, pr et inS
    for (int i = 1; i <= n; i++)
    {
        d[i] = p[s][i];
        inS[i] = 1;
        pr[i] = -1;
    }
    d[s] = 0;
    pr[s] = 0;
    inS[s] = 0; // on supprime le sommet s
    int ind = n - 1;
    while (ind > 0) {
        // Calcul du minimum selon d des sommets de S
        int m = INT_MAX;
        int j = -1;
        for (int i = 1; i <= n; i++)
        {
            if (inS[i] == 1 && d[i] < m)
            {
                m = d[i];
                j = i;
            }
        }
        if (j == -1) return;
        inS[j] = 0;
        ind--;
        int k = aps[j];
        while (this->fs[k].getCle() != 0)
        {
            if (inS[this->fs[k].getCle()] == 1)
            {
                int v = d[j] + p[j][this->fs[k].getCle()];
                if (v < d[this->fs[k].getCle()])
                {
                    d[this->fs[k].getCle()] = v;
                    pr[this->fs[k].getCle()] = j;
                }
            }
            k++;
        }
    }
}

bool GrapheOriente::lireGraphe(std::string nomFic)
{
        std::ifstream fic(nomFic);
        if(fic.is_open())
        {
            int n, m;
            fic >> n >> m;
            vector<vector<Sommet>> matrice(n,vector<Sommet>(n));
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    int s;
                    fic >> s;
                    matrice[i][j] = Sommet(s);
                }
            }
            GrapheOriente g(matrice,n,m);
            *this = g;
            return true;
        }
        return false;
}

