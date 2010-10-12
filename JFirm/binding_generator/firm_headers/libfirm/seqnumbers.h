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
 * @brief    Implements simple sequence numbers for Firm debug info.
 * @author   Michael Beck
 * @date     2005
 * @version  $Id$
 * @brief
 *  Sequence numbers for Firm.
 *
 *  A sequence number is an unique number representing a filename
 *  and a line number. The number 0 represents empty information.
 *  This module is an optional "snap-in" for the Firm debug info.
 *  In simple cases it should be possible to use sequence numbers
 *  as dbg_info.
 */
#ifndef FIRM_DEBUG_SEQNUMBERS_H
#define FIRM_DEBUG_SEQNUMBERS_H

#include "ident.h"

#include "begin.h"

/**
 * @typedef seqno_t
 *
 * An opaque type for a sequence number.
 */

/**
 * Create a new sequence number from a filename and a line number.
 *
 * @param filename  a file name
 * @param lineno    a line number
 *
 * @return  a sequence number for this position.
 */
FIRM_API seqno_t firm_seqno_enter(const char *filename, unsigned lineno);

/**
 * Create a new sequence number from a filename ident and a line number.
 *
 * @param filename  an ident
 * @param lineno    a line number
 *
 * @return  a sequence number for this position.
 */
FIRM_API seqno_t firm_seqno_enter_id(ident *filename, unsigned lineno);

/**
 * Retrieve filename and line number from a sequence number.
 *
 * @param seqno   a sequence number
 * @param lineno  after return contains the line number of this position
 *
 * @return  the file name of this position.
 */
FIRM_API const char *firm_seqno_retrieve(seqno_t seqno, unsigned *lineno);

/**
 * Creates the sequence number pool.
 * Is not called by init_firm(), because the sequence number
 * support is optional. Call firm_seqno_init() after init_firm()
 * if sequence numbers should be used.
 */
FIRM_API void firm_seqno_init(void);

/**
 * Terminates the sequence number pool.
 * Sequence numbers cannot be resolved anymore.
 * Call this function to terminate the sequence
 * pool.
 */
FIRM_API void firm_seqno_term(void);

#include "end.h"

#endif
