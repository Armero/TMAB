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

#ifndef CURSO_H
#define CURSO_H
#include <string>
using namespace std;

class Curso
{
    public:
        Curso(unsigned Cd_Curso, string Nm_Curso, unsigned Cd_Coordenacao,
              string Nm_Area,
              unsigned Nu_Semestres): _Cd_Curso (Cd_Curso),
                                      _Nm_Curso (Nm_Curso),
                                      _Cd_Coordenacao (Cd_Coordenacao),
                                      _Nm_Area (Nm_Area),
                                      _Nu_Semestres (Nu_Semestres) {};


        unsigned Get_Cd_Curso() { return _Cd_Curso; }
        void Set_Cd_Curso(unsigned val) { _Cd_Curso = val; }
        string Get_Nm_Curso() { return _Nm_Curso; }
        void Set_Nm_Curso(string val) { _Nm_Curso = val; }
        unsigned Get_Cd_Coordenacao() { return _Cd_Coordenacao; }
        void Set_Cd_Coordenacao(unsigned val) { _Cd_Coordenacao = val; }
        string Get_Nm_Area() { return _Nm_Area; }
        void Set_Nm_Area(string val) { _Nm_Area = val; }
        unsigned Get_Nu_Semestres () {return _Nu_Semestres; }
        void Set_Nu_Semestres (unsigned val) {_Nu_Semestres = val; }

    protected:

    private:
        unsigned _Cd_Curso;
        string _Nm_Curso;
        unsigned _Cd_Coordenacao;
        string _Nm_Area;
        unsigned _Nu_Semestres;
};

#endif // CURSO_H
