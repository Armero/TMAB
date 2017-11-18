#ifndef GERADORDEDADOS_H
#define GERADORDEDADOS_H
#include <vector>
#include <string>

typedef std::vector <std::string> Nome;


class GeradorDeDados
{
    public:
        GeradorDeDados();
        Nome GerarNome(bool,int,bool);
        std::string NometoString(Nome);
        std::vector < std::string > LerNomes(bool);
        std::vector < std::string > LerSobrenomes();
        virtual ~GeradorDeDados();

    protected:

    private:
};

#endif // GERADORDEDADOS_H
