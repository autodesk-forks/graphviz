/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: Details at https://graphviz.org
 *************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _BFS_H_
#define _BFS_H_

#include <neatogen/defs.h>

    typedef struct {
	int *data;
	int queueSize;
	int end;
	int start;
    } Queue;

    extern void mkQueue(Queue *, int);
    extern void freeQueue(Queue *);
    extern void initQueue(Queue *, int startVertex);
    extern boolean deQueue(Queue *, int *);
    extern boolean enQueue(Queue *, int);

    extern void bfs(int, vtx_data *, int, DistType *, Queue *);
    extern int bfs_bounded(int, vtx_data *, int, DistType *, Queue *, int,
			   int *);

#endif

#ifdef __cplusplus
}
#endif
