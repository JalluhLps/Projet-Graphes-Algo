#ifndef ARETE_H
#define ARETE_H

class Arete // Pour les besoins de Kruskal
{
public:
    Arete(int s, int t, double p);
    int getS() const;
    int getT() const;
    int getPoids() const;
private:
    int s, t; // 1ère et 2ème extrémité de l'arête
    double poids;
};

#endif // ARETE_H
