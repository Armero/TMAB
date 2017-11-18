#ifndef GERADORDEDADOS_H
#define GERADORDEDADOS_H
<<<<<<< HEAD
#include <vector>
#include <string>

typedef std::vector <std::string> Nome;
=======
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <math.h>
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> master
>>>>>>> master

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
        virtual ~GeradorDeDados();


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

        virtual ~GeradorDeDados();

    private:
    vector <string> CURSOS;

};

#endif // GERADORDEDADOS_H
