#ifndef _ENDERECO_
#define _ENDERECO_

#include <string>

class Endereco{
  public:
    Endereco();
    Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);
    virtual ~Endereco();

    std::string getLogradouro();
    void setLogradouro(std::string logradouro);
    int getNumero();
    void setNumero(int numero);
    std::string getBairro();
    void setBairro(std::string bairro);
    std::string getCidade();
    void setCidade(std::string cidade);
    std::string getCep();
    void setCep(std::string cep);

  private:
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cidade;
    std::string cep;
};

#endif //_ENDERECO_