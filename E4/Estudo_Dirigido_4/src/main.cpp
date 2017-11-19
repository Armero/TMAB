/*

CREATE TABLE Pessoa
(
	Cd_Pessoa            INTEGER NOT NULL,
	Nm_Pessoa            CHAR(60) NOT NULL,
	PRIMARY KEY (Cd_Pessoa)
);

--- ^OK ---

CREATE TABLE Professor
(
	Nu_SIAPE             INTEGER NOT NULL,
	Ds_Titulo            CHAR(255) NOT NULL,
	Nm_Local_Gabinete    CHAR(60) NOT NULL,
	Nu_Telefone          CHAR(11) NOT NULL,
	En_Email             CHAR(60) NOT NULL,
	En_Web               CHAR (255),
	Cd_Pessoa            INTEGER NOT NULL,
	Ic_Classe            CHAR(60) NULL,
	PRIMARY KEY (Nu_SIAPE),
	FOREIGN KEY R_24 (Cd_Pessoa) REFERENCES Pessoa (Cd_Pessoa)
);

--- ^OK ---

CREATE TABLE Coordenacao
(
	Cd_Coordenacao       INTEGER NOT NULL,
	Nu_SIAPE             INTEGER NULL,
	PRIMARY KEY (Cd_Coordenacao),
	FOREIGN KEY R_25 (Nu_SIAPE) REFERENCES Professor (Nu_SIAPE)
);

--- ^OK ---

CREATE TABLE Curso
(
	Cd_Curso             INTEGER NOT NULL,
	Nm_Curso             CHAR(60) NOT NULL,
	Cd_Coordenacao       INTEGER NOT NULL,
	Nm_Area              CHAR(60) NULL,
	PRIMARY KEY (Cd_Curso),
	FOREIGN KEY R_9 (Cd_Coordenacao) REFERENCES Coordenacao (Cd_Coordenacao)
);

--- ^OK ---

CREATE TABLE Aluno
(
	Nu_Dre               INTEGER NOT NULL,
	Cd_Pessoa            INTEGER NOT NULL,
	Nu_Coordenador       INTEGER NULL,
	Cd_Curso             INTEGER NOT NULL,
	PRIMARY KEY (Nu_Dre),
	FOREIGN KEY R_23 (Cd_Pessoa) REFERENCES Pessoa (Cd_Pessoa),
	FOREIGN KEY R_33 (Nu_Coordenador) REFERENCES Professor (Nu_SIAPE),
	FOREIGN KEY R_34 (Cd_Curso) REFERENCES Curso (Cd_Curso)
);

--- ^OK ---

CREATE TABLE Periodo
(
	Cd_Periodo           CHAR(6) NOT NULL,
	Dt_Inicio            DATE NOT NULL,
	Dt_Fim               DATE NOT NULL,
	PRIMARY KEY (Cd_Periodo)
);
--- ^OK ---


CREATE TABLE Grade_Curricular
(
	Cd_Grade             INTEGER NOT NULL,
	Nu_Dre               CHAR(9) NOT NULL,
	Cd_Periodo           DECIMAL(5,1) NOT NULL,
	PRIMARY KEY (Cd_Grade),
	FOREIGN KEY R_14 (Nu_Dre) REFERENCES Aluno (Nu_Dre),
	FOREIGN KEY R_36 (Cd_Periodo) REFERENCES Periodo (Cd_Periodo)
);

--- ^OK ---

CREATE TABLE Disciplina
(
	Cd_Disciplina        CHAR(6) NOT NULL,
	Nm_Disciplia         CHAR(60) NOT NULL,
	Qt_Creditos          INTEGER NOT NULL,
	Ds_Ementa            CHAR(255) NOT NULL,
	Ds_Bibilografia      CHAR(255) NOT NULL,
	Cd_Grade             INTEGER NOT NULL,
	PRIMARY KEY (Cd_Disciplina),
	FOREIGN KEY R_5 (Cd_Grade) REFERENCES Grade_Curricular (Cd_Grade)
);

--- ^OK ---

CREATE TABLE Pre_Requisitos
(
	Cd_Disciplina_Dependente CHAR(6) NOT NULL,
	Cd_Pre_Requisito     CHAR(6) NULL,
	PRIMARY KEY (Cd_Disciplina_Dependente),
	FOREIGN KEY R_27 (Cd_Disciplina_Dependente) REFERENCES Disciplina (Cd_Disciplina),
	FOREIGN KEY R_30 (Cd_Pre_Requisito) REFERENCES Disciplina (Cd_Disciplina)
);

--- ^OK ---

CREATE TABLE Incricao
(
	Cd_Inscricao         INTEGER NOT NULL,
	Nu_Grau              DECIMAL(4,2) NULL,
	Nu_Dre               INTEGER NULL,
	PRIMARY KEY (Cd_Inscricao),
	FOREIGN KEY R_31 (Nu_Dre) REFERENCES Aluno (Nu_Dre)
);
--- ^OK ---


CREATE TABLE Turma
(
	Nu_Turma             INTEGER NOT NULL,
	Nm_Local             CHAR(60) NOT NULL,
	Nu_Vagas             INTEGER NOT NULL,
	Cd_Disciplina        CHAR(6) NOT NULL,
	Ds_Horario           CHAR(60) NULL,
	Nu_SIAPE             INTEGER NOT NULL,
	Cd_Inscricao         INTEGER NULL,
	PRIMARY KEY (Nu_Turma),
	FOREIGN KEY R_22 (Cd_Disciplina) REFERENCES Disciplina (Cd_Disciplina),
	FOREIGN KEY R_26 (Nu_SIAPE) REFERENCES Professor (Nu_SIAPE),
	FOREIGN KEY R_32 (Cd_Inscricao) REFERENCES Incricao (Cd_Inscricao)
);

--- ^OK ---

CREATE TABLE Atividade
(
	Cd_Atividade         INTEGER NOT NULL,
	Nm_Titulo_JIE        CHAR(60) NOT NULL,
	Nu_Nota              decimal(4,2) NOT NULL,
	Ic_Tipo_Atividade    CHAR(60) NOT NULL,
	Nu_Dre               INTEGER NULL,
	Nu_Orientador        INTEGER NULL,
	PRIMARY KEY (Cd_Atividade),
	FOREIGN KEY R_19 (Nu_Dre) REFERENCES Aluno (Nu_Dre),
	FOREIGN KEY R_35 (Nu_Orientador) REFERENCES Professor (Nu_SIAPE)
*/

#include <iostream>
#include "Pessoa.h"
#include "Professor.h"
#include "GeradorDeDados.h"


using namespace std;

int main (void)
{
    GeradorDeDados gerador;
    bool masculino = true;
    bool nomeComposto = false;
    int qtdeSobrenomes = 1;

    GeradorDeDados g1;
    g1.gerarPessoas("pessoas.csv", 1000);
    g1.gerarProfessor("professores.csv", 10);
    g1.gerarCoordenacao("coordenacoes.csv", 5);
    g1.gerarCursos("cursos.csv", 10);
    g1.gerarAlunos("alunos.csv", 100);
    g1.gerarIncricoes("inscricoes.csv", 100);

    return (0);
}
