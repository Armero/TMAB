SELECT Disciplina.Cd_Disciplina, Disciplina.Nm_Disciplina, 
Grade_Curso.Ic_Periodo, 
Grade_Curso.Cd_Curso, Turma.Cd_Periodo, Aluno.Cd_Pessoa
FROM Aluno
INNER JOIN Grade_Curso ON Aluno.Cd_Curso = Grade_Curso.Cd_Curso
AND Grade_Curso.Ic_Periodo = 1
INNER JOIN Disciplina ON Grade_Curso.Cd_Disciplina = Disciplina.Cd_Disciplina
INNER JOIN Turma ON Turma.Cd_Disciplina = Disciplina.Cd_Disciplina

WHERE Aluno.Cd_Pessoa = 42 AND Turma.Cd_Periodo = 2;

