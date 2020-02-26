#ifndef _TERRENO_
#define _TERRENO_

#include "./imovel.h"

class Terreno : public Imovel{
  public:
    Terreno();
    Terreno(double area, std::string descricao, double valor, int situacao, Endereco endereco);
    virtual ~Terreno();

    double getArea();
    void setArea(double area);

    virtual std::string descricaoImovel();
    virtual std::string exibeImovel();

  private:
    double area;
};

#endif //_TERRENO_