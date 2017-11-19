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

#ifndef ALUNO_H
#define ALUNO_H


class Aluno
{
    public:
        Aluno(unsigned Nu_Dre, unsigned Cd_Pessoa,
              unsigned Nu_Coordenador, unsigned Cd_Curso)
              :_Nu_Dre (Nu_Dre), _Cd_Pessoa(Cd_Pessoa),
              _Nu_Coordenador (Nu_Coordenador), _Cd_Curso(Cd_Curso)
              {};

        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }
        unsigned Get_Cd_Pessoa() { return _Cd_Pessoa; }
        void Set_Cd_Pessoa(unsigned val) { _Cd_Pessoa = val; }
        unsigned Get_Nu_Coordenador() { return _Nu_Coordenador; }
        void Set_Nu_Coordenador(unsigned val) { _Nu_Coordenador = val; }
        unsigned Get_Cd_Curso() { return _Cd_Curso; }
        void Set_Cd_Curso(unsigned val) { _Cd_Curso = val; }

    protected:

    private:
        unsigned _Nu_Dre;
        unsigned _Cd_Pessoa;
        unsigned _Nu_Coordenador;
        unsigned _Cd_Curso;
};

#endif // ALUNO_H
