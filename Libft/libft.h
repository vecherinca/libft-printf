/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:05:11 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/08 20:47:29 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
#define FT_LIBFT_H

#include <stdlib.h>
#include <unistd.h>

int ft_isascii(int c);
int ft_isdigit(int c);
unsigned int	ft_strlcat(char *  dst, const char * src, size_t dstsize);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n)
#endif