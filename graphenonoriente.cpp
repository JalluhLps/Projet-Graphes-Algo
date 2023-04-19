#include "graphenonoriente.h"

GrapheNonOriente::GrapheNonOriente(const vector<vector<Sommet>>& mat) : Graphe{mat}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Sommet>& fs, const vector<Sommet>& aps) : Graphe{fs, aps}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls) : Graphe{lp, ls}
{}

