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


#include <iostream>
#include "Pessoa.h"
#include "Professor.h"
#include "GeradorDeDados.h"


using namespace std;

int main (void)
{
    cout << "#################### Estudo dirigido 05 #################" << endl;
    cout << "Grupo K" << endl;
    cout <<  "Felipe Claudio e Thiago Koster Lago" << endl;
    cout <<  endl;
    cout <<  endl;

    GeradorDeDados gerador;

    cout << "Criando pasta em \"C:\\TMAB\"" << endl;

    gerador.criarPasta("C:\\TMAB");

    cout << "Criando arquivos .csv na pasta criada..." << endl;


    gerador.gerarPessoas("C:\\TMAB\\pessoas.csv", 1000);
    gerador.gerarProfessor("C:\\TMAB\\professores.csv", 40);
    gerador.gerarCoordenacao("C:\\TMAB\\coordenacoes.csv", 5);
    gerador.gerarCursos("C:\\TMAB\\cursos.csv",4);
    gerador.gerarAlunos("C:\\TMAB\\alunos.csv", 990);
    gerador.gerarAtividades("C:\\TMAB\\atividades.csv", 100);
    gerador.gerarPeriodo("C:\\TMAB\\periodos.csv", 8);
    gerador.gerarDisciplina("C:\\TMAB\\disciplinas.csv",200);
    gerador.gerarGrade("C:\\TMAB\\gradecurricular.csv",1000);
    gerador.gerarPreRequisito("C:\\TMAB\\pre_requisitos.csv",50);
    gerador.gerarTurmas("C:\\TMAB\\turmas.csv",70, 10);
    gerador.gerarIncricoes("C:\\TMAB\\inscricoes.csv");
    gerador.gerarGradeCurso("C:\\TMAB\\gradecursos.csv");


    cout << "Execucao finalizada" << endl;
    return (0);
}
