/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:55:34 by wsilveir          #+#    #+#             */
/*   Updated: 2025/07/17 20:49:07 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

int	main(int argc, char *argv[])
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
	char *bonusfiles[] = {
		"./src/ft_lstnew.c",
		"./src/ft_lstadd_front.c",
		"./src/ft_lstsize.c",
		"./src/ft_lstlast.c",
		"./src/ft_lstadd_back.c",
		"./src/ft_lstdelone.c",
		"./src/ft_lstclear.c",
		"./src/ft_lstiter.c",
		"./src/ft_lstmap.c",
		0
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
			printf(RED"❌ Invalid file name: %s\n"RESET, files[i]);
			success = 0;
			fcount++;
		}
		close(fd);
		i++;
	}
	i = 0;
	if (argc == 2 && strcmp(argv[1], "--check-bonus") == 0)
	{
		while (bonusfiles[i])
		{
			fd = open(bonusfiles[i], O_RDONLY);
			if (fd == -1)
			{
				printf(RED"Invalid file name: %s\n"RESET, bonusfiles[i]);
				success = 0;
				fcount++;
			}
			close(fd);
			i++;
		}
	}

	if (success)
	{
		printf("-------------------------------------------------------\n");
		printf(GREEN"✅ SUCCESS: all file names were validated successfully."RESET);
		printf("\n------------------------------------------\n");
	}
	else
	{
		printf("-------------------------------------------------------\n");
		printf(RED"❌ FAILED: %d files failed verification."RESET, fcount);
		printf("\n-------------------------------------------------------\n");
	}

	close(fd);
	return (0);
}

