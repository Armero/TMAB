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

#include <iostream>
using namespace std;

#include <stdio.h>

#define OTL_ODBC // Compile OTL 4.0/ODBC
#include <otlv4.h> // include the OTL 4.0 header file

otl_connect db; // connect object

void lancarNotas(int Nu_Turma)
{
    otl_stream i(50, // buffer size
                "SELECT D.Nm_Pessoa, A.Nu_Dre, A.Nu_Grau\
                FROM Inscricao as A\
                INNER JOIN Turma as B ON B.Nu_Turma = A.Nu_Turma\
                INNER JOIN Aluno as C ON A.Nu_Dre = C.Nu_Dre\
                INNER JOIN Pessoa as D ON D.Cd_Pessoa = C.Cd_Pessoa\
                where B.Nu_Turma =:f<int>",
				 // SELECT statement
			  db // connect object
			 );


    char f1[1000][60];
    int f2[1000];
    float f3[1000];
    int aux = 0;

    i << Nu_Turma;

    while(!i.eof()){ // while not end-of-data
		i>>f1[aux]>>f2[aux]>>f3[aux];
		aux++;
	}

    otl_stream o(100, // buffer size
			  "update Inscricao SET Nu_Grau =:f1<float> where Nu_Turma=:f2<int> AND Nu_Dre=:f3<int>",
				 // SQL statement
			  db // connect object
			 );


    for (int k=0; k<aux; k++)
	{
		float nu_grau;
		cout << "Digite a nota do aluno: " << f1[k] << endl;
		cin >> nu_grau;

		o<<nu_grau<<Nu_Turma<<f2[k];
	}
}

//Mudar o Where para que o professor seja identificado pelo numero do SIAPE
void listarPauta (unsigned Nu_Siape, unsigned Cd_Periodo)
{
    otl_stream i(50, // buffer size
            " SELECT Aluno.Nu_Dre, Pessoa.Nm_Pessoa FROM Turma\
            INNER JOIN Professor ON Turma.Nu_Siape = Professor.Nu_Siape\
            INNER JOIN Inscricao ON Turma.Nu_Turma = Inscricao.Nu_Turma\
            INNER JOIN Periodo ON Turma.Cd_Periodo = Periodo.Cd_Periodo\
            INNER JOIN Aluno ON Inscricao.Nu_Dre = Aluno.Nu_Dre\
            INNER JOIN Pessoa ON Aluno.Cd_Pessoa = Pessoa.Cd_Pessoa\
            WHERE Professor.Nu_SIAPE = :f<unsigned> AND\
            Periodo.Cd_Periodo = :ff<unsigned>; ",
          db
         );

         unsigned f1[1000];
         char f2 [1000][60];
         unsigned aux = 0;

         i << Nu_Siape << Cd_Periodo;
         while(!i.eof()){ // while not end-of-data
            i>>f1[aux]>>f2[aux];
            cout << aux + 1 <<  " Dre: " << f1[aux] << " Nome: "<< f2[aux] << endl;
            aux++;
        }
}

void inline printDate (otl_datetime t)
{
    cout << t.day << "/" << t.month << "/" << t.year;
}

//Mudar o Where para que o numero do DRE identifique o aluno efetivamente
void listarHistorico (unsigned Nu_Dre)
{
  otl_stream i(50, // buffer size
            "SELECT Disciplina.Nm_Disciplina, Periodo.Dt_Inicio, Periodo.Dt_Fim\
            FROM Grade_Curricular\
            INNER JOIN Aluno ON Grade_Curricular.Nu_Dre = Aluno.Nu_Dre\
            INNER JOIN Disciplina ON Grade_Curricular.Cd_Disciplina = Disciplina.Cd_Disciplina\
            INNER JOIN Periodo ON Grade_Curricular.Cd_Periodo = Periodo.Cd_Periodo\
           \
            WHERE Aluno.Nu_DRE = :f<unsigned>;",
          db
         );

         char f1 [1000][60];
         otl_datetime tm1;
         otl_datetime tm2;
         unsigned aux = 0;

         i << Nu_Dre;
         while(!i.eof()){ // while not end-of-data
            i>>f1[aux]>>tm1>>tm2;
            cout << aux + 1 <<  "| Disciplina: " << f1[aux] <<"| "<< "Data de Inicio: ";
            printDate(tm1);
            cout << "|";
            cout << "Data de Termino: ";
            printDate(tm2) ;
            cout << endl;
            aux++;
        }
}

