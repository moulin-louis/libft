//
// Created by loumouli on 2/7/24.
//

#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Memory Manipulation FN

void* ft_memset(void* s, int32_t c, uint64_t n);

void* ft_memmove(void* dest, const void* src, uint64_t n);

void* ft_memcpy(void* dest, const void* src, uint64_t n);

void* memcpy_avx(void* dest, const void* src, uint64_t n);

void* memcpy_x86(void* dest, const void* src, uint64_t n);

int32_t ft_memcmp(const void* s1, const void* s2, uint64_t n);

void* ft_memchr(const void* s, int32_t c, uint64_t n);

void* ft_calloc(uint64_t nmemb, uint64_t size);

void ft_bzero(void* s, uint64_t n);

#endif // MEMORY_H
