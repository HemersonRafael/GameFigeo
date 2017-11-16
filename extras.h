#ifndef EXTRAS_H
#define EXTRAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "figurageometrica.h"

class Extras
{
public:
    //!Cria um arquivo do tipo CSV e salva a forma de objetos como reta, retângulo, círculo e screen no nome do arquivo atribuído.
    void logCsv(std::string data, std::string filename, std::string header);
    //!Carregar o arquivo gerado pelo método randFigures, realizar a leitura e armazenar os dados em um vector de FiguraGeometrica.
    void loadFigures(std::string fileName, int sizeScreen [], std::vector<FiguraGeometrica*> &data, std::vector<char> &brush, std::vector <std::string> &gabarito);
    //!Gerar a forma de objetos como reta, retângulo, círculo e screen aleatoriamente e salva no arquivo figuras.csv.
    void randFigures( std::string fileName, int size );


};

#endif // EXTRAS_H
