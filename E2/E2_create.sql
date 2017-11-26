-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2017-10-01 00:58:52.182

-- tables
-- Table: Aluno
CREATE TABLE Aluno (
    Nu_Dre int NOT NULL,
    Pessoa_Cd_Pessoa int NOT NULL,
    Professor_Nu_SIAPE int NOT NULL,
    Curso_Cd_Curso int NOT NULL,
    CONSTRAINT Aluno_pk PRIMARY KEY (Nu_Dre)
);

-- Table: Atividade
CREATE TABLE Atividade (
    Cd_Atividade int NOT NULL,
    Nm_Titulo_JIE char(60) NOT NULL,
    Nu_Nota decimal(4,2) NOT NULL,
    Ic_Tipo_Atividade char(60) NOT NULL,
    Professor_Nu_SIAPE int NOT NULL,
    Aluno_Nu_Dre int NOT NULL,
    CONSTRAINT Atividade_pk PRIMARY KEY (Cd_Atividade)
);

-- Table: Coordenacao
CREATE TABLE Coordenacao (
    Professor_Nu_SIAPE int NOT NULL,
    Cd_Coordenacao int NOT NULL,
    CONSTRAINT Coordenacao_pk PRIMARY KEY (Cd_Coordenacao)
);

-- Table: Curso
CREATE TABLE Curso (
    Cd_Curso int NOT NULL,
    Nm_Curso char(60) NOT NULL,
    Coordenacao_Cd_Coordenacao int NOT NULL,
    CONSTRAINT Cd_Curso PRIMARY KEY (Cd_Curso)
);

-- Table: Disciplina
CREATE TABLE Disciplina (
    Cd_Disciplina char(6) NOT NULL,
    Nm_Disciplia char(60) NOT NULL,
    Qt_Creditos int NOT NULL,
    Ds_ementa char(255) NOT NULL,
    Ds_Bibilografia char(255) NOT NULL,
    Grade_Curricular_Cd_Grade int NOT NULL,
    CONSTRAINT Disciplina_pk PRIMARY KEY (Cd_Disciplina)
);

-- Table: Grade_Curricular
CREATE TABLE Grade_Curricular (
    Cd_Grade int NOT NULL,
    Periodo_Cd_Periodo int NOT NULL,
    Aluno_Nu_Dre int NOT NULL,
    CONSTRAINT Grade_Curricular_pk PRIMARY KEY (Cd_Grade)
);

-- Table: Periodo
CREATE TABLE Periodo (
    Cd_Periodo int NOT NULL,
    Dt_Inicio date NOT NULL,
    Dt_Fim date NOT NULL,
    CONSTRAINT Periodo_pk PRIMARY KEY (Cd_Periodo)
);

-- Table: Pessoa
CREATE TABLE Pessoa (
    Cd_Pessoa int NOT NULL,
    Nm_NomePessoa char(60) NOT NULL,
    CONSTRAINT Pessoa_pk PRIMARY KEY (Cd_Pessoa)
);

-- Table: Professor
CREATE TABLE Professor (
    Nu_SIAPE int NOT NULL,
    Ds_Titulo char(255) NOT NULL,
    Nm_local char(60) NOT NULL,
    Nu_Telefone char (11) NOT NULL,
    En_email char(60) NOT NULL,
    En_web char (60) NULL,
    Pessoa_Cd_Pessoa int NOT NULL,
    CONSTRAINT Professor_pk PRIMARY KEY (Nu_SIAPE)
);

-- Table: Turma
CREATE TABLE Turma (
    Nu_Turma int NOT NULL,
    Disciplina_Cd_Disciplina char(6) NOT NULL,
    Nm_Local char(60) NOT NULL,
    Nu_Vagas int NOT NULL,
    CONSTRAINT Turma_pk PRIMARY KEY (Nu_Turma)
);

-- foreign keys
-- Reference: Aluno_Curso (table: Aluno)
ALTER TABLE Aluno ADD CONSTRAINT Aluno_Curso FOREIGN KEY Aluno_Curso (Curso_Cd_Curso)
    REFERENCES Curso (Cd_Curso);

-- Reference: Aluno_Pessoa (table: Aluno)
ALTER TABLE Aluno ADD CONSTRAINT Aluno_Pessoa FOREIGN KEY Aluno_Pessoa (Pessoa_Cd_Pessoa)
    REFERENCES Pessoa (Cd_Pessoa);

-- Reference: Aluno_Professor (table: Aluno)
ALTER TABLE Aluno ADD CONSTRAINT Aluno_Professor FOREIGN KEY Aluno_Professor (Professor_Nu_SIAPE)
    REFERENCES Professor (Nu_SIAPE);

-- Reference: Atividade_Aluno (table: Atividade)
ALTER TABLE Atividade ADD CONSTRAINT Atividade_Aluno FOREIGN KEY Atividade_Aluno (Aluno_Nu_Dre)
    REFERENCES Aluno (Nu_Dre);

-- Reference: Atividade_Professor (table: Atividade)
ALTER TABLE Atividade ADD CONSTRAINT Atividade_Professor FOREIGN KEY Atividade_Professor (Professor_Nu_SIAPE)
    REFERENCES Professor (Nu_SIAPE);

-- Reference: Coordenacao_Professor (table: Coordenacao)
ALTER TABLE Coordenacao ADD CONSTRAINT Coordenacao_Professor FOREIGN KEY Coordenacao_Professor (Professor_Nu_SIAPE)
    REFERENCES Professor (Nu_SIAPE);

-- Reference: Curso_Coordenacao (table: Curso)
ALTER TABLE Curso ADD CONSTRAINT Curso_Coordenacao FOREIGN KEY Curso_Coordenacao (Coordenacao_Cd_Coordenacao)
    REFERENCES Coordenacao (Cd_Coordenacao);

-- Reference: Disciplina_Grade_Curricular (table: Disciplina)
ALTER TABLE Disciplina ADD CONSTRAINT Disciplina_Grade_Curricular FOREIGN KEY Disciplina_Grade_Curricular (Grade_Curricular_Cd_Grade)
    REFERENCES Grade_Curricular (Cd_Grade);

-- Reference: Grade_Curricular_Aluno (table: Grade_Curricular)
ALTER TABLE Grade_Curricular ADD CONSTRAINT Grade_Curricular_Aluno FOREIGN KEY Grade_Curricular_Aluno (Aluno_Nu_Dre)
    REFERENCES Aluno (Nu_Dre);

-- Reference: Grade_Curricular_Periodo (table: Grade_Curricular)
ALTER TABLE Grade_Curricular ADD CONSTRAINT Grade_Curricular_Periodo FOREIGN KEY Grade_Curricular_Periodo (Periodo_Cd_Periodo)
    REFERENCES Periodo (Cd_Periodo);

-- Reference: Professor_Pessoa (table: Professor)
ALTER TABLE Professor ADD CONSTRAINT Professor_Pessoa FOREIGN KEY Professor_Pessoa (Pessoa_Cd_Pessoa)
    REFERENCES Pessoa (Cd_Pessoa);

-- Reference: Turma_Disciplina (table: Turma)
ALTER TABLE Turma ADD CONSTRAINT Turma_Disciplina FOREIGN KEY Turma_Disciplina (Disciplina_Cd_Disciplina)
    REFERENCES Disciplina (Cd_Disciplina);

-- End of file.

