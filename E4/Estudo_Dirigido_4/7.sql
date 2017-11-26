SELECT T.Nm_Local, T.Ds_Horario, Pessoa.Nm_Pessoa
FROM Turma AS T
INNER JOIN Professor ON T.Nu_SIAPE = Professor.Nu_SIAPE
INNER JOIN Pessoa ON Professor.Cd_Pessoa = Pessoa.Cd_Pessoa;