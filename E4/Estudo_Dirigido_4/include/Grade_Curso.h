#ifndef GRADE_CURSO_H
#define GRADE_CURSO_H


class Grade_Curso
{
    public:

        Grade_Curso(unsigned Cd_Curso, string Cd_Disciplina,
                    unsigned Ic_Periodo, unsigned Qt_Creditos):
                    _Cd_Curso(Cd_Curso),
                    _Cd_Disciplina(Cd_Disciplina),
                    _Ic_Periodo(Ic_Periodo),
                    _Qt_Creditos(Qt_Creditos) {}


        unsigned Get_Cd_Curso() { return _Cd_Curso; }
        void Set_Cd_Curso(unsigned val) { _Cd_Curso = val; }
        string Get_Cd_Disciplina() { return _Cd_Disciplina; }
        void Set_Cd_Disciplina(string val) { _Cd_Disciplina = val; }
        unsigned Get_Ic_Periodo() { return _Ic_Periodo; }
        void Set_Ic_Periodo(unsigned val) { _Ic_Periodo = val; }
        unsigned Get_Qt_Creditos() { return _Qt_Creditos; }
        void Set_Qt_Creditos(unsigned val) { _Qt_Creditos = val; }

    protected:

    private:
        unsigned _Cd_Curso;
        string _Cd_Disciplina;
        unsigned _Ic_Periodo;
        unsigned _Qt_Creditos;
};

#endif // GRADE_CURSO_H
