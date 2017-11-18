#ifndef CURSO_H
#define CURSO_H
#include <string>
using namespace std;

class Curso
{
    public:
        Curso(unsigned Cd_Curso, string Nm_Curso, unsigned Cd_Coordenacao,
              string Nm_Area): _Cd_Curso (Cd_Curso),
                               _Nm_Curso (Nm_Curso),
                               _Cd_Coordenacao (Cd_Coordenacao),
                               _Nm_Area (Nm_Area) {};

        unsigned Get_Cd_Curso() { return _Cd_Curso; }
        void Set_Cd_Curso(unsigned val) { _Cd_Curso = val; }
        string Get_Nm_Curso() { return _Nm_Curso; }
        void Set_Nm_Curso(string val) { _Nm_Curso = val; }
        unsigned Get_Cd_Coordenacao() { return _Cd_Coordenacao; }
        void Set_Cd_Coordenacao(unsigned val) { _Cd_Coordenacao = val; }
        string Get_Nm_Area() { return _Nm_Area; }
        void Set_Nm_Area(string val) { _Nm_Area = val; }

    protected:

    private:
        unsigned _Cd_Curso;
        string _Nm_Curso;
        unsigned _Cd_Coordenacao;
        string _Nm_Area;
};

#endif // CURSO_H