void inscreverAluno(unsigned Cd_Periodo,unsigned dre)
{   unsigned nuTurma;

     otl_stream i(50, // buffer size
            " SELECT Nm_Disciplina, Ds_Horario,Nm_Local,Pessoa.Nm_Pessoa,Turma.Nu_Turma\
            FROM Turma\
            INNER JOIN Disciplina ON Turma.Cd_Disciplina = Disciplina.Cd_Disciplina\
            INNER JOIN Professor ON Turma.Nu_Siape = Professor.Nu_Siape\
            INNER JOIN Pessoa ON Professor.Cd_Pessoa = Pessoa.Cd_Pessoa\
            WHERE Turma.Cd_Periodo = :f<unsigned>;",
          db
         );

    char f1 [1000][50];
    char f2 [1000][50];
    char f3 [1000][50];
    char f4 [1000][50];
    unsigned f5[1000];
    unsigned aux = 0;

    i << Cd_Periodo;
    while(!i.eof()){ // while not end-of-data
            i>>f1[aux]>>f2[aux]>>f3[aux]>>f4[aux]>>f5[aux];
            cout << "Numero turma: " << f5[aux] <<  "| " << f1[aux] << "| "<< f2[aux] <<  "| " << f3[aux] <<  "| " <<f4[aux] << "| " <<endl;
            aux++;
        }

    cout<<"Digite o numero da turma que voce quer se inscrever : ";
    cin >> nuTurma;
     if (cin.fail()) {
            //Not an int.
                cout << "input invalido" << endl;
                return;
            }

    otl_stream o(50, // buffer size
			  "INSERT INTO Inscricao (Nu_Grau, Nu_Dre,Nu_Turma)\
                VALUES(0,:ff <unsigned>,:fff<unsigned>);",
				 // SQL statement
			  db // connect object
			 );

    o <<  dre << nuTurma;
    cout << "Inscricao realizada!" << endl;
    otl_stream i2 (50,
           "select Pessoa.Nm_Pessoa, Aluno.Nu_Dre from Pessoa\
            inner join Aluno on Pessoa.Cd_Pessoa = Aluno.Cd_Pessoa\
            where Aluno.Nu_Dre = :f<unsigned>",
            db);
    char nome [60];
    unsigned DRE;
    i2 << dre;
    i2 >> nome >> DRE;

    cout << "Aluno: " << nome << " Dre: " << DRE << " Inscrito na turma: " << nuTurma << endl;
}


void showMenu()
{
    unsigned entrada,nuSiape,cdPeriodo,nuTurma,cdPessoa,dre;
    bool sair = false;

    cout << "Estudo Dirigido 6 - TMAB" << endl;
    cout << "Grupo K" << endl;
    cout << "Felipe Claudio da Silva Santos" << endl;
    cout << "Thiago Koster Lago" << endl;
    cout << endl;

    while (!sair)
    {
        cout << endl;
        cout << "---------------------Menu------------------" << endl;
        cout << "|1 - Se matricular em turma               |" << endl;
        cout << "|2 - Listar pauta de turma do professor   |" << endl;
        cout << "|3 - Lancar notas de turma                |" << endl;
        cout << "|4 - Listar historico de aluno            |" << endl;
        cout << "|0 - Sair do sistema                      |" << endl;
        cout << "-------------------------------------------" << endl;

        cout << endl;
        cout << endl;
        cout << endl;

        cout << "Digite a opcao correspondente a operacao desejada: ";

        cin >> entrada;

        switch(entrada)
        {
            case 1 :
                cout << "Matricular em Turma..." << endl;
                cout << "Digite o DRE e codigo do periodo separados por espaco: ";
                cin >> dre >> cdPeriodo;
                if (cin.fail()) {
                //Not an int.
                    cout << "input invalido" << endl;
                    break;
                }
                inscreverAluno(cdPeriodo,dre);
                break;

            case 2 :
                cout << "Listar pauta de turma do professor..." << endl;
                cout << "Digite o Numero do SIAPE do professor e o codigo do periodo separados por espaco: " << endl;
                cin >> nuSiape >> cdPeriodo;

                if (cin.fail()) {
                //Not an int.
                    cout << "input invalido" << endl;
                    break;
                }
                listarPauta(nuSiape, cdPeriodo);
                break;

            case 3 :
                cout << "Lancar notas de turma..." << endl;
                cout << "Digite o numero da turma: " << endl;
                cin >> nuTurma;
                lancarNotas(nuTurma);
                break;

            case 4 :
                cout << "Listar historico de aluno..." << endl;
                cout << "Digite o DRE referente ao aluno: " << endl;
                cin >> cdPessoa;

                if (cin.fail()) {
                //Not an int.
                    cout << "input invalido" << endl;
                    break;
                }
                listarHistorico(cdPessoa);
                break;

            case 0:
                sair = true;
                break;

            default:

                cout << "Opcao invalida, tente novamente..." << endl;
                showMenu();
                break;
        }
    }

}

int main()
{
 otl_connect::otl_initialize(); // initialize ODBC environment
 try{

  db.rlogon("UID=root;PWD=;DSN=E06-K"); // connect to ODBC
  showMenu();
 }

 catch(otl_exception& p){ // intercept OTL exceptions
  cerr<<p.msg<<endl; // print out error message
  cerr<<p.stm_text<<endl; // print out SQL that caused the error
  cerr<<p.sqlstate<<endl; // print out SQLSTATE message
  cerr<<p.var_info<<endl; // print out the variable that caused the error
 }

 db.logoff(); // disconnect from Oracle

 return 0;
}
