#ifndef COORDENACAO_H
#define COORDENACAO_H


class Coordenacao
{
    public:
        Coordenacao(unsigned Nu_Siape):_Nu_Siape (Nu_Siape) {};

        unsigned Get_Cd_Coordenacao() { return _Cd_Coordenacao; }
        void Set_Cd_Coordenacao(unsigned val) { _Cd_Coordenacao = val; }
        unsigned Get_Nu_Siape() { return _Cd_Coordenacao; }
        void SetCd_Coordenaca0o(unsigned val) { _Cd_Coordenacao = val; }

    protected:

    private:
        unsigned _Cd_Coordenacao;
        unsigned _Nu_Siape;
};

#endif // COORDENACAO_H
