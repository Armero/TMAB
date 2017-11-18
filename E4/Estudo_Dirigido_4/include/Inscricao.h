#ifndef INSCRICAO_H
#define INSCRICAO_H


class Inscricao
{
    public:
        Inscricao(unsigned Cd_Inscricao, float Nu_Grau, unsigned Nu_Dre)
        : _Cd_Inscricao (Cd_Inscricao),
        _Nu_Grau (Nu_Grau),
        _Nu_Dre (Nu_Dre){};

        unsigned Get_Cd_Inscricao() { return _Cd_Inscricao; }
        void Set_Cd_Inscricao(unsigned val) { _Cd_Inscricao = val; }
        float Get_Nu_Grau() { return _Nu_Grau; }
        void Set_Nu_Grau(float val) { _Nu_Grau = val; }
        unsigned Get_Nu_Dre() { return _Nu_Dre; }
        void Set_Nu_Dre(unsigned val) { _Nu_Dre = val; }

    protected:

    private:
        unsigned _Cd_Inscricao;
        float _Nu_Grau;
        unsigned _Nu_Dre;
};

#endif // INSCRICAO_H
