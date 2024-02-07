cmake_minimum_required(VERSION 3.22)
project(ft C)

include_directories(./inc)
add_compile_options(-Wall -Werror -Wextra -g -mavx -msse2 -msse4.2 -march=native -fno-builtin)

add_library(ft STATIC src/string/ft_atoi.c
        src/memory/ft_calloc.c
        src/character/ft_isascii.c
        src/memory/ft_bzero.c
        src/character/ft_isalnum.c
        src/character/ft_isalpha.c
        src/character/ft_isdigit.c
        src/character/ft_isprint.c
        src/memory/ft_memchr.c
        src/memory/ft_memcmp.c
        src/memory/ft_memcpy.c
        src/memory/ft_memcpy_avx.c
        src/memory/ft_memcpy_x86.c
        src/string/ft_strdup.c
        src/memory/ft_memmove.c
        src/memory/ft_memset.c
        src/string/ft_strchr.c
        src/string/ft_strlcat.c
        src/string/ft_strlcpy.c
        src/string/ft_strlen.c
        src/string/ft_strncmp.c
        src/string/ft_strnstr.c
        src/string/ft_strrchr.c
        src/character/ft_tolower.c
        src/character/ft_toupper.c
        src/string/ft_substr.c
        src/string/ft_strjoin.c
        src/string/ft_strtrim.c
        src/string/ft_split.c
        src/string/ft_itoa.c
        src/string/ft_strmapi.c
        src/string/ft_striteri.c
        src/io/ft_putchar_fd.c
        src/io/ft_putstr_fd.c
        src/io/ft_putendl_fd.c
        src/io/ft_putnbr_fd.c
        src/s_list/ft_lstadd_back.c
        src/s_list/ft_lstadd_front.c
        src/s_list/ft_lstclear.c
        src/s_list/ft_lstdelone.c
        src/s_list/ft_lstiter.c
        src/s_list/ft_lstlast.c
        src/s_list/ft_lstmap.c
        src/s_list/ft_lstnew.c
        src/s_list/ft_lstsize.c
        src/string/clean_split.c
        src/s_list/ft_lstfilter.c
        src/s_list/ft_lstsort.c
        src/io/ft_read_file.c
        src/t_set/t_set.c
        src/t_hashTable/t_hashTable.c
        ./src/ft_hexdump.c
        src/t_hashTable/farmhash.c
        inc/t_hashTable.h
        inc/t_set.h
        inc/s_list.h
        inc/character.h
        inc/string.h
        inc/memory.h
        inc/io.h
        inc/t_rb.h
        src/t_rb/t_rb.c)

add_compile_options(-g)
add_executable(tester ./test.c)
target_link_libraries(tester ft)
