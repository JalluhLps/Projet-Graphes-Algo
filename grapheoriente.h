#ifndef GRAPHEORIENTE_H
#define GRAPHEORIENTE_H

#include "graphe.h"

class GrapheOriente : public Graphe
{
public:
    // A revenir dessus
    GrapheOriente(const vector<vector<Sommet>>& matrice);
    GrapheOriente(const vector<Sommet>& fs, const vector<Sommet>& aps);
    GrapheOriente(const vector<Chainon>& lp, const vector<Chainon>& ls);

    /** Je ne suis pas encore tout à fait sûre de ce qu'il faut mettre dedans */
};

#endif // GRAPHEORIENTE_H
