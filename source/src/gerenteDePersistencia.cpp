#include <iostream>
#include <fstream>

#include "../include/gerenteDePersistencia.h"
#include "../include/apartamento.h"
#include "../include/casa.h"
#include "../include/terreno.h"
#include "../include/endereco.h"
#include "../include/sistema.h"

// Sobrecarga do operador << para escrita em arquivo
std::ostream &operator<<(std::ostream &out, const Imovel *imovel){
  out << imovel;
  return out;
}

// Sobrecarga do operador >> para leitura em arquivo
std::ifstream &operator>>(std::ifstream &in, const Imovel *imovel){
  in >> imovel;
  return in;
}

std::vector<Imovel*> GerenteDePersistencia::recuperarImovel(){
  std::ifstream stream;
  stream.open("./source/files/persistencia.txt", std::ios::in);
  
  Imovel *imovel;
  std::vector<Imovel*> im;

  int tipoImovel, situacao, numero, numQuartos, numPavimentos, vagasGaragem;
  double area, areaTerreno, valorCondominio, valor;
  std::string descricao, logradouro, bairro, cidade, cep, posicao;

  if(stream.good()){
    while(!stream.eof()){
      
      stream >> tipoImovel;
      stream.ignore();
      
      if(tipoImovel == 1){
        getline(stream, descricao);
        stream >> situacao;
        stream.ignore();
        getline(stream, logradouro);
        getline(stream, bairro);
        getline(stream, cidade);
        getline(stream, cep);
        stream >> numero;
        stream.ignore();
        getline(stream, posicao);
        stream >> numQuartos;
        stream.ignore();
        stream >> vagasGaragem;
        stream.ignore();
        stream >> area;
        stream.ignore();
        stream >> valorCondominio;
        stream.ignore();
        stream >> valor;
        stream.ignore();
        Endereco endereco = Endereco(logradouro, numero, bairro, cidade, cep);
        imovel = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, descricao, valor, situacao, endereco);
        im.push_back(imovel);
      }

      if(tipoImovel == 2){
        getline(stream, descricao);
        stream >> situacao;
        stream.ignore();
        getline(stream, logradouro);
        getline(stream, bairro);
        getline(stream, cidade);
        getline(stream, cep);
        stream >> numero;
        stream.ignore();
        stream >> numPavimentos;
        stream.ignore();
        stream >> numQuartos;
        stream.ignore();
        stream >> areaTerreno;
        stream.ignore();
        stream >> area;
        stream.ignore();
        stream >> valor;
        stream.ignore();
        Endereco endereco = Endereco(logradouro, numero, bairro, cidade, cep);
        imovel = new Casa(numPavimentos, numQuartos, areaTerreno, area, descricao, valor, situacao, endereco);
        im.push_back(imovel);
      }
      
      if(tipoImovel == 3){
        getline(stream, descricao);
        stream >> situacao;
        stream.ignore();
        getline(stream, logradouro);
        getline(stream, bairro);
        getline(stream, cidade);
        getline(stream, cep);
        stream >> numero;
        stream.ignore();
        stream >> area;
        stream.ignore();
        stream >> valor;
        stream.ignore();
        Endereco endereco = Endereco(logradouro, numero, bairro, cidade, cep);
        imovel = new Terreno(area, descricao, valor, situacao, endereco);
        im.push_back(imovel);
      }
    }
  }
  stream.close();
  return im;
}

void GerenteDePersistencia::salvarImovel(std::vector<Imovel*> imovel){
  std::vector<Imovel*>::iterator it;
  std::ofstream stream;
  stream.open("./source/files/persistencia.txt", std::ios::out);

  int cont = 0;

  if(!stream.is_open()){
    std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
    stream.close();
    return;
  }

  for(it = imovel.begin(); it != imovel.end(); it++){
    if(cont > 0){
      stream << "\n";
    }
    stream << (*it)->getTipo() << std::endl;
    stream << (*it)->getDescricao() << std::endl;
    stream << (*it)->getSituacao() << std::endl;
    stream << (*it)->getEndereco().getLogradouro() << std::endl;
    stream << (*it)->getEndereco().getBairro() << std::endl;
    stream << (*it)->getEndereco().getCidade() << std::endl;
    stream << (*it)->getEndereco().getCep() << std::endl;
    stream << (*it)->getEndereco().getNumero() << std::endl;

    if((*it)->getTipo() == 1){
      stream << ((Apartamento*)*it)->getPosicao() << std::endl;
      stream << ((Apartamento*)*it)->getNumQuartos() << std::endl;
      stream << ((Apartamento*)*it)->getVagasGaragem() << std::endl;
      stream << ((Apartamento*)*it)->getArea() << std::endl;
      stream << ((Apartamento*)*it)->getValorCondominio() << std::endl;
      stream << ((Apartamento*)*it)->getValor();
    }

    if((*it)->getTipo() == 2){
      stream << ((Casa*)*it)->getNumPavimentos() << std::endl;
      stream << ((Casa*)*it)->getNumQuartos() << std::endl;
      stream << ((Casa*)*it)->getAreaTerreno() << std::endl;
      stream << ((Casa*)*it)->getAreaConstruida() << std::endl;
      stream << ((Casa*)*it)->getValor();
    }

    if((*it)->getTipo() == 3){
      stream << ((Terreno*)*it)->getArea() << std::endl;
      stream << ((Terreno*)*it)->getValor();
    }
    cont++;
  }
  stream.close();
}