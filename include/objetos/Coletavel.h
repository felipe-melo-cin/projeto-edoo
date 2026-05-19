#ifndef _COLETAVEL_H_
#define _COLETAVEL_H_

#include <string>

class Coletavel {
private:
    std::string nome;
public:
    int aparecer();
    const std::string& get_nome() { return nome; }
    void set_nome(const std::string& nome) { this->nome = nome; }
};

#endif