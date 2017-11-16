#include "jogador.h"

Jogador::Jogador()
{
    nome = " ";
    score = 0;
}

Jogador::~Jogador()
{
    //dtor
}
void Jogador::setNome(std::string _nome)
{
    nome = _nome;
}
std::string Jogador::getNome()
{
    return nome;
}
void Jogador::setScore(int _score)
{
    score = _score;
}
int Jogador::getScore()
{
    return score;
}
