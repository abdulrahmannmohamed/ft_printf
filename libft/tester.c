/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:33:09 by bvilla            #+#    #+#             */
/*   Updated: 2018/11/05 11:47:21 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>

int lin = 1;

void ft_putlng(long long int nb)
{
	long long int	neg;

	neg = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		neg = -1;
	}
	if (nb > 9 || nb < -9)
		ft_putlng((nb / 10) * neg);
	ft_putchar((nb % 10) * neg + '0');
}

void printDoubleArray(char **arr)
{
	
	for (int i = 0; arr[i]; i++)
	{
		ft_putstr(arr[i]);
		ft_putstr(", ");
	}
}



void printArray(void *arr, int len, int type) 
{ 
	if (type == 1)
	{
		ft_putstr(arr);
		return;
	}
	if (type == 2)
	{
		while (len-- > 0)
		{
			ft_putchar(*(char*)arr);
			arr++;
		}
	}
	if (type == 3)
	{
		while (len-- > 0 && *(char*)arr)
		{
			ft_putchar(*(char*)arr);
			arr++;
		}
	}
	if (type == 4)
	{
		for (int i=0; i<len; i++)
		{ 
			ft_putnbr(((int*)arr)[i]); 
			ft_putstr(", ");
		}
		return;
	}
	if (type == 8)
	{
		for (int i=0; i<len; i++)
		{ 
			ft_putlng(((long long int*)arr)[i]); 
			ft_putstr(", ");
		}
	}

}

void memset_test(void *b, int c, size_t len, int type)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		memset(b, c, len);
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		printArray(b, len/type, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		ft_memset(b, c, len);

		printArray(b, len/type, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}

void bzero_test(void *s, size_t n, int ofst, int len, int type)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		bzero(s + ofst, n);
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		printArray(s, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		ft_bzero(s + ofst, n);
		printArray(s, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}

void memcpy_test(void *dst, const void *src, size_t n, int len, int type, int ofst)
{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		tmp = memcpy(dst, src, n);
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		printArray(tmp + ofst, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		tmp = ft_memcpy(dst, src, n);
		printArray(tmp + ofst, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void memccpy_test(void *dst, const void *src, int c, size_t n, int len, int type)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = memccpy(dst, src, c, n);
		printArray(dst, len, type);
		ft_putstr(" point to:");
		if (tmp)
			ft_putnbr(*((unsigned char*)tmp));
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_memccpy(dst, src, c, n);
		printArray(dst, len, type);
		ft_putstr(" point to:");
		if (tmp)
			ft_putnbr( *((unsigned char*)tmp));
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void memmove_test(void *dst, const void *src, size_t n, int len, int type, int ofst)
{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		tmp = memmove(dst, src, n);
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		printArray(tmp + ofst, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		tmp = ft_memmove(dst, src, n);
		printArray(tmp +  ofst, len, type);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void memchr_test(const void *s, int c, size_t n)
{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		tmp = memchr(s, c, n);
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		if (tmp)
			ft_putstr(tmp);
		else
			ft_putstr("NULL");
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		tmp = ft_memchr(s, c, n);
		if (tmp)
			ft_putstr(tmp);
		else
			ft_putstr("NULL");
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void memcmp_test(const void *s1, const void *s2, size_t n)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		tmp = memcmp(s1, s2, n);
		ft_putnbr(tmp);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		tmp = ft_memcmp(s1, s2, n);
		ft_putnbr(tmp);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strlen_test(const char *s)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");
		tmp = strlen(s);
		ft_putnbr(tmp);
		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		tmp = ft_strlen(s);
		ft_putnbr(tmp);
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strdup_test(const char *s1)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strdup(s1);
		ft_putstr(tmp);
		ft_putstr(" og: ");
		if (s1)
			ft_putnbr((int)s1);
		ft_putstr(" point to:");
		if (tmp)
			ft_putnbr((int)tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strdup(s1);
		ft_putstr(tmp);
		ft_putstr(" og: ");
		if (s1)
			ft_putnbr((int)s1);
		ft_putstr(" point to:");
		if (tmp)
			ft_putnbr((int)tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}


void strcpy_test(char *dst, const char *src, int ofst)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strcpy(dst, src);
		ft_putstr(tmp + ofst);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strcpy(dst, src);
		ft_putstr(tmp + ofst);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strncpy_test(char *dst, const char *src, size_t len, int ofst, int type)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strncpy(dst, src, len);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strncpy(dst, src, len);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strcat_test(char *s1, const char *s2, int ofst, int len, int type)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strcat(s1, s2);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strcat(s1, s2);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strncat_test(char *s1, const char *s2, size_t n, int ofst, int len, int type)

{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strncat(s1, s2, n);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strncat(s1, s2, n);
		printArray(tmp + ofst, len, type);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strlcat_test(char *dst, const char *src, size_t dstsize, int ofst, int len, int type)
{
	int parent;
	size_t tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strlcat(dst, src, dstsize);
		printArray(dst + ofst, len, type);
		ft_putstr(" return:");
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strlcat(dst, src, dstsize);
		printArray(dst + ofst, len, type);
		ft_putstr(" return:");
		ft_putnbr(tmp);


		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strchr_test(const char *s, int c)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strchr(s, c);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strchr(s, c);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");


		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strrchr_test(const char *s, int c)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strrchr(s, c);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strrchr(s, c);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");


		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strstr_test(const char *haystack, const char *needle)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strstr(haystack, needle);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strstr(haystack, needle);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");


		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strnstr_test(const char *haystack, const char *needle, size_t len)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strnstr(haystack, needle, len);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");


		tmp = ft_strnstr(haystack, needle, len);
		ft_putstr(" return:");
		if (tmp)
			ft_putnbr((int)tmp);
		else
			ft_putstr("NULL");


		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}


void strcmp_test(const char *s1, const char *s2)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strcmp(s1, s2);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strcmp(s1, s2);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strncmp_test(const char *s1, const char *s2, size_t n)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = strncmp(s1, s2, n);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strncmp(s1, s2, n);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void atoi_test(const char *str)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = atoi(str);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_atoi(str);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}
void isalpha_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = isalpha(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_isalpha(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void isdigit_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = isdigit(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_isdigit(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}
void isalnum_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = isalnum(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_isalnum(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void isascii_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = isascii(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_isascii(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void isprint_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = isprint(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_isprint(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void toupper_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = toupper(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_toupper(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void tolower_test(int c)
{
	int parent;
	int	tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		tmp = tolower(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_tolower(c);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}
void memalloc_test(size_t size, int	pass)
{
	int parent;
	void *tmp;
	int i = size;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		if (pass)
			while (i--)
				ft_putchar('\0');
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		if ((tmp = ft_memalloc(size)))
			printArray(tmp, size, 2);
		else
			ft_putstr("NULL");
	
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void memdel_test(size_t size, int pass)
{
	int parent;
	void *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		if(pass)
			ft_putstr("NULL");
		else
			ft_putstr("MALLOC FAIL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		if ((tmp = ft_memalloc(size)))
		{
			ft_memdel(&tmp);
			if(tmp)
				ft_putnbr((int)tmp);
			else
				ft_putstr("NULL");
		}
		else
			ft_putstr("MALLOC FAIL");
	
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strnew_test(size_t size, int	pass)
{
	int parent;
	char *tmp;
	int i = size + 1;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		if (pass)
			while (i--)
				ft_putchar('\0');
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		if ((tmp = ft_strnew(size)))
			printArray(tmp, size + 1, 2);
		else
			ft_putstr("NULL");
	
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strdel_test(size_t size, int pass)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		if(pass)
			ft_putstr("NULL");
		else
			ft_putstr("MALLOC FAIL");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		if ((tmp = ft_strnew(size)))
		{
			ft_strdel(&tmp);
			if(tmp)
				ft_putnbr((int)tmp);
			else
				ft_putstr("NULL");
		}
		else
			ft_putstr("MALLOC FAIL");
	
		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}


void strclr_test(char *s, size_t n)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		bzero(s, n - 1);
		printArray(s, n, 2);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		ft_strclr(s);
		printArray(s, n, 2);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}

void strupr(char *c) {*c = toupper(*c);} 

void striter_test(char *s, char *ex)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		ft_striter(s, strupr);
		ft_putstr(s);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}

void litCase(unsigned int i, char *c) {	*c = i % 2 ? tolower(*c) : toupper(*c); }

void striteri_test(char *s, char *ex)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		ft_striteri(s, litCase);
		ft_putstr(s);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}

char strlwr(char c) {return tolower(c);} 

void strmap_test(char *s, char *ex)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strmap(s, strlwr);
		ft_putstr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}

}
char revLitCase(unsigned int i, char c) { return (i % 2 ? toupper(c) : tolower(c));}

void strmapi_test(char *s, char *ex)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strmapi(s, revLitCase);
		ft_putstr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strequ_test(char const *s1, char const *s2, char *ex)
{
	int parent;
	int tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strequ(s1, s2);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void strnequ_test(char const *s1, char const *s2, size_t n, char *ex)
{
	int parent;
	int tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strnequ(s1, s2, n);
		ft_putnbr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	strsub_test(char const *s, unsigned int start, size_t len)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		printArray((char*)s + start, len, 3);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strsub(s, start, len);
		ft_putstr(tmp);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}
void	strjoin_test(char const *s1, char const *s2)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(s1);
		ft_putstr(s2);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");

		tmp = ft_strjoin(s1, s2);
		if(tmp)
			ft_putstr(tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	strtrim_test(char const *s, char *ex)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		tmp = ft_strtrim(s);
		if (tmp)
			ft_putstr(tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	strsplit_test(char const *s, char c, char *ex)
{
	int parent;
	char **tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		tmp = ft_strsplit(s, c);
		if (tmp)
			printDoubleArray(tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	itoa_test(int n, char *ex)
{
	int parent;
	char *tmp;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(ex);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		tmp = ft_itoa(n);
		if (tmp)
			ft_putstr(tmp);
		else
			ft_putstr("NULL");

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	putendl_test(char const *s)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(s);
		ft_putstr("\n");

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		ft_putendl(s);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	putchar_fd_test(char c, int fd)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		write(fd, &c, 1);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		ft_putchar_fd(c, fd);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	putstr_fd_test(char *c, int fd)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putstr(c);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		ft_putstr_fd(c, fd);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	putendl_fd_test(char const *s, int fd)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putendl(s);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		ft_putendl_fd(s, fd);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

void	putnbr_fd_test(int n, int fd)
{
	int parent;

	parent = fork();
	if (!parent)
	{
		ft_putstr("**");
		ft_putnbr(lin);
		ft_putstr("**");

		ft_putnbr(n);

		ft_putstr("%%%%");
		ft_putstr("\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		lin++;
		ft_putstr("**");
		ft_putnbr(lin++);
		ft_putstr("**");
		
		ft_putnbr_fd(n, fd);

		ft_putstr("%%%%");
		ft_putstr("\n");
	}
}

	char a = 'a';
	int ten[10];
	int four[4];
	int three[3];
	int one[1];
	int hund[100];
	char s1[] = "hello";
	char hw[] = "Hello World!";
	char fuck[] = "fuck";
	char s10[] = "0123456789";
	char s30[] = "012345678911234567892123456789";
	char hel[20] = "Hello ";
	char wr[] = "world!";
	long long int l_thirty[30];
	long long int l_one[1];
	long long int l_five[5];

void	reset()
{
	a = 'a';
	ft_bzero(ten, 40);
	ft_bzero(four, 16);
	ft_bzero(three, 12);
	ft_bzero(one, 4);
	ft_bzero(hund, 400);
	ft_memcpy(s1, "hello", sizeof("hello"));
	ft_memcpy(hw, "Hello World!", sizeof("Hello World!"));
	ft_memcpy(fuck, "fuck", sizeof("fuck"));
	ft_memcpy(hel, "Hello ", sizeof("Hello "));
	ft_memcpy(wr, "world!", sizeof("world!"));
	ft_memcpy(s10, "0123456789", sizeof("0123456789"));
	ft_memcpy(s30, "012345678911234567892123456789", sizeof("012345678911234567892123456789"));
	ft_bzero(l_thirty, 240);
	ft_bzero(l_one, 8);
	ft_bzero(l_five, 40);
}



int main() 
{ 

	ft_putstr("\n\nmemset test\n\n");	
	memset_test(ten, 10, 40, 4);
	memset_test(four, 0, 16, 4);
//	memset_test(four, 15, 24, 4); //len is longer than memblock BOTH UNDEFINED
	memset_test(s1, 65, 5, 1);
	memset_test(s10, '1',8, 1); 
	memset_test(l_five, 75, 40, 8);
//	memset_test(s30, 356, 30, 1); //C is bigger than unsigned char just wraps around
//	memset_test(ten, 10, -20, 4); //len is neg DONTWORK
	memset_test(four, 0, 0, 4); //len is zero


	ft_putstr("\n\nbzero test\n\n");		
	bzero_test(s1, 2, 0, 5, 2);
	bzero_test(s30, 10, 15, 30, 2);
	bzero_test(ten, 10, 4, 10, 4);
//	bzero_test(s1, 10, 0, 10, 2); //n is bigger than string UNDEFINED
//	bzero_test(s1, -2, 0, 5, 2); //n is neg DONTWORK
	bzero_test(s1, 0, 0, 5, 2);

	ft_putstr("\n\nmemcpy test\n\n");
	memcpy_test(hw, fuck, 4, 12, 1, 0);
	memcpy_test(hw, fuck, 5, 12, 2, 0);
	memcpy_test(hw, "hello", 5, 12, 2, 0);
	memcpy_test(s30, "hello", 5, 30, 4, 0);
	memcpy_test(hw, s30, 5, 12, 2, 0);
//	memcpy_test(s1, hw, 12, 12, 2, 0); //n is bigger than dst size BOTH UNDEFINED
//	memcpy_test("FUCK", "ME", 2, 4, 2, 0); //dst is CONST both BUS ERR
	memcpy_test(fuck, "what", 0, 4, 2, 0);
//	memcpy_test(s30, "is", -2, 30, 4, 0); //memcpy aborts but we cant use that function
	reset();
//	memcpy_test(hw + 3, hw, 9, 12, 2, -3); // overlap undefined
	reset();
//	memcpy_test(hw, hw + 1, 11, 12, 2, 0); // overlap undefined

	reset();

	ft_putstr("\n\nmemCcpy test\n\n");

	memccpy_test(hw, "fuck", 'w', 4, 12, 2);
	reset();
	memccpy_test(hw, "what", 'w', 4, 12, 2);
	reset();
	memccpy_test(hw, "nope", 'p', 4, 12, 2);
	reset();
	memccpy_test(s1, "psych", 'h', 5, 12, 1);
	memccpy_test(hw, "chai", 0, 5, 12, 2);
	reset();
	memccpy_test(hw, fuck, 'k', 5, 12, 2);
	memccpy_test(fuck, "what", 'r', 0, 4, 2);
//	memccpy_test(NULL, "what", 't', 5, 5, 2); //seg fault

	reset();

	ft_putstr("\n\nmemmove test\n\n");

	memmove_test(hw, fuck, 4, 12, 1, 0);
	memmove_test(hw, fuck, 5, 12, 2, 0);
	memmove_test(hw, "hello", 5, 12, 2, 0);
	memmove_test(s30, "hello", 5, 30, 4, 0);
	memmove_test(hw, s30, 5, 12, 2, 0);
	ft_putstr("\n"); //overlap stuff
	reset();
	memmove_test(hw, hw + 1, 4, 12, 2, 0);	
	memmove_test(fuck + 1, fuck + 2, 2, 4, 2, -1);
	reset();
	memmove_test(fuck + 1, fuck, 3, 4, 2, -1);
	memmove_test(s1 + 1, s1, 4, 5, 2, -1);
	reset();

	ft_putstr("\n\nmemchr test\n\n");
	
	memchr_test(hw, 'l', 12);
	memchr_test(hw, 'z', 12);
	memchr_test(hw, 'e', 1);
	memchr_test(hw, 'e', 2);
	memchr_test(hw, 'o', 5);
	memchr_test(hw, 'H', 0);

	ft_putstr("\n\nmemcmp test\n\n");
	reset();
	memcmp_test("what", "what", 4);
	memcmp_test("what", "what", 5);
	memcmp_test("1234", "1235", 4);
	memcmp_test("fuck this", "fuck thir", sizeof("fuck this"));
	memcmp_test("no", "fucking way", 0);
	memcmp_test("A", "\0", 1);
	hw[0] = -1;
	memcmp_test(hw, "\0", 1);
	hw[0] = -87;
	memcmp_test(hw, "\0", 1);
	memcmp_test(hw, "~", 1);
	hw[0] = -128;
	memcmp_test(hw, "\0", 1);
	reset();

	ft_putstr("\n\nstrlen test\n\n");
	reset();
	strlen_test(hw);
	strlen_test(fuck);
	strlen_test(s1);
	strlen_test("");
	strlen_test("WTF");


	ft_putstr("\n\nstrdup test\n\n");
	reset();
	strdup_test(hw);
	strdup_test(s1);
	strdup_test(fuck);
	strdup_test("shit");

	ft_putstr("\n\nSTRcpy test\n\n");
	reset();
	strcpy_test(hw, fuck, 0);
	strcpy_test(hw, s1, 0);
	strcpy_test(hw, "this cool", 0);
	strcpy_test(hw + 2, "fuck", -2);
	reset();

	ft_putstr("\n\nSTRNcpy test\n\n");
	reset();
	strncpy_test(hw, fuck, 3, 0, 1);
	strncpy_test(hw, "shit", 2, 0, 1);
	strncpy_test(hw, "this cool", 6, 0,1);
	strncpy_test(hw + 2, "fuck", 3,-2,1);
	strncpy_test(hw + 2, "fuck", 4,-2,1);
	strncpy_test(hw + 2, "fuck", 5,-2,1);
	strncpy_test(hw, "fuck", 12, 0, 2);
	reset();

	ft_putstr("\n\nSTRcat test\n\n");
	reset();
	strcat_test(hel, wr, 0, 12, 1);
	reset();
	strcat_test(hel, "", 0, 0, 1);
	reset();	
	wr[1] = '\0';
	strcat_test(hel, wr, 0 , 0, 1);


 	ft_putstr("\n\nstrNcat test\n\n");
	reset();
	strncat_test(hel, wr, 3, 0, 20, 2);
	reset();
	strncat_test(hel, "", 1, 0, 20, 2);
	reset();	
	wr[1] = '\0';
	strncat_test(hel, wr, 40, 0 , 20, 2);
	reset();
	strncat_test(hel, "well it looks like you done messed up", 10, 0, 20, 2);
	reset();
	strncat_test(hel, "well it looks like you done messed up", 14, 0, 20, 2);
	
	char    s3[4] = "";
	char	*src = "aaa";
	char	s20[20];
	char	test[] = "test";
	memset(s20, 'B', 20);
	
	printArray(s3,4, 2);
 	ft_putstr("\n\nstrLcat test\n\n");
	reset();
	strlcat_test(hel, wr, 20, 0, 20, 2);
	reset();
	strlcat_test(hel, "", 20, 0, 20, 2);
	reset();	
	wr[1] = '\0';
	strlcat_test(hel, wr, 10, 0 , 20, 2);
	reset();
	strlcat_test(hel, "well it looks like you done messed up", 19, 0, 20, 2);
	reset();
	strlcat_test(hel, "well it looks like you done messed up", 20, 0, 20, 2);
	reset();
	strlcat_test(hel, "well it looks like you done messed up", 1, 0, 20, 2); 	//dstsize is bigger than strlen(dst)
	strlcat_test(s3, "thx to ntoniolo for this test !", 4, 0, 40, 3);
	strlcat_test(s20, src, 20, 0, 24, 2);
	strlcat_test(test, src, 1, 0, 5, 2);

	ft_putnbr(__builtin___strlcat_chk (s20, src, 20, __builtin_object_size (s20, 2 > 1 ? 1 : 0)));
return 0;
	ft_putstr("\n\nstrchr test\n\n");
	reset();	
	strchr_test(hw, 'l');
	strchr_test(hw, 'z');
	strchr_test(hw, 'e');
	strchr_test(hw, 'o');
	strchr_test(hw, 'H');

	ft_putstr("\n\nstrRchr test\n\n");

	strrchr_test(hw, 'l');
	strrchr_test(hw, 'z');
	strrchr_test(hw, 'e');
	strrchr_test(hw, 'o');
	strrchr_test(hw, 'H');
	
	ft_putstr("\n\nstrstr test\n\n");
	reset();
	strstr_test("hello world", "world");
	ft_strcpy(hw + 6, "hello");
	strstr_test(hw, "hello");
	reset();
	strstr_test(hw, "World!");
	strstr_test(hw, "World");
	strstr_test("hel hell hellO ello hhello", "hello");


	ft_putstr("\n\nstrNstr test\n\n");
	reset();
	strnstr_test("hello world", "world", 13);
	ft_strcpy(hw + 6, "hello");
	strnstr_test(hw, "Hello", 5);
	strnstr_test(hw, "Hello", 4);
	reset();
	strnstr_test(hw, "World!", 11);
	strnstr_test(hw, "World", 0);
	strnstr_test("hel hell hellO ello hhello", "hello", 26);
	strnstr_test("hel hell hellO ello hhello", "hello", 25);
	strnstr_test("hel hell hellO ello hhello", "hello", 27);
	strnstr_test("hel hell hellO ello hhello", "hello", -1);
	strnstr_test("hel hell hellO ello hhello", "hello", 3000000000);
	strnstr_test("abcdefghijklmnopqrstuvwxyz", "j", 10);
	strnstr_test("abcdefghijklmnopqrstuvwxyz", "j", 9);
	strnstr_test("w wh wha what what!", "what!", 19);
	strnstr_test("w wh wha what what!", "what!", 18);

	ft_putstr("\n\nstrcmp test\n\n");
	reset();
	strcmp_test("what", "what");
	strcmp_test("what", "what");
	strcmp_test("1234", "1235");
	strcmp_test("fuck this", "fuck thir");
	strcmp_test("no", "fucking way");
	strcmp_test("A", "\0");
	hw[0] = -1;
	strcmp_test(hw, "\0");
	hw[0] = -87;
	strcmp_test(hw, "\0");
	strcmp_test(hw, "~");
	hw[0] = -128;
	strcmp_test(hw, "\0");
	strcmp_test("", "");
	reset();


	ft_putstr("\n\nstrncmp test\n\n");
	reset();
	strncmp_test("what", "what", 4);
	strncmp_test("what", "what", 5);
	strncmp_test("1234", "1235", 4);
	strncmp_test("fuck this", "fuck thir", sizeof("fuck this"));
	strncmp_test("no", "fucking way", 0);
	strncmp_test("A", "\0", 1);
	hw[0] = -1;
	strncmp_test(hw, "\0", 1);
	hw[0] = -87;
	strncmp_test(hw, "\0", 1);
	strncmp_test(hw, "~", 1);
	hw[0] = -128;
	strncmp_test(hw, "\0", 1);
	strncmp_test("what do you want", "what do you want", 30);
	strncmp_test("what do you want", "what do you want\0fuck", 30);
	strncmp_test("what do you want", "what do you wans", 30);
	reset();
	
	ft_putstr("\n\natoi test\n\n");
	reset();
	atoi_test("  \t  -234");
	atoi_test(" ++234");
	atoi_test("  asdf7899995");
	atoi_test("   2147483648");
	atoi_test(" +123456 789");
	atoi_test(" -2147483648");
	atoi_test("  -21474836489");
	atoi_test(" -1+23456 789");
	atoi_test(" -2147.df.a483648");

	ft_putstr("\n\nisalpha test\n\n");
	reset();
	isalpha_test('a');
	isalpha_test('z');
	isalpha_test('b');
	isalpha_test('a' - 1);
	isalpha_test('z' + 1);
	isalpha_test('r');
	isalpha_test('A' - 1);
	isalpha_test('Z' + 1);
	isalpha_test('A');
	isalpha_test('Z');
	isalpha_test('G');
	isalpha_test('t');
	isalpha_test('1');
	isalpha_test('0');
	isalpha_test(255);
	isalpha_test(0);
	isalpha_test(256);
	isalpha_test(27);
	isalpha_test(65);

	ft_putstr("\n\nisDIGIT test\n\n");
	reset();
	isdigit_test('0');
	isdigit_test('9');
	isdigit_test('b');
	isdigit_test('0' - 1);
	isdigit_test('9' + 1);
	isdigit_test('r');
	isdigit_test('A' - 1);
	isdigit_test('Z' + 1);
	isdigit_test('&');
	isdigit_test('Z');
	isdigit_test('G');
	isdigit_test('4');
	isdigit_test('1');
	isdigit_test('0');
	isdigit_test(255);
	isdigit_test(-1);
	isdigit_test(256);
	isdigit_test(27);
	isdigit_test(65);

	ft_putstr("\n\nisALNUM test\n\n");
	reset();
	isalnum_test('0');
	isalnum_test('9');
	isalnum_test('b');
	isalnum_test('0' - 1);
	isalnum_test('9' + 1);
	isalnum_test('r');
	isalnum_test('A' - 1);
	isalnum_test('Z' + 1);
	isalnum_test('&');
	isalnum_test('Z');
	isalnum_test('G');
	isalnum_test('4');
	isalnum_test('1');
	isalnum_test('0');
	isalnum_test(255);
	isalnum_test(-1);
	isalnum_test(256);
	isalnum_test(27);
	isalnum_test(65);
	isalnum_test('a');
	isalnum_test('z');
	isalnum_test('b');
	isalnum_test('a' - 1);
	isalnum_test('z' + 1);
	isalnum_test('A' - 1);
	isalnum_test('Z' + 1);
	isalnum_test('A');
	isalnum_test('t');
	isalnum_test('1');
	isalnum_test('0');
	isalnum_test(255);
	isalnum_test(0);
	isalnum_test(256);
	isalnum_test(27);
	isalnum_test(65);

	ft_putstr("\n\nisASCII test\n\n");
	reset();
	isascii_test('a');
	isascii_test(' ');
	isascii_test('b');
	isascii_test(128);
	isascii_test('9' + 1);
	isascii_test(0);
	isascii_test('A' - 1);
	isascii_test('Z' + 1);
	isascii_test('&');
	isascii_test('Z');
	isascii_test('G');
	isascii_test('4');
	isascii_test('1');
	isascii_test(127);
	isascii_test(255);
	isascii_test(-1);
	isascii_test(256);
	isascii_test(27);
	isascii_test(65);
	
	ft_putstr("\n\nisPRINT test\n\n");
	reset();
	isprint_test('0');
	isprint_test(' ');
	isprint_test('b');
	isprint_test('0' - 1);
	isprint_test('9' + 1);
	isprint_test(2);
	isprint_test(128);
	isprint_test(31);
	isprint_test('&');
	isprint_test('Z');
	isprint_test(126);
	isprint_test(127);
	isprint_test('1');
	isprint_test('0');
	isprint_test(255);
	isprint_test(-1);
	isprint_test(256);
	isprint_test(27);
	isprint_test(65);

	ft_putstr("\n\ntoUPPER test\n\n");
	toupper_test('a');
	toupper_test('b');
	toupper_test('a' - 1);
	toupper_test('z');
	toupper_test(0);
	toupper_test(255);
	toupper_test('z' + 1);
	toupper_test(500);
	toupper_test(-40);
	toupper_test(-2000);
	toupper_test(200);
	toupper_test('m');

	ft_putstr("\n\ntolower test\n\n");
	tolower_test('A');
	tolower_test('B');
	tolower_test('A' - 1);
	tolower_test('Z');
	tolower_test(0);
	tolower_test(255);
	tolower_test('Z' + 1);
	tolower_test(500);
	tolower_test(-40);
	tolower_test(-2000);
	tolower_test(200);
	tolower_test('M');

	ft_putstr("\n\nmemalloc test\n\n");
	memalloc_test(10, 1);
	memalloc_test(100, 1);
	memalloc_test(1000, 1);
	memalloc_test(10000, 1);
	memalloc_test(0, 1);

	ft_putstr("\n\nmemdel test\n\n");
	memdel_test(10, 1);
	memdel_test(100, 1);
	memdel_test(1000, 1);
	memdel_test(10000, 1);
	memdel_test(0, 1);


	ft_putstr("\n\nstrnew test\n\n");
	strnew_test(10, 1);
	strnew_test(100, 1);
	strnew_test(1000, 1);
	strnew_test(10000, 1);
	strnew_test(0, 1);

	ft_putstr("\n\nstrdel test\n\n");
	strdel_test(10, 1);
	strdel_test(100, 1);
	strdel_test(1000, 1);
	strdel_test(10000, 1);
	strdel_test(0, 1);

	reset();

	ft_putstr("\n\nstrclr test\n\n");
	strclr_test(hw, sizeof(hw));
	strclr_test(s1, sizeof(s1));
	strclr_test(fuck, sizeof(fuck));
	strclr_test(s30, sizeof(s30));
	strclr_test(s10, sizeof(s10));

	ft_putstr("\n\nstriter test\n\n");
	reset();
	striter_test(s1, "HELLO");
	striter_test(fuck, "FUCK");
	striter_test(hw, "HELLO WORLD!");


	ft_putstr("\n\nstriteri test\n\n");
	reset();
	striteri_test(s1, "HeLlO");
	striteri_test(fuck, "FuCk");
	striteri_test(hw, "HeLlO WoRlD!");

	ft_putstr("\n\nstrmap test\n\n");
	ft_striter(s1, strupr);
	ft_striter(fuck, strupr);
	ft_striter(hw, strupr);

	strmap_test(s1, "hello");
	strmap_test(fuck, "fuck");
	strmap_test(hw, "hello world!");

	ft_putstr("\n\nstrMAPi test\n\n");
	reset();
	strmapi_test(s1, "hElLo");
	strmapi_test(fuck, "fUcK");
	strmapi_test(hw, "hElLo wOrLd!");


	ft_putstr("\n\nstrequ test\n\n");
	reset();
	strequ_test(s1, "hello", "1");
	strequ_test(fuck, "fUcK", "0");
	strequ_test(hw, "hElLo wOrLd", "0");
	strequ_test(hw, "Hello World!", "1");
	strequ_test(hw, "Hello World", "0");
	strequ_test(hw, "Hello World!!", "0");
	strequ_test(hw, "\0Hello World!", "0");
	strequ_test(hw, hw, "1");

	ft_putstr("\n\nstrnequ test\n\n");
	reset();
	strnequ_test("what", "what", 4, "1");
	strnequ_test("what", "what", 5, "1");
	strnequ_test("1234", "1235", 4, "0");
	strnequ_test("fuck this", "fuck thir", sizeof("fuck this"), "0");
	strnequ_test("no", "fucking way", 0, "1");

	ft_putstr("\n");
	strnequ_test("A", "\0", 1, "0");
	hw[0] = -1;
	strnequ_test(hw, "\0", 1, "0");
	hw[0] = -87;
	strnequ_test(hw, "\0", 1, "0");
	strnequ_test(hw, "~", 1, "0");
	hw[0] = -128;
	strnequ_test(hw, "\0", 1, "0");
	ft_putstr("\n");

	strnequ_test("what do you want", "what do you want", 30, "1");
	strnequ_test("what do you want", "what do you want\0fuck", 30, "1");
	strnequ_test("what do you want", "what do you wans", 30, "0");
	reset();

	ft_putstr("\n\nstrsub test\n\n");
	reset();
	strsub_test("what", 2, 2);
	strsub_test("Hello people", 6, 7);
	strsub_test(hw, 0, sizeof(hw));
   	strsub_test(hw, 3, 4);	

	ft_putstr("\n\nstrjoin test\n\n");
	strjoin_test("what", " the fuck");
	strjoin_test("  no", " fucking way");
	strjoin_test("yeah ", " browski   ");
	strjoin_test("omae ", " nani yatterun yaro");
	strjoin_test("nande", "yanen");
	strjoin_test("homma", "ni ka");
	strjoin_test("d", "");
	strjoin_test("", "");

	ft_putstr("\n\nstrtrim test\n\n");
	strtrim_test("   what  ", "what");
	strtrim_test("   does this really work  ", "does this really work");
	strtrim_test("      what about now              ", "what about now");
	strtrim_test(" what stagger", "what stagger");
	strtrim_test("no space", "no space");
	strtrim_test("   what", "what");

	ft_putstr("\n\nstrsplit test\n\n");
	strsplit_test("***does****this****work***", '*', "does, this, work, ");
	strsplit_test("***does****this****work***", ' ', "***does****this****work***, ");
	strsplit_test("does****this****work***", '*', "does, this, work, ");
	strsplit_test("***does****this****work", '*', "does, this, work, ");
	strsplit_test("*does****this****work", '*', "does, this, work, ");
	strsplit_test("does****this****work*", '*', "does, this, work, ");
	strsplit_test("*does****this****work*", '*', "does, this, work, ");
	strsplit_test("", '*', "");
	strsplit_test("what is up party people", ' ', "what, is, up, party, people, ");
	strsplit_test("i.guess.this.works.", '.', "i, guess, this, works, ");

	ft_putstr("\n\nitoa test\n\n");
	itoa_test(123456, "123456");
	itoa_test(0, "0");
	itoa_test(-123456, "-123456");
	itoa_test(-2147483648, "-2147483648");
	itoa_test(2147483647, "2147483647");
	itoa_test(-234, "-234");

	ft_putstr("\n\nputendl test\n\n");
	putendl_test("what");
	putendl_test(hw);
	putendl_test("");
	putendl_test("123");

	ft_putstr("\n\nputchar_fd test\n\n");
	putchar_fd_test('c', 1);
	putchar_fd_test('\0', 1);
	putchar_fd_test(127, 1);
	putchar_fd_test(35, 1);

	ft_putstr("\n\nputSTR_fd test\n\n");
	putstr_fd_test("what!", 1);
	putstr_fd_test("", 1);
	putstr_fd_test(NULL, 1);
	putstr_fd_test("ok 1234", 1);
	putstr_fd_test("yeah", 1);


	ft_putstr("\n\nputendl_fd test\n\n");
	putendl_fd_test("what", 1);
	putendl_fd_test(hw, 1);
	putendl_fd_test("", 1);
	putendl_fd_test("123", 1);


	ft_putstr("\n\nputNBR_fd test\n\n");
	putnbr_fd_test(1234, 1);
	putnbr_fd_test(0, 1);
	putnbr_fd_test(-2147483648, 1);
	putnbr_fd_test(2147483647, 1);

	return (0);
	
} 


