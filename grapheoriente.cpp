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

void GrapheOriente::tarjan(int u, vector<int>& indices, vector<int>& low, stack<int>& pile, vector<bool>& dans_pile, vector<vector<int>>& composantes)
{
        static int index = 0;
        indices[u] = index;
        low[u] = index;
        index++;

        pile.push(u);
        dans_pile[u] = true;

        for (unsigned i = aps[u]; i < this->fs.size() && this->fs[i].getCle() == u; i++) {
            int v = this->matrice[u][i - aps[u]].getCle();
            if (indices[v] == -1) {
                tarjan(v, indices, low, pile, dans_pile, composantes);
                low[u] = std::min(low[u], low[v]);
            } else if (dans_pile[v]) {
                low[u] = std::min(low[u], indices[v]);
            }
        }

        if (low[u] == indices[u]) {
            vector<int> composante;
            int v;
            do {
                v = pile.top();
                pile.pop();
                dans_pile[v] = false;
                composante.push_back(v);
            } while (v != u);
            composantes.push_back(composante);
        }
}


vector<vector<int>> GrapheOriente::trouverCFC()
{
        int n = this->n;

        vector<int> indices(n, -1);
        vector<int> low(n, -1);
        vector<bool> dans_pile(n, false);
        stack<int> pile;
        vector<vector<int>> composantes;

        for (int u = 0; u < n; u++) {
            if (indices[u] == -1) {
                tarjan(u, indices, low, pile, dans_pile, composantes);
            }
        }

        return composantes;
}

int trouver_composante(int u, vector<vector<int>>& composantes) {
        for (unsigned i = 0; i < composantes.size(); i++) {
            for (int v : composantes[i]) {
                if (v == u) {
                    return i;
                }
            }
        }
        return -1; // Ne devrait jamais arriver
}

vector<vector<int>> GrapheOriente::trouverGrapheReduit(vector<vector<int>>& composantes)
{
        int nb_composantes = composantes.size();
        vector<vector<int>> graphe_reduit(nb_composantes, vector<int>(nb_composantes, 0));

        // Ajouter les arêtes entre les nœuds du graphe réduit
        for (int u = 0; u < nb_composantes; u++) {
            for (int v : composantes[u]) {
                int cu = trouver_composante(u, composantes);
                int cv = trouver_composante(v, composantes);
                if (cu != cv) {
                    graphe_reduit[cu][cv] = 1;
                }
            }
        }

        return graphe_reduit;
}

void GrapheOriente::trouver_bases(vector<vector<int>>& graphe_reduit, vector<vector<int>>& composantes) {
        int nb_composantes = composantes.size();
        for (int i = 0; i < nb_composantes; i++) {
            for (int j = this->aps[i]; j < this->aps[i+1]; j++) {
                int k = trouver_composante(graphe_reduit[i][j], composantes);
                if (k != i) {
                    graphe_reduit[k][this->aps[k+1]] = i;
                    this->aps[k+1]++;
                }
            }
        }
}
