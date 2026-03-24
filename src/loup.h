#ifndef LOUP_H
#define LOUP_H

#include "animal.h"

class Loup : public Animal
{
    public :
    Loup(int maxX, int maxY);
    Loup(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif