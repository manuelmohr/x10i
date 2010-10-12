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
 * @brief    Traverse an ir graph
 * @author   Boris Boesler, Goetz Lindenmaier
 * @version  $Id$
 * @brief
 *  Traverse an ir graph:
 *  - execute the pre function before recursion
 *  - execute the post function after recursion
 *
 *  Uses current_ir_graph (from irgraph.h)!!! Set it to the proper
 *  graph before starting the walker.
 */
#ifndef FIRM_IR_IRGWALK_H
#define FIRM_IR_IRGWALK_H

#include "firm_types.h"
#include "begin.h"

/**
 * Walks over the ir graph.
 *
 * Walks over the ir graph, starting at the node given as first argument.
 * Executes pre before visiting the predecessor of a node, post after.
 * irg_walk uses the visited flag in irg and the nodes to determine visited
 * nodes.  It executes inc_irg_visited(current_ir_graph) to generate a new
 * flag.  Therefore current_ir_graph must be set before calling the walker.
 * It marks the node as visited before executing pre.
 * The void* env can be used to pass status information between the
 * pre and post functions.  Does not use the link fields.
 *
 * @param node  the start node
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 */
FIRM_API void irg_walk(ir_node *node, irg_walk_func *pre, irg_walk_func *post,
                       void *env);

/**
 * core walker function. Does NOT touch current_ir_graph and does not call
 * inc_irg_visited before walking
 */
FIRM_API void irg_walk_core(ir_node *node, irg_walk_func *pre,
                            irg_walk_func *post, void *env);

/**
 * Walks over all reachable nodes in the ir graph.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * Like irg_walk(), but walks over all reachable nodes in the ir
 * graph, starting at the end operation. During the walk current_ir_graph
 * is set to irg.  Does not use the link field.  If interprocedural_view
 * is set, visits all reachable irgs.
 */
FIRM_API void irg_walk_graph(ir_graph *irg, irg_walk_func *pre,
                             irg_walk_func *post, void *env);

/**
 * Walks over the ir graph.
 *
 * Walks over the ir graph, starting at the node given as first argument.
 * Executes pre before visiting the predecessor of a node, post after.
 * irg_walk uses the visited flag in irg and the nodes to determine visited
 * nodes.  It executes inc_irg_visited(current_ir_graph) to generate a new
 * flag.  Therefore current_ir_graph must be set before calling the walker.
 * It marks the node as visited before executing pre.
 * The void* env can be used to pass status information between the
 * pre and post functions.  Does not use the link fields.
 * This walker also follows additional dependency egdes.
 *
 * @param node  the start node
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 */
FIRM_API void irg_walk_in_or_dep(ir_node *node, irg_walk_func *pre,
                                 irg_walk_func *post, void *env);

/**
 * Walks over all reachable nodes in the ir graph.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * Like irg_walk(), but walks over all reachable nodes in the ir
 * graph, starting at the end operation. During the walk current_ir_graph
 * is set to irg.  Does not use the link field.
 * This walker also follows additional dependency egdes.
 * interprocedural_view is not yet supported.
 */
FIRM_API void irg_walk_in_or_dep_graph(ir_graph *irg, irg_walk_func *pre,
                                       irg_walk_func *post, void *env);

/**
 * Executes irg_walk(end, pre, post, env) for all irgraphs in irprog.
 *
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * This function executes irg_walk(end, pre, post, env) for all irgraphs in irprog.
 * Sets current_ir_graph properly for each walk.  Conserves current
 * current_ir_graph.  In interprocedural view nodes can be visited several
 * times.  Does not use the link field.
 */
FIRM_API void all_irg_walk(irg_walk_func *pre, irg_walk_func *post, void *env);

#ifdef INTERPROCEDURAL_VIEW
/**
 * Walks all irgs in interprocedural view.
 *
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * This function walks all irgs in interprocedural view.
 * Visits each node only once.  Sets current_ir_graph properly. Does not use the link field.
 */
FIRM_API void cg_walk(irg_walk_func *pre, irg_walk_func *post, void *env);
#endif

