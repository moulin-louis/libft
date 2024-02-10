//
// Created by loumouli on 2/7/24.
//

#ifndef IO_H
#define IO_H

#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>
#include "t_set.h"

// I/O FN

// Print a character on the given FD
void ft_putchar_fd(char c, int32_t fd);

// Print a null terminated string on the given FD
void ft_putstr_fd(const char* s, int32_t fd);

// Print a null terminated string with a '\n' on the given FD
void ft_putendl_fd(char* s, int32_t fd);

// Print a number on the given FD
void ft_putnbr_fd(int32_t n, int32_t fd);

// Read a whole file from a fiven path using t_set
t_set* read_file(const char* path);

#endif // IO_H
