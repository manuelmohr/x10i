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
 * @brief    Compute and access out edges (also called def-use edges).
 * @author   Goetz Lindenmaier, Michael Beck
 * @date     1.2002
 * @version  $Id$
 */
#ifndef FIRM_ANA_IROUTS_H
#define FIRM_ANA_IROUTS_H

#include "firm_types.h"
#include "begin.h"

/*------------------------------------------------------------------*/
/* Accessing the out datastructures.                                */
/* These routines only work properly if the ir_graph is in state    */
/* outs_consistent or outs_inconsistent.                            */
/*------------------------------------------------------------------*/

/** To iterate through the successors iterate from 0 to i < get_irn_outs(). No
   order of successors guaranteed.  Will return edges from block to floating
   nodes even if irgraph is in state "op_pin_state_floats". */
/* returns the number of successors of the node: */
FIRM_API int get_irn_n_outs(const ir_node *node);

/** Get the User of a node from the Def-Use edge at position pos. */
FIRM_API ir_node *get_irn_out(const ir_node *def, int pos);

/**
 * Get the User and its input position from the Def-Use edge of def
 * at position pos.
 */
FIRM_API ir_node *get_irn_out_ex(const ir_node *def, int pos, int *in_pos);

/**
 * Set the User at position pos.
 *
 * @param def     the Def node
 * @param pos     the number of the Def-Use edge tat is modified
 * @param use     the Use node
 * @param in_pos  the number of the corresponding Use-Def edge in the use node in array
 */
FIRM_API void set_irn_out(ir_node *def, int pos, ir_node *use, int in_pos);

/* Methods to iterate through the control flow graph. Iterate from 0 to
   i < get_Block_cfg_outs(block). No order of successors guaranteed. */

/** Return the number of control flow successors, ignore keep-alives. */
FIRM_API int get_Block_n_cfg_outs(const ir_node *node);

/** Return the number of control flow successors, honor keep-alives. */
FIRM_API int get_Block_n_cfg_outs_ka(const ir_node *node);

/** Access predecessor n, ignore keep-alives. */
FIRM_API ir_node *get_Block_cfg_out(const ir_node *node, int pos);

/** Access predecessor n, honor keep-alives. */
FIRM_API ir_node *get_Block_cfg_out_ka(const ir_node *node, int pos);

/** Walks over the graph starting at node.  Walks also if graph is in state
   "outs_inconsistent".  Assumes current_ir_graph is set properly. */
FIRM_API void irg_out_walk(ir_node *node, irg_walk_func *pre,
                           irg_walk_func *post, void *env);

/** Walks only over Block nodes in the graph.  Has it's own visited
   flag, so that it can be interleaved with the other walker.
   node must be either op_Block or mode_X.  */
FIRM_API void irg_out_block_walk(ir_node *node, irg_walk_func *pre,
                                 irg_walk_func *post, void *env);

/**
 * returns 1 if outs have been computed for a node, 0 otherwise.
 *
 *  this is useful to detect newly created nodes that have no outs set yet
 */
FIRM_API int get_irn_outs_computed(const ir_node *node);

/*------------------------------------------------------------------*/
/* Building and Removing the out datastructure                      */
/*------------------------------------------------------------------*/

/** Computes the out edges.  Sets a flag in irg to "outs_consistent".  If the
    graph is changed this flag must be set to "outs_inconsistent".  Computes
    out edges from block to floating nodes even if graph is in state
   "op_pin_state_floats".   Optimizes Tuple nodes. */
FIRM_API void compute_irg_outs(ir_graph *irg);
FIRM_API void compute_irp_outs(void);

FIRM_API void assure_irg_outs(ir_graph *irg);

#ifdef INTERPROCEDURAL_VIEW
/** Computes the out edges in interprocedural view */
FIRM_API void compute_ip_outs(void);
/** Frees the out datastructures.  Sets the flag in irg to "outs_none". */
FIRM_API void free_ip_outs(void);
#endif

FIRM_API void free_irg_outs(ir_graph *irg);
FIRM_API void free_irp_outs(void);

#include "end.h"

#endif
