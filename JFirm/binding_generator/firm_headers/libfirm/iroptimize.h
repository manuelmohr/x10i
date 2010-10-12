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
 * @brief   Available Optimisations of libFirm.
 * @version $Id$
 */
#ifndef FIRM_IROPTIMIZE_H
#define FIRM_IROPTIMIZE_H

#include "firm_types.h"
#include "begin.h"

/**
 * Control flow optimization.
 *
 * Removes empty blocks doing if simplifications and loop simplifications.
 * A block is empty if it contains only a Jmp node and Phi nodes.
 * Merges single entry single exit blocks with their predecessor
 * and propagates dead control flow by calling equivalent_node().
 * Independent of compiler flag it removes Tuples from cf edges,
 * Bad predecessors from Blocks and Phis, and unnecessary predecessors of End.
 * Destroys backedge information.
 *
 * @bug Chokes on Id nodes if called in a certain order with other
 *      optimizations.  Call local_optimize_graph() before to remove
 *      Ids.
 */
FIRM_API void optimize_cf(ir_graph *irg);

/**
 * Creates an ir_graph pass for optimize_cf().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *optimize_cf_pass(const char *name);

/**
 * Perform path-sensitive jump threading on the given graph.
 *
 * @param irg  the graph
 */
FIRM_API void opt_jumpthreading(ir_graph* irg);

/**
 * Creates an ir_graph pass for opt_jumpthreading().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_jumpthreading_pass(const char *name);

/**
 * Creates an ir_graph pass for opt_loopunroll().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_loopunroll_pass(const char *name);


/**
 * Try to simplify boolean expression in the given ir graph.
 * eg. x < 5 && x < 6 becomes x < 5
 *
 * @param irg  the graph
 */
FIRM_API void opt_bool(ir_graph *irg);

/**
 * Creates an ir_graph pass for opt_bool().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_bool_pass(const char *name);

/**
 * Try to reduce the number of conv nodes in the given ir graph.
 *
 * @param irg  the graph
 *
 * @return non-zero if the optimization could be applied, 0 else
 */
FIRM_API int conv_opt(ir_graph *irg);

/**
 * Creates an ir_graph pass for conv_opt().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *conv_opt_pass(const char *name);

/**
 * Do the scalar replacement optimization.
 * Make a date flow analyze and split the
 * data flow edges.
 *
 * @param irg  the graph which should be optimized
 */
FIRM_API void data_flow_scalar_replacement_opt(ir_graph *irg);

/**
 * A callback that checks whether a entity is an allocation
 * routine.
 */
typedef int (*check_alloc_entity_func)(ir_entity *ent);

/**
 * Do simple and fast escape analysis for one graph.
 *
 * @param irg       the graph
 * @param callback  a callback function to check whether a
 *                  given entity is a allocation call
 */
FIRM_API void escape_enalysis_irg(ir_graph *irg,
                                  check_alloc_entity_func callback);

/**
 * Do simple and fast escape analysis for all graphs.
 *
 * This optimization implements a simple and fast but inexact
 * escape analysis. Some addresses might be marked as 'escaped' even
 * if they are not.
 * The advantage is a low memory footprint and fast speed.
 *
 * @param run_scalar_replace  if this flag in non-zero, scalar
 *                            replacement optimization is run on graphs with removed
 *                            allocation
 * @param callback            a callback function to check whether a
 *                            given entity is a allocation call
 *
 * This optimization removes allocation which are not used (rare) and replace
 * allocation that can be proved dead at the end of the graph which stack variables.
 *
 * The creation of stack variable allows scalar replacement to be run only
 * on those graphs that have been changed.
 *
 * This is most effective on Java where no other stack variables exists.
 */
FIRM_API void escape_analysis(int run_scalar_replace,
                              check_alloc_entity_func callback);

