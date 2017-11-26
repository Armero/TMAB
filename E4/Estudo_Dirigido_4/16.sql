SELECT COUNT( Nu_Dre),Turma.Nu_SIAPE FROM Inscricao
INNER JOIN Turma ON Turma.Nu_Turma = Inscricao.Nu_Turma
WHERE Inscricao.Nu_Dre IN (SELECT Nu_Dre FROM Inscricao
							INNER JOIN Turma ON Turma.Nu_Turma = Inscricao.Nu_Turma
							WHERE Turma.Nu_SIAPE = 143221535
							)
AND Turma.Nu_SIAPE = 122972907;
