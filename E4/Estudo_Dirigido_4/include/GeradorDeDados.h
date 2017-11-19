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
#include "Professor.h"
#include "Coordenacao.h"
#include "Curso.h"
#include "Aluno.h"
#include <fstream>
#include <iterator>

#define SEP ";" //Separador do arquivo CSV

#define EOS		'\0'

using namespace std;

class GeradorDeDados
{
    public:
        GeradorDeDados();
        Nome GerarNome(bool,int,bool);
        std::string NometoString(Nome);
        std::vector < std::string > LerNomes(bool);
        std::vector < std::string > LerSobrenomes();


        //numeroElementos eh o numero de total de elementos no vetor que sera gerado
        //numeroInicial eh o numero minimo permitido
        //numeroFinal eh o numero maximo permitido
        //OBS: nao colocar numero de elementos maior que 10,
        //pois a funcao nao conseguira gerar o numero
        unsigned gerarNumeros (unsigned numeroElementos,
                               unsigned numeroInicial,
                               unsigned numeroFinal);


        //gera o arquivo .csv com o numero de pessoas desejadas
        void gerarPessoas (string nomeArquivo, unsigned qtdPessoas);

        //gera o arquivo .csv com o numero de professores desejados
        void gerarProfessor (string nomeArquivo, unsigned qtdProfessores);

        //gera o arquivo .csv com o numero de coordenacoes desejados
        void gerarCoordenacao (string nomeArquivo, unsigned qtdCoordenacoes);

        //gera o arquivo .csv com o numero de cursos desejados
        void gerarCursos (string nomeArquivo, unsigned qtdCursos);

        //gera o arquivo .csv com o numero de aluno desejados
        void gerarAlunos (string nomeArquivo, unsigned qtdAlunos);

    private:
    string GerarTelefone (string prefixo, unsigned numero); //Adiciona o prefixo ao numero de entrada e retorna tudo como string
    void gerarEmaileEnWeb (string nome, string &email, string &enWeb);
    string gerarLocalGabinete ();
    vector <string> CURSOS;
    vector <string> TITULOS;
    vector <string> EMAILS;
    vector <string> DOMINIOS;
    vector <string> BLOCOS;
    vector <string> CLASSE;
    vector <Pessoa> pessoas;
    vector <Professor> prof;
    vector <Coordenacao> coord;
    vector <Curso> cursos;
    vector <Aluno> alunos;
};

#endif // GERADORDEDADOS_H
