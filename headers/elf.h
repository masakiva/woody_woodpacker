/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:58:33 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/20 15:57:01 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELF_H
# define ELF_H

// from https://opensource.apple.com/source/dtrace/dtrace-78/sys/elftypes.h
typedef	unsigned long		Elf64_Addr;
typedef	unsigned short		Elf64_Half;
typedef	unsigned long		Elf64_Off;
typedef	unsigned int		Elf64_Word;

// from https://opensource.apple.com/source/dtrace/dtrace-78/sys/elf.h
#define	EI_NIDENT	16
typedef	struct
{
	unsigned char	e_ident[EI_NIDENT];	/* ident bytes */
	Elf64_Half		e_type;				/* file type */
	Elf64_Half		e_machine;			/* target machine */
	Elf64_Word		e_version;			/* file version */
	Elf64_Addr		e_entry;			/* start address */
	Elf64_Off		e_phoff;			/* phdr file offset */
	Elf64_Off		e_shoff;			/* shdr file offset */
	Elf64_Word		e_flags;			/* file flags */
	Elf64_Half		e_ehsize;			/* sizeof ehdr */
	Elf64_Half		e_phentsize;		/* sizeof phdr */
	Elf64_Half		e_phnum;			/* number phdrs */
	Elf64_Half		e_shentsize;		/* sizeof shdr */
	Elf64_Half		e_shnum;			/* number shdrs */
	Elf64_Half		e_shstrndx;			/* shdr string index */
}		Elf64_Ehdr;

#endif // ELF_H
