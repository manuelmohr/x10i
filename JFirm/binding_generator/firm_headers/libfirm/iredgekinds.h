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
 * @brief  Declares different kind of edges between nodes
 * @date   29.08.2006
 * @author Sebastian Hack
 */
#ifndef FIRM_IR_IREDGEKINDS_H
#define FIRM_IR_IREDGEKINDS_H

#include "begin.h"

/** Supported Edge kinds. */
enum _ir_edge_kind_t {
	EDGE_KIND_NORMAL,  /**< Normal data flow edges. */
	EDGE_KIND_BLOCK,   /**< Block to Block control flow edges. */
	EDGE_KIND_DEP,     /**< Dependency edges. */
	EDGE_KIND_LAST
};

typedef enum _ir_edge_kind_t ir_edge_kind_t;

#include "end.h"

#endif
