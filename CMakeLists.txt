cmake_minimum_required(VERSION 3.22)
project(ft C)

include_directories(./inc)
add_compile_options(-Wall -Werror -Wextra -g -mavx -msse2 -msse4.2 -march=native -fno-builtin)

add_library(ft STATIC
        inc/t_hashTable.h
        inc/t_set.h
        inc/t_sList.h
        inc/character.h
        inc/strings.h
        inc/memory.h
        inc/io.h
        inc/t_rb.h
        inc/t_bTree.h
        src/strings/ft_atoi.c
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
        src/strings/ft_strdup.c
        src/memory/ft_memmove.c
        src/memory/ft_memset.c
        src/strings/ft_strchr.c
        src/strings/ft_strlcat.c
        src/strings/ft_strlcpy.c
        src/strings/ft_strlen.c
        src/strings/ft_strncmp.c
        src/strings/ft_strnstr.c
        src/strings/ft_strrchr.c
        src/character/ft_tolower.c
        src/character/ft_toupper.c
        src/strings/ft_substr.c
        src/strings/ft_strjoin.c
        src/strings/ft_strtrim.c
        src/strings/ft_split.c
        src/strings/ft_itoa.c
        src/strings/ft_strmapi.c
        src/strings/ft_striteri.c
        src/io/ft_putchar_fd.c
        src/io/ft_putstr_fd.c
        src/io/ft_putendl_fd.c
        src/io/ft_putnbr_fd.c
        src/t_sList/ft_lstadd_back.c
        src/t_sList/ft_lstadd_front.c
        src/t_sList/ft_lstclear.c
        src/t_sList/ft_lstdelone.c
        src/t_sList/ft_lstiter.c
        src/t_sList/ft_lstlast.c
        src/t_sList/ft_lstmap.c
        src/t_sList/ft_lstnew.c
        src/t_sList/ft_lstsize.c
        src/strings/clean_split.c
        src/t_sList/ft_lstfilter.c
        src/t_sList/ft_lstsort.c
        src/io/ft_read_file.c
        src/t_set/t_set.c
        src/t_hashTable/t_hashTable.c
        src/ft_hexdump.c
        src/t_hashTable/farmhash.c
        src/t_rb/t_rb.c
        src/t_bTree/t_bTree.c)

add_executable(tester ./test.c)
target_link_libraries(tester ft)
