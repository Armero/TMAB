/**
* UFRJ - Universidade Federal do Rio de Janeiro
* IM - Instituto de Matemática
* DMA - Departamento de Matemática Aplicada
*
* TMAB - Programação C/C++ & Banco de Dados
* ParteII - Programação OO em C++
*
* Descrição do Estudo Dirigido 04
* Prazo de Entrega: 21 de novembro de 2017
*
* Prof. Milton Ramirez (milton@labma.ufrj.br)
* Rio de Janeiro, 13 de novembro de 2017
* Grupo K
* Felipe Claudio
* Thiago Koster Lago
**/

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
#include<windows.h>


using namespace std;
vector <vector <string> > data;
string alphabet[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
string bibliografias[4] = {"Stack Overflow", "The C++ Programming Language","Fundamentals of Database Systems","Effective C++"};

GeradorDeDados::GeradorDeDados()
{
    srand (time(NULL));
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
    CLASSE.push_back("Associado");
    CLASSE.push_back("Assistente");
    CLASSE.push_back("Adjunto");
    CLASSE.push_back("Titular");
    CURSOS.push_back("Poli Engenharia Eletrônica");
    CURSOS.push_back("Poli Engenharia Quimica");
    CURSOS.push_back("Poli Engenharia Elétrica");
    CURSOS.push_back("Poli Engenharia Mecânica");
    CURSOS.push_back("IM Aplicada");
    CURSOS.push_back("IF Física");
    CURSOS.push_back("FND Direito");
    CURSOS.push_back("IFCS Filosofia");
    CURSOS.push_back("CCS Medicina");
    CURSOS.push_back("CCS Enfermagem");
    CURSOS.push_back("Letras Ingles");
    CURSOS.push_back("Letras Espanhol");
    TIPO_ATV.push_back("Iniciacao Científica");
    TIPO_ATV.push_back("Extensão");
    TIPO_DISCIPLINAS.push_back("Básica");
    TIPO_DISCIPLINAS.push_back("Profissional");
    TIPO_DISCIPLINAS.push_back("Optativa");
    for (unsigned i = 0; i < CURSOS.size(); i++)
    {
        cursosUtilizados.push_back(false);
    }
    gerarMaterias(200, 200, 200);
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
            valor -= rand()% numeroFinal;

        if ( valor < numeroInicial)
            valor += rand ()% numeroFinal;
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

//Separa a string dada em um vetor de strings
Nome GeradorDeDados::separarString (string texto)
{
    istringstream iss(texto);
    Nome nomes;
    copy(istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter(nomes));

    return nomes;
}

void GeradorDeDados::gerarMaterias(unsigned nObrigatorias, unsigned nProfissionais, unsigned nOptativas)
{
    unsigned cont = 0;
    for ( ; cont < nObrigatorias; cont++)
    {
        char caux [10];
        sprintf(caux, "%d", cont+1);
        string saux (caux);
        MATERIAS.push_back("Diciplina Commum" + saux);
    }
    for (; cont < (nObrigatorias + nProfissionais); cont++)
    {
        char caux [10];
        sprintf(caux, "%d", cont+1 - nObrigatorias);
        string saux (caux);
        MATERIAS.push_back("Diciplina Profissional" + saux);
    }
    for (; cont < (nObrigatorias + nProfissionais + nOptativas); cont++)
    {
        char caux [10];
        sprintf(caux, "%d", cont+1 - nObrigatorias - nProfissionais);
        string saux (caux);
        MATERIAS.push_back("Diciplina Optativa" + saux);
    }
}

void GeradorDeDados::gerarPessoas (string nomeArquivo, unsigned qtdPessoas)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for (unsigned numP = 0; numP < qtdPessoas; numP++)
    {
        string sexo = "";
        bool masculino = true;
        unsigned idade = rand() %80 + 15;
        if (rand() % 2 == 0)
        {
            sexo = "Masculino";
            masculino = true;
        }

        else
        {
            sexo = "Feminino";
            masculino = false;
        }

        pessoas.push_back(Pessoa (numP, NometoString(GerarNome(rand()%2,rand()%2 + 1, masculino)),sexo,idade));
        arquivo <<  pessoas[numP].Get_Cd_Pessoa()  << SEP  << pessoas[numP].Get_Nm_NomePessoa() << SEP
        << pessoas[numP].Get_Ds_SexPessoa()<< SEP << pessoas[numP].Get_Nu_IdadePessoa() << endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarPeriodo(string nomeArquivo, unsigned qtdPeriodo)
{
    char buffer [33];
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for (unsigned index = 0; index < qtdPeriodo; index++)
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

void GeradorDeDados::gerarProfessor (string nomeArquivo, unsigned qtdProf)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for (unsigned numP = 0; numP <qtdProf; numP++)
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
    Nome nomes = separarString(nome);

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
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for (unsigned numP = 0; numP < qtdCoord; numP++)
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

    //limita o numero de cursos gerados ao maximo de cursos
    //existentes na database
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    if (qtdCursos > CURSOS.size())
        qtdCursos = CURSOS.size();

    unsigned valor = 0;

    for (unsigned numP = 0; numP <qtdCursos; numP++)
    {
        //Faz com que todos os cursos gerados sejam diferentes
        valor = rand() % CURSOS.size();
        while (cursosUtilizados[valor])
            valor = rand() % CURSOS.size();

        Nome nomes = separarString(CURSOS[valor]);
        cursosUtilizados[valor] = true;
        string nmCurso;

        //possibilita que um curso tenha nome composto
        if (nomes.size() > 2)
            nmCurso = nomes[1] + " " + nomes[2];
        else
            nmCurso = nomes[1];

        cursos.push_back(Curso(numP, nmCurso,
                               coord[rand() % coord.size()].Get_Cd_Coordenacao(),
                               nomes[0],
                               (rand()% 7 + 4) )) ;

        arquivo << cursos[numP].Get_Cd_Curso() << SEP <<
                   cursos[numP].Get_Nm_Curso() << SEP <<
                   cursos[numP].Get_Cd_Coordenacao() << SEP <<
                   cursos[numP].Get_Nm_Area() << SEP <<
                   cursos[numP].Get_Nu_Semestres()<< endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarAlunos (string nomeArquivo, unsigned qtdAlunos)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for (unsigned numP = 0; numP <qtdAlunos; numP++)
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


void GeradorDeDados::gerarIncricoes (string nomeArquivo, unsigned minAlunosInscritos)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());

    arquivo << "\"sep=" << SEP <<"\"" << endl;
    unsigned total = 0;
    unsigned numTurma = 0;
    for (unsigned numP = 0; numP < turmas.size(); numP++)
    {
        //indica se o aluno ja foi inscrito na materia
        vector <bool> alunoInscrito;
        for (unsigned i = 0; i < alunos.size(); i++)
            alunoInscrito.push_back(false);

        //preenche uma materia com um numero de alunos aleatorios
        unsigned numVagas = turmas[numTurma].Get_Nu_Vagas();
        unsigned numInscricoes = ((numVagas - minAlunosInscritos) % numVagas) + minAlunosInscritos;
        unsigned numAluno = rand() % alunos.size();

        for (unsigned cont = 0; cont < numInscricoes; cont++)
        {
            //procura alunos nao inscritos na materia
            while (alunoInscrito[numAluno])
                numAluno = rand() % alunos.size();

            //cria o objeto da inscricao com uma nota randomica entre 0 e 10
            inscricoes.push_back(Inscricao(total,
                                           (float) (rand() % 101) /10,
                                            alunos[numAluno].Get_Nu_Dre(),
                                            turmas[numTurma].Get_Nu_Turma()));

            //realiza a inscricao do aluno nas materias
            arquivo << inscricoes[total].Get_Cd_Inscricao() << SEP <<
                       inscricoes[total].Get_Nu_Grau() << SEP <<
                       inscricoes[total].Get_Nu_Dre() << SEP <<
                       inscricoes[total].Get_Nu_Turma()<< endl;

            alunoInscrito[numAluno] = true;
            total++;
        }
        numTurma++;
    }
    arquivo.close();
}



void GeradorDeDados :: gerarGrade(string nomeArquivo, unsigned qtdGrades)
{
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for(unsigned index = 0;index < qtdGrades; index ++)
    {
        unsigned dre = alunos[rand() % alunos.size()].Get_Nu_Dre();                        //TODO: MUDAR COMO PEGA O DRE
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
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for(unsigned index = 0; index < qtdDisciplina;index ++)
    {
        string cdDisciplina = alphabet[rand() % 26] + alphabet[rand() % 26] + alphabet[rand() % 26] +
                                itoa(rand() % 200 + 100,buffer,10);
        unsigned qtdCred = rand() % 6 + 1;
        string ementa = "Ementa da disciplina uma breve descrição";
        string bibliografia = bibliografias[rand() % 4];
        unsigned cdGrade = grades[rand() % grades.size()].Get_Cd_Grade();
        disciplinas.push_back(Disciplina(cdDisciplina,MATERIAS[rand() % MATERIAS.size()] ,
                                         qtdCred, ementa, bibliografia,
                                         cdGrade, TIPO_DISCIPLINAS[rand()% TIPO_DISCIPLINAS.size()]));
        arquivo << disciplinas[index].Get_Cd_Disciplina() << SEP << disciplinas[index].Get_Nm_Disciplina()
            << SEP << disciplinas[index].Get_Qt_Creditos() << SEP << disciplinas[index].Get_Ds_Ementa()
            << SEP << disciplinas[index].Get_Ds_Bibliografia() << SEP << disciplinas[index].GetCd_Grade()
            << SEP << disciplinas[index].Get_Ic_Disciplina() << endl;
    }
    arquivo.close();
}


void GeradorDeDados :: gerarPreRequisito(string nomeArquivo,unsigned qtdPreReq)
{
    ofstream arquivo;
    arquivo.open(nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for(unsigned index = 0;index < qtdPreReq;index++)
    {
        preRequisitos.push_back(Pre_Requisitos(disciplinas[rand() % disciplinas.size()].Get_Cd_Disciplina(),index + 1));
        arquivo << preRequisitos[index].Get_Cd_Disciplina_Dependente() << SEP << preRequisitos[index].Get_Cd_Pre_Requisito() << endl;
    }
    arquivo.close();
}


void GeradorDeDados :: gerarTurmas(string nomeArquivo, unsigned qtdMaxAlunos, unsigned qtdMinAlunos)
{
    char buffer [20];
    unsigned qtdTurmas = (double) alunos.size()/qtdMaxAlunos;
    ofstream arquivo;
    const unsigned MAX_MATERIAS_PROF = 4;
    arquivo.open(nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    for(unsigned index = 0; index < qtdTurmas; index++)
    {

        //vetor com o numero de materias ministradas por cada professor
        vector <unsigned> numMateriasProf;
        for (unsigned i = 0; i < prof.size(); i++)
            numMateriasProf.push_back(0);

        //Busca ate encontrar um professor que ministre menos que 4 materias
        unsigned numProfessor = rand() % prof.size();
        while (numMateriasProf[numProfessor] > (rand () % MAX_MATERIAS_PROF + 1) )
            numProfessor = rand() % prof.size();


        int nuTurma = rand()%qtdTurmas + 1;
        unsigned numDisciplina = 0;

        //limita o numero minimo e maximo de vagas
        unsigned vagas = (rand() % (qtdMaxAlunos - qtdMinAlunos)) +  qtdMinAlunos;

        //gera o local, o codigo e o horario da disciplina
        string nmLocal = "Sala " + (string) itoa(rand()%300 + 100,buffer,10);
        string cdDisciplina = disciplinas[rand() % disciplinas.size()].Get_Cd_Disciplina();
        string horario = (string) itoa(rand()%10 + 7,buffer,10) + ":00";

        //obtem o numero do SIAPE do professor
        unsigned siape = prof[numProfessor].Get_Nu_SIAPE();
        turmas.push_back(Turma(nuTurma,nmLocal,vagas,cdDisciplina,horario,siape,periodos[rand() % periodos.size()].Get_Cd_Periodo()));

        //salva os dados no arquivo
        arquivo << turmas[index].Get_Nu_Turma() << SEP << turmas[index].Get_Nm_Local() << SEP << turmas[index].Get_Nu_Vagas()
            << SEP << turmas[index].Get_Cd_Disciplina() << SEP << turmas[index].Get_Ds_Horario() << SEP << turmas[index].Get_Nu_Siape()
            << SEP << turmas[index].Get_Cd_Periodo() << endl;

        //gera mais uma numero de vagas aleatorio para outra turma
        vagas = (rand() % (qtdMaxAlunos - qtdMinAlunos)) +  qtdMinAlunos;

        //adiciona mia uma materia para o professor
        numMateriasProf[numProfessor]++;

    }
    arquivo.close();
}

void GeradorDeDados::gerarAtividades (string nomeArquivo, unsigned qtdAtividades)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;
    string titulo = "Pesquisa Generica";
    for (unsigned numP = 0; numP <qtdAtividades; numP++)
    {
        atividades.push_back (Atividade (numP, titulo, 10 * ((float) (rand() % 101) / 100),
                                    TIPO_ATV[rand() % TIPO_ATV.size()],
                                    alunos[rand() % alunos.size()].Get_Nu_Dre(),
                                    prof[rand() % prof.size()].Get_Nu_SIAPE() ) );
        arquivo << atividades[numP].Get_Cd_Atividade() << SEP <<
                   atividades[numP].Get_Nm_Titulo_JIE() << SEP <<
                   atividades[numP].Get_Nu_Nota() << SEP <<
                   atividades[numP].Get_Ic_Tipo_Atividade() << SEP <<
                   atividades[numP].Get_Nu_Dre() << SEP <<
                   atividades[numP].Get_Nu_Orientador() << endl;
    }
    arquivo.close();
}

void GeradorDeDados::gerarGradeCurso(string nomeArquivo)
{
    ofstream arquivo;
    arquivo.open (nomeArquivo.c_str());
    //arquivo << "\"sep=" << SEP <<"\"" << endl;

    //conta o numero de disciplinas no total de grades
    //responsavel por contar o numero de grades criadas
    unsigned ContDisciplinas = 0;

    //popula cada curso ordenadamente
    for (unsigned i = 0; i < cursos.size(); i++)
    {
        //Popula cada semestre de um curso
        for (unsigned j = 0; j < cursos[i].Get_Nu_Semestres(); j++)
        {
            //Vetor que indica quais materias ja estao na grade
            vector <bool> materiasNaGrade;
            for (unsigned aux = 0; aux < disciplinas.size(); aux++)
                materiasNaGrade.push_back(false);

            //numero de materias em um periodo
            unsigned numMaterias = rand ()%4 + 4;
            for (unsigned k = 0; k < numMaterias; k++)
            {
                unsigned numDisciplina = rand() % disciplinas.size();

                //seleciona uma disciplina aleatoria
                while (materiasNaGrade[numDisciplina])
                    numDisciplina = rand() % disciplinas.size();

                //adiciona uma nova grade no vetor de grades
                gradesCursos.push_back(Grade_Curso(i, disciplinas[numDisciplina].Get_Cd_Disciplina(), j+1,
                                                   disciplinas[numDisciplina].Get_Qt_Creditos()));


                //escreve no arquivo a grade
                arquivo << gradesCursos[ContDisciplinas].Get_Cd_Curso() << SEP
                        << gradesCursos[ContDisciplinas].Get_Cd_Disciplina() << SEP
                        << gradesCursos[ContDisciplinas].Get_Ic_Periodo() << SEP
                        << gradesCursos[ContDisciplinas].Get_Qt_Creditos() << endl;

                materiasNaGrade[numDisciplina] = true;
                ContDisciplinas++;
            }
        }
    }

}
void GeradorDeDados::criarPasta(const char * path)
{
    if(!CreateDirectory(path,NULL))
    {
        return;
    }
}
