//
// Created by loumouli on 2/7/24.
//

#ifndef STRING_H
#define STRING_H

#include <stdint.h>

// String FN

// All string must be null-terminated

// Return a pointer to the substring in `s` starting at `start` index and with a lenght of `len`
char* ft_substr(char const* s, int32_t start, uint64_t len);

// Return a pointer in the string if the given string is found
char* ft_strnstr(const char* big, const char* little, uint64_t len);

// Call memcmp on two string, up to `n` bytes
int32_t ft_strncmp(const char* s1, const char* s2, uint64_t n);

// Compare two string with a given compare function, up to `n` bytes
int32_t ft_strncmp_map(const char* s1, const char* s2, uint64_t n, char (*map)(char));

// Compare two whole string
int32_t ft_strcmp(const char* s1, const char* s2);

// Return the lenght of the given strig,
uint64_t ft_strlen(const char* s);

// Cope `size` bytes from dest to src
uint64_t ft_strlcpy(char* dest, const char* src, uint64_t size);

uint64_t ft_strlcat(char* dst, const char* src, uint64_t size);

// Clone the given string on the heap
char* ft_strdup(const char* s);

// Return a pointer in the string if the given character is found
char* ft_strchr(const char* s, int32_t c);

// Return a pointer in the string if the given character is found, search in reverse
char* ft_strrchr(const char* s, int32_t c);

// Create a new string on the heap that combine both string
char* ft_strjoin(char const* s1, char const* s2);

// Split a given string based on a character
char** ft_split(char const* s, char c);

// Clean a double array of string
void clean_array(char** arr);

// Trim the given set , the start and the end of a string
char* ft_strtrim(char const* s1, char const* set);

// Convert a string into a number
int32_t ft_atoi(const char* nptr);

// Convert a number into a string on the heap
char* ft_itoa(int32_t n);

// Clone the string and apply `f` to every character
char* ft_strmapi(char const* s, char (*f)(unsigned int32_t, char));

// Apply `f` to every character
void ft_striteri(char* s, void (*f)(unsigned int32_t, char*));

#endif // STRING_H
