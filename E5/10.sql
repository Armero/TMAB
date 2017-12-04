SELECT Pessoa.Nm_Pessoa, Pessoa.Nu_Idade
FROM Pessoa
WHERE Pessoa.Nu_Idade = (SELECT MAX(Nu_Idade) 
							FROM Pessoa 
							INNER JOIN Aluno 
							ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa);