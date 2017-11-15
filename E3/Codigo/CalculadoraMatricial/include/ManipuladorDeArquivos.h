#ifndef MANIPULADORDEARQUIVOS_H
#define MANIPULADORDEARQUIVOS_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "CMatriz.h"

using namespace std;

class ManipuladorDeArquivos
{
    public:
        ManipuladorDeArquivos();
        virtual ~ManipuladorDeArquivos();
        void GravaResultados (CMatriz , string); //Grava uma matriz no arquivo de saida
        void GravaResultados (vector<CMatriz> , string); //Grava um vetor de matrizes no arquivo de saida
        vector <MATRIZ>* GetMatriz(string);
        void InserirResultadoArquivo (CMatriz, vector<CMatriz> &,const string); //Insere a matriz no vetor de resultados e permite ao usuario
                                                //escolher quais dados irao para o arquivo de saida

    private:
};

#endif // MANIPULADORDEARQUIVOS_H
