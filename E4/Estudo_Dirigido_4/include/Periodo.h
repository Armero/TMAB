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

#ifndef PERIODO_H
#define PERIODO_H


class Periodo
{
    public:
        Periodo(unsigned Cd_Periodo, string Dt_Inicio, string Dt_Fim):
        _Cd_Periodo (Cd_Periodo),_Dt_Inicio (Dt_Inicio),_Dt_Fim (Dt_Fim) {};

        unsigned Get_Cd_Periodo() { return _Cd_Periodo; };
        void Set_Cd_Periodo(unsigned val) { _Cd_Periodo = val; };

        string Get_Dt_Inicio() { return _Dt_Inicio; };
        void Set_Dt_Inicio (string val) { _Dt_Inicio = val; };

        string Get_Dt_Fim() { return _Dt_Fim; };
        void Set_Dt_Fim(string val) { _Dt_Fim = val; };

    private:
        unsigned _Cd_Periodo;
        string _Dt_Inicio;
        string _Dt_Fim;
};

#endif // PERIODO_H
