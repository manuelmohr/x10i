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
 * @brief    Support for ir graph modification.
 * @author   Martin Trapp, Christian Schaefer, Goetz Lindenmaier
 * @version  $Id$
 */
#ifndef FIRM_IR_IRGMOD_H
#define FIRM_IR_IRGMOD_H

#include "firm_types.h"
#include "begin.h"

/** Exchanges two nodes by conserving edges leaving old (i.e.,
   pointers pointing to old).  Turns the old node into an Id. */
FIRM_API void exchange(ir_node *old, ir_node *nw);

/** Turns a node into a "useless" Tuple.
 *
 *  Turns a node into a "useless" Tuple.  The Tuple node just forms a tuple
 *  from several inputs. All predecessors of the tuple are set to bad and
 *  should be replaced if necssary. The block predecessor remains the same.
 *  This is useful if a node returning a tuple is removed, but the Projs
 *  extracting values from the tuple are not available.
 *
 *  @param node The node to be turned into a tuple.
 *  @param arity The number of values formed into a Tuple.
 */
FIRM_API void turn_into_tuple(ir_node *node, int arity);

/** Walks over the passed IR graph and collects all Phi nodes as a
  * list in their corresponding block (using get_Block_phis() API).
  * Further it collects all Proj nodes in a list of the node producing
  * the tuple. In case of nested tuples the Projs are collected in the
  * node producing the outermost Tuple.
  * All partBlocks are linked to its macroblock header.
  * All other link fields are cleared afterwards.
  */
FIRM_API void collect_phiprojs(ir_graph *irg);

/** Parts a block into two.  This is useful to insert other blocks within a
 *  given block.
 *
 * Adds a new block (new_block) in the control flow before the block
 * (old_block) of node.  Moves node and its predecessors from old_block to
 * new_block.  Moves all Projs that depend on moved nodes and are in old_block
 * to new_block. Moves all Phi nodes from old_block to new_block.  To achieve
 * this the routine assumes that all Phi nodes are in the Phi list (see get_Block_phis())
 * of old_block.  Further it assumes that all Proj nodes are accessible by the link field
 * of the nodes producing the Tuple and all partBlocks are linked to its MacroBlock header.
 * This can be established by collect_phiprojs().  part_block() conserves this property.
 * Adds a Jmp node to new_block that jumps to old_block.
 *
 * @param node   The node were to break the block
 */
FIRM_API void part_block(ir_node *node);

/**
 * Kill a node by setting its predecessors to Bad and finally
 * exchange the node by Bad itself.
 */
FIRM_API void kill_node(ir_node *node);

#include "end.h"

#endif
