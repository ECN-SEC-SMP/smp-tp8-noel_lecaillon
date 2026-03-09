#ifndef LOUP_H
#define LOUP_H

#include "animal.h"

class Loup : Animal
{
    public :
    Loup();
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif