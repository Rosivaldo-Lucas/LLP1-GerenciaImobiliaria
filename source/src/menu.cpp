#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

#include "../include/sistema.h"
#include "../include/imovel.h"
#include "../include/endereco.h"
#include "../include/apartamento.h"
#include "../include/casa.h"
#include "../include/terreno.h"
#include "../include/menu.h"

// Métodos auxiliares
void cabecalho();
void startFile();
void inputEndereco();
void inputApartamento();
void inputCasa();
void inputTerreno();
void output(int op, int situacao, int auxSituacao, int auxTipo);
void outputBusca(std::string pesquisa, int op, int aux);
void outputImovel();
void outputEditar(std::string, int op);
void outputBuscaValor(double valor);

// Constantes
#define TEMPO 1.5
const char *clear = "clear";

// Variáveis
int op, id;
double valorBusca;
std::string pesquisa;
std::string logradouro, bairro, cidade, cep, posicao, descricao;
int numero, numQuartos, vagasGaragem, situacao, numPavimentos;
double valor, valorCondominio, area, areaTerreno;

// Variáveis para manipular a lista de imoveis
std::vector<Imovel*> im;
std::vector<Imovel*>::iterator it;
std::vector<int> indexs;
std::vector<int>::iterator itIndex;

// Instâncias de objetos
Endereco endereco;
Sistema sistema;
GerenteDePersistencia persistencia;
Imovel *imovel; //Objeto polimorfico

void startFile(){
  im = persistencia.recuperarImovel();
  if(im.size() == 0){
    std::cout << "Não foi encontrado nenhum imovel na base de dados." << std::endl;
  }else{
    std::cout << "Base de dados inicializada." << std::endl;
    sistema.createLista(im);
  }
  sleep(TEMPO);
  system(clear);
}

