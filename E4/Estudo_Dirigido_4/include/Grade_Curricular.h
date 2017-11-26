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

#ifndef GRADE_CURRICULAR_H
#define GRADE_CURRICULAR_H


class Grade_Curricular
{
    public:
        static unsigned contGrade;
        Grade_Curricular(unsigned Cd_Grade, unsigned Nu_Dre,
                         unsigned Cd_Periodo, string Cd_Disciplina):
                        _Cd_Grade (Cd_Grade),
                        _Nu_Dre (Nu_Dre),
                        _Cd_Periodo (Cd_Periodo),
                        _Cd_Disciplina(Cd_Disciplina){};

        unsigned Get_Cd_Grade() { return _Cd_Grade; }
        void Set_Cd_Grade(unsigned val) { _Cd_Grade = val; }

        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }

        unsigned Get_Cd_Periodo() { return _Cd_Periodo; }
        void Set_Cd_Periodo(unsigned val) { _Cd_Periodo = val; }

        string Get_Cd_Disciplina () { return _Cd_Disciplina; }
        void Set_Cd_Disciplina (string val) {_Cd_Disciplina = val; }

    private:
        unsigned _Cd_Grade;
        unsigned _Nu_Dre;
        unsigned _Cd_Periodo;
        string _Cd_Disciplina;
};

#endif // GRADE_CURRICULAR_H
