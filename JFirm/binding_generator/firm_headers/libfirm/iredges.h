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
 * @brief   Public header for the automatically updating outs.
 * @author  Sebastian Hack
 * @date    3.2.2005
 * @version $Id$
 */
#ifndef FIRM_IR_IREDGES_H
#define FIRM_IR_IREDGES_H

#include "firm_types.h"
#include "iredgekinds.h"
#include "begin.h"

/**
 * Get the first edge pointing to some node.
 * @note There is no order on out edges. First in this context only
 * means, that you get some starting point into the list of edges.
 * @param irn The node.
 * @param kind The kind of the edge.
 * @return The first out edge that points to this node.
 */
FIRM_API const ir_edge_t *get_irn_out_edge_first_kind(const ir_node *irn,
                                                      ir_edge_kind_t kind);

/**
 * Get the next edge in the out list of some node.
 * @param irn The node.
 * @param last The last out edge you have seen.
 * @return The next out edge in @p irn 's out list after @p last.
 */
FIRM_API const ir_edge_t *get_irn_out_edge_next(const ir_node *irn,
                                                const ir_edge_t *last);

/**
 * A convenience iteration macro over all out edges of a node.
 * @param irn  The node.
 * @param kind The edge's kind.
 * @param edge An ir_edge_t pointer which shall be set to the current
 * edge.
 */
#define foreach_out_edge_kind(irn, edge, kind) \
	for(edge = get_irn_out_edge_first_kind(irn, kind); edge; edge = get_irn_out_edge_next(irn, edge))

/**
 * A convenience iteration macro over all out edges of a node, which is safe
 * against alteration of the current edge.
 *
 * @param irn  The node.
 * @param edge An ir_edge_t pointer which shall be set to the current edge.
 * @param ne   The next edge, enables alteration safe edge processing.
 * @param kind The kind of the edge.
 */
#define foreach_out_edge_kind_safe(irn, edge, ne, kind) \
	for((edge) = (get_irn_out_edge_first_kind(irn, kind)), (ne) = ((edge) ? (get_irn_out_edge_next(irn, edge)) : NULL); \
		edge; (edge) = (ne), (ne) = ((edge) ? (get_irn_out_edge_next(irn, edge)) : NULL))

/**
 * Convenience macro for normal out edges.
 */
#define foreach_out_edge(irn, edge)            foreach_out_edge_kind(irn, edge, EDGE_KIND_NORMAL)

/**
 * Convenience macro for normal out edges.
 */
#define foreach_out_edge_safe(irn, edge, tmp)  foreach_out_edge_kind_safe(irn, edge, tmp, EDGE_KIND_NORMAL)

/**
 * A convenience iteration macro for all control flow edges.
 */
#define foreach_block_succ(bl, edge)           foreach_out_edge_kind(bl, edge, EDGE_KIND_BLOCK)

/*
 * Get the source node of an edge.
 * @param edge The edge.
 * @return The source node of that edge.
 */
FIRM_API ir_node *get_edge_src_irn(const ir_edge_t *edge);

/**
 * Get the position of an edge.
 * @param edge The edge.
 * @return The position in the in array of that edges source.
 */
FIRM_API int get_edge_src_pos(const ir_edge_t *edge);

/**
 * Get the edge object of an outgoing edge at a node.
 * @param  irg  The graph, the node is in.
 * @param  irn  The node at which the edge originates.
 * @param  pos  The position of the edge.
 * @param  kind The kind of the edge.
 * @return      The corresponding edge object or NULL,
 *              if no such edge exists.
 */
FIRM_API const ir_edge_t *get_irn_edge_kind(ir_graph *irg, const ir_node *irn,
                                            int pos, ir_edge_kind_t kind);

/**
 * Get the number of registered out edges for a specific kind.
 * @param irn The node.
 * @param kind The kind.
 */
FIRM_API int get_irn_n_edges_kind(const ir_node *irn, ir_edge_kind_t kind);

/**
 * Check, if the out edges are activated.
 *
 * @param irg   The graph.
 * @param kind  The edge kind.
 *
 * @return 1, if the edges are present for the given irg, 0 if not.
 */
FIRM_API int edges_activated_kind(const ir_graph *irg, ir_edge_kind_t kind);

/**
 * Activate the edges for an irg.
 *
 * @param irg   The graph to activate the edges for.
 * @param kind  The edge kind.
 */
FIRM_API void edges_activate_kind(ir_graph *irg, ir_edge_kind_t kind);

/**
 * Deactivate the edges for an irg.
 *
 * @param irg   The graph.
 * @param kind  The edge kind.
 */
