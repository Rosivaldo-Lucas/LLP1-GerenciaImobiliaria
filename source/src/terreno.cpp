#include <sstream>

#include "../include/terreno.h"

Terreno::Terreno() : Imovel(){
  this->area = 0.0;
}
Terreno::Terreno(double area, std::string descricao, double valor, int situacao, Endereco endereco) : Imovel(descricao, valor, situacao, endereco){
  setArea(area);
  setTipo(3);
}
Terreno::~Terreno(){ }

std::string Terreno::descricaoImovel(){
  std::stringstream str;
  str << "Tipo do imovel: TERRENO" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Valor: " << this->getValor() << std::endl;
  return str.str();
}

std::string Terreno::exibeImovel(){
  std::stringstream str;
  str << "Tipo do imovel: TERRENO" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Situacao[1-Aluguel/2-Venda]: " << this->getSituacao() << std::endl
      << "Logradouro: " << this->getEndereco().getLogradouro() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "CEP: " << this->getEndereco().getCep() << std::endl
      << "Numero: " << this->getEndereco().getNumero() << std::endl
      << "Area do terreno: " << this->getArea() << std::endl
      << "Valor da casa: " << this->getValor() << std::endl;
  return str.str();
}

double Terreno::getArea(){
  return this->area;
}
void Terreno::setArea(double area){
  this->area = area;
  if(area < 0){
    this->area = 0.0;
  }
}
