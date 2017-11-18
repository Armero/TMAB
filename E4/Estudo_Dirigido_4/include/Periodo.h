#ifndef PERIODO_H
#define PERIODO_H


class Periodo
{
    public:
        Periodo(unsigned Cd_Periodo, string Dt_Inicio, string Dt_Fim):
        _Cd_Periodo (Cd_Periodo),
        _Dt_Inicio (Dt_Inicio),
        _Dt_Fim (Dt_Fim);

    private:
        unsigned _Cd_Periodo;
        string _Dt_Inicio;
        string _Dt_Fim;
};

#endif // PERIODO_H
