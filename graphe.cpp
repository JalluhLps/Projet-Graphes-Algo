#include "graphe.h"

Graphe::Graphe(const vector<vector<Sommet>>& mat) : matrice{mat}, actif{MAT}
{}

Graphe::Graphe(const vector<Sommet>& fs, const vector<Sommet>& aps) : fs{fs}, aps{aps}, actif{FS}
{}

Graphe::Graphe(const vector<Chainon>& lp, const vector<Chainon>& ls) : listePrincipale{lp}, listeSecondaire{ls}, actif{LISTE}
{}

bool Graphe::isMatrice() const
{
    return actif == MAT;
}

bool Graphe::isFsAps() const
{
    return actif == FS;
}

bool Graphe::isListe() const
{
    return actif == LISTE;
}


// NEED APS et FS
bool Graphe::calculDistance (int racine, vector<int> &dist )
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
            it = this->aps[s].getCle();
            t = fs[it].getCle();
            while (t.getCle() > 0) // parcourir tous les successeurs de chaque sommet du bloc courant
                {
                if (dist[t.getCle()] == -1) // Si le successeur du sommet courant n’est pas encore marqué
                    {
                    j++;
                    fil[j] = t.getCle(); // on le place dans le bloc suivant en préparation et on lui affecte la distance courante
                    dist[t.getCle()] = k; // variante : dist[t] = dist[fil[i]]+1;
                    }
                t = fs[it];
                it++;
                }
            }
        }
    return true;
   }
