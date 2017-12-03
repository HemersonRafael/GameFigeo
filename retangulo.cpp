#include "retangulo.h"
#include "reta.h"
#include <cmath>

Retangulo::Retangulo(int _x0, int _y0, int _altura, int _largura)
{
    x = _x0;
    y = _y0;
    altura = _altura;
    largura = _largura;
}

void Retangulo::draw(Screen &t)
{

    Reta r1(y, x+largura-1, y+altura, x+largura-1);
    r1.draw(t);
    Reta r2(y, x, y, x+largura-1);
    r2.draw(t);
    Reta r3(y, x, y+altura-1, x);
    r3.draw(t);
    Reta r4(y+altura-1, x, y+altura-1, x+largura-1);
    r4.draw(t);

}
