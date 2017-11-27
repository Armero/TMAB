SELECT Inscricao.Nu_Turma, COUNT(Inscricao.Nu_Turma) AS 'NUMERO DE INSCRICOES NA TURMA' FROM Inscricao
INNER JOIN TURMA ON Inscricao.Nu_Turma = Turma.Nu_Turma
WHERE Turma.Cd_Periodo = 2
GROUP BY Inscricao.Nu_Turma;
