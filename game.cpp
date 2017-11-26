#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "unistd.h"
#include "figurageometrica.h"
#include "screen.h"
#include "data.h"
#include "game.h"

using namespace std;

Game::Game()
{
    nome = " ";
    score = 0;
    sizeFile = 10;
    fileName = "figuras.csv";
    pontuacao = 0;
    microseconds = 1000000;
}

Game::~Game()
{
    //dtor
}
void Game::setNome(string _nome)
{
    nome = _nome;
}
string Game::getNome()
{
    return nome;
}
void Game::setScore(int _score)
{
    score = _score;
}
int Game::getScore()
{
    return score;
}
void Game::startGame()
{
    int controle;

    data.randFigures(fileName.c_str(),sizeFile);

    data.loadFigures("figuras.csv",sizeScreen,figura,brush,gabarito);

    Screen tela(sizeScreen[0],sizeScreen[1]);

    for (unsigned int i=0; i < sizeFile; i++)
    {
        tela.setBrush(brush[i]);
        figura[i]->draw(tela);

        cout << "Figura " << i+1  << " e um: "<< endl;
        cout << tela;
        cout << "Digite \n 1 - reta 2 - retangulo  3 - circulo  4 - triangulo: ";
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
        string aux1 = gabarito[i] , aux2 =resultado[i];

        if( aux1 == aux2 ){
            pontuacao+=10;
        }
        else{
            pontuacao-=5;
        }

        tela.clear();
        cout << endl;
        usleep(microseconds);
        system("clear");
    }

    cout << "sua pontuacao foi " << pontuacao << " de 100" << " pontos" << endl;

        for(int i=0;i<sizeFile;i++){
            cout << gabarito[i]<< " = " << resultado[i] << endl;
         }

    system("read -p \"Pressione enter para sair\" saindo");
    remove("figuras.csv");
}

void Game::menu()
{
    int opcao;
    do{
        cout << "*************** Game Figeo ***************" << endl;
        cout << "MENU:" << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Rank dos jogadores" << endl;
        cout << "3 - Sair do jogo" << endl;
        cout << "Informe sua opcao:" << endl;
        cin >> opcao;
        if((opcao < 1) || (opcao >3)){
           cout << "A opcao informada  e invalida!" << endl;
        }
     }while((opcao < 1) || (opcao >3));

    switch (opcao) {
    case 1:
        startGame();
        break;
    case 2:

        break;
    case 3:

        break;

    }

}


