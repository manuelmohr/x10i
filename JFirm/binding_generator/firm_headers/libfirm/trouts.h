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
 * @brief    Reverse edges that reference types/entities.
 * @author   Goetz Lindenmaier
 * @date     29.10.2004
 * @version  $Id$
 * @brief
 *  Trouts list all uses of types and entities.
 *  Each type gets a list of all Alloc nodes allocating it.
 *  Each entity gets two lists:
 *    - one containing all accesses (Load, (Call), Store),
 *    - and one containing all uses to get a reference (Sel, SymConst).
 */
#ifndef FIRM_ANA_TROUTS_H
#define FIRM_ANA_TROUTS_H

#include "firm_types.h"
#include "irgraph.h"

#include "begin.h"

/*-----------------------------------------------------------------*/
/* Accessing the trout datastructures.                             */
/* These routines only work properly if firm is in state           */
/* trouts_consistent or trouts_inconsistent.                       */
/*-----------------------------------------------------------------*/

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* entities                                                        */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/** Number of Load/Store nodes that possibly access this entity. */
FIRM_API int get_entity_n_accesses(const ir_entity *ent);
/** Load/Store node that possibly access this entity. */
FIRM_API ir_node *get_entity_access(const ir_entity *ent, int pos);

/** Number of references to an entity, in form of SymConst/Sel.
 *  Including references from constant entities and the like. */
FIRM_API int get_entity_n_references(const ir_entity *ent);
/** References to an entity, in form of SymConst/Sel
 *  Including references from constants. */
FIRM_API ir_node *get_entity_reference(const ir_entity *ent, int pos);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* types                                                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/** Number of Alloc nodes that create an instance of this type. */
FIRM_API int get_type_n_allocs(const ir_type *tp);
/** Alloc node that create an instance of this type. */
FIRM_API ir_node *get_type_alloc(const ir_type *tp, int pos);

/** Number of Cast nodes that cast a pointer to this type. */
FIRM_API int get_type_n_casts(const ir_type *tp);
/** Cast node that cast a pointer to this type. */
FIRM_API ir_node *get_type_cast(const ir_type *tp, int pos);
FIRM_API void add_type_cast(const ir_type *tp, ir_node *cast);
/** Return number of upcasts. O(\#casts). */
FIRM_API int get_class_n_upcasts(const ir_type *clss);
/** Return number of downcasts. O(\#casts). */
FIRM_API int get_class_n_downcasts(const ir_type *clss);

/* Access all pointer types that point to tp. */
FIRM_API int     get_type_n_pointertypes_to(const ir_type *tp);
FIRM_API ir_type *get_type_pointertype_to(const ir_type *tp, int pos);
FIRM_API void    add_type_pointertype_to(const ir_type *tp, ir_type *ptp);

/* Access all array types that contain elements of type tp.
 * Does not find subarrays, e.g., int[] being element of int[][]
 * for multi dimensional arrays. */
FIRM_API int     get_type_n_arraytypes_of(const ir_type *tp);
FIRM_API ir_type *get_type_arraytype_of(const ir_type *tp, int pos);
FIRM_API void    add_type_arraytype_of(const ir_type *tp, ir_type *atp);

/*------------------------------------------------------------------*/
/* Building and Removing the trout datastructure                    */
/*------------------------------------------------------------------*/

/** The state of the tr_out datastructure.
 *
 *  We reuse the enum of irouts.
 *  @see irouts.h. */
FIRM_API irg_outs_state get_trouts_state(void);
/** Set the tr out state to inconsistent if it is consistent. */
FIRM_API void           set_trouts_inconsistent(void);

/** Compute the outs of types and entities.
 *
 *  Collects all reference from irnodes to types or entities in the
 *  corresponding types/entities.  Further reverses references between
 *  types and entities.
 *
 *  Annotates the following nodes:
 *    Alloc    --> get_Alloc_type()
 *    Cast     --> get_Cast_type()
 *    Sel      --> get_Sel_entity()
 *    SymConst --> get_SymConst_entity()
 *    Load(addr)  --> get_addr_entity() \  ent von SymConst, oder falls Sel: ent von
 *    Store(addr) --> get_addr_entity() /  outermost im compound.  Ansonsten: nirgends.
 *                                         d.h. wir bekommen die array Elementzugriffe
 *                                         an die jack array Klasse annotiert.
 *    Call(Sel)   --> get_Sel_entity()  // ev. Tabellenzugriff --> Load.
 *
 *   type --> pointer type refering to this type.
 *   type --> entity of this type. @@@ to be implemented.
 *
 *  Sets trout state to outs_consistent.
 */
FIRM_API void compute_trouts(void);

/** Free trout data. */
FIRM_API void free_trouts(void);

#include "end.h"

#endif