// Método responsavel pela gerencia dos menus
void menuPrincipal(){
  startFile(); // Inicializa a base de dados
  while(true){
    cabecalho();
    std::cout << "\t1- Cadastrar imoveis." << std::endl;
    std::cout << "\t2- Listar imoveis." << std::endl;
    std::cout << "\t3- Buscar imoveis." << std::endl;
    std::cout << "\t4- Editar imoveis." << std::endl;
    std::cout << "\t5- Remover imoveis." << std::endl;
    std::cout << "\t6- Sair." << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> op;
    std::cin.ignore();
    if(op == 6){
      system(clear);
      std::cout << "Deseja salvar todas as alteracoes feitas no sistema?" << std::endl;
      std::cout << "1- SIM." << std::endl;
      std::cout << "2- NAO." << std::endl;
      std::cout << "----------------------------------------------------" << std::endl;
      std::cout << "OPCAO: ";
      std::cin >> op;
      if(op == 1){
        persistencia.salvarImovel(im);
        std::cout << "" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "Alteracoes salvas com sucesso." << std::endl;
        sleep(TEMPO);
        system(clear);
        break;
      }
      system(clear);
      break;
    }
    switch(op){
      case 1: // Cadastro de imoveis
        system(clear);
        menuCadastro();
        break;
      case 2: // Listar imoveis
        system(clear);
        menuListar();
        break;
      case 3: // Buscar imoveis
        system(clear);
        menuBuscar();
        break;
      case 4: // Editar imoveis
        system(clear);
        while(true){
          std::cout << "----------BUSQUE PELO IMOVEL QUE DESEJA EDITAR----------" << std::endl;
          std::cout << "\t1- Apartamento." << std::endl;
          std::cout << "\t2- Casa." << std::endl;
          std::cout << "\t3- Terreno." << std::endl;
          std::cout << "\t4- Voltar." << std::endl;
          std::cout << "---------------------------------------------------------" << std::endl;
          std::cout << "Ecolha uma opcao de busca: ";
          std::cin >> op;
          std::cin.ignore();
          if(op == 4){
            system(clear);
            break;
          }
          switch(op){
            case 1: // Editar apartamento
              system(clear);
              std::cout << "Informe a descricao do apartamento que deseja editar: ";
              getline(std::cin, pesquisa);
              outputEditar(pesquisa, op);
              std::cout << "Pressione enter para voltar.";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 2: // Editar casa
              system(clear);
              std::cout << "Informe a descricao da casa que deseja editar: ";
              getline(std::cin, pesquisa);
              outputEditar(pesquisa, op);
              std::cout << "Pressione enter para voltar.";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 3: // Editar terreno
              system(clear);
              std::cout << "Informe a descricao do terreno que deseja editar: ";
              getline(std::cin, pesquisa);
              outputEditar(pesquisa, op);
              std::cout << "Pressione enter para voltar.";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            default:
              std::cout << "Escolha uma opcao valida." << std::endl;
              sleep(TEMPO);
              system(clear);
              break;
          }
        }
        break;
      case 5: // Deletar imoveis
        system(clear);
        while(true){
          std::cout << "----------BUSQUE PELO IMOVEL QUE DESEJA REMOVER----------" << std::endl;
          std::cout << "\t1- Buscar por bairro." << std::endl;
          std::cout << "\t2- Buscar por cidade." << std::endl;
          std::cout << "\t3- Buscar por descricao." << std::endl;
          std::cout << "\t4- Voltar." << std::endl;
          std::cout << "---------------------------------------------------------" << std::endl;
          std::cout << "Ecolha uma opcao de busca: ";
          std::cin >> op;
          std::cin.ignore();
          if(op == 4){
            system(clear);
            break;
          }
          switch(op){
            case 1: // Buscar por bairro para deletar
              system(clear);
              std::cout << "----------BUSCANDO IMOVEIS PELO BAIRRO----------" << std::endl;
              std::cout << "" << std::endl;
              std::cout << "Informe o bairro que deseja buscar: ";
              getline(std::cin, pesquisa);
              std::cout << "" << std::endl;
              outputBusca(pesquisa, op, 2);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 2: // Buscar por cidade para deletar
              system(clear);
              std::cout << "----------BUSCANDO IMOVEIS PELA CIDADE----------" << std::endl;
              std::cout << "" << std::endl;
              std::cout << "Informe a cidade que deseja buscar: ";
              getline(std::cin, pesquisa);
              std::cout << "" << std::endl;
              outputBusca(pesquisa, op, 2);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 3: // Buscar por descricao para deletar
              system(clear);
              std::cout << "----------BUSCANDO IMOVEIS PELA DESCRICAO----------" << std::endl;
              std::cout << "" << std::endl;
              std::cout << "Informe a descricao que deseja buscar: ";
              getline(std::cin, pesquisa);
              std::cout << "" << std::endl;
              outputBusca(pesquisa, op, 2);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            default:
              std::cout << "Escolha uma opcao valida." << std::endl;
              sleep(TEMPO);
              system(clear);
              break;
          }
        }
        break;
      default:
        std::cout << "Escolha uma opcao valida." << std::endl;
        sleep(TEMPO);
        system(clear);
        break;
    }
  }
}

// Método responsavel pelo cadastro dos imoveis
void menuCadastro(){
  while(true){
    system(clear);
    cabecalho();
    std::cout << "\t1- Apartamento." << std::endl;
    std::cout << "\t2- Casa." << std::endl;
    std::cout << "\t3- Terreno." << std::endl;
    std::cout << "\t4- Voltar." << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Escolha uma opcao de cadastro: ";
    std::cin >> op;
    std::cin.ignore();
    if(op == 4){
      system(clear);
      break;
    }
    switch(op){
      case 1:
        system(clear);
        std::cout << "----------CADASTRO DO APARTAMENTO----------" << std::endl;
        inputEndereco();
        inputApartamento();
        endereco.setLogradouro(logradouro);
        endereco.setBairro(bairro);
        endereco.setCidade(cidade);
        endereco.setCep(cep);
        endereco.setNumero(numero);
        imovel = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, descricao, valor, situacao, endereco);
        sistema.create(imovel);
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Apartamento cadastrado com sucesso." << std::endl;
        sleep(TEMPO);
        break;
      case 2:
        system(clear);
        std::cout << "----------CADASTRO DA CASA----------" << std::endl;
        inputEndereco();
        inputCasa();
        endereco.setLogradouro(logradouro);
        endereco.setBairro(bairro);
        endereco.setCidade(cidade);
        endereco.setCep(cep);
        endereco.setNumero(numero);
        imovel = new Casa(numPavimentos, numQuartos, areaTerreno, area, descricao, valor, situacao, endereco);
        sistema.create(imovel);
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Casa cadastrada com sucesso." << std::endl;
        sleep(TEMPO);
        break;
      case 3:
        system(clear);
        std::cout << "----------CADASTRO DO TERRENO----------" << std::endl;
        inputEndereco();
        inputTerreno();
        endereco.setLogradouro(logradouro);
        endereco.setBairro(bairro);
        endereco.setCidade(cidade);
        endereco.setCep(cep);
        endereco.setNumero(numero);
        imovel = new Terreno(area, descricao, valor, situacao, endereco);
        sistema.create(imovel);
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Terreno cadastrado com sucesso." << std::endl;
        sleep(TEMPO);
        break;
      default:
        std::cout << "Escolha uma opcao valida." << std::endl;
        sleep(TEMPO);
        system(clear);
        break;
    }
  }
}

