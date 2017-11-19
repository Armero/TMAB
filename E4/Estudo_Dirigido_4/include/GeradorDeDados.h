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
#include <fstream>

#define SEP "," //Separador do arquivo CSV

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
        int DatetoNumber(int,int,int);
        string NumbertoDate(long);

        //numeroElementos eh o numero de total de elementos no vetor que sera gerado
        //numeroInicial eh o numero minimo permitido
        //numeroFinal eh o numero maximo permitido
        //OBS: nao colocar numero de elementos maior que 10,
        //pois a funcao nao conseguira gerar o numero
        unsigned gerarNumeros (unsigned numeroElementos,
                               unsigned numeroInicial,
                               unsigned numeroFinal);

        //Adiciona o prefixo ao numero de entrada e retorna tudo como string
        string GerarTelefone (string prefixo, unsigned numero);
        void gerarPessoas (string nomeArquivo, unsigned qtdPessoas);
        void gerarPeriodo(string nomeArquivo, unsigned qtdPeriodos);
        void gerarGrade(string nomeArquivo, unsigned qtdGrades);
        void gerarDisciplina(string nomeArquivo,unsigned qtdGrades);
        void gerarPreRequisito(string nomeArquivo,unsigned qtdPreReq);

    private:
    vector <string> CURSOS;
    vector <Pessoa> pessoas;
    vector <Periodo> periodos;
    vector <Grade_Curricular> grades;
    vector <Disciplina> disciplinas;
    vector <Pre_Requisitos> preRequisitos;

};

#endif // GERADORDEDADOS_H
