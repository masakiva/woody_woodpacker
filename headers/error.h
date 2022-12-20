/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:32:32 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/20 16:11:27 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# define ARG_OPTIONS	"h"
# define HELP_OPTION	0x01
# define LONG_HELP_OPTION	"help"

# define HELP_MSG	"[woody_woodpacker] usage:\n"\
	"Provide the path to an ELF executable file as the only argument of the "\
	"program.\n"

enum		e_errcode
{
	MALLOC_ERR,
	WRITE_ERR,
	OPEN_ERR,
	CLOSE_ERR,
	READ_ERR,
	MMAP_ERR,
	MUNMAP_ERR,
	_ERRNO_END_,
	NOT_ELF,
	NOT_64BITS,
	BAD_VER,
	BAD_TYPE,
	NO_ENTRYPOINT,
	NO_PHTABLE,
};

t_byte	retrieve_options(int argc, char **argv, char *op_chars);

int		error_exit(enum e_errcode errcode);

#endif // ERROR_H
