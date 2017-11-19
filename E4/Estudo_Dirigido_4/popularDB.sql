LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/pessoas.csv' INTO TABLE Pessoa
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/professores.csv' INTO TABLE Professor
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/coordenacoes.csv' INTO TABLE Coordenacao
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/cursos.csv' INTO TABLE Curso
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/alunos.csv' INTO TABLE Aluno
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/inscricoes.csv' INTO TABLE Inscricao
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/atividades.csv' INTO TABLE Atividade
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/periodos.csv' INTO TABLE Periodo
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES
(Cd_Periodo, @DATE_STR1, @DATE_STR2)
SET Periodo.Dt_Inicio = STR_TO_DATE(@DATE_STR1, '%d/%m/%Y'),
SET Periodo.Dt_Inicio = STR_TO_DATE(@DATE_STR2, '%d/%m/%Y'),;
/* LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/pessoas.csv' INTO TABLE pessoa
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/pessoas.csv' INTO TABLE pessoa
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n'	
IGNORE 1 LINES; */