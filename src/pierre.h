#ifndef PIERRE_H
#define PIERRE_H

#include "animal.h"

class Pierre : Animal
{
    public :
    Pierre();
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif