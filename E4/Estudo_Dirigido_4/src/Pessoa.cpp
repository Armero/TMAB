#include "Pessoa.h"

unsigned Pessoa::contPessoa = 0;
Pessoa::Pessoa(unsigned _Cd_Pessoa, string _Nm_NomePessoa)
{
    SetCd_Pessoa(_Cd_Pessoa);
    SetNm_NomePessoa(_Nm_NomePessoa);
}
