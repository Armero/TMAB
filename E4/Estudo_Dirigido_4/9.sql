SELECT DISTINCT Turma.Nu_Turma,COUNT(Nu_Dre) AS 'Numero de Alunos' ,Cd_Periodo, Pessoa.Nm_Pessoa AS 'Professor'
,Professor.Cd_Pessoa 
FROM Turma
INNER JOIN Inscricao ON Turma.Nu_Turma = Inscricao.Nu_Turma
INNER JOIN Professor ON Turma.Nu_SIAPE = Professor.Nu_SIAPE
INNER JOIN Pessoa ON Pessoa.Cd_Pessoa = Professor.Cd_Pessoa
WHERE Professor.Cd_Pessoa = 0
AND Cd_Periodo = 7
GROUP BY Turma.Nu_Turma;