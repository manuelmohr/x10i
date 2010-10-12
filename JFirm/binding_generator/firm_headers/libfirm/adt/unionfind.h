/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 *
 * This file is part of libFirm.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.
 *
 * Licensees holding valid libFirm Professional Edition licenses may use
 * this file in accordance with the libFirm Commercial License.
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

/**
 * @file
 * @brief      Union-Find datastructure
 * @author     Matthias Braun
 * @version    $Id: unionfind.h 27143 2010-02-13 11:17:42Z mallon $
 * @brief
 *  Union-Find datastructure
 *
 *  This implementation uses weighted sets and path compression which results
 *  in (nearly) O(n) complexity for n find and union operations
 */
#ifndef FIRM_ADT_UNIONFIND_H
#define FIRM_ADT_UNIONFIND_H

#include <assert.h>

/**
 * Call this to initialize an array of @p count elements to be used by the
 * union find functions.
 *
 * @param data    The array (you have to allocate it yourself)
 * @param n_elems number of elements handled by the datastructure
 */
static inline void uf_init(int* data, size_t n_elems)
{
	size_t i;
	for(i = 0; i < n_elems; ++i) {
		data[i] = -1;
	}
}

/**
 * Merge 2 sets (union operation). Note that you have to pass the
 * representatives of the sets and not just random elements
 *
 * @param data	The union find data
 * @param set1	Representative of set1
 * @param set2	Representative of set2
 * @return      the new representative of the set (which is set1 or set2)
 */
static inline int uf_union(int* data, int set1, int set2)
{
	int d1;
	int d2;
	int newcount;

	if(set1 == set2)
		return set1;

	/* need 2 set representatives */
	d1 = data[set1];
	d2 = data[set2];
	assert(d1 < 0 && d2 < 0);

	newcount = d1 + d2;
	if(d1 > d2) {
		data[set1] = set2;
		data[set2] = newcount;
		return set2;
	} else {
		data[set2] = set1;
		data[set1] = newcount;
		return set1;
	}
}

/**
 * Finds the representative for the set with member @p e.
 * The representative of a set is unique, so if the find operations finds
 * the same/different representatives, then the elements are in the
 * the same/different sets.
 *
 * @param data	The union find data
 * @param e		The element
 * @return		The representative of the set that contains @p e
 */
static inline int uf_find(int* data, int e)
{
	/* go through list to find representative */
	int repr = e;
	while(data[repr] >= 0) {
		repr = data[repr];
	}

	/* update list to point to new representative (path compression) */
	while(e != repr) {
		int next = data[e];
		data[e] = repr;
		e = next;
	}

	return repr;
}

#endif
