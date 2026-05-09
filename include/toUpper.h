#ifndef _TOUPPER_H_
#define _TOUPPER_H_

#include <cctype>
#include <string>

// TRANSFORMA TODOS OS CARACTERES DE UMA STRING EM MAIÚSCULO
inline void toUpper(std::string& s) { for (char& c : s) c = std::toupper(c); }

#endif