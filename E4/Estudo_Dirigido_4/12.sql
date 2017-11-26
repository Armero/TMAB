SELECT Nm_Disciplina, Disciplina.Cd_Disciplina,Nm_Curso, Ic_Periodo FROM Grade_Curso
INNER JOIN Disciplina ON Disciplina.Cd_Disciplina = Grade_Curso.Cd_Disciplina
INNER JOIN Curso ON Curso.Cd_Curso = Grade_Curso.Cd_Curso
WHERE Curso.Nm_Curso = "Engenharia Quimica";