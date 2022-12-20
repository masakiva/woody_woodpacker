/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:34:18 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/20 16:14:58 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int		error_exit(enum e_errcode errcode)
{
	const char		*err_msg[] = {
		"Memory allocation failure",
		"Cannot write on standard output",
		"Cannot open file specified as argument",
		"Problem closing file",
		"Cannot read file specified as argument",
		"Problem mapping the file into memory",
		"Problem unmapping the file from memory",
		"--- separator ---",
		"File is not of ELF format",
		"ELF file is not of 64-bit format",
		"Only ELF file of version 1 is supported",
		"Only ELF files of type ET_EXEC or ET_DYN are supported",
		"ELF executable does not have any entry point",
		"ELF executable does not have any program header table",
	};

	ft_putstr_fd("[computorv1] error: ", STDERR_FILENO);
	ft_putstr_fd(err_msg[errcode], STDERR_FILENO);
	if (errcode < _ERRNO_END_)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);

	exit(EXIT_FAILURE);
}
