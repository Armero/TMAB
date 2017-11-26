/**
* UFRJ - Universidade Federal do Rio de Janeiro
* IM - Instituto de Matemática
* DMA - Departamento de Matemática Aplicada
*
* TMAB - Programação C/C++ & Banco de Dados
* ParteII - Programação OO em C++
*
* Descrição do Estudo Dirigido 04
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
        Pessoa(unsigned Cd_Pessoa, string Nm_NomePessoa, string Ds_SexPessoa, unsigned Nu_IdadePessoa):
        _Cd_Pessoa(Cd_Pessoa), _Nm_NomePessoa (Nm_NomePessoa) , _Ds_SexPessoa (Ds_SexPessoa), _Nu_IdadePessoa (Nu_IdadePessoa){};
        virtual ~Pessoa() {};

        unsigned Get_Cd_Pessoa() { return _Cd_Pessoa; };
        void Set_Cd_Pessoa(unsigned val) { _Cd_Pessoa = val; };

        string Get_Nm_NomePessoa() { return _Nm_NomePessoa; };
        void Set_Nm_NomePessoa(string val) {_Nm_NomePessoa = val;};

        string Get_Ds_SexPessoa() {return _Ds_SexPessoa;};
        void Set_Ds_SexPessoa(string val)
        {
         if(val.at(0) == 'm' || val.at(0) == 'M')
            _Ds_SexPessoa = "Masculino";
         else if(val.at(0) == 'f' || val.at(0) == 'F')
            _Ds_SexPessoa == "Feminino";
        };

        unsigned Get_Nu_IdadePessoa() { return _Nu_IdadePessoa; };
        void Set_Nu_IdadePessoa (unsigned val) {_Nu_IdadePessoa = val;};

    private:
        unsigned _Cd_Pessoa;
        string _Nm_NomePessoa;
        string _Ds_SexPessoa;
        unsigned _Nu_IdadePessoa;
};

#endif // PESSOA_H
