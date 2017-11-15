#include "Calculadora.h"

Calculadora::Calculadora()
{
    //ctor
}

Calculadora::~Calculadora()
{
    //dtor
}

void Calculadora::MultiplicarConstante(float a, CMatriz matrizB, CMatriz &output)
{
    output = matrizB * a;
}

void Calculadora::MultiplicarMatrizes(CMatriz ma, CMatriz mb, CMatriz &mout)
{
    mout = ma * mb;
}

void Calculadora::TransporMatriz(CMatriz ma, CMatriz &mb)
{
    mb = ma.TransporMatriz();
}

void Calculadora::SomarMatriz(CMatriz a, CMatriz b,CMatriz &output)
{
    output = a + b;
}
