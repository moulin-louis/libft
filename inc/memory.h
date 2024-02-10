//
// Created by loumouli on 2/7/24.
//

#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Memory Manipulation FN

//Set a given array to a given number, up to `n` bytes
void* ft_memset(void* s, int32_t c, uint64_t n);

// Copy `n` bytes from dest to src, memory can overlap
void* ft_memmove(void* dest, const void* src, uint64_t n);

// Copy `n` bytes from `dest` to `src`, memory must not overlap
void* ft_memcpy(void* dest, const void* src, uint64_t n);

// void* memcpy_avx(void* dest, const void* src, uint64_t n);

// void* memcpy_x86(void* dest, const void* src, uint64_t n);

//Compare `n` bytes from both array
int32_t ft_memcmp(const void* s1, const void* s2, uint64_t n);

// Search up to `n` bytes for a given bytes
void* ft_memchr(const void* s, int32_t c, uint64_t n);

// Allocatgd on the heap `nmemb` * `size` bytes, zero out the allocated buffer
void* ft_calloc(uint64_t nmemb, uint64_t size);

// Zero out up to `n` bytes the array
void ft_bzero(void* s, uint64_t n);

#endif // MEMORY_H
