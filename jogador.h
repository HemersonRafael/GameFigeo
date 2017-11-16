#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>

class Jogador
{
public:
    Jogador();
    virtual ~Jogador();
    void setNome(std::string _nome);
    std::string getNome();
    void setScore(int _score);
    int getScore();

protected:

private:
    std::string nome;
    int score;
};

#endif // JOGADOR_H
