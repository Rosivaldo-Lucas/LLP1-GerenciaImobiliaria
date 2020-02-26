#include "../include/imovel.h"

Imovel::Imovel(){
  this->descricao = "";
  this->valor = 0.0;
  this->tipo = 0;
  this->situacao = 0;
  this->endereco = Endereco("", 0, "", "", "");
}
Imovel::Imovel(std::string descricao, double valor, int situacao, Endereco endereco){
  setDescricao(descricao);
  setValor(valor);
  setTipo(tipo);
  setSituacao(situacao);
  setEndereco(endereco);
}
Imovel::~Imovel(){ }

std::string Imovel::getDescricao(){
  return this->descricao;
}
void Imovel::setDescricao(std::string descricao){
  this->descricao = descricao;
}

double Imovel::getValor(){
  return this->valor;
}
void Imovel::setValor(double valor){
  this->valor = valor;
  if(valor < 0){
    this->valor = 0;
  }
}

int Imovel::getTipo(){
  return this->tipo;
}
void Imovel::setTipo(int tipo){
  this->tipo = tipo;
  if(tipo < 0){
    this->tipo = 0;
  }
}

int Imovel::getSituacao(){
  return this->situacao;
}
void Imovel::setSituacao(int situacao){
  this->situacao = situacao;
  if(situacao < 0){
    this->situacao = 0;
  }
}

Endereco Imovel::getEndereco(){
  return this->endereco;
}
void Imovel::setEndereco(Endereco endereco){
  this->endereco = endereco;
}
