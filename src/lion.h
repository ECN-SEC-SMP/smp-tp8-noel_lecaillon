#ifndef LION_H
#define LION_H

#include "animal.h"

class Lion : Animal
{
    public :
    Lion();
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif