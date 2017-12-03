#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"

class Circulo : public FiguraGeometrica
{
private:
    int x;
    int y;
    int r;
    int fill;    
public:
    //!Inicializar a posição inicial, raio e se é ou não preenchido o círculo.
    Circulo(int _x, int _y, int _r, int _fill);
    //!Desenha a forma do objeto do círculo.
    void draw(Screen &t);
    //!Trasnlada o pixel informado de um desenho.
    void translade(int _x, int _y, Screen &t );
};

#endif // CIRCULO_H
