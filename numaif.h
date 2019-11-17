/* Copyright (C) 2018-2019 VMware, Inc.
   PDX-License-Identifier: GPL-2.0

   libnuma is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; version
   2.1.

   libnuma is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should find a copy of v2.1 of the GNU Lesser General Public License
   somewhere on your Linux system; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA */

#ifndef NUMAIF_H
#define NUMAIF_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* Kernel interface for NUMA API */

/* System calls */
extern long get_pgreplpolicy(int *mode, unsigned long *nmask,
			unsigned long maxnode, void *addr, unsigned flags);
extern long set_pgreplpolicy(int mode, const unsigned long *nmask,
			  unsigned long maxnode);	
extern long get_mempolicy(int *mode, unsigned long *nmask,
			unsigned long maxnode, void *addr, unsigned flags);
extern long mbind(void *start, unsigned long len, int mode,
	const unsigned long *nmask, unsigned long maxnode, unsigned flags);
extern long set_mempolicy(int mode, const unsigned long *nmask,
			  unsigned long maxnode);
extern long migrate_pages(int pid, unsigned long maxnode,
			  const unsigned long *frommask,
			  const unsigned long *tomask);

extern long move_pages(int pid, unsigned long count,
		void **pages, const int *nodes, int *status, int flags);

/* Policies */
#define MPOL_DEFAULT     0
#define MPOL_PREFERRED   1
#define MPOL_BIND        2
#define MPOL_INTERLEAVE  3
#define MPOL_LOCAL       4
#define MPOL_MAX         5

/* Flags for get_mem_policy */
#define MPOL_F_NODE    (1<<0)   /* return next il node or node of address */
				/* Warning: MPOL_F_NODE is unsupported and
				   subject to change. Don't use. */
#define MPOL_F_ADDR     (1<<1)  /* look up vma using address */
#define MPOL_F_MEMS_ALLOWED (1<<2) /* query nodes allowed in cpuset */

/* Flags for mbind */
#define MPOL_MF_STRICT  (1<<0)  /* Verify existing pages in the mapping */
#define MPOL_MF_MOVE	(1<<1)  /* Move pages owned by this process to conform to mapping */
#define MPOL_MF_MOVE_ALL (1<<2) /* Move every page to conform to mapping */

#ifdef __cplusplus
}
#endif

#endif
