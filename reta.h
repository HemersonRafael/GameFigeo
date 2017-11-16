#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

class Reta: public FiguraGeometrica
{
private:
    int x1,x2,y1,y2;
    std::string tipo;

public:
    //!Inicializar a posição inicial e final de uma reta.
    Reta(int _x1, int _y1, int _x2, int _y2);
    //!Desenha a forma do objeto reta.
    void draw(Screen &t);
    std::string getTipo();
};

#endif // RETA_H


