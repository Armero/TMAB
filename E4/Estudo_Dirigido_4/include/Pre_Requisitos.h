#ifndef PRE_REQUISITOS_H
#define PRE_REQUISITOS_H


class Pre_Requisitos
{
    public:
        Pre_Requisitos(unsigned Cd_Disciplina, unsigned Cd_Pre_Requisito):
        _Cd_Disciplina_Dependente(Cd_Disciplina), _Cd_Pre_Requisito (Cd_Pre_Requisito) {};
        unsigned Get_Cd_Disciplina_Dependente() { return _Cd_Disciplina_Dependente; }
        void Set_Cd_Disciplina_Dependente(unsigned val) { _Cd_Disciplina_Dependente = val; }
        unsigned Get_Cd_Pre_Requisito() { return _Cd_Pre_Requisito; }
        void Set_Cd_Pre_Requisito(unsigned val) { _Cd_Pre_Requisito = val; }

    protected:

    private:
        unsigned _Cd_Disciplina_Dependente;
        unsigned _Cd_Pre_Requisito;
};
typedef std::vector<Pre_Requisitos> preRequisitosVect;
#endif // PRE_REQUISITOS_H
