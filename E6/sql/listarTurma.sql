SELECT D.Nm_Pessoa, A.Nu_Dre, A.Nu_Grau
FROM Inscricao as A
INNER JOIN Turma as B ON B.Nu_Turma = A.Nu_Turma
INNER JOIN Aluno as C ON A.Nu_Dre = C.Nu_Dre
INNER JOIN Pessoa as D ON D.Cd_Pessoa = C.Cd_Pessoa
WHERE B.Nu_Turma = 6;