/**
 * Optimize function calls by handling const functions.
 *
 * This optimization first detects all "const functions", i.e.,
 * IR graphs that neither read nor write memory (and hence did
 * not create exceptions, as these use memory in Firm).
 *
 * The result of calls to such functions depends only on its
 * arguments, hence those calls are no more pinned.
 *
 * This is a rather strong criteria, so do not expect that a
 * lot of functions will be found. Moreover, all of them might
 * already be inlined if inlining is activated.
 * Anyway, it might be good for handling builtin's or pseudo-graphs,
 * even if the later read/write memory (but we know how).
 *
 * This optimizations read the irg_const_function property of
 * entities and and sets the irg_const_function property of
 * graphs.
 *
 * If callee information is valid, we also optimize polymorphic Calls.
 *
 * @param force_run  if non-zero, an optimization run is started even
 *                   if no const function graph was detected.
 *                   Else calls are only optimized if at least one
 *                   const function graph was detected.
 * @param callback   a callback function to check whether a
 *                   given entity is a allocation call
 *
 * If the frontend created external entities with the irg_const_function
 * property set, the force_run parameter should be set, else
 * should be unset.
 *
 * @note This optimization destroys the link fields of nodes.
 */
FIRM_API void optimize_funccalls(int force_run,
                                 check_alloc_entity_func callback);

/**
 * Creates an ir_prog pass for optimize_funccalls().
 *
 * @param name       the name of this pass or NULL
 * @param force_run  if non-zero, an optimization run is started even
 *                   if no const function graph was detected.
 *                   Else calls are only optimized if at least one
 *                   const function graph was detected.
 * @param callback   a callback function to check whether a
 *                   given entity is a allocation call
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *optimize_funccalls_pass(const char *name,
                                                 int force_run,
                                                 check_alloc_entity_func callback);

/**
 * Does Partial Redundancy Elimination combined with
 * Global Value Numbering.
 * Can be used to replace place_code() completely.
 *
 * Based on VanDrunen and Hosking 2004.
 *
 * @param irg  the graph
 */
FIRM_API void do_gvn_pre(ir_graph *irg);

/**
 * Creates an ir_graph pass for do_gvn_pre().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *do_gvn_pre_pass(const char *name);

/**
 * This function is called to evaluate, if a
 * mux(@p sel, @p mux_false, @p mux_true) should be built for the current
 * architecture.
 * If it returns non-zero, a mux is created, else the code
 * is not modified.
 * @param sel        A selector of a Cond.
 * @param phi_list   phi node to be converted
 * @param i          First data predecessor involved in if conversion
 * @param j          Second data predecessor involved in if conversion
 */
typedef int (*arch_allow_ifconv_func)(ir_node *sel, ir_node *mux_false,
                                      ir_node *mux_true);

/**
 * The parameters structure.
 */
struct ir_settings_if_conv_t {
	int                 max_depth;       /**< The maximum depth up to which expressions
	                                       are examined when it has to be decided if they
	                                       can be placed into another block. */
	arch_allow_ifconv_func allow_ifconv; /**< Evaluator function, if not set all possible Psi
	                                       nodes will be created. */
};

/**
 * Perform If conversion on a graph.
 *
 * @param irg The graph.
 * @param params The parameters for the if conversion.
 *
 * Cannot handle blocks with Bad control predecessors, so call it after control
 * flow optimization.
 */
FIRM_API void opt_if_conv(ir_graph *irg, const ir_settings_if_conv_t *params);

/**
 * Creates an ir_graph pass for opt_if_conv().
 *
 * @param name     the name of this pass or NULL
 * @param params   The parameters for the if conversion.
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_if_conv_pass(
	const char *name, const ir_settings_if_conv_t *params);

/**
 * Tries to reduce dependencies for memory nodes where possible by parllelizing
 * them and synchronising with Sync nodes
 * @param irg   the graph where memory operations should be parallelised
 */
FIRM_API void opt_parallelize_mem(ir_graph *irg);

