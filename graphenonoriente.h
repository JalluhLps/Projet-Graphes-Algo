#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H

#include "graphe.h"

class GrapheNonOriente : public Graphe
{
public:
    // A revenir dessus
    GrapheNonOriente(const vector<vector<Sommet>>& matrice);
    GrapheNonOriente(const vector<Sommet>& fs, const vector<Sommet>& aps);
    GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls);

    bool codagePrufer (vector <int> & prufer); // Cedric Notes en bas de la fn à voir

 /*Je ne suis pas encore tout à fait sûre de ce qu'il faut mettre dedans */
};







#endif // GRAPHENONORIENTE_H
