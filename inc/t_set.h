//
// Created by loumouli on 2/7/24.
//

#ifndef T_SET_H
#define T_SET_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// Set(vector) structure
typedef struct {
  void* data; // Content array, grow dynamicaly when needed
  const uint64_t nbytes_data; // Number in bytes of the data
  uint64_t len; // Actual used len of the content array
  uint64_t capacity; // Capacity in nbytes of the content array
} t_set;

// VECTOR FN

// Init a t_set on the heap
t_set* ft_set_new(uint64_t nbytes);

// Clone a t_set and all the elements
t_set* ft_set_clone(const t_set* set);

// Clear the vector (keep the allocated array)
void ft_set_clear(t_set* set, uint64_t (*destroy_fn)(void *data));

// Destroy the t_set
void ft_set_destroy(t_set* set, uint64_t (*destroy_fn)(void *data));

// Reserver a given capacity for the content array
uint64_t ft_set_reserve(t_set* set, uint64_t capacity);

// Check if the t_set has the given data in it
// Data must be the same size as nbytes_data
bool ft_set_has(const t_set* set, const void* data);

// Will return a pointer in the array to the given index
void* ft_set_get(const t_set* set, uint64_t idx);

// Insert data at a given index in the array
// Data must be the same size as nbytes_data
uint64_t ft_set_insert(t_set* set, const void* data, uint64_t idx);

// Push the all data in the t_set (data can vary in len)
// Data must be the same size as nbytes_data
uint64_t ft_set_push(t_set* set, const void* data, uint64_t len);

// Apply a given function to all element in the arary
uint64_t ft_set_iter(const t_set* set, uint64_t (*iter_fn)(void* data));

#endif // T_SET_H