FIRM_API void edges_deactivate_kind(ir_graph *irg, ir_edge_kind_t kind);

/**
 * Reroute edges of a specified kind from an old node to
 * a new one.
 *
 * @param old   the old node
 * @param nw    the new node
 * @param kind  the edge kind
 * @param irg   the graph on which the rerouting occurs
 */
FIRM_API void edges_reroute_kind(ir_node *old, ir_node *nw, ir_edge_kind_t kind,
                                 ir_graph *irg);

/**
 * Verifies the out edges of graph @p irg.
 * @return 1 if a problem was found, 0 otherwise
 */
FIRM_API int edges_verify(ir_graph *irg);

/**
 * veriy a certrain kind of out edges of graph @p irg.
 * @returns 1 if a problem was found, 0 otherwise
 */
FIRM_API int edges_verify_kind(ir_graph *irg, ir_edge_kind_t kind);

/**
 * Set edge verification flag.
 */
FIRM_API void edges_init_dbg(int do_dbg);

/**
 * Creates an ir_graph pass for edges_verify().
 *
 * @param name                the name of this pass or NULL
 * @param assert_on_problem   assert if problems were found
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *irg_verify_edges_pass(const char *name,
                                                unsigned assert_on_problem);

FIRM_API const ir_edge_t *get_irn_edge(ir_graph *irg, const ir_node *src,
                                       int pos);

#define edges_reroute(old, nw, irg)                     edges_reroute_kind(old, nw, EDGE_KIND_NORMAL, irg)
#define edges_activated(irg)                            (edges_activated_kind(irg, EDGE_KIND_NORMAL) && edges_activated_kind(irg, EDGE_KIND_BLOCK))

#ifndef get_irn_n_edges
#define get_irn_n_edges(irn)                            get_irn_n_edges_kind(irn, EDGE_KIND_NORMAL)
#endif

#ifndef get_irn_out_edge_first
#define get_irn_out_edge_first(irn)                     get_irn_out_edge_first_kind(irn, EDGE_KIND_NORMAL)
#endif

#ifndef get_block_succ_first
#define get_block_succ_first(irn)                       get_irn_out_edge_first_kind(irn, EDGE_KIND_BLOCK)
#endif

#ifndef get_block_succ_next
#define get_block_succ_next(irn, last)                  get_irn_out_edge_next(irn, last)
#endif

/**
 * Activates data and block edges for an irg.
 * If the irg phase is phase_backend, Dependence edges are
 * additionally activated.
 *
 * @param irg  The graph to activate the edges for.
 */
FIRM_API void edges_activate(ir_graph *irg);

/**
 * Deactivate data and block edges for an irg.
 * If the irg phase is phase_backend, Dependence edges are
 * additionally deactivated.
 * @param irg  The graph.
 */
FIRM_API void edges_deactivate(ir_graph *irg);

/**
 * Ensure that edges are activated.
 *
 * @param irg  the IR graph
 *
 * @return 0 if edges was deactivated before the call, 1 else
 */
FIRM_API int edges_assure(ir_graph *irg);

/**
 * Ensure that edges of a given kind are activated.
 *
 * @param irg   the IR graph
 * @param kind  the edge kind
 *
 * @return 0 if edges was deactivated before the call, 1 else
 */
FIRM_API int edges_assure_kind(ir_graph *irg, ir_edge_kind_t kind);

FIRM_API void edges_node_deleted(ir_node *irn, ir_graph *irg);

/**
 * Notify normal and block edges.
 */
FIRM_API void edges_notify_edge(ir_node *src, int pos, ir_node *tgt,
                                ir_node *old_tgt, ir_graph *irg);

/**
 * Walks only over Block nodes in the graph. Uses the block visited
 * flag, so that it can be interleaved with another walker.
 *
 * @param block  the start block
 * @param pre    the pre visit function
 * @param post   the post visit function
 * @param env    the environment for the walker
 */
FIRM_API void irg_block_edges_walk(ir_node *block, irg_walk_func *pre,
                                   irg_walk_func *post, void *env);

FIRM_API void irg_walk_edges(ir_node *start, irg_walk_func *pre,
                             irg_walk_func *post, void *env);

/**
 * Reset the user's private data at offset 'offset'
 * The user has to remember his offset and the size of his data!
 * Caution: Using wrong values here can destroy other users private data!
 *
 * @param irg     the IR graph to operate on
 * @param offset  offset of the private data inside the edge
 * @param size    length of the private data inside the edge
 */
FIRM_API void edges_reset_private_data(ir_graph *irg, int offset,
                                       unsigned size);

#include "end.h"

#endif
