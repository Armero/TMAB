
SELECT Pessoa.Ic_Sexo AS 'Sexo',
	   SUM(IF(Pessoa.Nu_Idade BETWEEN 1 AND 15,1,0)) AS '-15',
	   SUM(IF(Pessoa.Nu_Idade BETWEEN 15 AND 20,1,0)) AS '15 - 20',
       SUM(IF(Pessoa.Nu_Idade BETWEEN 20 AND 25,1,0)) AS '20 - 25',
       SUM(IF(Pessoa.Nu_Idade BETWEEN 25 AND 50,1,0)) AS '25 - 50',
	   SUM(IF(Pessoa.Nu_Idade BETWEEN 50 AND 110,1,0)) AS '+50'
FROM Pessoa
INNER JOIN Aluno ON Pessoa.Cd_Pessoa = Aluno.Cd_Pessoa
GROUP BY Pessoa.Ic_Sexo;