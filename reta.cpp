#include "reta.h"
#include <iostream>
#include <cmath>

Reta::Reta(int _x1, int _y1, int _x2, int _y2)
{
    x1 = _x1;
    x2 = _x2;
    y1 = _y1;
    y2 = _y2;
}

void Reta::draw(Screen &t)
{
    float tamanho, delta_x, delta_y, x, y, i;

    // Tamanho: Aproxima o tamanho da reta
    if( abs(x2 - x1) > abs(y2 - y1))
    {
        tamanho = abs(x2 - x1);
    }
    else
    {
        tamanho = abs(y2 - y1);
    }
    //seleciona o maior dos valores entre Delta_x e Delta_y como unidade de rasterização
    delta_x = (x2 - x1)/tamanho;
    delta_y = (y2 - y1)/tamanho;
    i = 0;
    x = x1;
    y = y1;
    while(i < tamanho)
    {
        t.setPixel(round(x), round(y));
        x += delta_x;
        y += delta_y;
        i = i + 1;
    }
}
