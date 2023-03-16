#include "sommetChainon.h"

sommetChainon::sommetChainon(int cle) : sommet{cle}
{
    d_lpSuiv = nullptr;
    d_lsSuiv = nullptr;
}

sommetChainon* sommetChainon::lpSuiv()
{
    return d_lpSuiv;
}
sommetChainon* sommetChainon::lsSuiv()
{
    return d_lsSuiv;
}
