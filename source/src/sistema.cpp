#include "../include/sistema.h"
#include <iostream>

// Método para cadastrar imovel
void Sistema::create(Imovel *imovel){
  this->imovel.push_back(imovel);
}

void Sistema::createLista(std::vector<Imovel*> imovel){
  std::vector<Imovel*>::iterator it;
  for(it = imovel.begin(); it != imovel.end(); it++){
    this->imovel.push_back((*it));
  }
}

// Método para deletar imovel
void Sistema::deleteImovel(int index){
  this->imovel.erase(this->imovel.begin() + index);
  std::cout << "Imovel deletado com sucesso" << std::endl;
}

// Método para editar imovel
void Sistema::updateImovel(Imovel *imovel, int index){
  //delete this->imovel[index];
  this->imovel.erase(this->imovel.begin() + index);
  this->imovel.insert(this->imovel.begin() + index, imovel);
  std::cout << "Apartamento editado com sucesso." << std::endl;
}

// Método para listar todos os imoveis
std::vector<Imovel*> Sistema::getImovel(){
  return this->imovel;
}

// Método para listar imovel por tipo
std::vector<Imovel*> Sistema::getImoveis(int tipo){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;

  if(tipo == 1){ // Apartamentos
    for(it = this->imovel.begin(); it != this->imovel.end(); it++){
      if((*it)->getTipo() == 1){
        imovelRetorno.push_back(*it);
      }
    }
  }

  if(tipo == 2){ // Casas
    for(it = this->imovel.begin(); it != this->imovel.end(); it++){
      if((*it)->getTipo() == 2){
        imovelRetorno.push_back(*it);
      }
    }
  }
  if(tipo == 3){ // Terreno
    for(it = this->imovel.begin(); it != this->imovel.end(); it++){
      if((*it)->getTipo() == 3){
        imovelRetorno.push_back(*it);
      }
    }
  }
  return imovelRetorno;
}

// Método para listar imovel por aluguel ou venda
std::vector<Imovel*> Sistema::getImoveisSituacao(int situacao){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;
  
  if(situacao == 1){ // Imoveis para aluguel
    for(it = this->imovel.begin(); it != this->imovel.end(); it++){
      if((*it)->getSituacao() == 1){
        imovelRetorno.push_back(*it);
      }
    }
  }

  if(situacao == 2){ // Imoveis para venda
    for(it = this->imovel.begin(); it != this->imovel.end(); it++){
      if((*it)->getSituacao() == 2){
        imovelRetorno.push_back(*it);
      }
    }
  }
  return imovelRetorno;
}

// Método para buscar imovel por bairro retonando uma lista de indexs
std::vector<int> Sistema::getImoveisBairro(std::string pesquisaBairro){
  std::vector<int> imovelRetorno;
  std::vector<int>::iterator it;

  std::string verifica;
  pesquisaBairro = this->converte.toLowerCase(pesquisaBairro);

  for(int i = 0; i < this->imovel.size(); i++){
    verifica = this->imovel[i]->getEndereco().getBairro();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaBairro) < pesquisaBairro.length()){
      imovelRetorno.push_back((i));
    }
  }

  return imovelRetorno; // Retorna uma lista com os index encontrados
}
// Método para buscar imovel por bairro retornando uma lista de imoveis
std::vector<Imovel*> Sistema::getImoveisBairroLista(std::string pesquisaBairro){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;

  std::string verifica;
  pesquisaBairro = this->converte.toLowerCase(pesquisaBairro);

  for(it = this->imovel.begin(); it != this->imovel.end(); it++){
    verifica = (*it)->getEndereco().getBairro();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaBairro) < pesquisaBairro.length()){
      imovelRetorno.push_back(*it);
    }
  }
  return imovelRetorno; // Retorna uma lista com todos os imoveis encontrados
}

std::vector<Imovel*> Sistema::getImoveisCidadeLista(std::string pesquisaCidade){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;

  std::string verifica;
  pesquisaCidade = this->converte.toLowerCase(pesquisaCidade);

  for(it = this->imovel.begin(); it != this->imovel.end(); it++){
    verifica = (*it)->getEndereco().getCidade();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaCidade) < pesquisaCidade.length()){
      imovelRetorno.push_back(*it);
    }
  }
  return imovelRetorno; // Retorna uma lista com todos os imoveis encontrados
}
std::vector<int> Sistema::getImoveisCidade(std::string pesquisaCidade){
  std::vector<int> imovelRetorno;
  std::vector<int>::iterator it;

  std::string verifica;
  pesquisaCidade = this->converte.toLowerCase(pesquisaCidade);

  for(int i = 0; i < this->imovel.size(); i++){
    verifica = this->imovel[i]->getEndereco().getCidade();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaCidade) < pesquisaCidade.length()){
      imovelRetorno.push_back((i));
    }
  }
  
  return imovelRetorno; // Retorna uma lista com os index encontrados
}

std::vector<Imovel*> Sistema::getImoveisDescricaoLista(std::string pesquisaDescricao){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;

  std::string verifica;
  pesquisaDescricao = this->converte.toLowerCase(pesquisaDescricao);

  for(it = this->imovel.begin(); it != this->imovel.end(); it++){
    verifica = (*it)->getDescricao();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaDescricao) < pesquisaDescricao.length()){
      imovelRetorno.push_back(*it);
    }
  }
  return imovelRetorno;
}
std::vector<int> Sistema::getImoveisDescricao(std::string pesquisaDescricao){
  std::vector<int> imovelRetorno;
  std::vector<int>::iterator it;

  std::string verifica;
  pesquisaDescricao = this->converte.toLowerCase(pesquisaDescricao);

  for(int i = 0; i < this->imovel.size(); i++){
    verifica = this->imovel[i]->getDescricao();
    verifica = this->converte.toLowerCase(verifica);

    if(verifica.find(pesquisaDescricao) < pesquisaDescricao.length()){
      imovelRetorno.push_back((i));
    }
  }
  
  return imovelRetorno;
}

std::vector<Imovel*> Sistema::getImovelValor(double valor){
  std::vector<Imovel*> imovelRetorno;
  std::vector<Imovel*>::iterator it;

  for(it = this->imovel.begin(); it != this->imovel.end(); it++){
    if((*it)->getValor() <= valor){
      imovelRetorno.push_back(*it);
    }
  }
  return imovelRetorno;
}