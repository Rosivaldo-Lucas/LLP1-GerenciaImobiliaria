#ifndef _CASA_
#define _CASA_

#include "./imovel.h"

class Casa : public Imovel{
  public:
    Casa();
    Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida, std::string descricao, double valor, int situacao, Endereco endereco);
    virtual ~Casa();

    int getNumPavimentos();
    void setNumPavimentos(int numPavimentos);
    int getNumQuartos();
    void setNumQuartos(int numQuartos);
    double getAreaTerreno();
    void setAreaTerreno(double areaTerreno);
    double getAreaConstruida();
    void setAreaConstruida(double areaConstruida);

    virtual std::string descricaoImovel();
    virtual std::string exibeImovel();

  private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
};

#endif //_CASA_