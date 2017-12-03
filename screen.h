#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include <fstream>
using namespace std;
class Screen
{
private:
    // armazenam o tamanho da tela de desenho
    // no de linhas e de colunas
    int nlin, ncol;
    // guarda o caractere usado para desenhar
    char brush;
    // armazena a matriz da tela
    vector< vector<char> > mat;
public:
    // construtor da classe
    //! Inicializar o tamanho da matriz do desenho com o número de linhas e colunas atribuídos.
    Screen(int _nlin, int _ncol);
    // desenha um pixel da matriz usando o caratere
    // guardado em 'brush'
    //! Desenha o pixel na matriz na posição atribuída.
    void setPixel(int _x, int _y);
    // limpa a tela
    //! Limpa a matriz do desenho, preenchendo-a com espaços.
    void clear();
    // muda o caractere de desenho
    //! Define qual caracter será utilizado para desenha.
    void setBrush(char _brush = ' ');
    // envia a tela para um stream de saida
    //! Envia a matriz com o desenho para um stream de saída
    friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
