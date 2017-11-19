LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/pessoas.csv' INTO TABLE Pessoa
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/professores.csv' INTO TABLE Professor
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/coordenacoes.csv' INTO TABLE Coordenacao
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';
 
LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/cursos.csv' INTO TABLE Curso
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/alunos.csv' INTO TABLE Aluno
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

CREATE TABLE aux
(
	Cd_P           CHAR(6) NOT NULL,
	Dt_I           CHAR (20) NOT NULL,
	Dt_F           CHAR(20) NOT NULL
);

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/periodos.csv' INTO TABLE aux
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\r\n';

INSERT INTO periodo (Cd_Periodo, Dt_Inicio, Dt_Fim)
SELECT  Cd_P,
        STR_TO_DATE(Dt_I, '%d/%c/%Y'),
        STR_TO_DATE(Dt_F, '%d/%c/%Y')
FROM   aux;

drop table aux;

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/periodos.csv' INTO TABLE periodo
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/grades.csv' INTO TABLE Grade_Curricular
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/disciplinas.csv' INTO TABLE Disciplina
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/pre_requisitos.csv' INTO TABLE Pre_Requisitos
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/inscricoes.csv' INTO TABLE Inscricao
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/turmas.csv' INTO TABLE Turma
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';

LOAD DATA INFILE 'C:/Users/felip/Documents/Materias/2017_2/TMAB/Estudos_Dirigidos/TMAB/E4/Estudo_Dirigido_4/atividades.csv' INTO TABLE Atividade
FIELDS TERMINATED BY ';' 
LINES TERMINATED BY '\r\n';