/**
 * Creates an ir_graph pass for opt_sync().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_parallelize_mem_pass(const char *name);

/*
 * Check if we can replace the load by a given const from
 * the const code irg.
 *
 * @param load   the load to replace
 * @param c      the constant
 *
 * @return in the modes match or can be transformed using a reinterpret cast
 *         returns a copy of the constant (possibly Conv'ed) on the
 *         current_ir_graph
 */
FIRM_API ir_node *can_replace_load_by_const(const ir_node *load, ir_node *c);

/**
 * Load/Store optimization.
 *
 * Removes redundant non-volatile Loads and Stores.
 * May introduce Bad nodes if exceptional control flow
 * is removed. The following cases are optimized:
 *
 * Load without result: A Load which has only a memory use
 *   is removed.
 *
 * Load after Store: A Load after a Store is removed, if
 *   the Load doesn't have an exception handler OR is in
 *   the same block as the Store.
 *
 * Load after Load: A Load after a Load is removed, if the
 *   Load doesn't have an exception handler OR is in the
 *   same block as the previous Load.
 *
 * Store before Store: A Store immediately before another
 *   Store in the same block is removed, if the Store doesn't
 *   have an exception handler.
 *
 * Store after Load: A Store after a Load is removed, if the
 *   Store doesn't have an exception handler.
 *
 * @return non-zero if the optimization could be applied, 0 else
 */
FIRM_API int optimize_load_store(ir_graph *irg);

/**
 * Creates an ir_graph pass for optimize_load_store().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *optimize_load_store_pass(const char *name);

/**
 * New experimental alternative to optimize_load_store.
 * Based on a dataflow analysis, so load/stores are moved out of loops
 * where possible
 */
FIRM_API int opt_ldst(ir_graph *irg);

/**
 * Creates an ir_graph pass for opt_ldst().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_ldst_pass(const char *name);

/**
 * Optimize loops by peeling or unrolling them if beneficial.
 *
 * @param irg  The graph whose loops will be processed
 *
 * This function did not change the graph, only it's frame type.
 * The layout state of the frame type will be set to layout_undefined
 * if entities were removed.
 */
FIRM_API void loop_optimization(ir_graph *irg);

/**
 * Optimize the frame type of an irg by removing
 * never touched entities.
 *
 * @param irg  The graph whose frame type will be optimized
 *
 * This function did not change the graph, only it's frame type.
 * The layout state of the frame type will be set to layout_undefined
 * if entities were removed.
 */
FIRM_API void opt_frame_irg(ir_graph *irg);

/**
 * Creates an ir_graph pass for opt_frame_irg().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_frame_irg_pass(const char *name);

/** Possible flags for the Operator Scalar Replacement. */
typedef enum osr_flags {
	osr_flag_none               = 0,  /**< no additional flags */
	osr_flag_lftr_with_ov_check = 1,  /**< do linear function test replacement
	                                       only if no overflow can occur. */
	osr_flag_ignore_x86_shift   = 2,  /**< ignore Multiplications by 2, 4, 8 */
	osr_flag_keep_reg_pressure  = 4   /**< do NOT increase register pressure by introducing new
	                                       induction variables. */
} osr_flags;

/* FirmJNI cannot handle identical enum values... */

/** default setting */
#define osr_flag_default osr_flag_lftr_with_ov_check

