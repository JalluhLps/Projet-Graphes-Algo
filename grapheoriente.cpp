#include "grapheoriente.h"

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

    for (int i = aps[u]; i < aps[u+1]; i++)
    {
        int v = fs[i].getCle();
        if (profondeur[v] == -1)
        {
            tarjanVisite(v, rang, pile, profondeur, bas, dansPile, num);
            bas[u] = std::min(bas[u], bas[v]);
        }
        else if (dansPile[v])
        {
            bas[u] = std::min(bas[u], profondeur[v]);
        }
    }

    if (bas[u] == profondeur[u])
    {
        int v;
        do
        {
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
