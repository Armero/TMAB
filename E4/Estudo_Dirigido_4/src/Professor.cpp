#include "Professor.h"
#include <iostream>


unsigned Professor::contProfessor = 0;

Professor::Professor(unsigned Nu_Siape, string Ds_Titulo,
                     string Local_Gabinete, string Nu_Telefone,
                     string En_Email, string En_Web,
                     string Ic_Classe, Pessoa pessoa):
                     Pessoa(pessoa.GetCd_Pessoa(), pessoa.GetNm_NomePessoa())

{
    Set_Nu_SIAPE(Nu_Siape);
    Set_Ds_Titulo(Ds_Titulo);
    Set_Local_Gabinete(Local_Gabinete);
    Set_Nu_Telefone(Nu_Telefone);
    Set_En_Email(En_Email);
    Set_En_Web(En_Web);
    Set_Cd_Professor(contProfessor);
    Set_Ic_Classe(Ic_Classe);
    contProfessor++;
}
