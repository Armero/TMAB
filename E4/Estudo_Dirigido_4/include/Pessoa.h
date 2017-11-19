/**
* UFRJ - Universidade Federal do Rio de Janeiro
* IM - Instituto de Matem�tica
* DMA - Departamento de Matem�tica Aplicada
*
* TMAB - Programa��o C/C++ & Banco de Dados
* ParteII - Programa��o OO em C++
*
* Descri��o do Estudo Dirigido 04
* Prazo de Entrega: 21 de novembro de 2017
*
* Prof. Milton Ramirez (milton@labma.ufrj.br)
* Rio de Janeiro, 13 de novembro de 2017
* Grupo K
* Felipe Claudio
* Thiago Koster Lago
**/

#ifndef PESSOA_H
#define PESSOA_H
#include <string>

const int TAMANHO_MAXIMO_NOME = 60;

using namespace std;

class Pessoa
{
    public:
        Pessoa(unsigned Cd_Pessoa, string Nm_NomePessoa):
        _Cd_Pessoa(Cd_Pessoa), _Nm_NomePessoa (Nm_NomePessoa) {};
        virtual ~Pessoa() {};

        unsigned Get_Cd_Pessoa() { return _Cd_Pessoa; };
        void Set_Cd_Pessoa(unsigned val) { _Cd_Pessoa = val; };
        string Get_Nm_NomePessoa() { return _Nm_NomePessoa; };
        void Set_Nm_NomePessoa(string val) {_Nm_NomePessoa = val;};

    private:
        unsigned _Cd_Pessoa;
        string _Nm_NomePessoa;
};

#endif // PESSOA_H
