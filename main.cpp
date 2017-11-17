#include <iostream>
#include "unistd.h"
#include "screen.h"
#include "extras.h"
#include <vector>
#include "figurageometrica.h"
#include <cstdio>
#include <cstring>

int main(){

    Extras extras;
    unsigned int sizeFile = 10;

    string fileName = "figuras.csv";
    std::vector <FiguraGeometrica*> data;
    std::vector <char> brush;
    std::vector <std::string> gabarito;
    std::vector <std::string> resultado;
    int pontuacao = 0,controle ;
    int sizeScreen[2];
    int microseconds = 1000000;

    extras.randFigures(fileName.c_str(),sizeFile);

    extras.loadFigures("figuras.csv",sizeScreen,data,brush,gabarito);

    Screen tela(sizeScreen[0],sizeScreen[1]);

    for (unsigned int i=0; i < sizeFile; i++)
    {
        tela.setBrush(brush[i]);
        data[i]->draw(tela);

        std::cout << "Figura " << i+1  << " e um: "<< endl;
        std::cout << tela;
        std::cout << "Digite 1 - para reta, 2 - para retangulo, 3 - para circulo ou 4 - para triangulo:\n";
        std::cin >> controle;

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
        std::cout << endl;
        usleep(microseconds);
    }
    std::cout << "sua pontuacao foi de " << pontuacao << "pontos" << std::endl;
    for(int i=0;i<sizeFile;i++){
        std::cout << gabarito[i]<< " = " << resultado[i] << std::endl;
    }
    system("read -p \"Pressione enter para sair\" saindo");
    remove("figuras.csv");
    return 0;
}

