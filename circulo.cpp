#include "circulo.h"
#include <cmath>
#define SIN 0.707106781

Circulo::Circulo(int _x, int _y, int _r, int _fill)
{
    x = _x;
    y = _y;
    r = _r;
    fill = _fill;
    tipo = "circulo";
}

void Circulo::translade(int _x, int _y, Screen &t )
{
    float xinicial = _x*SIN - _y*SIN;
    float yinicial = _x*SIN + _y*SIN;

    for(int i =0 ; i< 7; i++)
    {
        t.setPixel(round(xinicial+ x), round(yinicial + y));
        float tempX = xinicial;
        float tempY = yinicial;

        xinicial = tempX*SIN - tempY*SIN;
        yinicial = tempX*SIN + tempY*SIN;
    }
}

void Circulo::draw(Screen &t)
{
    float _x, _y, d;
    _x = 0;
    _y = r;
    d = 1 - r;

    t.setPixel(round(x-r), round(y));
    t.setPixel(round(x+r), round(y));
    t.setPixel(round(x), round(y-r));
    t.setPixel(round(x), round(y+r));

    while(_y > _x)
    {
        if(d < 0)
        {
            d = d + (2 * _x) + 3;
            _x = _x + 1;
        }
        else
        {
            d = d + (2 * (_x - _y)) + 5;
            _x +=  1;
            _y -=  1;
        }

        t.setPixel(round(_x + x), round(_y + y));

        if(fill)
        {
            for(int i=round(x - r); i<round(x + r); i++)
            {
                for(int j=round(y - r); j<round(y + r); j++)
                {
                    if( (pow(round(i - x),2) + pow(round(j - y),2)) <= pow(r,2))
                    {
                        t.setPixel(i,j);
                    }
                }
            }
        }
        translade(_x,_y,t);
    }
}
