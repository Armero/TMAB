#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <vector>
#include "CMatriz.h"
#include "CMatriz.h"
#include "vector"
#include "ManipuladorDeArquivos.h"
#include "Calculadora.h"

using namespace std;

class Interface
{
    public:
        Interface();
        virtual ~Interface();
        void MostrarOpcoes (); //Menu principal
        void GetInput(); //Ler input do usuario
        void MostrarMatriz(CMatriz); //Mostrar matriz
        void MotrarTodasMatrizes (vector<CMatriz>); //Mostra todas as matrizes lida pelo programa
        const CMatriz& SelecionarMatriz (vector<CMatriz> vetorCMatriz); //Seleciona uma das matrizes lidas pelo programa

    private:
        vector <CMatriz> listaCMatrizes; //lista com todos as matrizes lidas do arquivo
        vector <CMatriz> listaResultados; //lista com todos as matrizes lidas do arquivo
        ManipuladorDeArquivos manipuladorDeArquivos; //manipulador de arquivos
        string arquivoEntrada;
        string arquivoSaida;
        bool fim;
};

#endif // INTERFACE_H
