#include "../include/endereco.h"

Endereco::Endereco(){
  this->logradouro = "";
  this->numero = 0;
  this->bairro = "";
  this->cidade = "";
  this->cep = "";
}
Endereco::Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep){
  setLogradouro(logradouro);
  setNumero(numero);
  setBairro(bairro);
  setCidade(cidade);
  setCep(cep);
}
Endereco::~Endereco(){ }

std::string Endereco::getLogradouro(){
  return this->logradouro;
}
void Endereco::setLogradouro(std::string logradouro){
  this->logradouro = logradouro;
}

int Endereco::getNumero(){
  return this->numero;
}
void Endereco::setNumero(int numero){
  this->numero = numero;
  if(numero < 0){
    this->numero = 1;
  }
}

std::string Endereco::getBairro(){
  return this->bairro;
}
void Endereco::setBairro(std::string bairro){
  this->bairro = bairro;
}

std::string Endereco::getCidade(){
  return this->cidade;
}
void Endereco::setCidade(std::string cidade){
  this->cidade = cidade;
}

std::string Endereco::getCep(){
  return this->cep;
}
void Endereco::setCep(std::string cep){
  this->cep = cep;
}