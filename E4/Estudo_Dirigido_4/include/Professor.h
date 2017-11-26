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

#ifndef PROFESSOR_H
#define PROFESSOR_H


#include "Pessoa.h"

class Professor
{
    public:
        Professor(unsigned Nu_Siape, string Ds_Titulo,
                  string Local_Gabinete, string Nu_Telefone,
                  string En_Email, string En_Web,
                  string Ic_Classe, unsigned Cd_Professor,
                  unsigned Cd_Pessoa):
                  _Nu_SIAPE (Nu_Siape), _Ds_Titulo (Ds_Titulo),
                  _Local_Gabinete (Local_Gabinete),
                  _Nu_Telefone (Nu_Telefone), _En_Email (En_Email),
                  _En_Web (En_Web), _Ic_Classe (Ic_Classe),
                  _Cd_Professor (Cd_Professor),
                  _Cd_Pessoa(Cd_Pessoa) {};

        unsigned Get_Nu_SIAPE() { return _Nu_SIAPE; }
        void Set_Nu_SIAPE(unsigned val) { _Nu_SIAPE = val; }
        string Get_Ds_Titulo() { return _Ds_Titulo; }
        void Set_Ds_Titulo(string val) { _Ds_Titulo = val; }
        string Get_Local_Gabinete() { return _Local_Gabinete; }
        void Set_Local_Gabinete(string val) { _Local_Gabinete = val; }
        string Get_Nu_Telefone() { return _Nu_Telefone; }
        void Set_Nu_Telefone(string val) { _Nu_Telefone = val; }
        string Get_En_Email() { return _En_Email; }
        void Set_En_Email(string val) { _En_Email = val; }
        string Get_En_Web() { return _En_Web; }
        void Set_En_Web(string val) { _En_Web = val; }
        unsigned Get_Cd_Professor() { return _Cd_Professor; }
        void Set_Cd_Professor(unsigned val) { _Cd_Professor = val; }
        string Get_Ic_Classe() { return _Ic_Classe; }
        void Set_Ic_Classe(string val) { _Ic_Classe = val; }
        unsigned Get_Cd_Pessoa () {return _Cd_Pessoa;}
        void Set_Cd_Pessoa (unsigned val) {_Cd_Pessoa = val;}

    private:
        unsigned _Nu_SIAPE;
        string _Ds_Titulo;
        string _Local_Gabinete;
        string _Nu_Telefone;
        string _En_Email;
        string _En_Web;
        unsigned _Cd_Professor;
        string _Ic_Classe;
        unsigned _Cd_Pessoa;
};

#endif // PROFESSOR_H
