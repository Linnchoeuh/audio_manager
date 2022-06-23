/**
 * @file adm_baselib.h
 * @author Lenny Vigeon (lenny.vigeon@ecole-89.com)
 * @date 01-04-2022
 */

#ifndef		__ADM_BASELIB_H__
#define		__ADM_BASELIB_H__

#include	<stdlib.h>
#include	<stdbool.h>
#include	<stdarg.h>
#include	<unistd.h>

#define ADM_TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + ('a' - 'A')) : (c))
#define ADM_TOUPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - ('a' - 'A')) : (c))

char *adm_strdup(char *s);

char *adm_strndup(const char *s,
			      size_t n);

size_t adm_strlen(const char *s);

size_t adm_strnlen(const char *s,
			    	size_t n);

int	adm_strcmp(const char *str1,
			    const char *str2);

int	adm_strncmp(const char *first,
			     const char	*second,
			     size_t	length);

int	adm_strcasecmp(const char	*a,
					const char	*b);

ssize_t	adm_fdputs(int fd,
				   const char *str);

ssize_t	adm_puts(const char *str);


char *adm_str_fuse(char *str1,
					char *str2);

bool adm_str_append(char **target,
				   		char *merge);

char *adm_str_chain_fuse(ssize_t len, ...);

int	adm_print_base(ssize_t	nbr,
				   int	base);

void *adm_memcpy(void *restrict destination,
				 const void *restrict source,
				 size_t size);

void *adm_memset(void *ptr,
				 int value,
				 size_t count);

#endif  /*      __ADM_BASELIB_H__    */