/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:55:34 by wsilveir          #+#    #+#             */
/*   Updated: 2025/07/15 18:17:27 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	int		fcount;
	int		success;
	char *files[] = {
		"./src/ft_atoi.c",
		"./src/ft_bzero.c",
		"./src/ft_calloc.c",
		"./src/ft_isalnum.c",
		"./src/ft_isalpha.c",
		"./src/ft_isascii.c",
		"./src/ft_isdigit.c",
		"./src/ft_isprint.c",
		"./src/ft_memchr.c",
		"./src/ft_memcmp.c",
		"./src/ft_memcpy.c",
		"./src/ft_memmove.c",
		"./src/ft_memset.c",
		"./src/ft_strchr.c",
		"./src/ft_strdup.c",
		"./src/ft_strlcat.c",
		"./src/ft_strlcpy.c",
		"./src/ft_strlen.c",
		"./src/ft_strncmp.c",
		"./src/ft_strnstr.c",
		"./src/ft_strrchr.c",
		"./src/ft_tolower.c",
		"./src/ft_toupper.c",
		"./src/ft_substr.c",
		"./src/ft_strjoin.c",
		"./src/ft_strtrim.c",
		"./src/ft_split.c",
		"./src/ft_itoa.c",
		"./src/ft_strmapi.c",
		"./src/ft_striteri.c",
		"./src/ft_putchar_fd.c",
		"./src/ft_putstr_fd.c",
		"./src/ft_putendl_fd.c",
		"./src/ft_putnbr_fd.c"
	};


	i = 0;
	fcount = 0;
	success = 1;
	printf("-------------------------------------------------------\n");
	while (i < 34)
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			printf("Invalid file name: %s\n", files[i]);
			success = 0;
			fcount++;
		}
			i++;
	}

	if (success)
	{
		printf("-------------------------------------------------------\n");
		printf("SUCCESS: all file names were validated successfully.");
		printf("\n------------------------------------------\n");
	}
	else
	{
		printf("-------------------------------------------------------\n");
		printf("FAILED: %d files failed verification.", fcount);
		printf("\n-------------------------------------------------------\n");
	}

	close(fd);
	return (0);
}