// Método responsavel pela listagem dos imoveis cadastrados
void menuListar(){
  while(true){
    cabecalho();
    std::cout << "\t1- Listar todos os imoveis." << std::endl;
    std::cout << "\t2- Listar por tipo de imovel." << std::endl;
    std::cout << "\t3- Listar por aluguel ou venda." << std::endl;
    std::cout << "\t4- Voltar." << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Escolha uma opcao: ";
    std::cin >> op;
    std::cin.ignore();
    if(op == 4){
      system(clear);
      break;
    }
    switch(op){
      case 1: // Lista todos os imoveis
        system(clear);
        outputImovel();
        std::cout << "" << std::endl;
        std::cout << "Pressione enter para voltar...";
        if(getchar()){
          system(clear);
          break;
        }
        break;
      case 2: // Lista imovel por tipo
        system(clear);
        while(true){
          //cabecalho();
          std::cout << "----------LISTAR IMOVEIS PELO TIPO----------" << std::endl;
          std::cout << "\t1- Apartamento." << std::endl;
          std::cout << "\t2- Casa." << std::endl;
          std::cout << "\t3- Terreno." << std::endl;
          std::cout << "\t4- Voltar." << std::endl;
          std::cout <<  "-------------------------------------------" << std::endl;
          std::cout << "Escolha um imovel para listar: ";
          std::cin >> op;
          std::cin.ignore();
          if(op == 4){
            system(clear);
            break;
          }
          switch(op){
            case 1: // Apartamento
              system(clear);
              std::cout << "----------LISTANDO TODOS OS APARTAMENTOS----------" << std::endl;
              output(op, 0, 0, 1);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 2: // Casa
              system(clear);
              std::cout << "----------LISTANDO TODAS AS CASAS----------" << std::endl;
              output(op, 0, 0, 2);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 3: // Terreno
              system(clear);
              std::cout << "----------LISTANDO TODOS OS TERRENOS----------" << std::endl;
              output(op, 0, 0, 3);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            default:
              std::cout << "Ecolha uma opcao valida." << std::endl;
              sleep(TEMPO);
              system(clear);
              break;
          }
        }
        break;
      case 3: // Lista imovel por alguel ou venda
        system(clear);
        while(true){
          std::cout << "----------LISTAR IMOVEIS POR DISPONIBILIDADE----------" << std::endl;
          std::cout << "\t1- Imoveis para aluguel." << std::endl;
          std::cout << "\t2- Imoveis para venda." << std::endl;
          std::cout << "\t3- Voltar" << std::endl;
          std::cout << "------------------------------------------------------" << std::endl;
          std::cout << "Escolha a disponibilidade do imovel: ";
          std::cin >> op;
          std::cin.ignore();
          if(op == 3){
            system(clear);
            break;
          }
          switch(op){
            case 1: // Imovel para aluguel
              system(clear);
              std::cout << "----------LISTANDO IMOVEIS PARA ALUGUEL----------" << std::endl;
              output(0, op, 1, 0);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            case 2: // Imovel para Vender
              system(clear);
              std::cout << "----------LISTANDO IMOVEIS PARA VENDA----------" << std::endl;
              output(0, op, 2, 0);
              std::cout << "" << std::endl;
              std::cout << "Pressione enter para voltar...";
              if(getchar()){
                system(clear);
                break;
              }
              break;
            default:
              std::cout << "Escolha uma opcao valida." << std::endl;
              sleep(TEMPO);
              system(clear);
              break;
          }
        }
        break;
      default:
        std::cout << "Escolha uma opcao valida." << std::endl;
        sleep(TEMPO);
        system(clear);
        break;
    }
  }
}

