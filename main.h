#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct conversions - struct for print functions
 * @spec: specifier
 * @f: pointer to a printer functions
 * Description: stores pointers to functions.
 */

typedef struct conversions
{
	char *spec;
	int (*f)(va_list, char *, unsigned int);
} conversions_t;

int _printf(const char *format, ...);
int print_char(va_list __attribute__((unused)), char *, unsigned int);
int print_c(va_list argts, char *buff, unsigned int buffer_idx);
int print_s(va_list argts, char *buff, unsigned int buffer_idx);
int print_i(va_list argts, char *buff, unsigned int buffer_idx);
int print_b(va_list argts, char *buff, unsigned int buffer_idx);
int print_u(va_list argts, char *buff, unsigned int buffer_idx);
int print_o(va_list argts, char *buff, unsigned int buffer_idx);
int print_x(va_list argts, char *buff, unsigned int buffer_idx);
int print_X(va_list argts, char *buff, unsigned int buffer_idx);
int print_S(va_list argts, char *buff, unsigned int buffer_idx);
int print_add(va_list argts, char *buff, unsigned int buffer_idx);
int print_rev(va_list argts, char *buff, unsigned int buffer_idx);
int print_rot(va_list argts, char *buff, unsigned int buffer_idx);
int print_l_i(va_list argts, char *buff, unsigned int buffer_idx);
int print_l_u(va_list argts, char *buff, unsigned int buffer_idx);
int print_l_o(va_list argts, char *buff, unsigned int buffer_idx);
int print_l_x(va_list argts, char *buff, unsigned int buffer_idx);
int print_l_X(va_list argts, char *buff, unsigned int buffer_idx);
int print_h_i(va_list argts, char *buff, unsigned int buffer_idx);
int print_h_u(va_list argts, char *buff, unsigned int buffer_idx);
int print_h_o(va_list argts, char *buff, unsigned int buffer_idx);
int print_h_x(va_list argts, char *buff, unsigned int buffer_idx);
int print_h_X(va_list argts, char *buff, unsigned int buffer_idx);
int print_plus_i(va_list argts, char *buff, unsigned int buffer_idx);
int print_num_o(va_list argts, char *buff, unsigned int buffer_idx);
int print_num_x(va_list argts, char *buff, unsigned int buffer_idx);
int print_num_X(va_list argts, char *buff, unsigned int buffer_idx);
int print_space_i(va_list argts, char *buff, unsigned int buffer_idx);
int (*get_funcs(const char *s, int index))(va_list, char *, unsigned int);
int id_count_func(const char *s, int index);
unsigned int concat_buffer(char *buff, char c, unsigned int buffer_idx);
int write_buffer(char *buff, unsigned int byte_count);
char *print_binary(char *binary, long int input_int, int check, int bnry_size);
char *print_o_arr(char *bnry, char *oct);
char *print_l_oct_arr(char *bnry, char *oct);
char *print_s_oct_arr(char *bnry, char *oct);
char *print_x_arr(char *bnry, char *hex, int is_uppercase, int hex_size);

#endif

