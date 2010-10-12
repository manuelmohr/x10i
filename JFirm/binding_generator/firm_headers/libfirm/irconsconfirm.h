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
 * @brief    Construction of Confirm nodes
 * @author   Michael Beck
 * @date     6.2005
 * @version  $Id$
 */
#ifndef FIRM_ANA_IRCONSCONFIRM_H
#define FIRM_ANA_IRCONSCONFIRM_H

#include "firm_types.h"
#include "begin.h"

/**
 * Inject Confirm nodes into a graph.
 *
 * @param irg  the graph
 *
 * Confirm nodes carry confirmation information, such as
 * a relation between a value a and another value (or a constant)
 * b.
 *
 * These allows to do some range dependent optimizations for Cmp,
 * Abs, Min, Max nodes as well as bounds checking deletion.
 *
 * The heap analysis might profit also. On the other side, Confirm
 * nodes disturb local optimizations, because patterns are destroyed.
 *
 * It is possible to avoid this by skipping Confirm nodes, but this
 * is not implemented and is not cheap. The same happens with Casts
 * nodes too. The current solution is to remove Confirms at a later
 * pass.
 */
FIRM_API void construct_confirms(ir_graph *irg);

/**
 * Creates an ir_graph pass for construct_confirms().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *construct_confirms_pass(const char *name);

/**
 * Remove all Confirm nodes from a graph.
 *
 * Note that local_optimize() can handle this if
 * the remove Confirm node setting is on (set_opt_remove_Confirm(1)).
 */
FIRM_API void remove_confirms(ir_graph *irg);

/**
 * Creates an ir_graph pass for remove_confirms().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *remove_confirms_pass(const char *name);

#include "end.h"

#endif
