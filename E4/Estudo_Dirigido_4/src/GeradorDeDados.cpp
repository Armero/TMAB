#include "GeradorDeDados.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include<iterator>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;
vector <vector <string> > data;


GeradorDeDados::GeradorDeDados()
{
    srand (time(0));
}

unsigned GeradorDeDados::gerarNumeros (unsigned numeroElementos,
                       unsigned numeroInicial,
                       unsigned numeroFinal)
{
    char buffer [numeroElementos + 1];

    //randomiza cada elemento do vetor
    for (unsigned cont = 1; cont < numeroElementos; cont++)
       buffer [cont] = (rand() % 10) + '0';

    //finaliza a string com o numero aleatorio
    buffer [numeroElementos] = EOS;

    //faz com que o primeiro numero seja igual ao do valor minimo
    buffer [0] = (numeroInicial / pow (10, numeroElementos - 1)) + '0';

    //cria um inteiro com o numero gerado
    stringstream strValue (buffer);

    unsigned valor;
    strValue >> valor;

    //faz com que o valor esteja entre o maximo e o minimo passado
    while ( (valor > numeroFinal) || (valor < numeroInicial))
    {
        if ( valor > numeroFinal)
            valor -= rand();

        if ( valor < numeroInicial)
            valor += rand ();
    }
    return valor;
}

string GeradorDeDados::GerarTelefone (string prefixo, unsigned numero)
{
    char buffer [20];
    return prefixo + (string) itoa(numero, buffer, 10);
}

GeradorDeDados::~GeradorDeDados()
{
    //dtor
}

string GeradorDeDados::NometoString(Nome nome)
{
    string output = "";
    for(int i = 0; i < nome.size();i++)
    {
        if(i < nome.size() -1)
            output += nome[i] + " ";
        else
            output += nome[i];

    }

    return output;
}
vector<string> GeradorDeDados::LerNomes(bool masculino)
{
    ifstream file;
    file.open("Nomes.txt");
    string line0;
    string line1;
    vector <string> nomes;

    int i;

    if(!file)
    {
        cerr << "Erro: Nao pode abrir o arquivo desejado.";
    }
    else
    {
        for(int i = 0; i <=1; i++)
        {

            if(i == 0)
            {
                getline(file,line0);
            }
            else if(i == 1)
            {
                getline(file,line1);

            }
        }
        file.close();


            if(masculino)
            {
                std::stringstream ss(line0);

                std::istringstream buf(line0);
                std::istream_iterator<std::string> beg(buf), end;

                std::vector<std::string> nomesMasculinos(beg, end); // done!
                return nomesMasculinos;
            }

            else
            {
                std::stringstream ss(line1);

                std::istringstream buf(line1);
                std::istream_iterator<std::string> beg(buf), end;

                std::vector<std::string> nomesFemininos(beg, end); // done!
                return nomesFemininos;
            }

        }

}

vector<string> GeradorDeDados::LerSobrenomes()
{
    ifstream file;
    file.open("Sobrenomes.txt");
    string line;
    vector <string> sobrenomes;

    int i;

    if(!file)
    {
        cerr << "Erro: Nao pode abrir o arquivo desejado.";
    }
    else
    {

        if(getline(file,line))
        {
            std::stringstream ss(line);

            std::istringstream buf(line);
            std::istream_iterator<std::string> beg(buf), end;

            std::vector<std::string> sobrenomes(beg, end); // done!
            file.close();
            return sobrenomes;
        }

    }



}

Nome GeradorDeDados::GerarNome(bool nomeComposto,int qtdSobrenome, bool masculino)
{
    srand(time(NULL));
    std::vector<std::string> nomes = LerNomes(masculino);
    std::vector<std::string> sobrenomes = LerSobrenomes();

    if(nomeComposto == true)
    {
        Nome nome(qtdSobrenome + 2);
        for(int i = 0; i < nome.size();i++)
        {
            if(i < 2)
            {
                string temp = nomes[rand()% nomes.size()];
                if(i == 1)
                {
                    if( temp != nome[i-1])
                        nome[i] = temp;
                    else
                        i--;
                }
                else
                    nome[i] = temp;
            }

            else
                nome[i] = sobrenomes[rand() % sobrenomes.size()];
        }
        return nome;
    }

    else
    {
        Nome nome(qtdSobrenome + 1);
          for(int i = 0; i < nome.size();i++)
        {
            if(i < 1)
                nome[i] = nomes[rand()% nomes.size()];
            else
                nome[i] = sobrenomes[rand() % sobrenomes.size()];
        }

        return nome;
    }


}
