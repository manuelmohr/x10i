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
 * @brief   Statistics for Firm.
 * @author  Michael Beck
 * @version $Id$
 */
#ifndef FIRM_STAT_FIRMSTAT_H
#define FIRM_STAT_FIRMSTAT_H

#include "irhooks.h"
#include "begin.h"

/**
 * Statistic options, can be or'ed.
 */
enum firmstat_options_t {
	FIRMSTAT_ENABLED         = 0x00000001,    /**< enable statistics */
	FIRMSTAT_PATTERN_ENABLED = 0x00000002,    /**< enable pattern calculation */
	FIRMSTAT_COUNT_STRONG_OP = 0x00000004,    /**< if set, count Mul/Div/Mod/DivMod by constant */
	FIRMSTAT_COUNT_DAG       = 0x00000008,    /**< if set, count DAG statistics */
	FIRMSTAT_COUNT_DELETED   = 0x00000010,    /**< if set, count deleted graphs */
	FIRMSTAT_COUNT_SELS      = 0x00000020,    /**< if set, count Sel(Sel(..)) differently */
	FIRMSTAT_COUNT_CONSTS    = 0x00000040,    /**< if set, count Const statistics */
	FIRMSTAT_COUNT_EXTBB     = 0x00000080,    /**< if set, count extended Basic Block statistics */
	FIRMSTAT_CSV_OUTPUT      = 0x10000000     /**< CSV output of some mini-statistic */
};

/**
 * Additional flags for statistics.
 */
