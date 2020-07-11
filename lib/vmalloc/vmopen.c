/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

#include "vmhdr.h"
#include "vmalloc.h"
#include <stdlib.h>

/*	Opening a new region of allocation.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/

/**
 * @param disc ignored
 * @param meth method to manage space
 * @param mode ignored type of region
 */
Vmalloc_t *vmopen(Vmdisc_t *disc, Vmethod_t *meth, int mode) {
  Vmalloc_t *vm;

  (void)disc;
  (void)mode;

  vm = malloc(sizeof(*vm));
  if (vm == NULL) {
    return NULL;
  }

  vm->meth = *meth;

  vm->data = calloc(1, sizeof(*vm->data));
  if (vm->data == NULL) {
    free(vm);
    return NULL;
  }

  return vm;
}