// Método responsavel pela busca dos imoveis cadastrados
void menuBuscar(){
  while(true){
    cabecalho();
    std::cout << "\t1- Buscar por bairro." << std::endl;
    std::cout << "\t2- Buscar por cidade." << std::endl;
    std::cout << "\t3- Buscar por descricao." << std::endl;
    std::cout << "\t4- Buscar por valor do imovel." << std::endl;
    std::cout << "\t5- Voltar." << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Ecolha uma opcao de busca: ";
    std::cin >> op;
    std::cin.ignore();
    if(op == 5){
      system(clear);
      break;
    }
    switch(op){
      case 1: // Buscando por bairro
        system(clear);
        std::cout << "----------BUSCANDO IMOVEIS PELO BAIRRO----------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Informe o bairro que deseja buscar: ";
        getline(std::cin, pesquisa);
        std::cout << "" << std::endl;
        outputBusca(pesquisa, op, 1);
        std::cout << "" << std::endl;
        std::cout << "Pressione enter para voltar...";
        if(getchar()){
          system(clear);
          break;
        }
        break;
      case 2: // Buscando por cidade
        system(clear);
        std::cout << "----------BUSCANDO IMOVEIS PELA CIDADE----------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Informe a cidade que deseja buscar: ";
        getline(std::cin, pesquisa);
        std::cout << "" << std::endl;
        outputBusca(pesquisa, op, 1);
        std::cout << "" << std::endl;
        std::cout << "Pressione enter para voltar...";
        if(getchar()){
          system(clear);
          break;
        }
        break;
      case 3: // Buscando por descricao
        system(clear);
        std::cout << "----------BUSCANDO IMOVEIS PELA DESCRICAO----------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Informe a descricao que deseja buscar: ";
        getline(std::cin, pesquisa);
        std::cout << "" << std::endl;
        outputBusca(pesquisa, op, 1);
        std::cout << "" << std::endl;
        std::cout << "Pressione enter para voltar...";
        if(getchar()){
          system(clear);
          break;
        }
        break;
      case 4: // Buscando por valor
        system(clear);
        std::cout << "----------BUSCANDO IMOVEIS PELO VALOR----------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Informe ate que valor deseja buscar: ";
        std::cin >> valorBusca;
        std::cin.ignore();
        std::cout << "" << std::endl;
        outputBuscaValor(valorBusca);
        std::cout << "" << std::endl;
        std::cout << "Pressione enter para voltar...";
        if(getchar()){
          system(clear);
          break;
        }
        break;
      default:
        std::cout << "Escolha uma opcao valida." << std::endl;
        sleep(TEMPO);
        system(clear);
        break;
    }
  }
}

// Métodos auxiliares
void cabecalho(){
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "\t    GESTAO IMOBILIARIA" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
}

void inputEndereco(){
  std::cout << "Descricao: ";
  getline(std::cin, descricao);

  std::cout << "Disposicao[1-Aluguel/2-Venda]: ";
  std::cin >> situacao;
  std::cin.ignore();

  std::cout << "Logradouro: ";
  getline(std::cin, logradouro);

  std::cout << "Bairro: ";
  getline(std::cin, bairro);

  std::cout << "Cidade: ";
  getline(std::cin, cidade);

  std::cout << "CEP: ";
  getline(std::cin, cep);

  std::cout << "Numero: ";
  std::cin >> numero;
  std::cin.ignore();
}

void inputApartamento(){
  std::cout << "Posicao: ";
  getline(std::cin, posicao);

  std::cout << "Numero de quartos: ";
  std::cin >> numQuartos;
  std::cin.ignore();

  std::cout << "Vagas na garagem: ";
  std::cin >> vagasGaragem;
  std::cin.ignore();

  std::cout << "Area: ";
  std::cin >> area;
  std::cin.ignore();

  std::cout << "Valor do condominio: ";
  std::cin >> valorCondominio;
  std::cin.ignore();

  std::cout << "Valor do apartamento: ";
  std::cin >> valor;
  std::cin.ignore();
}

