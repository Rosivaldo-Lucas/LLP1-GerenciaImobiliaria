#include "../include/converteTexto.h"

std::string ConverteTexto::toLowerCase(std::string str){
  for(int i = 0; i < str.length(); i++){
    str[i] = tolower(str[i]);
  }
  return str;
}