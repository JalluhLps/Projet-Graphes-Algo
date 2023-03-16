#ifndef SOMMETCHAINON_H
#define SOMMETCHAINON_H

#include "sommet.h"

class sommetChainon : sommet {
public:
    sommetChainon( int cle);
    sommetChainon* lpSuiv();
    sommetChainon* lsSuiv();
private:
    sommetChainon * d_lpSuiv;
    sommetChainon * d_lsSuiv;

};
#endif // SOMMETCHAINON_H
