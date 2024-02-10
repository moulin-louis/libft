//
// Created by loumouli on 2/7/24.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdint.h>

// Character FN

// Check if a given int is printable
int32_t ft_isprint(int32_t c);

// Check if a given int is a digit in ASCII
int32_t ft_isdigit(int32_t c);

// Check if a given int is a ASCII character
int32_t ft_isascii(int32_t c);

// Check if a given int is alphabetic in ASCII
int32_t ft_isalpha(int32_t c);

// Check if a given int is alphabetic/numeric in ASCII
int32_t ft_isalnum(int32_t c);

// return the lowercase version of the caracter if its a uppercase alphabetic
char ft_tolower(char c);

// return the uppercase version of the caracter if its a lowercase alphabetic
char ft_toupper(char c);

#endif // CHARACTER_H
