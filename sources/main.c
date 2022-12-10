/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:21 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 18:02:52 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	read_file(char* path)
{
	char*	file_contents;
	char*	line;
	int		fd;
	int		ret;

	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		error_exit(OPEN_ERR);

	file_contents = ft_strdup("");
	ret = TRUE;
	while (ret == TRUE)
	{
		ret = get_next_line(fd, &line);
		if (ret == ERROR)
			error_exit(GNL_ERR);
		file_contents = strjoin_free(file_contents, line);
		if (file_contents == NULL)
			error_exit(MALLOC_ERR);
		free(line);
	}
	printf("%s\n", file_contents);
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
