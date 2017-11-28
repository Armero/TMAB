SELECT COUNT(Disciplina.Cd_Disciplina) AS 'NUMERO DE DISCIPLINAS DE UM DETERMINADO PERIODO' FROM Turma
INNER JOIN Disciplina ON Turma.Cd_Disciplina = Disciplina.Cd_Disciplina
WHERE Turma.Cd_Periodo = 2;