/**
 * Do the Operator Scalar Replacement optimization and linear
 * function test replacement for loop control.
 * Can be switched off using the set_opt_strength_red() flag.
 * In that case, only remove_phi_cycles() is executed.
 *
 * @param irg    the graph which should be optimized
 * @param flags  set of osr_flags
 *
 * The linear function replacement test is controlled by the flags.
 * If the osr_flag_lftr_with_ov_check is set, the replacement is only
 * done if do overflow can occur.
 * Otherwise it is ALWAYS done which might be insecure.
 *
 * For instance:
 *
 * for (i = 0; i < 100; ++i)
 *
 * might be replaced by
 *
 * for (i = 0; i < 400; i += 4)
 *
 * But
 *
 * for (i = 0; i < 0x7FFFFFFF; ++i)
 *
 * will not be replaced by
 *
 * for (i = 0; i < 0xFFFFFFFC; i += 4)
 *
 * because of overflow.
 *
 * More bad cases:
 *
 * for (i = 0; i <= 0xF; ++i)
 *
 * will NOT be transformed into
 *
 * for (i = 0xFFFFFFF0; i <= 0xFFFFFFFF; ++i)
 *
 * although here is no direct overflow. The OV occurs when the ++i
 * is executed (and would created an endless loop here!).
 *
 * For the same reason, a loop
 *
 * for (i = 0; i <= 9; i += x)
 *
 * will NOT be transformed because we cannot estimate whether an overflow
 * might happen adding x.
 *
 * Note that i < a + 400 is also not possible with the current implementation
 * although this might be allowed by other compilers...
 *
 * Note further that tests for equality can be handled some simpler (but are not
 * implemented yet).
 *
 * This algorithm destroys the link field of nodes.
 */
FIRM_API void opt_osr(ir_graph *irg, unsigned flags);

/**
 * Creates an ir_graph pass for remove_phi_cycles().
 *
 * @param name     the name of this pass or NULL
 * @param flags    set of osr_flags
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_osr_pass(const char *name, unsigned flags);

/**
 * Removes useless Phi cycles, i.e cycles of Phi nodes with only one
 * non-Phi node.
 * This is automatically done in opt_osr(), so there is no need to call it
 * additionally.
 *
 * @param irg    the graph which should be optimized
 *
 * This algorithm destroys the link field of nodes.
 */
FIRM_API void remove_phi_cycles(ir_graph *irg);

/**
 * Creates an ir_graph pass for remove_phi_cycles().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *remove_phi_cycles_pass(const char *name);


/** A default threshold. */
#define DEFAULT_CLONE_THRESHOLD 20

/**
 * Do procedure cloning. Evaluate a heuristic weight for every
 * Call(..., Const, ...). If the weight is bigger than threshold,
 * clone the entity and fix the calls.
 *
 * @param threshold   the threshold for cloning
 *
 * The threshold is an estimation of how many instructions are saved
 * when executing a cloned method. If threshold is 0.0, every possible
 * call is cloned.
 */
FIRM_API void proc_cloning(float threshold);

/**
 * Creates an ir_prog pass for proc_cloning().
 *
 * @param name        the name of this pass or NULL
 * @param threshold   the threshold for cloning
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *proc_cloning_pass(const char *name, float threshold);

/**
 * Reassociation.
 *
 * Applies Reassociation rules to integer expressions.
 * Beware: Works only if integer overflow might be ignored, as for C, Java
 * and for address expression.
 * Works only if Constant folding is activated.
 *
 * Uses loop information to detect loop-invariant (ie contant
 * inside the loop) values.
 *
 * See Muchnik 12.3.1 Algebraic Simplification and Reassociation of
 * Addressing Expressions.
 *
 * @return non-zero if the optimization could be applied, 0 else
 */
FIRM_API int optimize_reassociation(ir_graph *irg);

/**
 * Creates an ir_graph pass for optimize_reassociation().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *optimize_reassociation_pass(const char *name);

/**
 * Normalize the Returns of a graph by creating a new End block
 * with One Return(Phi).
 * This is the preferred input for the if-conversion.
 *
 * In pseudocode, it means:
 *
 * if (a)
 *   return b;
 * else
 *   return c;
 *
 * is transformed into
 *
 * if (a)
 *   res = b;
 * else
 *   res = c;
 * return res;
 */
FIRM_API void normalize_one_return(ir_graph *irg);

