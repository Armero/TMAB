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

#ifndef INSCRICAO_H
#define INSCRICAO_H


class Inscricao
{
    public:
        Inscricao(unsigned Cd_Inscricao, float Nu_Grau, unsigned Nu_Dre, unsigned Nu_Turma)
        : _Cd_Inscricao (Cd_Inscricao),
        _Nu_Grau (Nu_Grau),
        _Nu_Dre (Nu_Dre),
        _Nu_Turma (Nu_Turma){};

        unsigned Get_Cd_Inscricao() { return _Cd_Inscricao; }
        void Set_Cd_Inscricao(unsigned val) { _Cd_Inscricao = val; }

        float Get_Nu_Grau() { return _Nu_Grau; }
        void Set_Nu_Grau(float val) { _Nu_Grau = val; }

        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }

        unsigned Get_Nu_Turma() { return _Nu_Turma; }
        void Set_Nu_Turma(unsigned val) { _Nu_Turma = val; }



    protected:

    private:
        unsigned _Cd_Inscricao;
        float _Nu_Grau;
        unsigned _Nu_Dre;
        unsigned _Nu_Turma;
};

#endif // INSCRICAO_H
