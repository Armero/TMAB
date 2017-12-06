#include <iostream>
using namespace std;

#include <stdio.h>

#define OTL_ODBC // Compile OTL 4.0/ODBC
#include <otlv4.h> // include the OTL 4.0 header file

otl_connect db; // connect object

void insert()
// insert rows into table
{
 otl_stream o(50, // buffer size
              "insert into test_tab values(:f1<float>,:f2<char[31]>)",
                 // SQL statement
              db // connect object
             );
 char tmp[32];

 for(int i=1;i<=100;++i){
  sprintf(tmp,"Name%d",i);
  o<<(float)i<<tmp;
 }
}

void selectPessoa()
{
 otl_stream i(50, // buffer size
              "select * from Pessoa;",
                 // SELECT statement
              db // connect object
             );
   // create select stream

 int f1;
 char f2[60];
 char f3[60];
 int f4;

 //i<<8<<8; // assigning :f = 8; :ff = 8
   // SELECT automatically executes when all input variables are
   // assigned. First portion of output rows is fetched to the buffer

 while(!i.eof()){ // while not end-of-data
  i>>f1>>f2>>f3>>f4;
  cout<<"f1="<<f1<<", f2="<<f2<<", f3="<<f3<<", f4="<<f4<<endl;
 }

/* i<<4<<4; // assigning :f = 4, :ff = 4
   // SELECT automatically executes when all input variables are
   // assigned. First portion of output rows is fetched to the buffer

 while(!i.eof()){ // while not end-of-data
  i>>f1>>f2;
  cout<<"f1="<<f1<<", f2="<<f2<<endl;
 }
 */

}

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

    char f1[60][100];
    int f2[60];
    float f3;
    int aux = 0;

    i << Nu_Turma;

    while(!i.eof()){ // while not end-of-data
		i>>f1[aux]>>f2[aux]>>f3;
		aux++;
	}

    otl_stream o(50, // buffer size
			  "update Inscricao SET Nu_Grau =:f1<int> where Nu_Turma=:f2<int> AND Nu_Dre=:f3<int>",
				 // SQL statement
			  db // connect object
			 );

    for (int k=0; k<aux; k++)
	{
		int nu_grau;
		cout << "Digite a nota do aluno: " << f1[k] << endl;
		cin >> nu_grau;

		o<<nu_grau<<Nu_Turma<<f2[k];
	}
}


int main()
{
 otl_connect::otl_initialize(); // initialize ODBC environment
 try{

  db.rlogon("UID=root;PWD=;DSN=E06-K"); // connect to ODBC

  otl_cursor::direct_exec
   (
    db,
    "drop table test_tab",
    otl_exception::disabled // disable OTL exceptions
   ); // drop table

  otl_cursor::direct_exec
   (
    db,
    "create table test_tab(f1 int, f2 varchar(30))"
    );  // create table

  insert(); // insert records into table
  //selectPessoa(); // select records from table
  lancarNotas(1);
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
