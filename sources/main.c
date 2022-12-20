/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:21 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/20 15:54:29 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "error.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include "elf.h"

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

char*	get_outfile_name(void)
{
	char*		outfile_name;
	char*		index_str;
	static int	index = 1;

	if (index == 1)
	{
		index++;
		return (ft_strdup(OUTFILE_NAME));
	}
	index_str = ft_itoa(index);
	if (index_str == NULL)
		return (NULL);
	outfile_name = ft_strjoin(OUTFILE_NAME, index_str);
	free(index_str);
	index++;
	return (outfile_name);
}


int		create_outfile(void)
{
	char*	outfile_name;
	int		fd;

	fd = ERROR;
	while (fd == ERROR)
	{
		outfile_name = get_outfile_name();
		if (outfile_name == NULL)
			error_exit(MALLOC_ERR);
		fd = open(outfile_name, O_WRONLY | O_CREAT | O_EXCL,
				S_IRUSR | S_IWUSR | S_IXUSR
				| S_IRGRP | S_IXGRP
				| S_IROTH | S_IXOTH);
		free(outfile_name);
		if (fd == ERROR && errno != EEXIST)
			error_exit(OPEN_ERR);
	}

	return (fd);
}

void	check_input_file(char* input_file_contents)
{
	Elf64_Ehdr	elf_header;

	elf_header.e_ident[0] = 0x7f; // magic number (four bytes)
	elf_header.e_ident[1] = 0x45; // 'E'
	elf_header.e_ident[2] = 0x4c; // 'L'
	elf_header.e_ident[3] = 0x46; // 'F'
	if (ft_memcmp(input_file_contents, elf_header.e_ident, 4) != 0)
		error_exit(NOT_ELF);
	elf_header.e_ident[4] = 0x02; // 64-bit format
	if (ft_memcmp(input_file_contents + 4, elf_header.e_ident + 4, 1) != 0)
		error_exit(NOT_64BITS);
	// endianness?
	elf_header.e_ident[6] = 0x01; // version 1
	if (ft_memcmp(input_file_contents + 6, elf_header.e_ident + 6, 1) != 0)
		error_exit(BAD_VER);

	if ((Elf64_Half)*(input_file_contents + EI_NIDENT) != 0x2 && // ET_EXEC type
			(Elf64_Half)*(input_file_contents + EI_NIDENT) != 0x3) // ET_DYN
		error_exit(BAD_TYPE);
}

int		main(int argc, char** argv)
{
	char*	input_file_contents;
	size_t	file_size;
	//int		outfile_fd;
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

	check_input_file(input_file_contents);

	//outfile_fd = create_outfile();

	unmap_file(input_file_contents, file_size);

	return (EXIT_SUCCESS);
}
