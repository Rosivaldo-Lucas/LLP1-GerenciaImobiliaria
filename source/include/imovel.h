#ifndef _IMOVEL_
#define _IMOVEL_

#include <fstream>

#include "endereco.h"

class Imovel{
  public:
    Imovel();
    Imovel(std::string descricao, double valor, int situacao, Endereco endereco);
    virtual ~Imovel();

    std::string getDescricao();
    void setDescricao(std::string descricao);
    double getValor();
    void setValor(double valor);
    int getTipo();
    void setTipo(int tipo);
    int getSituacao();
    void setSituacao(int situacao);
    Endereco getEndereco();
    void setEndereco(Endereco endereco);

    virtual std::string descricaoImovel() = 0;
    virtual std::string exibeImovel() = 0;

  private:
    std::string descricao;
    double valor;
    int tipo; // 1-Apartamento 2-Casa 3-Terreno
    int situacao; // 1-Aluguel 2-Venda
    Endereco endereco;
};

#endif //_IMOVEL_