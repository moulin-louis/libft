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

void ft_putchar_fd(char c, int32_t fd);

void ft_putstr_fd(const char* s, int32_t fd);

void ft_putendl_fd(char* s, int32_t fd);

void ft_putnbr_fd(int32_t n, int32_t fd);

t_set* read_file(const char* path);

#endif // IO_H
