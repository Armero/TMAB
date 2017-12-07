/* SELECT Aluno.Nu_Dre, Pessoa.Nm_Pessoa, Periodo.Cd_Periodo FROM Turma 
INNER JOIN Professor ON Turma.Nu_Siape = Professor.Nu_Siape
INNER JOIN Inscricao ON Turma.Nu_Turma = Inscricao.Nu_Turma
INNER JOIN Periodo ON Turma.Cd_Periodo = Periodo.Cd_Periodo
INNER JOIN Aluno ON Inscricao.Nu_Dre = Aluno.Nu_Dre
INNER JOIN Pessoa ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa
WHERE Professor.Cd_Pessoa = 4;*/ /*AND*/
/* Periodo.Cd_Periodo = 2; */
/* 
SELECT Disciplina.Nm_Disciplina, DATE(Periodo.Dt_Inicio), Periodo.Dt_Fim
FROM Grade_Curricular
INNER JOIN Aluno ON Grade_Curricular.Nu_Dre = Aluno.Nu_Dre
INNER JOIN Disciplina ON Grade_Curricular.Cd_Disciplina = Disciplina.Cd_Disciplina
INNER JOIN Periodo ON Grade_Curricular.Cd_Periodo = Periodo.Cd_Periodo
WHERE Aluno.Cd_Pessoa = 356; */
/* 
SELECT D.Nm_Pessoa, A.Nu_Dre, A.Nu_Grau
        FROM Inscricao as A
        INNER JOIN Turma as B ON B.Nu_Turma = A.Nu_Turma
        INNER JOIN Aluno as C ON A.Nu_Dre = C.Nu_Dre
        INNER JOIN Pessoa as D ON D.Cd_Pessoa = C.Cd_Pessoa
        where B.Nu_Turma = 7; */
		
SELECT D.Nm_Pessoa, A.Nu_Dre, A.Nu_Grau
FROM Inscricao as A

INNER JOIN Turma as B ON B.Nu_Turma = A.Nu_Turma
INNER JOIN Aluno as C ON A.Nu_Dre = C.Nu_Dre
INNER JOIN Pessoa as D ON D.Cd_Pessoa = C.Cd_Pessoa
WHERE B.Nu_Turma = 11;