/**
 * Creates an ir_graph pass for normalize_one_return().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *normalize_one_return_pass(const char *name);

/**
 * Normalize the Returns of a graph by moving
 * the Returns upwards as much as possible.
 * This might be preferred for code generation.
 *
 * In pseudocode, it means:
 *
 * if (a)
 *   res = b;
 * else
 *   res = c;
 * return res;
 *
 * is transformed into
 *
 * if (a)
 *   return b;
 * else
 *   return c;
 */
FIRM_API void normalize_n_returns(ir_graph *irg);

/**
 * Creates an ir_graph pass for normalize_n_returns().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *normalize_n_returns_pass(const char *name);

/**
 * Do the scalar replacement optimization.
 * Replace local compound entities (like structures and arrays)
 * with atomic values if possible. Does not handle classes yet.
 *
 * @param irg  the graph which should be optimized
 *
 * @return non-zero, if at least one entity was replaced
 */
FIRM_API int scalar_replacement_opt(ir_graph *irg);

/**
 * Creates an ir_graph pass for scalar_replacement_opt().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *scalar_replacement_opt_pass(const char *name);

/** Performs strength reduction for the passed graph. */
FIRM_API void reduce_strength(ir_graph *irg);

/**
 * Optimizes tail-recursion calls by converting them into loops.
 * Depends on the flag opt_tail_recursion.
 * Currently supports the following forms:
 *  - return func();
 *  - return x + func();
 *  - return func() - x;
 *  - return x * func();
 *  - return -func();
 *
 * Does not work for Calls that use the exception stuff.
 *
 * @param irg   the graph to be optimized
 *
 * @return non-zero if the optimization could be applied, 0 else
 */
FIRM_API int opt_tail_rec_irg(ir_graph *irg);

/**
 * Creates an ir_graph pass for opt_tail_rec_irg().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *opt_tail_rec_irg_pass(const char *name);

/**
 * Optimize tail-recursion calls for all IR-Graphs.
 * Can currently handle:
 * - direct return value, i.e. return func().
 * - additive return value, i.e. return x +/- func()
 * - multiplicative return value, i.e. return x * func() or return -func()
 *
 * The current implementation must be run before optimize_funccalls(),
 * because it expects the memory edges pointing to calls, which might be
 * removed by optimize_funccalls().
 */
FIRM_API void opt_tail_recursion(void);

/**
 * Creates an ir_prog pass for opt_tail_recursion().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *opt_tail_recursion_pass(const char *name);

/** This is the type for a method, that returns a pointer type to
 *  tp.  This is needed in the normalization. */
typedef ir_type *(*gen_pointer_type_to_func)(ir_type *tp);

/**  Insert Casts so that class type casts conform exactly with the type hierarchy.
 *
 *  Formulated in Java, this achieves the following:
 *
 *  For a class hierarchy
 *    class A {}
 *    class B extends A {}
 *    class C extends B {}
 *  we transforms a cast
 *    (A)new C()
 *  to
 *    (A)((B)new C()).
 *
 *  The algorithm works for Casts with class types, but also for Casts
 *  with all pointer types that point (over several indirections,
 *  i.e. ***A) to a class type.  Normalizes all graphs.  Computes type
 *  information (@see irtypeinfo.h) if not available.
 *  Invalidates trout information as new casts are generated.
 *
 *  @param gppt_fct A function that returns a pointer type that points
 *    to the type given as argument.  If this parameter is NULL, a default
 *    function is used that either uses trout information or performs a O(n)
 *    search to find an existing pointer type.  If it can not find a type,
 *    generates a pointer type with mode_P_mach and suffix "cc_ptr_tp".
 */
FIRM_API void normalize_irp_class_casts(gen_pointer_type_to_func gppt_fct);

/**  Insert Casts so that class type casts conform exactly with the type hierarchy
 *   in given graph.
 *
 *   For more details see normalize_irp_class_casts().
 *
 *  This transformation requires that type information is computed. @see irtypeinfo.h.
 */
FIRM_API void normalize_irg_class_casts(ir_graph *irg,
                                        gen_pointer_type_to_func gppt_fct);

