#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "figurageometrica.h"
#include "data.h"

using namespace std;

class Game
{
public:
    Game();
    virtual ~Game();
    void menu();
    void startGame();
    void rank();

private:
    string nome;
    Data data;
    unsigned int sizeFile;
    string fileName;
    vector <FiguraGeometrica*> figura;
    vector <char> brush;
    vector <string> gabarito;
    vector <string> resultado;
    int pontuacao;
    int sizeScreen[2];
    int microseconds;

};

#endif // GAME_H
