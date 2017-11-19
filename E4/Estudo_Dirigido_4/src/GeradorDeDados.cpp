#include "GeradorDeDados.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include<iterator>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include<math.h>


using namespace std;
vector <vector <string> > data;
string alphabet[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };


GeradorDeDados::GeradorDeDados()
{
    srand (time(NULL));
    CURSOS.push_back("ENGENHARIA");
    CURSOS.push_back("MEDICINA");
    CURSOS.push_back("DIREITO");
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
            {
                nome[i] = sobrenomes[rand() % sobrenomes.size()];
                cout << "AQUI" << " " << "rand: " << rand() <<  endl;
            }

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


void GeradorDeDados::gerarPeriodo(string nomeArquivo, unsigned qtdPeriodo)
{

    char buffer [33];
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    for (unsigned index = 0; index < (qtdPeriodo -1); index++)
    {
        int ano = 1960 + index/2;
        int mes = 3 + index % 2 * 4;

        string dataInicio = "01/" + (string) itoa(mes,buffer,10) + "/" + (string) itoa(ano,buffer,10);
        mes += 4;
        string dataFim = "30/" + (string)itoa(mes,buffer,10) + "/" + (string)itoa(ano,buffer,10);

        periodos.push_back(Periodo (index + 1,dataInicio,dataFim));
        arquivo << periodos[index].Get_Cd_Periodo() << SEP <<  periodos[index].Get_Dt_Inicio() << SEP << periodos[index].Get_Dt_Fim() << endl;
    }
    arquivo.close();
}



void GeradorDeDados :: gerarGrade(string nomeArquivo, unsigned qtdGrades)
{
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    for(unsigned index = 0;index < qtdGrades; index ++)
    {
        unsigned dre = 111111111;                           //TODO: MUDAR COMO PEGA O DRE
        unsigned cdPeriodo = periodos[rand() % periodos.size()].Get_Cd_Periodo();
        grades.push_back(Grade_Curricular(index+1,dre,cdPeriodo));
        arquivo << grades[index].Get_Cd_Grade() << SEP << grades[index].Get_Nu_Dre() << SEP << grades[index].Get_Cd_Periodo() << endl;
    }

    arquivo.close();
}


void GeradorDeDados :: gerarDisciplina(string nomeArquivo,unsigned qtdDisciplina)
{
    ofstream arquivo;
    char buffer [30];
    arquivo.open(nomeArquivo.c_str());
    for(unsigned index = 0; index < qtdDisciplina;index ++)
    {
        string cdDisciplina = alphabet[rand() % 26] + alphabet[rand() % 26] + alphabet[rand() % 26] +
                                itoa(rand() % 200 + 100,buffer,10);
        string nomeDisciplina = "TMAB";
        unsigned qtdCred = rand() % 6 + 1;
        string ementa = "Ementa da disciplina, uma breve descrição";
        string bibliografia = "stack overflow";
        unsigned cdGrade = grades[rand() % grades.size()].Get_Cd_Grade();
        disciplinas.push_back(Disciplina(cdDisciplina,nomeDisciplina,qtdCred,ementa,bibliografia,cdGrade));
        arquivo << disciplinas[index].Get_Cd_Disciplina() << SEP << disciplinas[index].Get_Nm_Disciplina()
            << SEP << disciplinas[index].Get_Qt_Creditos() << SEP << disciplinas[index].Get_Ds_Ementa()
            << SEP << disciplinas[index].Get_Ds_Bibliografia() << SEP << disciplinas[index].GetCd_Grade() << endl;
    }
    arquivo.close();
}


void GeradorDeDados :: gerarPreRequisito(string nomeArquivo,unsigned qtdPreReq)
{
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    for(unsigned index = 0;index < qtdPreReq;index++)
    {
        preRequisitos.push_back(Pre_Requisitos(disciplinas[rand() % disciplinas.size()].Get_Cd_Disciplina(),index + 1));
        arquivo << preRequisitos[index].Get_Cd_Disciplina_Dependente() << SEP << preRequisitos[index].Get_Cd_Pre_Requisito() << endl;
    }
    arquivo.close();
}




void GeradorDeDados :: gerarTurmas(string nomeArquivo, unsigned qtdTurmas)
{
    char buffer [20];
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    for(unsigned index = 0; index < qtdTurmas; index++)
    {
        int nuTurma = rand()%1000 + 1;
        string nmLocal = "Sala " + (string) itoa(rand()%300 + 100,buffer,10);
        int vagas = rand() % 70 + 1;
        string cdDisciplina = disciplinas[rand() % disciplinas.size()].Get_Cd_Disciplina();
        string horario = (string) itoa(rand()%10 + 7,buffer,10) + ":00";
        int siape = gerarNumeros(9, 100000000, 900000000);
        turmas.push_back(Turma(nuTurma,nmLocal,vagas,cdDisciplina,horario,siape,index + 1));
        arquivo << turmas[index].Get_Nu_Turma() << SEP << turmas[index].Get_Nm_Local() << SEP << turmas[index].Get_Nu_Vagas()
            << SEP << turmas[index].Get_Cd_Disciplina() << SEP << turmas[index].Get_Ds_Horario() << SEP << turmas[index].Get_Nu_Siape()
            << SEP << turmas[index].Get_Cd_Inscricao() << endl;

    }

    arquivo.close();
}
