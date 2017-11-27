SELECT COUNT(Disciplina.Cd_Disciplina) FROM Turma
INNER JOIN Disciplina ON Turma.Cd_Disciplina = Disciplina.Cd_Disciplina
WHERE Turma.Cd_Periodo = 2;