SELECT Nm_Disciplina, Disciplina.Cd_Disciplina,Nu_Turma,Nu_Vagas,Ds_Horario, Turma.Cd_Periodo FROM Turma
INNER JOIN Disciplina ON Turma.Cd_Disciplina = Disciplina.Cd_Disciplina
WHERE Turma.Cd_Periodo = 10;