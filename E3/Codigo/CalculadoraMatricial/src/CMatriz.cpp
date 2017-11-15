#include "CMatriz.h"

//Inicializa linhas com as linhas maximas da matriz
//Colunas com o numero maximo de colunas da matriz
//E atribui os dados a matriz
CMatriz::CMatriz(MATRIZ matrizExterna)
{
    linhas = matrizExterna.size();
    colunas = matrizExterna[0].size();
    Init(matrizExterna);
}

CMatriz::CMatriz(unsigned linhasMatriz, unsigned colunasMatriz, float valor)
{
    linhas = linhasMatriz;
    colunas = colunasMatriz;
    MATRIZ *matrizInicializacao = new MATRIZ;
    (*matrizInicializacao).resize(linhas);
    for (unsigned l = 0; l <  linhas; l++)
        for (unsigned c = 0; c < colunas; c++)
            (*matrizInicializacao)[l].push_back(valor);

    Init (*matrizInicializacao);
}

CMatriz::~CMatriz()
{

}

//Atribui os dados a matriz
void CMatriz::Init(MATRIZ matrizExterna)
{
    unsigned linha = matrizExterna.size();
    unsigned coluna = matrizExterna[0].size();

    for (unsigned indiceL = 0; indiceL < linha; indiceL++)
    {
        //Cria uma vetor que tem a funcao de linha para inserir dentro da matriz
        LINHA *l = new LINHA;
        dados.push_back(*l);

        //insere os valores dentro de cada posicao da matriz
        for (unsigned indiceC =0; indiceC < coluna; indiceC++)
            dados[indiceL].push_back(matrizExterna[indiceL][indiceC]);

    }

}

//opcao de modificar um elemento unico da matriz
void CMatriz::SetDados (unsigned linha, unsigned coluna, float valor)
{
    try
    {
        dados.at(linha).at(coluna) = valor;
    }
    catch (exception e)
    {
        cout << "Os limites da matriz foram excedidos e o erro:" <<  e.what() << " foi obtido" << endl;;
    }
}

//Modifica os dados em uma matriz inicializada
void CMatriz::SetDados(MATRIZ matriz)
{
    for(unsigned i = 0; i < linhas;i++)
    {
        for(unsigned j = 0 ; j < colunas;j++)
        {
            SetDados(i,j,matriz[i][j]);
        }
    }
}

//retorna uma matriz constante para ser operada externamente
const MATRIZ CMatriz::GetDados()
{
    return dados;
}

CMatriz CMatriz::operator + (CMatriz b)
{
    CMatriz *erro = new CMatriz(1, 1, 0.0);
    if(this->GetColunas() != b.GetColunas())
    {
        cout << "Impossivel somar matrizes selecionadas, numero de colunas diferentes" << endl;
        return *erro;
    }

    if(this->GetLinhas() != b.GetLinhas())
    {
        cout << "Impossivel somar matrizes selecionadas, numero de linhas diferentes" << endl;
        return *erro;
    }
    //Obtem as informações das matrizes
    MATRIZ dadosA = this->GetDados();
    MATRIZ dadosB = b.GetDados();

    for(unsigned i = 0; i < this->GetLinhas();i++)
    {
        for(unsigned j = 0; j < b.GetColunas();j++)
        {

            dadosA[i][j] += dadosB[i][j];
        }
    }
    delete erro;
    CMatriz *resultado = new CMatriz(dadosA);
    return *resultado;
}

CMatriz CMatriz::operator*(CMatriz b)
{
    //o numero de linhas de mA deve ser igual ao de mb para que seja possivel realizar a multiplicacao
    CMatriz *erro = new CMatriz(1, 1, 0.0);

    if (this->GetColunas() != b.GetLinhas())
    {
        cout << "Impossivel multiplicar matrizes selecionadas, numero de colunas diferentes" << endl;
        return *erro;
    }

    float valor;
    MATRIZ matrizA = this->GetDados();
    MATRIZ matrizB = b.GetDados();
    CMatriz *resultado = new CMatriz(this->GetLinhas(), b.GetColunas(), 0.0);

    //multiplicacao utilizando o algoritmo mais simples possivel
    for (unsigned linha = 0; linha < this->GetLinhas(); linha++)
        for (unsigned coluna = 0; coluna < this->GetColunas(); coluna ++)
        {
            for (unsigned k = 0; k < this->GetColunas(); k++)
              valor += matrizA[linha][k] * matrizB[k][coluna];

            resultado->SetDados(linha, coluna, valor);
            valor = 0;
        }

    delete erro;
    return *resultado;
}

CMatriz CMatriz::operator*(float escalar)
{
    MATRIZ dadosB = this->GetDados();
    CMatriz *resultado = new CMatriz(this->GetLinhas(), this->GetColunas(), 0.0);
    for(unsigned i = 0; i < this->GetLinhas();i++)
    {
        for(unsigned j = 0; j < this->GetColunas();j++)
        {
            resultado->SetDados(i,j,escalar * dadosB[i][j]);
        }
    }
    return *resultado;
}

CMatriz CMatriz::TransporMatriz()
{
    MATRIZ matrizA = this->GetDados();
    MATRIZ matrizB;
    matrizB.resize(this->GetColunas()); //o numero de linhas da matriz transposta e igual ao numero de colunas da matriz original

    for (unsigned linha = 0; linha < this->GetColunas(); linha++)
    {
      //aloca espaco para as colunas da matriz
       matrizB[linha].resize(this->GetLinhas());
       for (unsigned coluna = 0; coluna < this->GetLinhas(); coluna ++)
            matrizB[linha][coluna] = matrizA[coluna][linha];
    }

    CMatriz *resultado = new CMatriz(matrizB);
    return *resultado;
}
