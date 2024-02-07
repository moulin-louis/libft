//
// Created by loumouli on 2/7/24.
//

#ifndef STRING_H
#define STRING_H

#include <stdint.h>

//String FN
char* ft_substr(char const* s, int32_t start, uint64_t len);

char* ft_strrchr(const char* s, int32_t c);

char* ft_strnstr(const char* big, const char* little, uint64_t len);

int32_t ft_strncmp(const char* s1, const char* s2, uint64_t n);

int32_t ft_strncmp_map(const char* s1, const char* s2, uint64_t n, char (*map)(char));

int32_t ft_strcmp(const char* s1, const char* s2);

uint64_t ft_strlen(const char* s);

uint64_t ft_strlcpy(char* dest, const char* src, uint64_t size);

uint64_t ft_strlcat(char* dst, const char* src, uint64_t size);

char* ft_strdup(const char* s);

char* ft_strchr(const char* s, int32_t c);

char* ft_strjoin(char const* s1, char const* s2);

char** ft_split(char const* s, char c);

void clean_array(char** arr);

char* ft_strtrim(char const* s1, char const* set);

int32_t ft_atoi(const char* nptr);

char* ft_itoa(int32_t n);

char* ft_strmapi(char const* s, char (*f)(unsigned int32_t, char));

void ft_striteri(char* s, void (*f)(unsigned int32_t, char*));

#endif //STRING_H
