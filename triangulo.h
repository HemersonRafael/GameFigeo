#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <figurageometrica.h>

class Triangulo : public FiguraGeometrica
{
private:
    int x1, y1, x2, x3;
public:
    Triangulo(int _x1, int _y1, int _x2, int _x3);
    void draw(Screen &t);
};

#endif // TRIANGULO_H
