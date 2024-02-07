//
// Created by loumouli on 2/7/24.
//

#ifndef T_SET_H
#define T_SET_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// Set(vector) structure
typedef struct {
  void* data; //Content array, grow dynamicaly when needed
  const uint64_t nbytes_data; //Number in bytes of the data
  uint64_t len; //Actual used len of the content array
  uint64_t capacity; //Capacity in nbytes of the content array
} t_set;

//VECTOR FN

t_set* ft_set_new(uint64_t nbytes);

t_set* ft_set_clone(const t_set* set);

void ft_set_clear(t_set* set);

void ft_set_clean(t_set* set);

uint64_t ft_set_reserve(t_set* set, uint64_t capacity);

bool ft_set_has(const t_set* set, const void* data);

void* ft_set_get(const t_set* set, uint64_t idx);

uint64_t ft_set_set(const t_set* set, uint64_t idx, const void* data, uint64_t nbytes_data);

uint64_t ft_set_insert(t_set* set, const void* data, uint64_t idx);

uint64_t ft_set_append(t_set* set, const void* data, size_t len);

#endif //T_SET_H
