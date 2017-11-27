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

#ifndef GERADORDEDADOS_H
#define GERADORDEDADOS_H
#include <vector>
#include <string>
typedef std::vector <std::string> Nome;
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <vector>
#include "Pessoa.h"
#include "Periodo.h"
#include "Grade_Curricular.h"
#include "Disciplina.h"
#include "Pre_Requisitos.h"
#include "Turma.h"
#include "Professor.h"
#include "Coordenacao.h"
#include "Curso.h"
#include "Aluno.h"
#include "Inscricao.h"
#include "Atividade.h"
#include "Grade_Curso.h"
#include <fstream>

#define SEP ";" //Separador do arquivo CSV

#define EOS		'\0'

using namespace std;

class GeradorDeDados
{
    public:
        GeradorDeDados();

        //numeroElementos eh o numero de total de elementos no vetor que sera gerado
        //numeroInicial eh o numero minimo permitido
        //numeroFinal eh o numero maximo permitido
        //OBS: nao colocar numero de elementos maior que 10,
        //pois a funcao nao conseguira gerar o numero
        unsigned gerarNumeros (unsigned numeroElementos,
                               unsigned numeroInicial,
                               unsigned numeroFinal);


        void criarPasta(const char *);

        void gerarPessoas (string nomeArquivo, unsigned qtdPessoas);
        void gerarPeriodo(string nomeArquivo, unsigned qtdPeriodos);
        void gerarGrade(string nomeArquivo, unsigned qtdGrades);
        void gerarDisciplina(string nomeArquivo,unsigned qtdGrades);
        void gerarPreRequisito(string nomeArquivo,unsigned qtdPreReq);
        void gerarTurmas(string nomeArquivo,unsigned qtdMaxAlunos, unsigned qtdMinAlunos);

        //gera o arquivo .csv com o numero de professores desejados
        void gerarProfessor (string nomeArquivo, unsigned qtdProfessores);

        //gera o arquivo .csv com o numero de coordenacoes desejados
        void gerarCoordenacao (string nomeArquivo, unsigned qtdCoordenacoes);

        //gera o arquivo .csv com o numero de cursos desejados
        void gerarCursos (string nomeArquivo, unsigned qtdCursos);

        //gera o arquivo .csv com o numero de aluno desejados
        //OBS: deve ser chamado depois de gerarProfessor por causa
        // dos codigos de pessoa
        void gerarAlunos (string nomeArquivo, unsigned qtdAlunos);

        //gera o arquivo .csv com as Inscricoes
        //OBS: deve ser chamado apos gerarTurma, pois depende de turma
        void gerarIncricoes (string nomeArquivo);

        //gera o arquivo .csv com o numero de inscricoes desejadas
        void gerarAtividades (string nomeArquivo, unsigned qtdAtividades);

        //gera grades para cada curso com numero de materias aleatorias por periodo
        //OBS: deve ser chamado depois de gerarDisciplina pois referencia
        //disciplinas
        void gerarGradeCurso (string nomeArquivo);

    private:

    //Adiciona o prefixo ao numero de entrada e retorna tudo como string
    string GerarTelefone (string prefixo, unsigned numero); //Adiciona o prefixo ao numero de entrada e retorna tudo como string
    void gerarEmaileEnWeb (string nome, string &email, string &enWeb);
    Nome GerarNome(bool,int,bool);
    std::string NometoString(Nome);
    std::vector < std::string > LerNomes(bool);
    std::vector < std::string > LerSobrenomes();
    Nome separarString (string texto);
    void gerarMaterias (unsigned nObrigatorias, unsigned nProfissionais, unsigned nOptativas); //Gera Materias conforme um padraos

    string gerarLocalGabinete ();
    vector <string> CURSOS;
    vector <string> TITULOS;
    vector <string> EMAILS;
    vector <string> DOMINIOS;
    vector <string> BLOCOS;
    vector <string> CLASSE;
    vector <string> TIPO_ATV;
    vector <string> MATERIAS;
    vector <string> TIPO_DISCIPLINAS;
    vector <Pessoa> pessoas;
    vector <Periodo> periodos;
    vector <Grade_Curricular> grades;
    vector <Disciplina> disciplinas;
    vector <Pre_Requisitos> preRequisitos;
    vector <Turma> turmas;
    vector <Professor> prof;
    vector <Coordenacao> coord;
    vector <Curso> cursos;
    vector <Aluno> alunos;
    vector <Grade_Curso> gradesCursos;
    vector <Inscricao> inscricoes;
    vector <Atividade> atividades;
    vector <bool> cursosUtilizados;
};

#endif // GERADORDEDADOS_H
