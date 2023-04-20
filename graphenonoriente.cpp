#include "graphenonoriente.h"

GrapheNonOriente::GrapheNonOriente(const vector<vector<Sommet>>& mat) : Graphe{mat}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Sommet>& fs, const vector<Sommet>& aps) : Graphe{fs, aps}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls) : Graphe{lp, ls}
{}


bool GrapheNonOriente::CodagePrufer(  vector <int> & pruf)
{
     // On créer une copie de la matrice car on va la modifier pour trouver le codage de prufer
    vector <vector <int>> Mat2D;
    Mat2D.resize(matrice.size() );


    for (int i = 0 ; i < matrice.size(); i++)
    {
        Mat2D[i].resize(  matrice[0].size()  );
        for ( int j = 0 ; j < matrice[0].size(); j++)
            Mat2D[i][j]= matrice[i][j].getCle();
    }
    //
    int nb_som = this->matrice.size();
    pruf.resize( matrice.size() -2);

    int k = 1;
    while (k <= nb_som-2)
    {
        int i = 1;
        while ( Mat2D[i][0] != 1  ) i++;
        int j = 1;
        while(  Mat2D[i][j] != 1) j++;

        pruf[k]=j;
        k++;
        Mat2D[i][j]=0;
        Mat2D[j][i]=0;
        Mat2D[i][0]=0;
        Mat2D[j][0]--;
    }
}

