#ifndef _APARTAMENTO_
#define _APARTAMENTO_

#include "imovel.h"

class Apartamento : public Imovel{
  public:
    Apartamento();
    Apartamento(std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, std::string descricao, double valor, int situacao, Endereco endereco);
    virtual ~Apartamento();

    std::string getPosicao();
    void setPosicao(std::string posicao);
    int getNumQuartos();
    void setNumQuartos(int numQuartos);
    double getValorCondominio();
    void setValorCondominio(double valorCondominio);
    int getVagasGaragem();
    void setVagasGaragem(int vagasGaragem);
    double getArea();
    void setArea(double area);

    virtual std::string descricaoImovel();
    virtual std::string exibeImovel();

  private:
    std::string posicao;
    int numQuartos;
    double valorCondominio;
    int vagasGaragem;
    double area;
};

#endif //_APARTAMENTO_