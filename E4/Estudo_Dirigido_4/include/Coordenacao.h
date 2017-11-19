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

#ifndef COORDENACAO_H
#define COORDENACAO_H


class Coordenacao
{
    public:
        Coordenacao(unsigned Cd_Coordenacao, unsigned Nu_Siape):
                    _Cd_Coordenacao(Cd_Coordenacao),
                     _Nu_Siape (Nu_Siape) {};

        unsigned Get_Cd_Coordenacao() { return _Cd_Coordenacao; }
        void Set_Cd_Coordenacao(unsigned val) { _Nu_Siape = val; }
        unsigned Get_Nu_Siape() { return _Nu_Siape; }
        void SetCd_Coordenaca0o(unsigned val) { _Cd_Coordenacao = val; }

    protected:

    private:
        unsigned _Cd_Coordenacao;
        unsigned _Nu_Siape;
};

#endif // COORDENACAO_H
