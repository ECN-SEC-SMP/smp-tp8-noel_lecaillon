#ifndef OURS_H
#define OURS_H

#include "animal.h"

class Ours : Animal
{
    public :
    Ours();
    void setAttaque();
    void deplace(int maxX, int maxY);
};


#endif