#include "Interface.h"


//Necessario fornecer arquivo de entrada e saida para o programa funcionar normalmente
Interface::Interface()
{
    cout << "Para ajuda, veja o arquivo help.txt" << endl;
    cout << "Insira o nome do arquivo de entrada dos dados:" << endl;
    cin >> arquivoEntrada;
    cout << "Insira o nome do arquivo que tera os resultados das operacoes" << endl;
    cin >> arquivoSaida;

    vector <MATRIZ> *listaMatrizes = manipuladorDeArquivos.GetMatriz(arquivoEntrada);
    for (unsigned contador = 0; contador < (*listaMatrizes).size(); contador++)
        listaCMatrizes.push_back((*listaMatrizes)[contador]);

    fim = false;
    while (!fim)
    {
        MostrarOpcoes();
        GetInput();
    }

}
Interface::~Interface()
{
}

void Interface::MostrarOpcoes()
{
    cout << "Calculadora Matricial" << endl;
    cout << "Menu" << endl;
    cout << "1 - Somar" << endl;
    cout << "2 - Multiplicar por constante" << endl;
    cout << "3 - Multiplicar matrizes"<< endl;
    cout << "4 - Transpor matriz" << endl;
    cout << "5 - Mostrar matrizes do arquivo" << endl;
    cout << "6 - Trocar arquivo de entrada" << endl;
    cout << "7 - Trocar arquivo de saida" << endl;
    cout << "8 - Sair do programa" << endl;

}

void Interface::GetInput()
{
    int opcao;
    Calculadora calc;
    cout << "Escolha uma opcao: ";
    cin >> opcao;

    if(opcao == 1)
    {

        cout << "Soma" << endl;
        //Seleciona as matrizes que serao somadas
        CMatriz ma = SelecionarMatriz(listaCMatrizes);
        CMatriz mb = SelecionarMatriz(listaCMatrizes);

        //Cria uma matriz com o tamanho necessario para gravar o resultado da operacao
        CMatriz mc (ma.GetLinhas(), ma.GetColunas(), 0.0);

        //Chama a operação soma
        calc.SomarMatriz(ma, mb, mc);
        cout << "Resultado:" << endl;
        MostrarMatriz(mc);
        manipuladorDeArquivos.InserirResultadoArquivo(mc, listaResultados, arquivoSaida);

    }else if(opcao == 2)
    {
        //Chama a operação Multiplicar por constante
        float valor;
        cout << "Multiplicar por constante" << endl;
        cout << "Insira a constante" << endl;
        cin >> valor;

        //Seleciona as matrizes que sera escalonada
        CMatriz ma = SelecionarMatriz(listaCMatrizes);

        //Cria uma matriz com o tamanho necessario para gravar o resultado da operacao
        CMatriz mb(ma.GetLinhas(), ma.GetColunas(), 0.0);

        //Realiza o escalonamento da matriz
        calc.MultiplicarConstante(valor, ma, mb);
        cout << "Resultado:" << endl;
        MostrarMatriz(mb);
        manipuladorDeArquivos.InserirResultadoArquivo(mb, listaResultados, arquivoSaida);

    }else if(opcao == 3)
    {
        //Chama a operação Multiplicar matrizes
        cout << "Multiplicar matrizes" << endl;

        //Seleciona as matrizes que serao multiplicadas
        CMatriz ma = SelecionarMatriz(listaCMatrizes);
        CMatriz mb = SelecionarMatriz(listaCMatrizes);

        //Cria uma matriz com o tamanho necessario para gravar o resultado da operacao
        CMatriz mc(ma.GetLinhas(), mb.GetColunas(), 0.0);

        //Realiza a multiplicacao matricial
        calc.MultiplicarMatrizes(ma, mb, mc);
        cout << "Resultado:" << endl;
        MostrarMatriz(mc);
        manipuladorDeArquivos.InserirResultadoArquivo(mc, listaResultados, arquivoSaida);

    }else if(opcao == 4)
    {
        //Chama a operação Transpor matriz
        cout << "Transpor matriz" << endl;

        //Seleciona as matrizes que sera transposta
        CMatriz ma = SelecionarMatriz(listaCMatrizes);

        //Cria a matriz responsavel por receber o resultado da matriz original transposta
        CMatriz mb(ma.GetColunas(), ma.GetLinhas(), 0.0);
        calc.TransporMatriz(ma, mb);
        cout << "Resultado:" << endl;
        MostrarMatriz(mb);
        manipuladorDeArquivos.InserirResultadoArquivo(mb, listaResultados, arquivoSaida);

    }else if(opcao == 5)
    {
        cout<< "Matrizes do arquivo: "<< endl;
        MotrarTodasMatrizes(listaCMatrizes);
    }else if (opcao == 6)
    {
        cout << "Digite o nome do arquivo de entrada" << endl;
        cin >> arquivoEntrada;
        vector <MATRIZ> *listaMatrizes = manipuladorDeArquivos.GetMatriz(arquivoEntrada);
        listaCMatrizes.clear();
        for (unsigned contador = 0; contador < (*listaMatrizes).size(); contador++)
            listaCMatrizes.push_back((*listaMatrizes)[contador]);
    }else if (opcao == 7)
    {
        cout << "Digite o nome do arquivo de saida" << endl;
        cin >> arquivoSaida;
        listaResultados.clear();
    }else if (opcao == 8)
    {
        fim = true;
    }
    else
    {
        //Opcao invalida
        cout << "Entrada invalida, entre com o numero referente a opcao desejada" << endl;
    }
}
void Interface::MostrarMatriz(CMatriz matrizExterna)
{
    unsigned linhas = 0 , colunas = 0;

    linhas = matrizExterna.GetLinhas();
    colunas = matrizExterna.GetColunas();

    MATRIZ matrizInterna = matrizExterna.GetDados();
    for (unsigned indiceL = 0; indiceL < linhas; indiceL++)
    {
        for (unsigned indiceC = 0; indiceC < colunas; indiceC++)
            cout << matrizInterna.at(indiceL).at(indiceC) <<" ";

        cout << endl;
    }
    cout << endl;
}

void Interface::MotrarTodasMatrizes (vector<CMatriz> vetorMatrizes)
{
    unsigned numMatrizes = vetorMatrizes.size();
    for (unsigned contador = 0; contador < numMatrizes; contador++)
    {
        cout << "Matriz " << contador << endl;
        MostrarMatriz(vetorMatrizes[contador]);
    }
}

const CMatriz& Interface::SelecionarMatriz (vector<CMatriz> vetorCMatriz)
{
    unsigned indiceMatriz;
    cout << "Digite o numero da Matriz Selecionada" << endl;
    cin >> indiceMatriz;
    cout << "\nMatriz Selecionada:" << endl;
    MostrarMatriz(listaCMatrizes.at(indiceMatriz));
    return vetorCMatriz.at(indiceMatriz);
}
