#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "figurageometrica.h"
#include "screen.h"
#include "data.h"
#include "game.h"

using namespace std;

Game::Game()
{
    nome = " ";
    sizeFile = 10;
    fileName = "figuras.csv";
    pontuacao = 0;
    microseconds = 1000000;
}

Game::~Game()
{
    //dtor
}

void Game::startGame()
{
    int controle;

    remove("figuras.csv");

    data.randFigures(fileName.c_str(),sizeFile);

    data.loadFigures("figuras.csv",sizeScreen,figura,brush,gabarito);

    Screen tela(sizeScreen[0],sizeScreen[1]);

    cout << "Informe o seu nome: ";
    cin >> nome;
    cout << endl;

    for (unsigned int i=0; i < sizeFile; i++)
    {
        do{
            tela.setBrush(brush[i]);
            figura[i]->draw(tela);

            cout << "Figura " << i+1  << " e um: "<< endl;
            cout << tela;
            cout << "Digite \n 1 - reta 2 - retangulo  3 - circulo  4 - triangulo: ";
            cin >> controle;
            if((controle < 1) || (controle > 4)){
                cout << "Informe uma opcao valida!" << endl;
                system("read -p \"Pressione enter para continuar\" saindo");
                system("clear");

            }
        }while ((controle < 1) || (controle > 4));

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
        system("clear");
    }

    cout << nome <<" sua pontuacao foi " << pontuacao << " de 100" << " pontos" << endl;

    cout << "Para exibir o gabarito digite 1 - sim 2 - nao: ";
    cin >> controle;
    if(controle == 1){
        for(int i=0;i<sizeFile;i++){
            string aux1 = gabarito[i] , aux2 =resultado[i];

            if(aux1 == "reta"){
                cout << "Figura " << setw(2) << i+1  << " " <<gabarito[i] << setw(10) << " =  " << resultado[i] << setw(10) << " -> " ;
            }
            else if(aux1 == "circulo"){
                cout << "Figura " << setw(2) << i+1  << " " <<gabarito[i] << setw(7) << " =  " << resultado[i] << setw(7) << " -> ";
            }
            else{
                cout << "Figura " << setw(2) << i+1  << " " <<gabarito[i] << "  =  " << resultado[i] << "  -> ";
            }

            if(aux1 == aux2){
                cout << " CORETA" << endl;
            }
            else{
                cout << " INCORETA" << endl;
            }


        }
    }
    system("read -p \"Pressione enter para continuar\" saindo");
    remove("figuras.csv");
}

void Game::rank()
{

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
            system("read -p \"Pressione enter para continuar\" saindo");
            system("clear");
        }
    }while((opcao < 1) || (opcao >3));

    switch (opcao) {
    case 1:
        startGame();
        break;
    case 2:
        rank();
        break;
    case 3:
        system("read -p \"Pressione enter para sair\" saindo");
        break;

    }

}


