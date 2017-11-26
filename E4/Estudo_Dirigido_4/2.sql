SELECT Nm_Disciplina,Disciplina.Cd_Disciplina,Curso.Nm_Curso,Disciplina.Qt_Creditos FROM Grade_Curso
INNER JOIN Disciplina ON Disciplina.Cd_Disciplina = Grade_Curso.Cd_Disciplina
INNER JOIN Curso ON Curso.Cd_Curso = Grade_Curso.Cd_Curso
WHERE Disciplina.Qt_Creditos = 4;
