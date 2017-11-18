#ifndef GRADE_CURRICULAR_H
#define GRADE_CURRICULAR_H


class Grade_Curricular
{
    public:
        static unsigned contGrade;
        Grade_Curricular(unsigned Cd_Grade, unsigned Nu_Dre,
                         unsigned Cd_Periodo):
                        _Cd_Grade (Cd_Grade),
                        _Nu_Dre (Nu_Dre),
                        _Cd_Periodo (Cd_Periodo) {};
        unsigned Get_Cd_Grade() { return _Cd_Grade; }
        void Set_Cd_Grade(unsigned val) { _Cd_Grade = val; }
        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }

    private:
        unsigned _Cd_Grade;
        unsigned _Nu_Dre;
        unsigned _Cd_Periodo;
};

#endif // GRADE_CURRICULAR_H
