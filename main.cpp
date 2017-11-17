#include <iostream>
#include "unistd.h"
#include "screen.h"
#include "extras.h"
#include <vector>
#include "figurageometrica.h"
#include <cstdio>
#include <cstring>
using namespace std;

int main(){

    Extras extras;
    //Jogador gamer;
    unsigned int sizeFile = 10;

    string fileName = "figuras.csv";
    std::vector <FiguraGeometrica*> data;
    std::vector <char> brush;
    std::vector <std::string> gabarito;
    std::vector <std::string> resultado;
    int pontuacao = 0,controle ;
    int sizeScreen[2] = {60,20};
    int microseconds = 1000000;

    extras.randFigures(fileName.c_str(),sizeFile);

    extras.loadFigures("figuras.csv",sizeScreen,data,brush,gabarito);

    Screen tela(sizeScreen[0],sizeScreen[1]);

    for (unsigned int i=0; i < sizeFile; i++)
    {
        tela.setBrush(brush[i]);
        data[i]->draw(tela);


        cout << tela;
        cout << "Figura " << i+1  << " e um: "<< endl;
        cout << "Digite 1 - para reta, 2 - para retangulo, 3 - para circulo, 4 - para tringulo";
        cin >> controle;

        switch (controle) {
            case 1:
                resultado.push_back ( "reta");
                break;
            case 2:
                resultado.push_back("retangulo");
                break;
            case 3:
                resultado.push_back( "circulo");
                break;
            case 4:
                resultado.push_back("triangulo");
                break;

            default:

                break;
        }
        std::string aux1 = gabarito[i] , aux2 =resultado[i];
        if( aux1 == aux2 ){
            pontuacao+=10;
        }
        else{
            pontuacao-=5;
        }

        tela.clear();
        cout << endl;
        usleep(microseconds);
    }
    cout << "sua pontuacao foi de " << pontuacao << "pontos" << endl;
    system("read -p \"Pressione enter para sair\" saindo");
    remove("figuras.csv");
    return 0;
}

