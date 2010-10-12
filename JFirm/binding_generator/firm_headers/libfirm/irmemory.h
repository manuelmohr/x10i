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
 * @brief    Memory disambiguator
 * @author   Michael Beck
 * @date     27.12.2006
 * @version  $Id$
 */
#ifndef FIRM_ANA_IRMEMORY_H
#define FIRM_ANA_IRMEMORY_H

#include "firm_types.h"
#include "begin.h"

/** The alias relation of two memory addresses. */
typedef enum {
	ir_no_alias,       /**< No alias. */
	ir_may_alias,      /**< Unknown state, may alias. */
	ir_sure_alias      /**< Sure alias. */
} ir_alias_relation;

/** The state of the entity usage flags. */
typedef enum {
	ir_entity_usage_not_computed,
	ir_entity_usage_computed
} ir_entity_usage_computed_state;

/** Possible options for the memory disambiguator. */
typedef enum {
	aa_opt_no_opt               = 0,  /**< no options: most conservative */
	aa_opt_type_based           = 1,  /**< use type based alias analysis: strict typed source language */
	aa_opt_byte_type_may_alias  = 2,  /**< if type based analysis is enabled: bytes types may alias other types */
	aa_opt_no_alias_args        = 4,  /**< arguments do not alias each other but may alias global storage */
	aa_opt_no_alias_args_global = 8,  /**< arguments do not alias global storage */
	aa_opt_no_alias             = 16, /**< two addresses NEVER alias, use with CAUTION (gcc -fno-alias) */
	aa_opt_inherited            = 128 /**< only for implementation: options from a graph are inherited from global */
} ir_disambuigator_options;

/**
 * Classify storage locations.
 * Except ir_sc_pointer they are all disjoint.
 * ir_sc_pointer potentially aliases all classes which don't have a
 * NOTTAKEN modifier.
 */
typedef enum {
	ir_sc_pointer           = 0x0,  /**< generic pointer, may be anything */
	ir_sc_globalvar         = 0x1,  /**< an address of a global variable */
	ir_sc_localvar          = 0x2,  /**< an address of a local variable or method argument */
	ir_sc_tls               = 0x3,  /**< an address of a thread local storage variable */
	ir_sc_malloced          = 0x4,  /**< an allocated heap address */
	ir_sc_globaladdr        = 0x5,  /**< a constant address of something */

	ir_sc_modifier_nottaken = 0x80, /**< if set, the address of the variable was not taken */
	ir_sc_modifier_argument = 0x40, /**< if set pointer was a function argument */
	ir_sc_modifiers         = ir_sc_modifier_nottaken | ir_sc_modifier_argument
} ir_storage_class_class_t;

/** Get the base storage class (ignore modifier) */
#define GET_BASE_SC(x) ((x) & ~ir_sc_modifiers)

/**
 * A source language specific memory disambiguator function.
 * Called by get_alias_relation().
 */
typedef ir_alias_relation (*DISAMBIGUATOR_FUNC)(
	const ir_graph *irg,
	const ir_node *adr1, const ir_mode *mode1,
	const ir_node *adr2, const ir_mode *mode2);

/**
 * Classify a base pointer.
 *
 * @param irg  the graph of the pointer
 * @param irn  the node representing the base address
 * @param ent  the base entity of the base address iff any
 */
FIRM_API ir_storage_class_class_t classify_pointer(const ir_graph *irg,
                                                   const ir_node *irn,
                                                   const ir_entity *ent);

/**
 * Returns a human readable name for an alias relation.
 */
FIRM_API const char *get_ir_alias_relation_name(ir_alias_relation rel);

/**
 * Determine the alias relation between two addresses.
 *
 * @param irg     The current graph.
 * @param adr1    The first address.
 * @param mode1   The mode of the first memory access.
 * @param adr2    The second address.
 * @param mode2   The mode of the second memory access.
 *
 * The memory disambiguator tries to determine the alias state between
 * two memory addresses. The following rules are used:
 *
 * - different variable from the same segment never alias (R1 a)
 * - variables from different segments never alias when:
 *   - a global variable and a local one never alias (R1 b)
 *   - a global variable and a TLS one never alias (R1 c)
 *   - a local variable and a TLS one never alias (R1 d)
 *   - a local variable and a parameter never alias (R1 e)
 *   - a global variable and the result of a malloc routine never alias (R1 f)
 *   - a local variable and the result of a malloc routine never alias (R1 g)
 *   - a TLS variable and the result of a malloc routine never alias (R1 h)
 *   - a parameter and the result of a malloc routine (obtained in the
 *     same routine as the parameter) never alias (R1 i)
 * - two different variables never alias (R2)
 * - if one is a variable whose address has never been taken
 *   there is no alias (R3)
 * - if two memory addresses have the same base and their offsets
 *   do not describe overlapping regions there is no alias (R4)
 * - if opt_strong_typed is set and both addresses describe entities,
 *   different types never alias (R5)
 *
 * If none of these rules apply, the points-to framework must be
 * interrogated to detect the alias relation.
 */
