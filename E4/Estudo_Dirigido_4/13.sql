SELECT Pessoa.Nm_Pessoa,Pessoa.Cd_Pessoa, Disciplina.Nm_Disciplina,
Inscricao.Nu_Grau, Periodo.Dt_Inicio, Periodo.Dt_Fim 
FROM Inscricao
INNER JOIN Turma ON Turma.Nu_Turma = Inscricao.Nu_Turma
INNER JOIN Disciplina ON Disciplina.Cd_Disciplina = Turma.Cd_Disciplina
INNER JOIN Aluno ON Inscricao.Nu_Dre = Aluno.Nu_Dre
INNER JOIN Pessoa ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa
INNER JOIN Periodo ON Turma.Cd_Periodo = Periodo.Cd_Periodo
WHERE Pessoa.Cd_Pessoa = 189	;