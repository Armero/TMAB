SELECT
	(SELECT COUNT(*) FROM Aluno) AS 'NUMERO DE ALUNOS',
	(SELECT COUNT(*) FROM Professor) AS 'NUMERO DE PROFESSORES',
	(SELECT COUNT(*) FROM Disciplina) AS 'NUMERO DE DISCIPLINAS'