/** Walks only over Block nodes in the graph.
 *
 * @param node  the start node
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * This function Walks only over Block nodes in the graph. Has it's own visited
 * flag, so that it can be interleaved with the other walker.
 * If a none block is passed, starts at the block this node belongs to.
 * If end is passed also visits kept alive blocks. Does not use the link field.
 */
FIRM_API void irg_block_walk(ir_node *node, irg_walk_func *pre,
                             irg_walk_func *post, void *env);

/**
 * Walks only over reachable Block nodes in the graph.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * Like irg_block_walk(), but walks over all reachable blocks in the
 * ir graph, starting at the end block. Does not use the link field.
 */
FIRM_API void irg_block_walk_graph(ir_graph *irg, irg_walk_func *pre,
                                   irg_walk_func *post, void *env);

/**
 * Walks over all code in const_code_irg.
 *
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 *
 * This function walks over all code in const_code_irg.
 * Uses visited flag in const_code_irg.  Does not use the link field.
 */
FIRM_API void walk_const_code(irg_walk_func *pre, irg_walk_func *post,
                              void *env);

/**
 * Walks over reachable nodes in block-wise topological order, i.e. visit
 * all nodes in a block before going to another block, starting at the end operation.
 * Executes pre before visiting the predecessor of a node, post after.
 * irg_walk_blkwise_graph() uses the visited flag in irg and the nodes to
 * determine visited nodes.
 * It executes inc_irg_visited(current_ir_graph) to generate a new
 * flag. It marks the node as visited before executing pre.
 * The void *env can be used to pass status information between the
 * pre and post functions.  Does not use the link fields.
 * Walks only intraprocedural, even in interprocedural view.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 */
FIRM_API void irg_walk_blkwise_graph(ir_graph *irg, irg_walk_func *pre,
                                     irg_walk_func *post, void *env);

/**
 * Walks over reachable nodes in block-wise topological order, i.e. visit
 * all nodes in a block before going to another block, starting at the end operation.
 * Executes pre before visiting the predecessor of a node, post after.
 * irg_walk_blkwise_graph() uses the visited flag in irg and the nodes to
 * determine visited nodes.
 * It executes inc_irg_visited(current_ir_graph) to generate a new
 * flag. It marks the node as visited before executing pre.
 * The void *env can be used to pass status information between the
 * pre and post functions.  Does not use the link fields.
 * Walks only intraprocedural, even in interprocedural view.
 * This walker also follows dependency edges.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 */
FIRM_API void irg_walk_in_or_dep_blkwise_graph(ir_graph *irg,
                                               irg_walk_func *pre,
                                               irg_walk_func *post, void *env);

/**
 * Walks over reachable nodes in block-wise topological order, i.e. visit
 * all nodes in a block before going to another block, starting at the end operation.
 * Visit the blocks in dominator tree top-down order.
 * Executes pre before visiting the predecessor of a node, post after.
 * irg_walk_blkwise_graph() uses the visited flag in irg and the nodes to
 * determine visited nodes.
 * It executes inc_irg_visited(current_ir_graph) to generate a new
 * flag. It marks the node as visited before executing pre.
 * The void *env can be used to pass status information between the
 * pre and post functions.  Does not use the link fields.
 * Walks only intraprocedural, even in interprocedural view.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 */
FIRM_API void irg_walk_blkwise_dom_top_down(ir_graph *irg, irg_walk_func *pre,
                                            irg_walk_func *post, void *env);

/**
 * Additionally walk over all anchors.
 * This function visits all anchor nodes that otherwise might not been visited in a
 * walk, for instance the Bad() node.
 *
 * @param irg   the irg graph
 * @param pre   walker function, executed before the predecessor of a node are visited
 * @param post  walker function, executed after the predecessor of a node are visited
 * @param env   environment, passed to pre and post
 */
FIRM_API void irg_walk_anchors(ir_graph *irg, irg_walk_func *pre,
                               irg_walk_func *post, void *env);

/**
 * Walker function which does not increase the visited flag before walking.
 * Do not use this unless you know what you are doing.
 */
unsigned irg_walk_2(ir_node *node, irg_walk_func *pre, irg_walk_func *post,
                    void *env);

#include "end.h"

#endif
