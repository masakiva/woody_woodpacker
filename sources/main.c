/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:21 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/17 18:40:34 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "error.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

#include <stdio.h>

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

char*	map_input_file(char* path, size_t* file_size)
{
	char*	file_in_mem;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		error_exit(OPEN_ERR);

	*file_size = get_file_size(fd);

	file_in_mem = mmap(NULL, *file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE,
			fd, 0);
	if (file_in_mem == MAP_FAILED)
		error_exit(MMAP_ERR);

	if (close(fd) == ERROR)
		error_exit(CLOSE_ERR);

	return (file_in_mem);
}

void	unmap_file(char* file_in_mem, size_t file_size)
{
	if (munmap(file_in_mem, file_size) == ERROR)
		error_exit(MUNMAP_ERR);
}

char*	get_output_filename(void)
{
	char*		output_filename;
	char*		index_str;
	static int	index = 1;

	if (index == 1)
	{
		index++;
		return (ft_strdup(OUTPUT_FILENAME));
	}
	index_str = ft_itoa(index);
	if (index_str == NULL)
		return (NULL);
	output_filename = ft_strjoin(OUTPUT_FILENAME, index_str);
	free(index_str);
	index++;
	return (output_filename);
}


int		create_output_file(void)
{
	char*	output_filename;
	int		fd;

	fd = ERROR;
	while (fd == ERROR)
	{
		output_filename = get_output_filename();
		if (output_filename == NULL)
			error_exit(MALLOC_ERR);
		fd = open(output_filename, O_WRONLY | O_CREAT | O_EXCL,
				S_IRUSR | S_IWUSR | S_IXUSR
				| S_IRGRP | S_IXGRP
				| S_IROTH | S_IXOTH);
		free(output_filename);
		if (fd == ERROR && errno != EEXIST)
			error_exit(OPEN_ERR);
	}

	return (fd);
}

int		main(int argc, char** argv)
{
	char*	input_file_contents;
	size_t	file_size;
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

	input_file_contents = map_input_file(argv[1], &file_size);

	unmap_file(input_file_contents, file_size);

	create_output_file();

	return (EXIT_SUCCESS);
}
