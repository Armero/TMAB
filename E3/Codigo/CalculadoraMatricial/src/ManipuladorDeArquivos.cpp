#include "ManipuladorDeArquivos.h"

ManipuladorDeArquivos::ManipuladorDeArquivos()
{
    //ctor
}

ManipuladorDeArquivos::~ManipuladorDeArquivos()
{
    //dtor
}

//Grava somentete uma matriz no arquivo de saida
void ManipuladorDeArquivos::GravaResultados (CMatriz matrizExterna, string nomeArquivo)
{
    MATRIZ matrizInterna = matrizExterna.GetDados();
    ofstream arquivo (nomeArquivo.c_str(), ios::app);
    if (arquivo.is_open())
    {
        arquivo << matrizExterna.GetLinhas() << " " << matrizExterna.GetColunas() << " ";
        for (unsigned linha = 0; linha < matrizExterna.GetLinhas(); linha++)
            for (unsigned coluna = 0; coluna < matrizExterna.GetColunas(); coluna++)
                arquivo << matrizInterna[linha][coluna] <<" ";

       arquivo << endl;
       arquivo.close();
    }
    else
        cout << "Nao foi possivel abrir o arquivo " << nomeArquivo << " !" << endl;
}

//Grava um vetor de matrizes no arquivo de saida
void ManipuladorDeArquivos::GravaResultados (vector<CMatriz> listaMatrizes, string nomeArquivo)
{
    for (unsigned numMatrizes = 0; numMatrizes < listaMatrizes.size(); numMatrizes++)
        GravaResultados(listaMatrizes[numMatrizes], nomeArquivo);
}

//Obtem a matriz atraves do arquivo de texto
vector<MATRIZ>* ManipuladorDeArquivos:: GetMatriz(string nomeArq)                        // Formato do arquivo utilizado:
{                                                                          // 2 3 1 2 3 4 5 6
    //Ordem da matriz                                                      // 2 linhas, 3 colunas : |1 2 3|
    int linhas,colunas;                                                    //                       |4 5 6|

    vector <MATRIZ> *vetorMatrizes = new vector <MATRIZ>;
    MATRIZ data;
    std::string filename = nomeArq.c_str();

    //Tenta abrir arquivo
    std::ifstream file(filename.c_str());
    std::string line;



    if(!file)
    {
        std::cout << "Imposivel abrir arquivo \"" << filename << "\" " <<endl;
    }

    //Popula o vetor data[][]. É um vetor com todas matrizes do arquivo
    while(std::getline(file,line))
    {
        std::vector<float> lineData;
        std::stringstream lineStream(line);

        float value;

        while(lineStream >> value)
        {
            lineData.push_back(value);

        }
        data.push_back(lineData);
    }


    for(unsigned linha = 0; linha < data.size(); linha++)
    {
        linhas = data[linha][0];
        colunas = data[linha][1];
        MATRIZ *m = new MATRIZ;
        vetorMatrizes->push_back(*m); //cria uma matriz de tamanho indeterminado
        for(int i = 0; i < linhas; i++)
        {
            vector <float> *l = new vector<float>;
            (*vetorMatrizes)[linha].push_back (*l); //cria uma linha de tamanho indeterminado e adiciona a matriz
            for(int j = 0; j < colunas;j++)
            {
                float *valor = new float (data[linha][i*colunas + j + 2]); //Soma dois para porque os dois primeiros elementos são o numero de linhas e colunas
                (*vetorMatrizes)[linha][i].push_back(*valor); //finalmente adiciona o valor ao elemento da matriz
            }
        }
    }
    file.close();
    return vetorMatrizes;
}

//Insere os resultados em um vetor de matrizes com os resultados das operacoes realizadas
//Deixa a cargo do usuario escolher se inserira o ultimo resultado ou todos os resultados obtidos ate o momento
//no arquivo de saida
void ManipuladorDeArquivos::InserirResultadoArquivo(CMatriz resultado, vector<CMatriz> &listaResultados, const string arquivoSaida)
{
    listaResultados.push_back(resultado);
    unsigned resposta = 0;
    cout << "Digite 1 para gravar a matriz do ultimo resultado" << endl;
    cout << "Digite 2 para gravar todos os resultados ate o momento" << endl;
    cout << "Digite 0 para nao gravar resultados ate o momento" << endl;
    cin >> resposta;

    switch (resposta)
    {
        case 1:
            GravaResultados(resultado, arquivoSaida);
            break;
        case 2:
            GravaResultados(listaResultados, arquivoSaida);
            break;
        default:
            ; //faz nada

    }
}
