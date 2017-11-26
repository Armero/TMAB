/**
* UFRJ - Universidade Federal do Rio de Janeiro
* IM - Instituto de Matem�tica
* DMA - Departamento de Matem�tica Aplicada
*
* TMAB - Programa��o C/C++ & Banco de Dados
* ParteII - Programa��o OO em C++
*
* Descri��o do Estudo Dirigido 04
* Prazo de Entrega: 21 de novembro de 2017
*
* Prof. Milton Ramirez (milton@labma.ufrj.br)
* Rio de Janeiro, 13 de novembro de 2017
* Grupo K
* Felipe Claudio
* Thiago Koster Lago
**/

#ifndef PRE_REQUISITOS_H
#define PRE_REQUISITOS_H


class Pre_Requisitos
{
    public:
        Pre_Requisitos(string Cd_Disciplina, unsigned Cd_Pre_Requisito):
        _Cd_Disciplina_Dependente(Cd_Disciplina), _Cd_Pre_Requisito (Cd_Pre_Requisito) {};
        string Get_Cd_Disciplina_Dependente() { return _Cd_Disciplina_Dependente; }
        void Set_Cd_Disciplina_Dependente(string val) { _Cd_Disciplina_Dependente = val; }
        unsigned Get_Cd_Pre_Requisito() { return _Cd_Pre_Requisito; }
        void Set_Cd_Pre_Requisito(unsigned val) { _Cd_Pre_Requisito = val; }

    protected:

    private:
        string _Cd_Disciplina_Dependente;
        unsigned _Cd_Pre_Requisito;
};
typedef std::vector<Pre_Requisitos> preRequisitosVect;
#endif // PRE_REQUISITOS_H
