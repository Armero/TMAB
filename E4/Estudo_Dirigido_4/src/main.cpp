/**
* UFRJ - Universidade Federal do Rio de Janeiro
* IM - Instituto de Matemática
* DMA - Departamento de Matemática Aplicada
*
* TMAB - Programação C/C++ & Banco de Dados
* ParteII - Programação OO em C++
*
* Descrição do Estudo Dirigido 04
* Prazo de Entrega: 21 de novembro de 2017
*
* Prof. Milton Ramirez (milton@labma.ufrj.br)
* Rio de Janeiro, 13 de novembro de 2017
* Grupo K
* Felipe Claudio
* Thiago Koster Lago
**/



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
    cout << "#################### Estudo dirigido 04 #################" << endl;
    cout << "Grupo K" << endl;
    cout <<  "Felipe Claudio e Thiago Koster Lago" << endl;
    cout <<  endl;
    cout <<  endl;

    GeradorDeDados gerador;

    cout << "Criando pasta em \"C:\\TMAB\"" << endl;

    gerador.criarPasta("C:\\TMAB");

    cout << "Criando arquivos .csv na pasta criada..." << endl;



    gerador.gerarPessoas("C:\\TMAB\\pessoas.csv", 1000);
    gerador.gerarProfessor("C:\\TMAB\\professores.csv", 20);
    gerador.gerarCoordenacao("C:\\TMAB\\coordenacoes.csv", 10);
    gerador.gerarCursos("C:\\TMAB\\cursos.csv", 5);
    gerador.gerarAlunos("C:\\TMAB\\alunos.csv", 900);
<<<<<<< HEAD
=======
    gerador.gerarIncricoes("C:\\TMAB\\inscricoes.csv", 300);
    gerador.gerarAtividades("C:\\TMAB\\atividades.csv", 100);
    gerador.gerarPeriodo("C:\\TMAB\\periodos.csv",10);
    gerador.gerarGrade("C:\\TMAB\\grades.csv",300);
    gerador.gerarDisciplina("C:\\TMAB\\disciplinas.csv",300);
    gerador.gerarPreRequisito("C:\\TMAB\\pre_requisitos.csv",50);
    gerador.gerarTurmas("C:\\TMAB\\turmas.csv",100);
    gerador.gerarGradeCurso("C:\\TMAB\\gradecursos.csv");
>>>>>>> Felipe

    gerador.gerarAtividades("C:\\TMAB\\atividades.csv", 100);
    gerador.gerarPeriodo("C:\\TMAB\\periodos.csv",20);
    gerador.gerarGrade("C:\\TMAB\\grades.csv",900);
    gerador.gerarDisciplina("C:\\TMAB\\disciplinas.csv",5);
    gerador.gerarPreRequisito("C:\\TMAB\\pre_requisitos.csv",1);
    gerador.gerarTurmas("C:\\TMAB\\turmas.csv",5);
    gerador.gerarIncricoes("C:\\TMAB\\inscricoes.csv", 900);

    cout << "Execucao finalizada" << endl;
    return (0);
}
