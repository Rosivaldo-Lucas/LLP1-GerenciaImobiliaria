#ifndef _GERENTE_DE_PERSISTENCIA_
#define _GERENTE_DE_PERSISTENCIA_

#include <vector>

#include "./imovel.h"

class GerenteDePersistencia{
  public:
    std::vector<Imovel*>recuperarImovel();
    void salvarImovel(std::vector<Imovel*> imovel);

    // Sobrecarga do operador << para escrita em arquivo
    friend std::ostream &operator<<(std::ostream &out, const Imovel *imovel);
    // Sobrecarga do operador >> para leitura em arquivo
    friend std::ifstream &operator>>(std::ifstream &in, const Imovel *imovel);
};

#endif //_GERENTE_DE_PERSISTENCIA_