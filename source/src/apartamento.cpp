#include <sstream>

#include "../include/apartamento.h"

Apartamento::Apartamento() : Imovel(){
  this->posicao = "";
  this->numQuartos = 0;
  this->valorCondominio = 0.0;
  this->vagasGaragem = 0;
  this->area = 0.0;
  setTipo(1);
}
Apartamento::Apartamento(std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, std::string descricao, double valor, int situacao, Endereco endereco) : Imovel(descricao, valor, situacao, endereco){
  setPosicao(posicao);
  setNumQuartos(numQuartos);
  setValorCondominio(valorCondominio);
  setVagasGaragem(vagasGaragem);
  setArea(area);
  setTipo(1);
}
Apartamento::~Apartamento(){ }

std::string Apartamento::descricaoImovel(){
  std::stringstream str;

  str << "Tipo do imovel: APARTAMENTO" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Valor: " << this->getValor() << std::endl;

  return str.str();

}

std::string Apartamento::exibeImovel(){
  std::stringstream str;
  str << "Tipo do imovel: APARTAMENTO" << std::endl
      << "Descricao: " << this->getDescricao() << std::endl
      << "Situacao[1-Aluguel/2-Venda]: " << this->getSituacao() << std::endl
      << "Logradouro: " << this->getEndereco().getLogradouro() << std::endl
      << "Bairro: " << this->getEndereco().getBairro() << std::endl
      << "Cidade: " << this->getEndereco().getCidade() << std::endl
      << "CEP: " << this->getEndereco().getCep() << std::endl
      << "Numero: " << this->getEndereco().getNumero() << std::endl
      << "Posicao: " << this->getPosicao() << std::endl
      << "Numero de quartos: " << this->getNumQuartos() << std::endl
      << "Vagas na garagem: " << this->getVagasGaragem() << std::endl
      << "Area do apartamento: " << this->getArea() << std::endl
      << "Valor do condominio: " << this->getValorCondominio() << std::endl
      << "Valor do apartamento: " << this->getValor() << std::endl;
  return str.str();
}

std::string Apartamento::getPosicao(){
  return this->posicao;
}
void Apartamento::setPosicao(std::string posicao){
  this->posicao = posicao;
}

int Apartamento::getNumQuartos(){
  return this->numQuartos;
}
void Apartamento::setNumQuartos(int numQuartos){
  this->numQuartos = numQuartos;
  if(numQuartos < 0){
    this->numQuartos = 0;
  }
}

double Apartamento::getValorCondominio(){
  return this->valorCondominio;
}
void Apartamento::setValorCondominio(double valorCondominio){
  this->valorCondominio = valorCondominio;
  if(valorCondominio < 0){
    this->valorCondominio = 0.0;
  }
}

int Apartamento::getVagasGaragem(){
  return this->vagasGaragem;
}
void Apartamento::setVagasGaragem(int vagasGaragem){
  this->vagasGaragem = vagasGaragem;
  if(vagasGaragem < 0){
    this->vagasGaragem = 0;
  }
}

double Apartamento::getArea(){
  return this->area;
}
void Apartamento::setArea(double area){
  this->area = area;
  if(area < 0){
    this->area = 0.0;
  }
}
