#include <queue>
#include "graphenonoriente.h"

GrapheNonOriente::GrapheNonOriente(const vector<vector<Sommet>>& mat, int n, int m) : Graphe{mat, n, m}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Sommet>& fs, const vector<int>& aps, int n, int m) : Graphe{fs, aps, n, m}
{}

GrapheNonOriente::GrapheNonOriente(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m) : Graphe{lp, ls, n, m}
{}

void GrapheNonOriente::rang(vector<int>& rang) // Algorithme de Kahn
{
    // Initialisation du vecteur de rangs à -1
    rang.resize(n, -1); // n => nb de sommets dans le graphe

    // Calcul du degré de chaque sommet
    vector<int> deg(n, 0);
    for (int i = 1; i <= n; i++)
    {
        // Parcours de la liste des sommets adjacents
        int t = this->aps[i];
        while (this->fs[t].getCle() > 0)
        {
            // Incrémentation du degré des deux sommets adjacents
            deg[i - 1]++;
            deg[this->fs[t].getCle() - 1]++;
            t++;
        }
    }

    // Initialisation de la file avec les sommets de degré 1
    std::queue<int> file;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            file.push(i + 1);
            // Le rang des sommets de degré 1 est 0
            rang[i] = 0;
        }
    }

    // Calcul des rangs pour les autres sommets
    while (!file.empty())
    {
        // On récupère le sommet en tête de file
        int u = file.front();
        file.pop();

        // On parcourt la liste de ses voisins
        int t = this->aps[u];
        while (this->fs[t].getCle() > 0)
        {
            int v = this->fs[t].getCle();
            // Si le voisin v n'a pas encore de rang
            if (rang[v - 1] == -1)
            {
                // On diminue le degré de v et on teste s'il devient de degré 1
                deg[v - 1]--;
                if (deg[v - 1] == 1)
                {
                    // On ajoute v à la file et on lui attribue un rang en fonction de u
                    file.push(v);
                    rang[v - 1] = rang[u - 1] + 1;
                }
            }
            t++;
        }
    }
}

bool GrapheNonOriente::codagePrufer(vector<int> &pruf)
{
     // On créer une copie de la matrice car on va la modifier pour trouver le codage de prufer
    vector<vector<int>> Mat2D;
    Mat2D.resize(matrice.size());


    for (unsigned i = 0 ; i < matrice.size(); i++)
    {
        Mat2D[i].resize(matrice[0].size());
        for ( unsigned j = 0 ; j < matrice[0].size(); j++)
            Mat2D[i][j]= matrice[i][j].getCle();
    }
    //
    int nb_som = this->matrice.size();
    pruf.resize(matrice.size() -2);

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

    return true;
}



bool GrapheNonOriente::calculDistance (int racine, vector<int> &dist)
{
    vector <int> fil;
    fil.reserve(fs.size() );
    dist.resize(this->fs.size());

    fil[0] = racine;

    for (unsigned i = 0; i < dist.size(); i++)
        dist[i] = -1;
    dist[racine] = 0;

    int i = 0, j = 1, k = 0, ifin, s, it;
    Sommet t (-1);
    while ( i < j ) // tant que la file d’attente n’est pas vide
    {
        k++;
        ifin = j;
        while (i < ifin) // parcourir le bloc courant
        {
            i++;
            s = fil[i];
            it = this->aps[s];
            t = fs[it].getCle();
            while (t.getCle() > 0) // parcourir tous les successeurs de chaque sommet du bloc courant
            {
                if (dist[t.getCle()] == -1) // Si le successeur du sommet courant n’est pas encore marqué
                {
                    j++;
                    fil[j] = t.getCle(); // on le place dans le bloc suivant en préparation et on lui affecte la distance courante
                    dist[t.getCle()] = k;
                }
                t = fs[it];
                it++;
            }
        }
    }

    return true;
   }
