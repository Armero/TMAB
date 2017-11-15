#ifndef PESSOA_H
#define PESSOA_H
#include <string>

const int TAMANHO_MAXIMO_NOME = 60;

using namespace std;

class Pessoa
{
    public:
        static unsigned contPessoa;
        Pessoa(unsigned _Cd_Pessoa = 0, string _Nm_NomePessoa = "VAZIO");
        virtual ~Pessoa() {};

        unsigned GetCd_Pessoa() { return _Cd_Pessoa; };
        void SetCd_Pessoa(unsigned val) { _Cd_Pessoa = val; };
        string GetNm_NomePessoa() { return _Nm_NomePessoa; };
        void SetNm_NomePessoa(string val) {_Nm_NomePessoa = val;};

    private:
        unsigned _Cd_Pessoa;
        string _Nm_NomePessoa;
};

#endif // PESSOA_H
