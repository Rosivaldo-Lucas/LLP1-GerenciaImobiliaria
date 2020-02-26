#include <sstream>

#include "../include/casa.h"

Casa::Casa() : Imovel(){
  this->numPavimentos = 0;
  this->numQuartos = 0;
  this->areaTerreno = 0;
  this->areaConstruida = 0;
}
Casa::Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida, std::string descricao, double valor, int situacao, Endereco endereco) : Imovel(descricao, valor, situacao, endereco){
  setNumPavimentos(numPavimentos);
  setNumQuartos(numQuartos);
  setAreaTerreno(areaTerreno);
  setAreaConstruida(areaConstruida);
  setTipo(2);
}
Casa::~Casa(){ }

std::string Casa::descricaoImovel(){
  std::stringstream str;

  str << "Tipo do imovel: CASA" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Valor: " << this->getValor() << std::endl;
  return str.str();

}

std::string Casa::exibeImovel(){
  std::stringstream str;
  str << "Tipo do imovel: CASA" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Situacao[1-Aluguel/2-Venda]: " << this->getSituacao() << std::endl
      << "Logradouro: " << this->getEndereco().getLogradouro() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "CEP: " << this->getEndereco().getCep() << std::endl
      << "Numero: " << this->getEndereco().getNumero() << std::endl
      << "Numero de pavimentos: " << this->getNumPavimentos() << std::endl
      << "Numero de quartos: " << this->getNumQuartos() << std::endl
      << "Area do terreno: " << this->getAreaTerreno() << std::endl
      << "Area construida: " << this->getAreaConstruida() << std::endl
      << "Valor da casa: " << this->getValor() << std::endl;
  return str.str();
}

int Casa::getNumPavimentos(){
  return this->numPavimentos;
}
void Casa::setNumPavimentos(int numPavimentos){
  this->numPavimentos = numPavimentos;
  if(numPavimentos < 0){
    this->numPavimentos = 0;
  }
}

int Casa::getNumQuartos(){
  return this->numQuartos;
}
void Casa::setNumQuartos(int numQuartos){
  this->numQuartos = numQuartos;
  if(numQuartos < 0){
    this->numQuartos = 0;
  }
}

double Casa::getAreaTerreno(){
  return this->areaTerreno;
}
void Casa::setAreaTerreno(double areaTerreno){
  this->areaTerreno = areaTerreno;
  if(areaTerreno < 0){
    this->areaTerreno = 0;
  }
}

double Casa::getAreaConstruida(){
  return this->areaConstruida;
}
void Casa::setAreaConstruida(double areaConstruida){
  this->areaConstruida = areaConstruida;
  if(areaConstruida < 0){
    this->areaConstruida = 0;
  }
}
