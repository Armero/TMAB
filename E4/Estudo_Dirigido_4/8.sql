SELECT DISTINCT Turma.Nu_Turma,Nm_Local,COUNT(Nu_Dre) AS 'Numero de Alunos' FROM Turma
INNER JOIN Inscricao ON Turma.Nu_Turma = Inscricao.Nu_Turma
WHERE Cd_Periodo = 7
GROUP BY Turma.Nu_Turma;