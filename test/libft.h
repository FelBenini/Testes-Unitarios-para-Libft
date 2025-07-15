/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:32:35 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/15 14:11:57 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_atoi(char *str);
void	*ft_memset(void *src, int value, size_t len);
size_t	ft_strlen(char *str);
void	*ft_bzero(void *src, size_t len);
char	*ft_strdup(const char *src);
int		ft_tolower(int C);
int		ft_toupper(int c);
int		ft_isalnum(int x);
int		ft_isdigit(int c);
int		ft_isprint(char c);
int		ft_isalpha(char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isascii(int c);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strrchr(const char *string, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