/** Optimize casting between class types.
 *
 *    class A { m(); }
 *    class B extends A { }
 *    class C extends B {}
 *  Performs the following transformations:
 *    C c = (C)(B)(A)(B)new C()  --> C c = (C)(B)newC() --> C c = new C()
 *    (Optimizing downcasts as A a = (A)(B)(new A()) --> A a = new A() can
 *     be suppressed by setting the flag opt_suppress_downcast_optimization.
 *     Downcasting A to B might cause an exception.  It is not clear
 *     whether this is modeled by the Firm Cast node, as it has no exception
 *     outputs.);
 *  If there is inh_m() that overwrites m() in B:
 *    ((A) new B()).m()  --> (new B()).inh_m()
 *  Phi((A)x, (A)y)  --> (A) Phi (x, y)  if (A) is an upcast.
 *
 *  Computes type information if not available. @see irtypeinfo.h.
 *  Typeinformation is valid after optimization.
 *  Invalidates trout information.
 */
FIRM_API void optimize_class_casts(void);

/**
 * CLiff Click's combo algorithm from
 *   "Combining Analyses, combining Optimizations".
 *
 * Does conditional constant propagation, unreachable code elimination and
 * optimistic global value numbering at once.
 *
 * @param irg  the graph to run on
 */
FIRM_API void combo(ir_graph *irg);

/**
 * Creates an ir_graph pass for combo.
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *combo_pass(const char *name);

/**
 * Inlines all small methods at call sites where the called address comes
 * from a SymConst node that references the entity representing the called
 * method.
 *
 * @param irg  the graph
 * @param size maximum function size
 *
 * The size argument is a rough measure for the code size of the method:
 * Methods where the obstack containing the firm graph is smaller than
 * size are inlined.  Further only a limited number of calls are inlined.
 * If the method contains more than 1024 inlineable calls none will be
 * inlined.
 * Inlining is only performed if flags `optimize' and `inlineing' are set.
 * The graph may not be in state phase_building.
 * It is recommended to call local_optimize_graph() after inlining as this
 * function leaves a set of obscure Tuple nodes, e.g. a Proj-Tuple-Jmp
 * combination as control flow operation.
 */
FIRM_API void inline_small_irgs(ir_graph *irg, int size);

/**
 * Creates an ir_graph pass for inline_small_irgs().
 *
 * @param name   the name of this pass or NULL
 * @param size   maximum function size
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *inline_small_irgs_pass(const char *name, int size);

/**
 * Inlineing with a different heuristic than inline_small_irgs().
 *
 * Inlines leave functions.  If inlinening creates new leave
 * function inlines these, too. (If g calls f, and f calls leave h,
 * h is first inlined in f and then f in g.)
 *
 * Then inlines all small functions (this is not recursive).
 *
 * For a heuristic this inlineing uses firm node counts.  It does
 * not count auxiliary nodes as Proj, Tuple, End, Start, Id, Sync.
 * If the ignore_runtime flag is set, calls to functions marked with the
 * mtp_property_runtime property are ignored.
 *
 * @param maxsize         Do not inline any calls if a method has more than
 *                        maxsize firm nodes.  It may reach this limit by
 *                        inlineing.
 * @param leavesize       Inline leave functions if they have less than leavesize
 *                        nodes.
 * @param size            Inline all function smaller than size.
 * @param ignore_runtime  count a function only calling runtime functions as
 *                        leave
 */
FIRM_API void inline_leave_functions(unsigned maxsize, unsigned leavesize,
                                     unsigned size, int ignore_runtime);

