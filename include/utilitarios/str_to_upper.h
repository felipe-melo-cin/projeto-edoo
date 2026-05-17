#ifndef _STR_TO_UPPER_H_
#define _STR_TO_UPPER_H_

#include <cctype>
#include <string>

// TRANSFORMA TODOS OS CARACTERES DE UMA STRING EM MAIÚSCULO
inline void str_to_upper(std::string& s) { for (char& c : s) c = std::toupper(c); }

#endif