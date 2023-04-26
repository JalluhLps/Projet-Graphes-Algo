#include "graphe.h"

Graphe::Graphe(const vector<vector<Sommet>>& mat, int n, int m) : matrice{mat}, n{n}, m{m}
{
    matrice2FsAps();
    matrice2Liste();
}

Graphe::Graphe(const vector<Sommet>& fs, const vector<int>& aps, int n, int m) : fs{fs}, aps{aps}, n{n}, m{m}
{
    fsAps2Liste();
    fsAps2Matrice();
}

Graphe::Graphe(const vector<Chainon>& lp, const vector<Chainon>& ls, int n, int m) : listePrincipale{lp},
    listeSecondaire{ls}, n{n}, m{m}
{
    liste2FsAps();
    liste2Matrice();
}

void Graphe::matrice2FsAps()
{
    // Réserve la bonne taille au 2 tabs pas de +1 car le nb de sommets et d'aretes n'est pas stocké dedans
    fs.resize(n+m);
    aps.resize(n);

    int k = 0; // car l'ind 0 ne sert pas à stocker la taille et +1 pour maintenir l'équilibre
    for (int i = 0; i < n; i++)
    {
        aps.push_back(k);
        for (int j = 0; j < n; j++)
            if (matrice[i][j].getCle() == 1)
                fs[k++] = Sommet{j+1};
        fs[k++] = Sommet{0};
    }
}

void Graphe::matrice2Liste()
{
    // On commence par vider les listes principales et secondaires
    listePrincipale.clear();
    listeSecondaire.clear();

    for (int i = 0; i < n; ++i)
    {
        Chainon* dernier = nullptr;
        for (int j = 0; j < n; ++j)
        {
            if (matrice[i][j].getCle() != 0) // s'il y a une arête entre i et j
            {
                Chainon* nouveau = new Chainon(matrice[i][j].getCle());
                if (dernier == nullptr) // premier Chainon de la liste principale
                {
                    listePrincipale.push_back(*nouveau);
                    dernier = &listePrincipale.back();
                } else
                { // ajout d'un Chainon à la liste secondaire
                    dernier->setLpSuivant(nouveau);
                    dernier = nouveau;
                    listeSecondaire.push_back(*nouveau);
                }
            }
        }
    }
}

void Graphe::fsAps2Matrice()
{
    // Réserve la bonne taille pour la matrice
    matrice.resize(n);
    for (int i = 0; i < n; i++)
        matrice[i].resize(n);

    int i = 0;
    for (unsigned j = 0; j < fs.size(); j++)
        if (fs[j].getCle() != 0)
            matrice[i][fs[j].getCle()] = 1;
        else
            i++;
}

void Graphe::fsAps2Liste()
{
    // On vide les deux listes principales et secondaires
    listePrincipale.clear();
    listeSecondaire.clear();

    // On ajoute des Chainons vides dans la liste principale
    for(int i=0; i<n+1; i++)
    {
        listePrincipale.push_back(Chainon(fs[i].getCle()));
    }

    // Pour chaque arc (i,j)
    for(int i=0; i<m; i++)
    {
        // On pointe vers le sommet i dans la liste principale
        Chainon *ptr = &listePrincipale[fs[i].getCle()];
        // On avance dans la liste secondaire de i jusqu'à atteindre sa fin
        while(ptr->getLsSuivant() != nullptr)
        {
            ptr = ptr->getLsSuivant();
        }
        // On ajoute un nouveau Chainon pour j à la fin de la liste secondaire de i
        ptr->setLsSuivant(&listePrincipale[aps[i]]);
    }

    // On remplit la liste secondaire
    for(int i=0; i<n+1; i++)
    {
        // On pointe vers le sommet i dans la liste principale
        Chainon *ptr = &listePrincipale[i];
        // On avance dans la liste secondaire de i jusqu'à atteindre sa fin
        while(ptr->getLsSuivant() != nullptr)
        {
            // On ajoute chaque Chainon j rencontré à la fin de la liste secondaire globale
            listeSecondaire.push_back(*(ptr->getLsSuivant()));
            ptr = ptr->getLsSuivant();
        }
        // On enlève la fin de la liste secondaire de i pour ne pas la compter deux fois
        ptr->setLsSuivant(nullptr);
    }
}

void Graphe::liste2Matrice()
{
    // Initialisation de la matrice d'adjacence n*n
    matrice.resize(n, std::vector<Sommet>(n, Sommet()));

    // Parcours de la liste principale
    for (int i = 0; i < n; i++)
    {
        Chainon* ptr = &listePrincipale[i];

        // Parcours de la liste secondaire
        while (ptr->getLsSuivant() != nullptr)
        {
            // Récupération de l'indice du sommet adjacent
            int j = ptr->getLsSuivant()->getCle();
            // Ajout d'une arête entre les sommets i et j dans la matrice d'adjacence
            matrice[i][j] = Sommet(1);
            // Passage au sommet suivant dans la liste secondaire
            ptr = ptr->getLsSuivant();
        }
    }
}

void Graphe::liste2FsAps()
{
    fs.clear();
    aps.clear();

    // Parcours de la liste principale pour initialiser le tableau aps
    for(unsigned i = 0; i < listePrincipale.size(); i++)
    {
        aps.push_back(fs.size()); // On ajoute l'indice de début de la liste secondaire de chaque sommet
        Chainon *ptr = &listePrincipale[i];

        // Parcours de la liste secondaire pour ajouter les sommets voisins
        while(ptr->getLsSuivant() != nullptr)
        {
            ptr = ptr->getLsSuivant();
            fs.push_back(ptr->getCle());
        }
    }

    aps.push_back(fs.size()); // On ajoute la taille de fs en dernier élément de aps
}