/**
 * Creates an ir_prog pass for inline_leave_functions().
 *
 * @param name            the name of this pass or NULL
 * @param maxsize         Do not inline any calls if a method has more than
 *                        maxsize firm nodes.  It may reach this limit by
 *                        inlineing.
 * @param leavesize       Inline leave functions if they have less than leavesize
 *                        nodes.
 * @param size            Inline all function smaller than size.
 * @param ignore_runtime  count a function only calling runtime functions as
 *                        leave
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *inline_leave_functions_pass(const char *name,
		unsigned maxsize, unsigned leavesize, unsigned size,
		int ignore_runtime);

typedef void (*opt_ptr)(ir_graph *irg);

/**
 * Heuristic inliner. Calculates a benefice value for every call and inlines
 * those calls with a value higher than the threshold.
 *
 * @param maxsize             Do not inline any calls if a method has more than
 *                            maxsize firm nodes.  It may reach this limit by
 *                            inlining.
 * @param inline_threshold    inlining threshold
 * @param after_inline_opt    optimizations performed immediately after inlining
 *                            some calls
 */
FIRM_API void inline_functions(unsigned maxsize, int inline_threshold,
                               opt_ptr after_inline_opt);

/**
 * Creates an ir_prog pass for inline_functions().
 *
 * @param name               the name of this pass or NULL
 * @param maxsize            Do not inline any calls if a method has more than
 *                           maxsize firm nodes.  It may reach this limit by
 *                           inlineing.
 * @param inline_threshold   inlining threshold
 * @param after_inline_opt   a function that is called after inlining a
 *                           procedure. You should run fast local optimisations
 *                           here which cleanup the graph before further
 *                           inlining
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *inline_functions_pass(const char *name,
		unsigned maxsize, int inline_threshold, opt_ptr after_inline_opt);

/**
 * Combines congruent blocks into one.
 *
 * @param irg   The IR-graph to optimize.
 *
 * @return non-zero if the graph was transformed
 */
FIRM_API int shape_blocks(ir_graph *irg);

/**
 * Creates an ir_graph pass for shape_blocks().
 *
 * @param name   the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *shape_blocks_pass(const char *name);

/**
 * Perform loop inversion on a given graph.
 * Loop inversion transforms a head controlled loop (like while(...) {} and
 * for(...) {}) into a foot controlled loop (do {} while(...)).
 */
FIRM_API void do_loop_inversion(ir_graph *irg);

/**
 * Perform loop unrolling on a given graph.
 * Loop unrolling multiplies the number loop completely by a number found
 * through a heuristic.
 */
FIRM_API void do_loop_unrolling(ir_graph *irg);

/**
 * Perform loop peeling on a given graph.
 */
FIRM_API void do_loop_peeling(ir_graph *irg);

/**
 * Creates an ir_graph pass for loop inversion.
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *loop_inversion_pass(const char *name);

/**
 * Creates an ir_graph pass for loop unrolling.
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *loop_unroll_pass(const char *name);

/**
 * Creates an ir_graph pass for loop peeling.
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *loop_peeling_pass(const char *name);

typedef ir_type *(*get_Alloc_func)(ir_node *n);
/** Set a new get_Alloc_func and returns the old one. */
FIRM_API get_Alloc_func firm_set_Alloc_func(get_Alloc_func newf);

/**
 * Creates an ir_graph pass for set_vrp_data()
 *
 * @param name The name of this pass or NULL
 *
 * @return the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *set_vrp_pass(const char *name);

/**
 * Removes all entities which are unused.
 *
 * Unused entities have ir_visibility_local and are not used directly or
 * indirectly through entities/code visible outside the compilation unit.
 * This is usually conservative than gc_irgs, but does not respect properties
 * of object-oriented programs.
 */
FIRM_API void garbage_collect_entities(void);

/** Pass for garbage_collect_entities */
FIRM_API ir_prog_pass_t *garbage_collect_entities_pass(const char *name);

