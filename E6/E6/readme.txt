Os arquivos .csv utilizados para popular o banco de dados est�o na pasta TMAB.
IMPORTANTE! : Esta pasta n�o deve ser renomeada, pois seu caminho � utilizado nos scripts de cria��o

Para criar o banco de dados,execute os seguintes passos:
1-Mova a pasta TMAB para o disco C. Criando o caminho C:\TMAB
2-Na linha de comando do mysql, execute os comandos onde "nomeDB" deve ser substituido pelo nome do banco de dados:
  2-1 - create database nomeDB;
  2-2 - use nomeDB;
3 - Agora utilize os scripts SQLs de cria��o do banco:
 3-1 - source C:/Caminho-dos-scripts/criarDB.sql;
 3-2 - source C:/Caminho-dos-scripts/popularDB.sql;
 
Para excluir o banco de dados, utilize o script dropDB.sql.

Dados �teis para utilizar no programa
Entrar na pasta sql/csv e copiar todos os csv para a pastar C:/TMAB/

T�picos:
1) Se matricular em turma:
	Exemplo de input:
		116996571 3
	Caso queira observar a lista de alunos, utilizar o script listarTurma.sql e modificar a turma escolhida

2) Listar pauta de turma do professor:
	Exemplo de input:
	141278988 8
	
3) Lan�ar notas de turma
	Exemplo de input:
	7 (n�mero da turma)
	(lan�ar notas)

4) Listar hist�rico de aluno
	Exemplo de input:
	116996571
	
Exemplos de DRES de alunos:
116996571
116999557
116994565
116998262

Exemplos de Numeros de SIAPES e Cd_Periodo:
141278988 8
116470141 7
102149145 4 ou 5