enum firmstat_optimizations_t {
	FS_OPT_NEUTRAL_0  = HOOK_OPT_LAST,        /**< a op 0 = 0 op a = a */
	FS_OPT_NEUTRAL_1,                         /**< a op 1 = 1 op a = a */
	FS_OPT_ADD_A_A,                           /**< a + a = a * 2 */
	FS_OPT_ADD_A_MINUS_B,                     /**< a + -b = a - b */
	FS_OPT_ADD_SUB,                           /**< (a + x) - x = (a - x) + x */
	FS_OPT_ADD_MUL_A_X_A,                     /**< a * x + a = a * (x + 1) */
	FS_OPT_SUB_0_A,                           /**< 0 - a = -a */
	FS_OPT_MINUS_SUB,                         /**< - (a - b) = b - a */
	FS_OPT_SUB_MINUS,                         /**< a - (-b) = a + b */
	FS_OPT_SUB_MUL_A_X_A,                     /**< a * x - a = a * (x - 1) */
	FS_OPT_SUB_SUB_X_Y_Z,                     /**< (x - y) - z = x - (y + z) */
	FS_OPT_SUB_C_NOT_X,                       /**< c - ~a = a + (c+1) */
	FS_OPT_SUB_TO_ADD,                        /**< (-a) - b = -(a + b), a - (b - c) = a + (c - b), a - (b * C) -> a + (b * -C) */
	FS_OPT_SUB_TO_NOT,                        /**< -1 - x -> ~x on two's complement */
	FS_OPT_SUB_TO_CONV,                       /**< a - NULL = (int)a */
	FS_OPT_MUL_MINUS,                         /**< (-a) * (b - c) -> a * (c - b) */
	FS_OPT_MUL_MINUS_1,                       /**< a * -1 = -a */
	FS_OPT_MINUS_MUL_C,                       /**< (-a) * C = a * (-C) */
	FS_OPT_MUL_MINUS_MINUS,                   /**< (-a) * (-b) = a * b */
	FS_OPT_OR,                                /**< a | a = a | 0 = 0 | a = a */
	FS_OPT_AND,                               /**< a & 0b1...1 = 0b1...1 & a =  a & a = a */
	FS_OPT_TO_EOR,                            /**< (a|b) & ~(a&b) = a^b */
	FS_OPT_EOR_A_A,                           /**< a ^ a = 0 */
	FS_OPT_EOR_A_B_A,                         /**< (a ^ b) ^ a = b */
	FS_OPT_EOR_TO_NOT_BOOL,                   /**< bool ^ 1 = !bool */
	FS_OPT_EOR_TO_NOT,                        /**< x ^ 0b1..1 = ~x, (a ^ b) & b -> ~a & b */
	FS_OPT_NOT_CMP,                           /**< !(a cmp b) = a !cmp b */
	FS_OPT_OR_SHFT_TO_ROTL,                   /**< (x << c) | (x >> (bits - c)) == Rotl(x, c) */
	FS_OPT_REASSOC_SHIFT,                     /**< (x SHF c1) SHF c2 = x SHF (c1+c2) */
	FS_OPT_SHIFT_AND,                         /**< (a SHF c) AND (b SHF c) = (a AND b) SHF c */
	FS_OPT_SHIFT_OR,                          /**< (a SHF c) OR (b SHF c) = (a OR b) SHF c */
	FS_OPT_SHIFT_EOR,                         /**< (a SHF c) XOR (b SHF c) = (a XOR b) SHF c */
	FS_OPT_CONV,                              /**< a Conv could be removed */
	FS_OPT_CAST,                              /**< a Cast could be removed */
	FS_OPT_MIN_MAX_EQ,                        /**< Min(a,a) = Max(a,a) = a */
	FS_OPT_MUX_COMBINE,                       /**< two Mux nodes where combined into one */
	FS_OPT_MUX_CONV,                          /**< MuxI(sel, 1, 0) = (I)sel */
	FS_OPT_MUX_BOOL,                          /**< Muxb(sel, true, false) = sel */
	FS_OPT_MUX_NOT_BOOL,                      /**< Muxb(sel, false, true) = Not(sel) */
	FS_OPT_MUX_OR_BOOL,                       /**< Muxb(sel, true, x) = Or(sel, x) */
	FS_OPT_MUX_ORNOT_BOOL,                    /**< Muxb(sel, x, true) = Or(Not(sel), x) */
	FS_OPT_MUX_AND_BOOL,                      /**< Muxb(sel, x, false) = And(sel, x) */
	FS_OPT_MUX_ANDNOT_BOOL,                   /**< Muxb(sel, false, x) = And(Not(sel), x) */
	FS_OPT_MUX_C,                             /**< Mux(C, f, t) = C ? t : f */
	FS_OPT_MUX_EQ,                            /**< Mux(v, x, x) = x */
	FS_OPT_MUX_TRANSFORM,                     /**< Mux(t ==/!= f, t, f) = f/t, Mux(t ==/!= 0, -t, t) = -t/t */
	FS_OPT_MUX_TO_MIN,                        /**< Mux(a < b, a, b) = Min(a,b) */
	FS_OPT_MUX_TO_MAX,                        /**< Mux(a > b, a, b) = Max(a,b) */
	FS_OPT_MUX_TO_ABS,                        /**< Mux(a > 0, a, -a) = Abs(a) */
	FS_OPT_MUX_TO_BITOP,                      /**< Mux((a & 2^x) ==/!= 0, 2^x, 0) = (a & 2^x) (xor 2^x) */
	FS_OPT_IDEM_UNARY,                        /**< Idempotent unary operation */
	FS_OPT_MINUS_NOT,                         /**< -(~x) = x + 1 */
	FS_OPT_NOT_MINUS_1,                       /**< ~(x - 1) = -x */
	FS_OPT_NOT_PLUS_1,                        /**< ~x + 1 = -x */
	FS_OPT_ADD_X_NOT_X,                       /**< ~x + x = -1 */
	FS_OPT_FP_INV_MUL,                        /**< x / y = x * (1.0/y) */
	FS_OPT_ABS_MINUS_X,                       /**< Abs(-x) = Abs(x) */
	FS_OPT_CONST_PHI,                         /**< Constant evaluation on Phi */
	FS_OPT_PREDICATE,                         /**< Predicate optimization */
	FS_OPT_DEMORGAN,                          /**< optimization using DeMorgan's law */
	FS_OPT_CMP_OP_OP,                         /**< CMP optimization: Cmp(OP(x), OP(y)) = Cmp(x, y) */
	FS_OPT_CMP_OP_C,                          /**< CMP optimization: Cmp(OP(x), c1) = Cmp(x, c2) */
	FS_OPT_CMP_CONV_CONV,                     /**< CMP optimization: Cmp(Conv(x), Conv(y)) = Cmp(x, y) */
	FS_OPT_CMP_CONV,                          /**< CMP optimization: Cmp(Conv(x), Conv(y)) = Cmp(Conv(x), y) */
	FS_OPT_CMP_TO_BOOL,                       /**< CMP optimization: Cmp(x, y) = BoolOP(x, y) */
	FS_OPT_CMP_CNST_MAGN,                     /**< CMP optimization: reduced magnitude of a const */
	FS_OPT_CMP_SHF_TO_AND,                    /**< CMP optimization: transformed shift into And */
	FS_OPT_CMP_MOD_TO_AND,                    /**< CMP optimization: transformed Mod into And */
	FS_OPT_NOP,                               /**< the operation is a NOP */
	FS_OPT_GVN_FOLLOWER,                      /**< GVN-PRE: replaced a follower */
	FS_OPT_GVN_FULLY,                         /**< GVN-PRE: replaced by fully redundant value */
	FS_OPT_GVN_PARTLY,                        /**< GVN-PRE: replaced by partly redundant value */
	FS_OPT_COMBO_CONST,                       /**< Combo: evaluated into Constant */
	FS_OPT_COMBO_CF,                          /**< Combo: removed conditional control flow */
	FS_OPT_COMBO_FOLLOWER,                    /**< Combo: replaced a follower */
	FS_OPT_COMBO_CONGRUENT,                   /**< Combo: replaced by congruent */
	FS_OPT_JUMPTHREADING,                     /**< Jump threading: removed conditional control flow */
	FS_OPT_RTS_ABS,                           /**< RTS optimization: call to abs() replaced */
	FS_OPT_RTS_ALLOCA,                        /**< RTS optimization: call to alloca() replaced */
	FS_OPT_RTS_SQRT,                          /**< RTS optimization: call to sqrt() replaced */
	FS_OPT_RTS_CBRT,                          /**< RTS optimization: call to cbrt() replaced */
	FS_OPT_RTS_POW,                           /**< RTS optimization: call to pow() replaced */
	FS_OPT_RTS_EXP,                           /**< RTS optimization: call to exp() replaced */
	FS_OPT_RTS_LOG,                           /**< RTS optimization: call to log() replaced */
	FS_OPT_RTS_SIN,                           /**< RTS optimization: call to sin() replaced */
	FS_OPT_RTS_COS,                           /**< RTS optimization: call to cos() replaced */
	FS_OPT_RTS_TAN,                           /**< RTS optimization: call to tan() replaced */
	FS_OPT_RTS_ASIN,                          /**< RTS optimization: call to asin() replaced */
	FS_OPT_RTS_ACOS,                          /**< RTS optimization: call to acos() replaced */
	FS_OPT_RTS_ATAN,                          /**< RTS optimization: call to atan() replaced */
	FS_OPT_RTS_SINH,                          /**< RTS optimization: call to sinh() replaced */
	FS_OPT_RTS_COSH,                          /**< RTS optimization: call to cosh() replaced */
	FS_OPT_RTS_TANH,                          /**< RTS optimization: call to tanh() replaced */
	FS_OPT_RTS_SYMMETRIC,                     /**< RTS optimization: call to symmetric function f(-x) replaced by f(x) */
	FS_OPT_RTS_STRCMP,                        /**< RTS optimization: call to strcmp() replaced */
	FS_OPT_RTS_STRNCMP,                       /**< RTS optimization: call to strncmp() replaced */
	FS_OPT_RTS_STRCPY,                        /**< RTS optimization: call to strcpy() replaced */
	FS_OPT_RTS_STRLEN,                        /**< RTS optimization: call to strlen() replaced */
	FS_OPT_RTS_MEMCPY,                        /**< RTS optimization: call to memcpy() replaced */
	FS_OPT_RTS_MEMPCPY,                       /**< RTS optimization: call to mempcpy() replaced */
	FS_OPT_RTS_MEMMOVE,                       /**< RTS optimization: call to memmove() replaced */
	FS_OPT_RTS_MEMSET,                        /**< RTS optimization: call to memset() replaced */
	FS_OPT_RTS_MEMCMP,                        /**< RTS optimization: call to memcmp() replaced */
	FS_BE_IA32_LEA,                           /**< Lea was created */
	FS_BE_IA32_LOAD_LEA,                      /**< Load merged with a Lea */
	FS_BE_IA32_STORE_LEA,                     /**< Store merged with a Lea */
	FS_BE_IA32_AM_S,                          /**< Source address mode node created */
	FS_BE_IA32_AM_D,                          /**< Destination address mode node created */
	FS_BE_IA32_CJMP,                          /**< CJmp created to save a cmp/test */
	FS_BE_IA32_2ADDRCPY,                      /**< Copy created due to 2-Addresscode constraints */
	FS_BE_IA32_SPILL2ST,                      /**< Created Store for a Spill */
	FS_BE_IA32_RELOAD2LD,                     /**< Created Load for a Reload */
	FS_BE_IA32_SUB2NEGADD,                    /**< Created Neg-Add for a Sub due to 2-Addresscode constraints */
	FS_BE_IA32_LEA2ADD,                       /**< Transformed Lea back into Add */
	FS_OPT_MAX
};

/**
 * Dump a snapshot of the statistic values.
 * Never called from libFirm should be called from user.
 *
 * @param fname  base name of the statistic output file
 * @param phase  a phase name. Prefix will be firmstat-\<phase\>-
 */
FIRM_API void stat_dump_snapshot(const char *fname, const char *phase);

/**
 * Creates an ir_prog pass for stat_dump_snapshot().
 *
 * @param name    the name of this pass or NULL
 * @param fname   base name of the statistic output file
 * @param phase   a phase name. Prefix will be firmstat-\<phase\>-
 *
 * @return  the newly created ir_prog pass
 */
FIRM_API ir_prog_pass_t *stat_dump_snapshot_pass(
	const char *name, const char *fname, const char *phase);

/**
 * initialize the statistics module.
 * Should be called directly after ir_init
 *
 * @param enable_options  a bitmask containing the statistic options
 */
FIRM_API void firm_init_stat(unsigned enable_options);

/**
 * terminates the statistics module, frees all memory
 */
FIRM_API void stat_term(void);

/**
 * returns 1 if statistic module is active, 0 otherwise
 */
FIRM_API int stat_is_active(void);

#include "end.h"

#endif
