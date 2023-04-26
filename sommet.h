#ifndef SOMMET_H
#define SOMMET_H

class Sommet
{
public:
    Sommet();
    Sommet(int cle);
    int getCle() const;
    void setCle( int newKey );
private:
    int cle;
};

#endif // SOMMET_H
