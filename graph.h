#ifndef GRAPH_H
#define GRAPH_H

#include <vector>


class graph {
public:

    bool vApsFs(); // permet de savoir si fs aps sont calculés
    bool vMatriceAdj(); // permet de savoir si la matrice adj est calculée
    bool vListesSeconPrim();  // permet de savoir si les listes secondaires et primaires sont calculées

private:
    std::vector<int> fs;
    std::vector<int> aps;

    std::vector<std::vector<int>> matriceAdj;

    std::vector<int> listePrincipal;
    std::vector<int> listeSecondaire;

};

#endif // GRAPH_H
