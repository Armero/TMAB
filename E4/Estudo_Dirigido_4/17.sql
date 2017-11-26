SELECT AVG(Inscricao.Nu_Grau) AS 'Media Turma',Turma.Nu_Turma,Turma.Cd_Periodo FROM Inscricao
INNER JOIN Turma ON Inscricao.Nu_Turma = Turma.Nu_Turma
GROUP BY Turma.Nu_Turma,Turma.Cd_Periodo;