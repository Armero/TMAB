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
    srand (time(NULL));
    CURSOS.push_back("ENGENHARIA");
    CURSOS.push_back("MEDICINA");
    CURSOS.push_back("DIREITO");
    TITULOS.push_back("Licenciatura");
    TITULOS.push_back("Bacharelado");
    TITULOS.push_back("Mestrado");
    TITULOS.push_back("Doutorado");
    TITULOS.push_back("PHD");
    EMAILS.push_back("@poli.ufrj.br");
    EMAILS.push_back("@hotmail.com");
    EMAILS.push_back("@gmail.com");
    EMAILS.push_back("@yahoo.com");
    EMAILS.push_back("@outlook.com");
    DOMINIOS.push_back(".ufrj.br");
    DOMINIOS.push_back(".com.br");
    DOMINIOS.push_back(".com");
    DOMINIOS.push_back(".org");
    BLOCOS.push_back("A-");
    BLOCOS.push_back("B-");
    BLOCOS.push_back("C-");
    BLOCOS.push_back("D-");
    BLOCOS.push_back("E-");
    BLOCOS.push_back("F-");
    BLOCOS.push_back("G-");
    BLOCOS.push_back("H-");
    BLOCOS.push_back("I-");
    CLASSE.push_back("Substituto");
    CLASSE.push_back("Adjunto");
    CLASSE.push_back("Titular");
    CURSOS.push_back("Engenharia Eletrônica");
    CURSOS.push_back("Engenharia Quimica");
    CURSOS.push_back("Engenharia Eletrica");
    CURSOS.push_back("Engenharia Mecanica");
    CURSOS.push_back("Matematica Aplicada");
    CURSOS.push_back("Fisica Medica");
    CURSOS.push_back("Direito Civil");
    CURSOS.push_back("Direito Trabalhista");
    CURSOS.push_back("Medicina Geriatrica");
    CURSOS.push_back("Letras Ingles");
    CURSOS.push_back("Letras Espanhol");
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

string GeradorDeDados::NometoString(Nome nome)
{
    string output = "";
    for(unsigned i = 0; i < nome.size();i++)
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
    std::vector<std::string> nomes = LerNomes(masculino);
    std::vector<std::string> sobrenomes = LerSobrenomes();

    if(nomeComposto == true)
    {
        Nome nome(qtdSobrenome + 2);
        for(unsigned i = 0; i < nome.size();i++)
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
          for(unsigned i = 0; i < nome.size();i++)
        {
            if(i < 1)
                nome[i] = nomes[rand()% nomes.size()];
            else
                nome[i] = sobrenomes[rand() % sobrenomes.size()];

        }

        return nome;
    }


}

void GeradorDeDados::gerarPessoas (string nomeArquivo, unsigned qtdPessoas)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    for (unsigned numP = 0; numP <(qtdPessoas - 1); numP++)
    {
        pessoas.push_back(Pessoa (numP + 1, NometoString(GerarNome(rand()%2,rand()%2 + 1,rand()%2))));
        arquivo <<  pessoas[numP].Get_Cd_Pessoa()  << SEP  << pessoas[numP].Get_Nm_NomePessoa() << endl;
    }
    arquivo.close();
}


void GeradorDeDados::gerarProfessor (string nomeArquivo, unsigned qtdProf)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    for (unsigned numP = 0; numP <(qtdProf - 1); numP++)
    {
        string email, enweb;
        gerarEmaileEnWeb(pessoas[rand()%pessoas.size()].Get_Nm_NomePessoa(), email,enweb);
        prof.push_back(Professor(gerarNumeros(9, 100000000, 900000000), TITULOS[rand()%TITULOS.size()], gerarLocalGabinete(),
                                             GerarTelefone("021", gerarNumeros(9,900000000, 999999999)),
                                             email, enweb, CLASSE[rand ()%CLASSE.size()],
                                             numP));
        arquivo << prof[numP].Get_Nu_SIAPE() << SEP <<
                prof[numP].Get_Ds_Titulo() << SEP <<
                prof[numP].Get_Local_Gabinete() << SEP <<
                prof[numP].Get_Nu_Telefone() << SEP <<
                prof[numP].Get_En_Email() << SEP <<
                prof[numP].Get_En_Web() << SEP <<
                prof[numP].Get_Cd_Professor() << SEP <<
                prof[numP].Get_Ic_Classe()<< endl;
    }
    arquivo.close();
}

//os emails e enderecos gerados serao no formato nome.sobrenome+algo
void GeradorDeDados::gerarEmaileEnWeb (string nome, string &email, string &enWeb)
{
    istringstream iss(nome);
    vector<string> nomes;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(nomes));

    email = nomes[0] + '.' + nomes[nomes.size()-1] + EMAILS [rand()% EMAILS.size()];
    enWeb = nomes[0] + '.' + nomes[nomes.size()-1] + DOMINIOS [rand()% DOMINIOS.size()];;
}

string GeradorDeDados::gerarLocalGabinete ()
{
    return GerarTelefone(BLOCOS[rand()%BLOCOS.size()], (rand ()%400)+ 1);
}

void GeradorDeDados::gerarCoordenacao (string nomeArquivo, unsigned qtdCoord)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    for (unsigned numP = 0; numP <(qtdCoord - 1); numP++)
    {
        coord.push_back(Coordenacao(numP, prof[rand() % prof.size()].Get_Nu_SIAPE()));
        arquivo <<  coord[numP].Get_Cd_Coordenacao() << SEP  << coord[numP].Get_Nu_Siape() << endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarCursos (string nomeArquivo, unsigned qtdCursos)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    if (qtdCursos > CURSOS.size())
        qtdCursos = CURSOS.size();

    for (unsigned numP = 0; numP <(qtdCursos - 1); numP++)
    {
        istringstream iss(CURSOS[rand()%CURSOS.size()]);
        vector<string> nomes;
        copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(nomes));
        cursos.push_back(Curso(numP, nomes[1], coord[rand() % coord.size()].Get_Cd_Coordenacao(), nomes[0]));
        arquivo << cursos[numP].Get_Cd_Curso() << SEP <<
                   cursos[numP].Get_Nm_Curso() << SEP <<
                   cursos[numP].Get_Cd_Coordenacao() << SEP <<
                   cursos[numP].Get_Nm_Area() << endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarAlunos (string nomeArquivo, unsigned qtdCoord)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    for (unsigned numP = 0; numP <(qtdCoord - 1); numP++)
    {
        alunos.push_back(Aluno( gerarNumeros(9, 105000000, 117000000), numP,
                                prof[rand() % prof.size()].Get_Cd_Professor(),
                                cursos[rand() % cursos.size()].Get_Cd_Curso()) );
        arquivo <<  alunos[numP].Get_Nu_Dre()<< SEP <<
                    alunos[numP].Get_Cd_Pessoa() << SEP <<
                    alunos[numP].Get_Nu_Coordenador() << SEP <<
                    alunos[numP].Get_Cd_Curso() << SEP << endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarIncricoes (string nomeArquivo, unsigned qtdCoord)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    for (unsigned numP = 0; numP <(qtdCoord - 1); numP++)
    {
        inscricoes.push_back(Inscricao(numP, 10 * ((float) (rand() % 101) / 100),
                                        alunos[rand() % alunos.size()].Get_Nu_Dre()));
        arquivo << inscricoes[numP].Get_Cd_Inscricao() << SEP <<
                   inscricoes[numP].Get_Nu_Grau() << SEP <<
                   inscricoes[numP].Get_Nu_Dre() << SEP << endl;
    }
    arquivo.close();
}
