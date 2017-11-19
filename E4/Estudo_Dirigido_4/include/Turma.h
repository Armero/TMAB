#ifndef TURMA_H
#define TURMA_H


class Turma
{
    public:
        Turma(unsigned Nu_Turma, string Nm_Local,
              unsigned Nu_Vagas, string Cd_Disciplina,
              string Ds_Horario, unsigned Nu_Siape,
              unsigned Cd_Inscricao):
              _Nu_Turma(Nu_Turma), _Nm_Local (Nm_Local),
              _Nu_Vagas (Nu_Vagas), _Cd_Disciplina (Cd_Disciplina),
              _Ds_Horario (Ds_Horario), _Nu_Siape (Nu_Siape),
              _Cd_Inscricao (Cd_Inscricao) {};

        unsigned Get_Nu_Turma() { return _Nu_Turma; }
        void Set_Nu_Turma(unsigned val) { _Nu_Turma = val; }

        string Get_Nm_Local() { return _Nm_Local; }
        void Set_Nm_Local(string val) { _Nm_Local = val; }

        unsigned Get_Nu_Vagas() { return _Nu_Vagas; }
        void Set_Nu_Vagas(unsigned val) { _Nu_Vagas = val; }

        string Get_Cd_Disciplina() { return _Cd_Disciplina; }
        void Set_Cd_Disciplina(string val) { _Cd_Disciplina = val; }

        string Get_Ds_Horario() { return _Ds_Horario; }
        void Set_Ds_Horario(string val) { _Ds_Horario = val; }

        unsigned Get_Nu_Siape() { return _Nu_Siape; }
        void Set_Nu_Siape(unsigned val) { _Nu_Siape = val; }

        unsigned Get_Cd_Inscricao() { return _Cd_Inscricao; }
        void Set_Cd_Inscricao(unsigned val) { _Cd_Inscricao = val; }

    protected:

    private:
        unsigned _Nu_Turma;
        string _Nm_Local;
        unsigned _Nu_Vagas;
        string _Cd_Disciplina;
        string _Ds_Horario;
        unsigned _Nu_Siape;
        unsigned _Cd_Inscricao;
};

#endif // TURMA_H
