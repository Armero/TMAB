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

#ifndef ATIVIDADE_H
#define ATIVIDADE_H


class Atividade
{
    public:
        Atividade(unsigned Cd_Atividade, string Nm_Titulo_JIE,
                  float Nu_Nota, string Ic_Tipo_Atividade,
                  unsigned Nu_Dre, unsigned Nu_Orientador):
                  _Cd_Atividade(Cd_Atividade), _Nm_Titulo_JIE (Nm_Titulo_JIE),
                  _Nu_Nota (Nu_Nota), _Ic_Tipo_Atividade (Ic_Tipo_Atividade),
                  _Nu_Dre (Nu_Dre), _Nu_Orientador (Nu_Orientador) {};

        unsigned Get_Cd_Atividade() { return _Cd_Atividade; }
        void Set_Cd_Atividade(unsigned val) { _Cd_Atividade = val; }
        string Get_Nm_Titulo_JIE() { return _Nm_Titulo_JIE; }
        void Set_Nm_Titulo_JIE(string val) { _Nm_Titulo_JIE = val; }
        float Get_Nu_Nota() { return _Nu_Nota; }
        void Set_Nu_Nota(float val) { _Nu_Nota = val; }
        string Get_Ic_Tipo_Atividade() { return _Ic_Tipo_Atividade; }
        void Set_Ic_Tipo_Atividade(string val) { _Ic_Tipo_Atividade = val; }
        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }
        unsigned Get_Nu_Orientador() { return _Nu_Orientador; }
        void Set_Nu_Orientador(unsigned val) { _Nu_Orientador = val; }

    protected:

    private:
        unsigned _Cd_Atividade;
        string _Nm_Titulo_JIE;
        float _Nu_Nota;
        string _Ic_Tipo_Atividade;
        unsigned _Nu_Dre;
        unsigned _Nu_Orientador;
};

#endif // ATIVIDADE_H