FIRM_API ir_alias_relation get_alias_relation(
	const ir_graph *irg,
	const ir_node *adr1, const ir_mode *mode1,
	const ir_node *adr2, const ir_mode *mode2);

/**
 * Set a source language specific memory disambiguator function.
 *
 * @param func  The callback.
 */
FIRM_API void set_language_memory_disambiguator(DISAMBIGUATOR_FUNC func);

/**
 * Initialize the relation cache.
 */
FIRM_API void mem_disambig_init(void);

/*
 * Determine the alias relation between two addresses and
 * cache the result.
 *
 * @param irg     The current graph.
 * @param adr1    The first address.
 * @param mode1   The mode of the first memory access.
 * @param adr2    The second address.
 * @param mode2   The mode of the second memory access.
 *
 * @see get_alias_relation()
 */
FIRM_API ir_alias_relation get_alias_relation_ex(
	const ir_graph *irg,
	const ir_node *adr1, const ir_mode *mode1,
	const ir_node *adr2, const ir_mode *mode2);

/**
 * Free the relation cache.
 */
FIRM_API void mem_disambig_term(void);

FIRM_API ir_entity_usage_computed_state get_irg_entity_usage_state(const ir_graph *irg);

FIRM_API void set_irg_entity_usage_state(ir_graph *irg,
                                         ir_entity_usage_computed_state state);

/**
 * Assure that the entity usage flags have been computed for the given graph.
 *
 * This is an intraprocedural analysis that computes the entity usage state
 * for all local variables.
 *
 * Note that this is a conservative estimation that by no Firm transformation
 * can be invalidated, so it's only recomputed if manually triggered by calling
 * set_irg_entity_usage_state(irg, ir_entity_usage_not_computed).
 * Even then the information is not cleaned from the variables, call
 * assure_irg_entity_usage_computed() again for recomputation.
 */
FIRM_API void assure_irg_entity_usage_computed(ir_graph *irg);

/**
 * Returns the current address taken state of the globals.
 */
FIRM_API ir_entity_usage_computed_state get_irp_globals_entity_usage_state(void);

/**
 * Sets the current address taken state of the globals.
 *
 * @param state  the new state
 */
FIRM_API void set_irp_globals_entity_usage_state(ir_entity_usage_computed_state state);

/**
 * Assure that the address taken flag is computed for the global and TLS entities (variables).
 *
 * This is an interprocedural analysis that computes the address_taken state
 * for all global and TLS variables.
 *
 * Note that this is a conservative estimation that by no Firm transformation
 * can be invalidated, so it's only recomputed if manually triggered by calling
 * set_irp_globals_entity_usage_state(ir_entity_usage_not_computed).
 * Even then the information is not cleaned from the variables, call
 * assure_irp_globals_entity_usage_computed() again for recomputation.
 */
FIRM_API void assure_irp_globals_entity_usage_computed(void);

/**
 * Get the memory disambiguator options for a graph.
 *
 * @param irg  the graph
 */
FIRM_API unsigned get_irg_memory_disambiguator_options(const ir_graph *irg);

/**
 * Set the memory disambiguator options for a graph.
 *
 * @param irg      the graph
 * @param options  a set of options
 */
FIRM_API void set_irg_memory_disambiguator_options(ir_graph *irg,
                                                   unsigned options);

/**
 * Set the global disambiguator options for all graphs not having local options.
 *
 * @param options  a set of options
 */
FIRM_API void set_irp_memory_disambiguator_options(unsigned options);

/**
 * Mark all private methods, i.e. those of which all call sites are known.
 * We use a very convervative estimation yet: If the address of a method is
 * never taken AND its visibility is visibility_local, then it's private.
 */
FIRM_API void mark_private_methods(void);

/**
 * Creates an ir_prog pass for mark_private_methods().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *mark_private_methods_pass(const char *name);

#include "end.h"

#endif
