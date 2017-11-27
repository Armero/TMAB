SELECT COUNT( Nu_Dre),Turma.Nu_SIAPE FROM Inscricao
INNER JOIN Turma ON Turma.Nu_Turma = Inscricao.Nu_Turma
WHERE Inscricao.Nu_Dre IN (SELECT Nu_Dre FROM Inscricao
							INNER JOIN Turma ON Turma.Nu_Turma = Inscricao.Nu_Turma
							WHERE Turma.Nu_SIAPE = 143221535
							)
AND Turma.Nu_SIAPE = 122972907;
SELECT Aluno.Nu_dre, Pessoa.Nm_Pessoa, Turma.Cd_Periodo
FROM Aluno
INNER JOIN Pessoa ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa
INNER JOIN Inscricao ON Inscricao.Nu_Dre = Aluno.Nu_Dre
INNER JOIN Turma ON Inscricao.Nu_Turma = Turma.Nu_Turma
INNER JOIN Professor ON Turma.Nu_SIAPE = Professor.Nu_SIAPE
WHERE Professor.Cd_Pessoa = 1 AND Turma.Cd_Periodo = 2

AND Aluno.Nu_dre IN (

SELECT Aluno.Nu_dre
FROM Aluno
INNER JOIN Pessoa ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa
INNER JOIN Inscricao ON Inscricao.Nu_Dre = Aluno.Nu_Dre
INNER JOIN Turma ON Inscricao.Nu_Turma = Turma.Nu_Turma
INNER JOIN Professor ON Turma.Nu_SIAPE = Professor.Nu_SIAPE
WHERE Professor.Cd_Pessoa = 1 AND Turma.Cd_Periodo = 2);
