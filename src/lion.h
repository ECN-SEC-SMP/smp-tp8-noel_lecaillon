#ifndef LION_H
#define LION_H

#include "animal.h"

class Lion : public Animal
{
    public :
    Lion(int maxX, int maxY);
    Lion(int maxX, int maxY, int a, int b);
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif