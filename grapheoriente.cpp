#include "grapheoriente.h"

GrapheOriente::GrapheOriente(const vector<vector<Sommet>>& mat) : Graphe{mat}
{}

GrapheOriente::GrapheOriente(const vector<Sommet>& fs, const vector<Sommet>& aps) : Graphe{fs, aps}
{}

GrapheOriente::GrapheOriente(const vector<Chainon>& lp, const vector<Chainon>& ls) : Graphe{lp, ls}
{}

