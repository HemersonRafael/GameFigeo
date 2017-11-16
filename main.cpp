#include <iostream>
#include "unistd.h"
#include "screen.h"
#include "extras.h"
#include <vector>
#include "figurageometrica.h"
#include <cstdio>
using namespace std;

int main(){

    Extras extras;
    //Jogador gamer;
    std::vector <FiguraGeometrica*> data;
    std::vector <char> brush;
    std::vector <std::string> gabarito;
    int sizeScreen[2] = {60,20};
    int microseconds = 1000000;

    string fileName = "figuras.csv";
    unsigned int sizeFile = 10;

    extras.randFigures(fileName.c_str(),sizeFile);

    extras.loadFigures("figuras.csv",sizeScreen,data,brush,gabarito);

    Screen tela(sizeScreen[0],sizeScreen[1]);

    for (unsigned int i=0; i < sizeFile; i++)
    {
        tela.setBrush(brush[i]);
        data[i]->draw(tela);
        cout << "Figura " << i+1 << ": " << gabarito[i]  << endl;
        cout << tela;
        tela.clear();
        cout << endl;
        usleep(microseconds);
    }
    system("read -p \"Pressione enter para sair\" saindo");
    remove("figuras.csv");
    return 0;
}