void inputCasa(){
  std::cout << "Numero de pavimentos: ";
  std::cin >> numPavimentos;
  std::cin.ignore();

  std::cout << "Numero de quartos: ";
  std::cin >> numQuartos;
  std::cin.ignore();

  std::cout << "Area do terreno: ";
  std::cin >> areaTerreno;
  std::cin.ignore();

  std::cout << "Area construida: ";
  std::cin >> area;
  std::cin.ignore();

  std::cout << "Valor da casa: ";
  std::cin >> valor;
  std::cin.ignore();
}

void inputTerreno(){
  std::cout << "Area do terreno: ";
  std::cin >> areaTerreno;
  std::cin.ignore();

  std::cout << "Valor do terreno: ";
  std::cin >> valor;
  std::cin.ignore();
}

// Métodos para mostrar dados
void outputImovel(){
  im = sistema.getImovel();
  it = im.begin();

  // Verifica se imoveis foram retornados
  if(im.size() == 0){
    std::cout << "Nenhum imovel encontrado." << std::endl;
    return;
  }

  // Exibe todos os imoveis cadastrados
  std::cout << "----------LISTANDO TODOS OS IMOVEIS----------" << std::endl;
  std::cout << "" << std::endl;
  for(it; it != im.end(); it++){
    // Exibindo todos os apartamentos cadastrados
    if((*it)->getTipo() == 1){
      std::cout << ((Apartamento*)*it)->descricaoImovel() << std::endl;
    }

    // Exibindo todas as casas cadastradas
    if((*it)->getTipo() == 2){
      std::cout << ((Casa*)*it)->descricaoImovel() << std::endl;
    }

    // Exibindo todos os terrenos cadastrados
    if((*it)->getTipo() == 3){
      std::cout << ((Terreno*)*it)->descricaoImovel() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
  }
}

void output(int tipo, int situacao, int auxSituacao, int auxTipo){
  if(tipo != 0){
    im = sistema.getImoveis(tipo);
  }
  if(situacao != 0){
    im = sistema.getImoveisSituacao(situacao);
  }
  it = im.begin();

  // Verifica se a imoveis para exibir
  if(im.size() == 0){
    std::cout << "Nenhum imovel foi encontrado." << std::endl;
    return;
  }

  // Exibindo apartamento
  for(it = im.begin(); it != im.end(); it++){
    if((*it)->getTipo() == 1 && auxTipo == 1){
      std::cout << ((Apartamento*)*it)->exibeImovel() << std::endl;
    }
  }

  // Exibindo casa
  for(it = im.begin(); it != im.end(); it++){
    if((*it)->getTipo() == 2 && auxTipo == 2){
      std::cout << ((Casa*)*it)->exibeImovel() << std::endl;
    }
  }

  // Exibindo terreno
  for(it = im.begin(); it != im.end(); it++){
    if((*it)->getTipo() == 3 && auxTipo == 3){
      std::cout << ((Terreno*)*it)->exibeImovel() << std::endl;
    }
  }

  // Exibe imoveis disponiveis para alugeul ou venda
  for(it = im.begin(); it != im.end(); it++){
    if((*it)->getSituacao() == 1 && auxSituacao == 1){
      std::cout << (*it)->exibeImovel() << std::endl;
    }
    if((*it)->getSituacao() == 2 && auxSituacao == 2){
      std::cout << (*it)->exibeImovel() << std::endl;
    }
  }
}

void outputBusca(std::string pesquisa, int op, int aux){
  // Buscas que retornam imoveis / aux == 1
  if(aux == 1){
    if(op == 1){
      im = sistema.getImoveisBairroLista(pesquisa);
      for(it = im.begin(); it != im.end(); it++){
        std::cout << (*it)->exibeImovel() << std::endl;
      }
    }
    if(op == 2){
      im = sistema.getImoveisCidadeLista(pesquisa);
      for(it = im.begin(); it != im.end(); it++){
        std::cout << (*it)->exibeImovel() << std::endl;
      }
    }
    if(op == 3){
      im = sistema.getImoveisDescricaoLista(pesquisa);
      for(it = im.begin(); it != im.end(); it++){
        std::cout << (*it)->exibeImovel() << std::endl;
      }
    }
  }

  // Buscas que retornam index / aux == 2
  if(aux == 2){
    // Deletando imovel por bairro
    if(op == 1){
      indexs = sistema.getImoveisBairro(pesquisa);

      if(indexs.size() == 0){
        std::cout << "Nenhum imovel foi encontrado." << std::endl;
        return;
      }

      if(indexs.size() > 1){
        itIndex = indexs.begin();
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Mais de um imovel foi encontrado." << std::endl;

        for(itIndex; itIndex != indexs.end(); itIndex++){
          std::cout << "Indice: " << (*itIndex) << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;

        std::cout << "Escolha um indice para remover: ";
        std::cin >> id;
        std::cin.ignore();
      }

      for(itIndex = indexs.begin(); itIndex != indexs.end(); itIndex++){
        id = (*itIndex);
      }

      sistema.deleteImovel(id);
    }

    if(op == 2){
      indexs = sistema.getImoveisCidade(pesquisa);

      if(indexs.size() == 0){
        std::cout << "Nenhum imovel foi encontrado." << std::endl;
        return;
      }

      if(indexs.size() > 1){
        itIndex = indexs.begin();
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Mais de um imovel foi encontrado." << std::endl;

        for(itIndex; itIndex != indexs.end(); itIndex++){
          std::cout << "Indice: " << (*itIndex) << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;

        std::cout << "Escolha um indice para remover: ";
        std::cin >> id;
        std::cin.ignore();
      }

      for(itIndex = indexs.begin(); itIndex != indexs.end(); itIndex++){
        id = (*itIndex);
      }

      sistema.deleteImovel(id);
    }

    if(op == 3){
      indexs = sistema.getImoveisDescricao(pesquisa);

      if(indexs.size() == 0){
        std::cout << "Nenhum imovel foi encontrado." << std::endl;
        return;
      }

      if(indexs.size() > 1){
        itIndex = indexs.begin();
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Mais de um imovel foi encontrado." << std::endl;

        for(itIndex; itIndex != indexs.end(); itIndex++){
          std::cout << "Indice: " << (*itIndex) << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;

        std::cout << "Escolha um indice para remover: ";
        std::cin >> id;
        std::cin.ignore();
      }

      for(itIndex = indexs.begin(); itIndex != indexs.end(); itIndex++){
        id = (*itIndex);
      }

      sistema.deleteImovel(id);
    }
  }
}

void outputEditar(std::string, int op){
  indexs = sistema.getImoveisDescricao(pesquisa);

  if(indexs.size() == 0){
    std::cout << "Nenhum imovel foi encontrado." << std::endl;
    return;
  }

  if(indexs.size() > 1){
    itIndex = indexs.begin();
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Mais de um imovel foi encontrado." << std::endl;

    for(itIndex; itIndex != indexs.end(); itIndex++){
      std::cout << "Indice: " << (*itIndex) << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    std::cout << "Escolha um indice para editar: ";
    std::cin >> id;
    std::cin.ignore();
  }

  for(itIndex = indexs.begin(); itIndex != indexs.end(); itIndex++){
    id = (*itIndex);
  }

  inputEndereco();
  endereco.setLogradouro(logradouro);
  endereco.setBairro(bairro);
  endereco.setCidade(cidade);
  endereco.setCep(cep);
  endereco.setNumero(numero);

  if(op == 1){
    inputApartamento();
    imovel = new Apartamento(posicao, numQuartos, valorCondominio, vagasGaragem, area, descricao, valor, situacao, endereco);
    sistema.updateImovel(imovel, id);
  }

  if(op == 2){
    inputApartamento();
    imovel = new Casa(numPavimentos, numQuartos, areaTerreno, area, descricao, valor, situacao, endereco);
    sistema.updateImovel(imovel, id);
  }

  if(op == 3){
    inputApartamento();
    imovel = new Terreno(area, descricao, valor, situacao, endereco);
    sistema.updateImovel(imovel, id);
  }
}

void outputBuscaValor(double valor){
  im = sistema.getImovelValor(valor);
  if(im.size() == 0){
    std::cout << "Nenhum imovel encontrado." << std::endl;
    return;
  }
  for(it = im.begin(); it != im.end(); it++){
    std::cout << (*it)->exibeImovel() << std::endl;
  }
}