#ifndef CMATRIZ_H
#define CMATRIZ_H
#include <vector>
#include <iostream>
#include <exception>

using namespace std;
typedef vector <float> LINHA;
typedef vector <LINHA> MATRIZ;

class CMatriz
{
    public:
        CMatriz(MATRIZ dados); //recebe um vetor do tipo Matriz e inicializa os dados internos do objeto
        CMatriz(unsigned linhasMatriz, unsigned colunasMatriz, float valor);
        ~CMatriz();

        void Init(MATRIZ val); //inicia a matriz com os valores de val
        void SetDados (unsigned linha, unsigned coluna, float valor); //muda um elemento da matriz somente
        void SetDados(MATRIZ);
        const MATRIZ GetDados(); //retorna os dados em uma matriz constante
        const unsigned GetLinhas ()const {return linhas;}; //indica o numero de linhas da matriz
        const unsigned GetColunas()const  {return colunas;};//indica o numero de colunas da matriz
        CMatriz operator + (CMatriz); //soma de matrizes
        CMatriz operator * (CMatriz); //multiplicacao de matrizes
        CMatriz operator * (float); //multiplicacao por constante
        CMatriz TransporMatriz(); //transpor matriz

    private:
        MATRIZ dados; //responsavel pelos dados da matriz
        unsigned linhas;
        unsigned colunas;
};

#endif // CMATRIZ_H
