#ifndef _SISTEMA_
#define _SISTEMA_

#include <vector>

#include "./imovel.h"
#include "./converteTexto.h"
#include "./gerenteDePersistencia.h"

class Sistema{
  public:
    // Métodos para CREATE, DELETE, UPDATE
    void create(Imovel *imovel);
    void createLista(std::vector<Imovel*> imovel);
    void deleteImovel(int index);
    void updateImovel(Imovel *imovel, int index);

    // Métodos para READ
    std::vector<Imovel*> getImovel();
    std::vector<Imovel*> getImoveis(int tipo);
    std::vector<Imovel*> getImoveisSituacao(int situacao);

    // Busca por bairro
    std::vector<Imovel*> getImoveisBairroLista(std::string pesquisaBairro); // return imovel
    std::vector<int> getImoveisBairro(std::string pesquisaBairro); // return index
    
    // Busca por cidade
    std::vector<Imovel*> getImoveisCidadeLista(std::string pesquisaCidade); // return imovel
    std::vector<int> getImoveisCidade(std::string pesquisaCidade); // return index

    // Buscar por descricao
    std::vector<Imovel*> getImoveisDescricaoLista(std::string pesquisaDescricao); // return imovel
    std::vector<int> getImoveisDescricao(std::string pesquisaDescricao); // return index

    // Buscar por valor
    std::vector<Imovel*> getImovelValor(double valor);

  private:
    std::vector<Imovel*> imovel;
    ConverteTexto converte;
    GerenteDePersistencia persistencia;
};

#endif //_SISTEMA_