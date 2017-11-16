#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"
#include <string>

class FiguraGeometrica
{

public:
    //!Uma função virtual pura que instruí a desenhar em um objeto do tipo screen.
    virtual void draw(Screen &t)=0;
};

#endif // FIGURAGEOMETRICA_H
