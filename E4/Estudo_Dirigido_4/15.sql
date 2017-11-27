SELECT Disciplina.Nm_Disciplina, Grade_Curricular.Cd_Disciplina 
FROM Grade_Curricular
INNER JOIN Periodo ON Grade_Curricular.Cd_Periodo = Periodo.Cd_Periodo
INNER JOIN Disciplina ON Grade_Curricular.Cd_Disciplina = Disciplina.Cd_Disciplina
WHERE Periodo.Cd_Periodo = 4

AND Grade_Curricular.Cd_Disciplina NOT IN (

SELECT Grade_Curricular.Cd_Disciplina 
FROM Grade_Curricular
INNER JOIN Periodo ON Grade_Curricular.Cd_Periodo = Periodo.Cd_Periodo
INNER JOIN Disciplina ON Grade_Curricular.Cd_Disciplina = Disciplina.Cd_Disciplina
WHERE Periodo.Cd_Periodo = 7 );