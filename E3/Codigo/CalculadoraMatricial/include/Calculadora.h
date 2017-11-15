#ifndef CALCULADORA_H
#define CALCULADORA_H
#include "CMatriz.h"
#include <vector>
#include <iostream>
#include "Interface.h"
#include "ManipuladorDeArquivos.h"

using namespace std;


class Calculadora
{
    public:
        Calculadora();
        ~Calculadora();
        void MultiplicarConstante(float k,CMatriz A,CMatriz &B); // B = k.*A
        void MultiplicarMatrizes(CMatriz A, CMatriz B, CMatriz &C); //C = A * B
        void TransporMatriz(CMatriz A, CMatriz &B); //B = transposta (A)
        void SomarMatriz(CMatriz A, CMatriz B, CMatriz &C); //C = A + B
    private:

};

#endif // CALCULADORA_H
