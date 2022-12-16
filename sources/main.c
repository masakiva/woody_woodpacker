/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:21 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/16 23:39:28 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096

size_t	get_file_size(int fd)
{
	size_t	file_size;
	ssize_t	ret;
	char	buf[BUFFER_SIZE];

	file_size = 0;
	ret = BUFFER_SIZE;
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, &buf, BUFFER_SIZE);
		file_size += ret;
	}
	if (ret == ERROR)
		error_exit(READ_ERR);

	return (file_size);
}

void	read_file(char* path)
{
	size_t	file_size;
	int		fd;
	char	*file_in_mem;

	fd = open(path, O_RDWR);
	if (fd == ERROR)
		error_exit(OPEN_ERR);

	file_size = get_file_size(fd);

	file_in_mem = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (file_in_mem == MAP_FAILED)
		error_exit(MMAP_ERR);

//	file_in_mem[0] = 'c';

	if (munmap(file_in_mem, file_size) == ERROR)
		error_exit(MUNMAP_ERR);

	if (close(fd) == ERROR)
		error_exit(CLOSE_ERR);
}

int		main(int argc, char** argv)
{
	t_byte	options;

	if (argc != 2)
	{
		if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
			error_exit(WRITE_ERR);
		return (EXIT_FAILURE);
	}
	options = retrieve_options(argc, argv, ARG_OPTIONS);
	if (options & HELP_OPTION)
	{
		if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
			error_exit(WRITE_ERR);
		return (EXIT_SUCCESS);
	}

	read_file(argv[1]);

	return (EXIT_SUCCESS);
}