/**
 * Performs dead node elimination by copying the ir graph to a new obstack.
 *
 *  The major intention of this pass is to free memory occupied by
 *  dead nodes and outdated analyzes information.  Further this
 *  function removes Bad predecessors from Blocks and the corresponding
 *  inputs to Phi nodes.  This opens optimization potential for other
 *  optimizations.  Further this phase reduces dead Block<->Jmp
 *  self-cycles to Bad nodes.
 *
 *  Dead_node_elimination is only performed if options `optimize' and
 *  `opt_dead_node_elimination' are set.  The graph may
 *  not be in state phase_building.  The outs datasturcture is freed,
 *  the outs state set to outs_none.  Backedge information is conserved.
 *  Removes old attributes of nodes.  Sets link field to NULL.
 *  Callee information must be freed (irg_callee_info_none).
 *
 * @param irg  The graph to be optimized.
 */
FIRM_API void dead_node_elimination(ir_graph *irg);

/**
 * Creates an ir_graph pass for dead_node_elimination().
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *dead_node_elimination_pass(const char *name);

/**
 * Inlines a method at the given call site.
 *
 *  Removes the call node and splits the basic block the call node
 *  belongs to.  Inserts a copy of the called graph between these nodes.
 *  Assumes that call is a Call node in current_ir_graph and that
 *  the type in the Call nodes type attribute is the same as the
 *  type of the called graph.
 *  Further it assumes that all Phi nodes in a block of current_ir_graph
 *  are assembled in a "link" list in the link field of the corresponding
 *  block nodes.  Further assumes that all Proj nodes are in a "link" list
 *  in the nodes producing the tuple.  (This is only an optical feature
 *  for the graph.)  Conserves this feature for the old
 *  nodes of the graph.  This precondition can be established by a call to
 *  collect_phisprojs(), see irgmod.h.
 *  As dead_node_elimination this function reduces dead Block<->Jmp
 *  self-cycles to Bad nodes.
 *
 *  Called_graph must be unequal to current_ir_graph.   Will not inline
 *  if they are equal.
 *  Sets visited masterflag in current_ir_graph to the max of the flag in
 *  current and called graph.
 *  Assumes that both, the called and the calling graph are in state
 *  "op_pin_state_pinned".
 *  It is recommended to call local_optimize_graph() after inlining as this
 *  function leaves a set of obscure Tuple nodes, e.g. a Proj-Tuple-Jmp
 *  combination as control flow operation.
 *
 *  @param call          the call node that should be inlined
 *  @param called_graph  the IR-graph that is called at call
 *
 *  @return zero if method could not be inlined (recursion for instance),
 *          non-zero if all went ok
 */
FIRM_API int inline_method(ir_node *call, ir_graph *called_graph);

/**
 * Code Placement.
 *
 * Pins all floating nodes to a block where they
 * will be executed only if needed.   Depends on the flag opt_global_cse.
 * Graph may not be in phase_building.  Does not schedule control dead
 * code.  Uses dominator information which it computes if the irg is not
 * in state dom_consistent.  Destroys the out information as it moves nodes
 * to other blocks.  Optimizes Tuples in Control edges.
 *
 * Call remove_critical_cf_edges() before place_code().  This normalizes
 * the control flow graph so that for all operations a basic block exists
 * where they can be optimally placed.
 */
FIRM_API void place_code(ir_graph *irg);

/**
 * Creates an ir_graph pass for place_code().
 * This pass enables GCSE, runs optimize_graph_df() and finally
 * place_code();
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *place_code_pass(const char *name);

/**
 * Determine information about the values of nodes and perform simplications
 * using this information.  This optimization performs a data-flow analysis to
 * find the minimal fixpoint.
 */
FIRM_API void fixpoint_vrp(ir_graph*);

/**
 * Creates an ir_graph pass for fixpoint_vrp().
 * This pass dDetermines information about the values of nodes
 * and perform simplications using this information.
 * This optimization performs a data-flow analysis to
 * find the minimal fixpoint.
 *
 * @param name     the name of this pass or NULL
 *
 * @return  the newly created ir_graph pass
 */
FIRM_API ir_graph_pass_t *fixpoint_vrp_irg_pass(const char *name);

#include "end.h"

#endif
