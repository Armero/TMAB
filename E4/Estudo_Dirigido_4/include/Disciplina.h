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

#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>

using namespace std;


class Disciplina
{
    public:
        Disciplina(string Cd_Disciplina, string Nm_Disciplina,
                   unsigned Qt_Creditos, string Ds_Ementa,
                   string Ds_Bibliografia, unsigned Cd_Grade,
                   string Ic_Disciplina):
                   _Cd_Disciplina (Cd_Disciplina),
                   _Nm_Disciplina (Nm_Disciplina),
                   _Qt_Creditos (Qt_Creditos),
                   _Ds_Ementa (Ds_Ementa),
                   _Ds_Bibliografia (Ds_Bibliografia),
                   _Cd_Grade (Cd_Grade),
                   _Ic_Disciplina(Ic_Disciplina) {};

        string Get_Cd_Disciplina() { return _Cd_Disciplina; }
        void Set_Cd_Disciplina(string val) { _Cd_Disciplina = val; }

        string Get_Nm_Disciplina() { return _Nm_Disciplina; }
        void Set_Nm_Disciplina(string val) { _Nm_Disciplina = val; }

        string Get_Ds_Ementa() { return _Ds_Ementa; }
        void Set_Ds_Ementa(string val) { _Ds_Ementa = val; }

        unsigned Get_Qt_Creditos() { return _Qt_Creditos; }
        void Set_Qt_Creditos(unsigned val) { _Qt_Creditos = val; }

        string Get_Ds_Bibliografia() { return _Ds_Bibliografia; }
        void Set_Ds_Bibliografia(string val) { _Ds_Bibliografia = val; }

        unsigned GetCd_Grade() { return _Cd_Grade; }
        void SetCd_Grade(unsigned val) { _Cd_Grade = val; }

        string Get_Ic_Disciplina () {return _Ic_Disciplina;}
        void Set_Ic_Disciplina (string val) { _Ic_Disciplina = val; }


    private:
        string _Cd_Disciplina;
        string _Nm_Disciplina;
        string _Ds_Ementa;
        unsigned _Qt_Creditos;
        string _Ds_Bibliografia;
        unsigned _Cd_Grade;
        string _Ic_Disciplina; //Indicador de tipo de disciplina
};

#endif // DISCIPLINA_H
