#ifndef PIERRE_H
#define PIERRE_H

#include "animal.h"

class Pierre : public Animal
{
    public :
    Pierre(int maxX, int maxY);
    Pierre(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif