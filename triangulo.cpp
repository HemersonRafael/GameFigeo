#include "triangulo.h"
#include "reta.h"


Triangulo::Triangulo(int _x1, int _y1, int _x2, int _x3)
{
    x1 = _x1;
    x2 = _x2;
    x3 = _x3;
    y1 = _y1;
    tipo = "triangulo";
}


void Triangulo::draw(Screen &t)
{
    Reta r1(x1,y1,x2,(y1/2));
    r1.draw(t);
    Reta r2(x1,y1,x3,(y1/2)+y1);
    r2.draw(t);
    Reta r3(x2,(y1/2),x3,(y1/2)+y1);
    r3.draw(t);
}
