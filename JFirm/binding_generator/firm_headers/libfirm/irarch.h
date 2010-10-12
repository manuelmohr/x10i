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
 * @brief  Some machine dependent optimizations.
 * @date   1.10.2004
 * @author Sebastian Hack
 * @version $Id$
 */
#ifndef FIRM_IR_IRARCH_H
#define FIRM_IR_IRARCH_H

#include "firm_types.h"
#include "begin.h"

/**
 * The Multiplication replacement can consist of the following instructions.
 */
typedef enum instr {
	LEA,   /**< the LEA instruction */
	SHIFT, /**< the SHIFT instruction */
	SUB,   /**< the SUB instruction */
	ADD,   /**< the ADD instruction */
	ZERO,  /**< creates a ZERO constant */
	MUL,   /**< the original MUL instruction */
	ROOT   /**< the ROOT value that is multiplied */
} insn_kind;

/**
 * A Callback for evaluating the costs of an instruction.
 *
 * @param kind   the instruction
 * @param tv     for MUL instruction, the multiplication constant
 *
 * @return the costs of this instruction
 */
typedef int (*evaluate_costs_func)(insn_kind kind, tarval *tv);

/**
 * A parameter structure that drives the machine dependent Firm
 * optimizations.
 */
struct ir_settings_arch_dep_t {
	/* Mul optimization */
	unsigned also_use_subs : 1;    /**< Use also Subs when resolving Muls to shifts */
	unsigned maximum_shifts;            /**< The maximum number of shifts that shall be inserted for a mul. */
	unsigned highest_shift_amount; /**< The highest shift amount you want to
	                                    tolerate. Muls which would require a higher
	                                    shift constant are left. */
	evaluate_costs_func evaluate;  /**< Evaluate the costs of a generated instruction. */

	/* Div/Mod optimization */
	unsigned allow_mulhs   : 1;    /**< Use the Mulhs operation for division by constant */
	unsigned allow_mulhu   : 1;    /**< Use the Mulhu operation for division by constant */
	unsigned max_bits_for_mulh;         /**< Maximum number of bits the Mulh operation can take.
	                                    Modes with higher amount of bits will use Mulh */
};

/**
 * A factory function, that provides architecture parameters for
 * machine dependent optimizations.
 */
typedef const ir_settings_arch_dep_t *(*arch_dep_params_factory_t)(void);

/**
 * A default parameter factory for testing purposes.
 */
FIRM_API const ir_settings_arch_dep_t *arch_dep_default_factory(void);

/**
 * Optimization flags.
 */
typedef enum {
	arch_dep_none         = 0,
	arch_dep_mul_to_shift = 1,  /**< optimize Mul into Shift/Add/Sub */
	arch_dep_div_by_const = 2,  /**< optimize Div into Shift/Add/Mulh */
	arch_dep_mod_by_const = 4   /**< optimize Mod into Shift/Add/Mulh */
} arch_dep_opts_t;

/**
 * Initialize the machine dependent optimizations.
 * @param factory   A factory that delivers parameters for these
 *                  optimizations. If NULL is passed, or this method
 *                  is not called, the machine dependent optimizations
 *                  are not enabled at all.
 */
FIRM_API void arch_dep_init(arch_dep_params_factory_t factory);

/**
 * Set the optimizations that shall be applied.
 * @param opts An optimization bit mask.
 */
FIRM_API void arch_dep_set_opts(arch_dep_opts_t opts);

/**
 * Replace Muls with Lea/Shifts/Add/Subs if these
 * have smaller costs than the original multiplication.
 *
 * @param irn       The Firm node to inspect.
 * @return          A replacement expression for irn.
 */
FIRM_API ir_node *arch_dep_replace_mul_with_shifts(ir_node *irn);

/**
 * Replace Divs with Shifts and Add/Subs and Mulh.
 * This function is driven by the 3 parameters:
 * - allow_mulhu
 * - allow_mulhs
 * - max_bits_for_mulh
 *
 * If irn is a Div with a Const, the constant is inspected if it meets the
 * requirements of the variables stated above. If a Shl/Add/Sub/Mulh
 * sequence can be generated that meets these requirements, this expression
 * is returned. In each other case irn is returned unmodified.
 *
 * @param irn       The Firm node to inspect.
 * @return          A replacement expression for irn.
 */
FIRM_API ir_node *arch_dep_replace_div_by_const(ir_node *irn);

/**
 * Replace Mods with Shifts and Add/Subs and Mulh.
 * This function is driven by the 3 parameters:
 * - allow_mulhu
 * - allow_mulhs
 * - max_bits_for_mulh
 *
 * If irn is a Mod with a Const, the constant is inspected if it meets the
 * requirements of the variables stated above. If a Shl/Add/Sub/Mulh
 * sequence can be generated that meets these requirements, this expression
 * is returned. In each other case irn is returned unmodified.
 *
 * @param irn       The Firm node to inspect.
 * @return          A replacement expression for irn.
 */
FIRM_API ir_node *arch_dep_replace_mod_by_const(ir_node *irn);

/**
 * Replace DivMods with Shifts and Add/Subs and Mulh.
 * This function is driven by the 3 parameters:
 * - allow_mulhu
 * - allow_mulhs
 * - max_bits_for_mulh
 *
 * If irn is a DivMod with a Const, the constant is inspected if it meets the
 * requirements of the variables stated above. If a Shl/Add/Sub/Mulh
 * sequence can be generated that meets these requirements, this expression
 * is returned. In each other case irn is returned unmodified.
 *
 * @param div       After call contains the Firm node div result or NULL.
 * @param mod       After call contains the Firm node mod result or NULL.
 * @param irn       The Firm node to inspect.
 */
FIRM_API void arch_dep_replace_divmod_by_const(ir_node **div, ir_node **mod,
                                               ir_node *irn);

#include "end.h"

#endif
