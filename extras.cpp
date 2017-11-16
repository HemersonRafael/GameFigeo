#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "extras.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include "triangulo.h"


void Extras::logCsv(std::string data, std::string filename, std::string header)
{
    std::ofstream myfile;

    while(true)
    {
        myfile.open(filename.c_str(), std::ios::in);
        if (myfile.is_open() && myfile.good())
        {
            myfile.close();
            myfile.open(filename.c_str(), std::ios::app);
            myfile << data <<std::endl;
            return;
        }
        else
        {
            myfile.open(filename.c_str(), std::ios::app);
            if (myfile.is_open() && myfile.good())
            {
                myfile << header << std::endl;
                myfile.close();
            }
        }
    }
}

void Extras::loadFigures(std::string fileName, int sizeScreen[], std::vector<FiguraGeometrica *> &data, std::vector<char> &brush, std::vector<string> &gabarito)
{

    srand(time(0));
    int figura;
    int vetorDeCaracteristicas[4];
    std::string aux; // variavel auxiliar
    std::string cell; // represeta uma celula de uma linha pro exemplo a palavra "retangle" da linha: retangle,10,20,30,40,50
    std::ifstream file (fileName.c_str());
    char brushTemp;

    if (!file.is_open() && !file.good())
    {
        std::cout << "Erro to read: " << fileName << std::endl;
        return;
    }

    getline(file,aux);
    std::stringstream lineStreamHeader( aux );

    for (int i =0; getline(lineStreamHeader,cell,','); i++ )
    {
        sizeScreen[i] = std::stoi(cell);
    }

    while( getline(file,aux) )
    {
        std::stringstream lineStream(aux);

        for (int contCell = 0; getline(lineStream, cell, ','); contCell++)
        {
            if(contCell == 0)
            {

                if(cell == "reta")
                {
                    figura = 1;
                    gabarito.push_back(cell);
                }
                else if (cell == "retangulo")
                {
                    figura = 2;
                    gabarito.push_back(cell);
                }
                else if (cell == "circulo")
                {
                    figura = 3;
                    gabarito.push_back(cell);
                }
                else if(cell == "triangulo") {
                    figura = 4;
                    gabarito.push_back(cell);
                }
            }
            else if (contCell < 5)
            {
                vetorDeCaracteristicas[contCell -1] = std::stoi(cell);
            }
            else
            {
                brushTemp =  std::stoi(cell);
                brush.push_back(brushTemp);
            }

        }

        switch (figura)
        {
        case 1:
            data.push_back( new Reta(vetorDeCaracteristicas[0],vetorDeCaracteristicas[1],
                                     vetorDeCaracteristicas[2],vetorDeCaracteristicas[3]) );
            break;

        case 2:
            data.push_back( new Retangulo(vetorDeCaracteristicas[0],vetorDeCaracteristicas[1],
                                          vetorDeCaracteristicas[2],vetorDeCaracteristicas[3]) );
            break;

        case 3:
            data.push_back( new Circulo(vetorDeCaracteristicas[0],vetorDeCaracteristicas[1],
                                        vetorDeCaracteristicas[2], vetorDeCaracteristicas[3]) );
            break;

        case 4:
            data.push_back( new Triangulo(vetorDeCaracteristicas[0],vetorDeCaracteristicas[1],
                                        vetorDeCaracteristicas[2], vetorDeCaracteristicas[3]) );
            break;

        }
    }
}

void Extras::randFigures(std::string fileName, int size)
{
    srand(time(0));
    std::string data;
    std::string header = "20,20";
    int figura;
    int caracteristicasAleatorias[4];
    unsigned int brushAleatorio;

    for(int i =0; i<size; i++)
    {

        figura = rand() % 4 + 1; // gera um valor entre 1 e 3;

        switch (figura)
        {
        case 1:{
            data = "reta";
            int teste1 = rand()%6 +1;
            int chave = rand()%4 + 1;
            int teste2 = rand()%13 + 5;
            if(chave == 1){
                caracteristicasAleatorias[0]= teste1;
                caracteristicasAleatorias[1]=teste1;
                caracteristicasAleatorias[2]=teste1;
                caracteristicasAleatorias[3]=teste2;
            }
            else if(chave == 2){
                caracteristicasAleatorias[0]= teste1;
                caracteristicasAleatorias[1]=teste1;
                caracteristicasAleatorias[2]=teste2;
                caracteristicasAleatorias[3]=teste1;
            }
            else if(chave == 3){
                caracteristicasAleatorias[0]= teste1;
                caracteristicasAleatorias[1]=teste1;
                caracteristicasAleatorias[2]=teste2;
                caracteristicasAleatorias[3]=teste2;
            }
            else if(chave == 4){
                caracteristicasAleatorias[0]= teste1;
                caracteristicasAleatorias[1]=1;
                caracteristicasAleatorias[2]=1;
                caracteristicasAleatorias[3]=teste1;
            }

            for(int i =0; i<4; i++){
                data+= "," + std::to_string(caracteristicasAleatorias[i]) ;
            }

            break;

        }
        case 2:{
            data = "retangulo";
            for(int i =0; i<4; i++)
            {
                if(i<2)
                {
                    caracteristicasAleatorias[i] = rand() % 5 + 1*i;
                }
                else
                {
                    caracteristicasAleatorias[i] = rand() % 17 + 1;
                }
                data+= "," + std::to_string(caracteristicasAleatorias[i]) ;
            }
            break;
        }
        case 3:{

            data = "circulo";
            for(int i =0; i<4; i++)
            {
                if(i<2)
                {
                    caracteristicasAleatorias[i] = 10;
                }
                else if(i == 2)
                {
                    caracteristicasAleatorias[i] = rand() % 5 + 4;
                }

                else if(i==3)
                {

                    caracteristicasAleatorias[3]= 0;
                }

                    data+= "," + std::to_string(caracteristicasAleatorias[i]) ;

            }
            break;
            }
        case 4:{
            int y = 10;
            int x1 =rand()%14 + 5;
            int x2 =y;
            int x3 =x2;

            data = "triangulo";
            caracteristicasAleatorias[0]= x1;
            caracteristicasAleatorias[1]= y;
            caracteristicasAleatorias[2]= x2;
            caracteristicasAleatorias[3]= x3;


            for(int i =0; i<4; i++)
            {
                data+= "," + std::to_string(caracteristicasAleatorias[i]) ;
            }
            break;
        }
        }

        brushAleatorio = 'o';
        data+= "," + std::to_string(brushAleatorio);
        logCsv(data.c_str(),fileName.c_str(),header.c_str());
    }
    std::cout << "Done!" <<std::endl;
}

