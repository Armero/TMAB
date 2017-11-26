SELECT Periodo.Dt_inicio, Periodo.Dt_fim, Disciplina.Cd_Disciplina, 
Disciplina.Nm_disciplina FROM Periodo
INNER JOIN Turma ON TURMA.Cd_Periodo = Periodo.Cd_Periodo
INNER JOIN Disciplina ON Disciplina.Cd_Disciplina = Turma.Cd_Disciplina
WHERE Periodo.Dt_inicio = DATE('2017/03/01');

/* GROUP BY (Disciplina.Cd_Disciplina, Periodo.Dt_inicio, Periodo.Dt_fim); */