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
 * @brief   Data modes of operations.
 * @author  Martin Trapp, Christian Schaefer, Goetz Lindenmaier, Mathias Heil,
 *          Michael Beck
 * @version $Id$
 * @brief
 *  This module specifies the modes that type the firm nodes.  It defines
 *  a datasturcture that describes a mode and implements constructors and
 *  access routines to this datastructure. Further it defines a set of
 *  predefined modes.
 *
 *  SEE ALSO:
 *    UKA tech report 1999-44 for more information about modes.
 */
#ifndef FIRM_IR_IRMODE_H
#define FIRM_IR_IRMODE_H

#include "firm_types.h"
#include "begin.h"

/* ********** Predefined modes ********** */

/** Helper values for ir_mode_sort. */
enum ir_mode_sort_helper {
	irmsh_is_num   = 0x10, /**< mode represents a number */
	irmsh_is_data  = 0x20, /**< mode represents data (can be carried in registers) */
	irmsh_is_datab = 0x40, /**< mode represents data or is internal boolean */
	irmsh_is_dataM = 0x80, /**< mode represents data or is memory */
};

/**
 * These values represent the different mode classes of value representations.
 * Beware: do not change the order of these values without checking
 * the mode_is
 */
typedef enum ir_mode_sort {
	/* Predefined sorts of modes */
	irms_auxiliary        = 0, /**< Only for Firm use. Not extensible. (irm_T) */
	irms_control_flow     = 1, /**< Marks all control flow modes. Not extensible. (irm_BB, irm_X) */
	irms_memory           = 2 | irmsh_is_dataM, /**< Marks the memory mode.  Not extensible. (irm_M) */

	/** Internal boolean representation.
	     Storing to memory impossible, convert first. (irm_b) */
	irms_internal_boolean = 3 | irmsh_is_datab,

	/* user-extensible sorts of modes */
	/** A mode to represent entities.
	    Restricted int computations can be performed */
	irms_reference        = 4 | irmsh_is_data | irmsh_is_datab | irmsh_is_dataM,
	/** A mode to represent int numbers.
	    Integer computations can be performed. */
	irms_int_number       = 5 | irmsh_is_data | irmsh_is_datab | irmsh_is_dataM | irmsh_is_num,
	/** A mode to represent float numbers.
	    Floating point computations can be performed. */
	irms_float_number     = 6 | irmsh_is_data | irmsh_is_datab | irmsh_is_dataM | irmsh_is_num,
} ir_mode_sort;

/** These values represent the different arithmetic operations possible with a mode.
    Further arithmetics can be defined, e.g., for @@@ modes.
 */
typedef enum ir_mode_arithmetic {
	irma_uninitialized = 0,
	irma_none = 1,              /**< For modes for which no representation is specified.
	                                 These are modes of sort auxiliary, internal_boolean and character. */
	irma_twos_complement = 2,   /**< Values of the mode are represented as two's complement.
                                     Only legal for modes of sort int_number and reference. */
	irma_ones_complement,       /**< Values of the mode are represented  as one's complement.
	                                 Only legal for modes of sort int_number and reference. */
	irma_int_BCD,               /**< Values of the mode are represented as binary coded decimals.
	                                 Only legal for modes of sort int_number and reference. */
	irma_ieee754 = 256,         /**< Values of the mode are represented according to ieee754
                                     floating point standard.  Only legal for modes of sort float_number. */
	irma_float_BCD,             /**< Values of the mode are represented  as binary coded decimals
	                                 according to @@@ which standards??? Only legal for modes of
	                                 sort float_number. */
	irma_max
} ir_mode_arithmetic;

/** Returns the name of the arithmetic type. */
FIRM_API const char *get_mode_arithmetic_name(ir_mode_arithmetic ari);

/* ********** Constructor for user defined modes **************** */
/**
 * Creates a new mode.
 *
 * @param name          the name of the mode to be created
 * @param sort          the ir_mode_sort of the mode to be created
 * @param bit_size      number of bits this mode allocate
 * @param sign          non-zero if this is a signed mode
 * @param arithmetic    arithmetic operations possible with a mode
 * @param modulo_shift  Is ignored for modes other than integer.
 *
 * This function constructs a new mode given by the parameters.
 * If the parameters match an already defined mode, this mode is returned
 * (including the default modes).
 * If the mode is newly allocated, a new unique mode_code is chosen.
 * Also, special value tarvals will be calculated such as null,
 * min, max and can be retrieved using the get_mode_* functions
 *
 * @return
 *   The new mode or NULL on error.
 *
 * @note
 *   It is allowed to construct the default modes. So, a call
 *   new_ir_mode("Is", irms_int_number, 32, 1, irma_twos_complement, 32) will return mode_Is.
 */
FIRM_API ir_mode *new_ir_mode(const char *name, ir_mode_sort sort, int bit_size,
                              int sign, ir_mode_arithmetic arithmetic,
                              unsigned int modulo_shift);

/**
 * Creates a new vector mode.
 *
 * @param name          the name of the mode to be created
 * @param sort          the ir_mode_sort of the mode to be created
 * @param bit_size      number of bits for one element of this mode
 * @param num_of_elem   number of elements in this vector mode
 * @param sign          non-zero if this is a signed mode
 * @param arithmetic    arithmetic operations possible with a mode
 * @param modulo_shift  Is ignored for modes other than integer.
 *
 * This function constructs a new vector mode given by the parameters.
 * If the parameters match an already defined mode, this mode is returned.
 * If the mode is newly allocated, a new unique mode_code is chosen.
 * Also, special value tarvals will be calculated such as null,
 * min, max and can be retrieved using the get_mode_* functions
 *
 * @return
 *   The new mode or NULL on error.
 */
FIRM_API ir_mode *new_ir_vector_mode(const char *name, ir_mode_sort sort,
                                     int bit_size, unsigned num_of_elem,
                                     int sign, ir_mode_arithmetic arithmetic,
                                     unsigned int modulo_shift);

/**
 * Checks whether a pointer points to a mode.
 *
 * @param thing     an arbitrary pointer
 *
 * @return
 *     true if the thing is a mode, else false
 */
FIRM_API int is_mode(const void *thing);

/* ********** Access methods to read mode information *********** */

/** Returns the ident* of the mode */
FIRM_API ident *get_mode_ident(const ir_mode *mode);

/** Returns the null-terminated name of this mode. */
FIRM_API const char *get_mode_name(const ir_mode *mode);

/** Returns a coarse classification of the mode. */
FIRM_API ir_mode_sort get_mode_sort(const ir_mode *mode);

/** Returns the size of values of the mode in bits. */
FIRM_API unsigned get_mode_size_bits(const ir_mode *mode);

/** Returns the size of values of the mode in bytes.
 *  If the size is not dividable by 8 returns -1. */
FIRM_API unsigned get_mode_size_bytes(const ir_mode *mode);

/** Returns the signess of a mode.
 *
 * Returns the signess of a mode: 1 if mode is signed. */
FIRM_API int get_mode_sign(const ir_mode *mode);

/** Returns the arithmetic of a mode */
FIRM_API ir_mode_arithmetic get_mode_arithmetic(const ir_mode *mode);

/** Get the modulo shift attribute.
 *
 *  Attribute modulo shift specifies for modes of kind irms_int_number
 *  whether shift applies modulo to value of bits to shift.  Zero for
 *  modes that are not integer.
 */
FIRM_API unsigned int get_mode_modulo_shift(const ir_mode *mode);

/** Return the number of vector elements.
 *
 *  Attribute vector_elem specifies the number of vector elements of
 *  a vector mode. For non-vector modes it returns 1 for data and 0
 *  for all other modes
 */
FIRM_API unsigned int get_mode_n_vector_elems(const ir_mode *mode);

/** Returns the stored intermediate information. */
FIRM_API void *get_mode_link(const ir_mode *mode);

/** Stores new intermediate information. */
FIRM_API void set_mode_link(ir_mode *mode, void *l);

/**
 * Returns the smallest representable value of a given mode.
 *
 * For modes of the sort float_number this is the most negative value
 * bigger than -infinite.
 */
FIRM_API tarval *get_mode_min(ir_mode *mode);

/**
 * Returns the biggest representable value o f a given mode.
 *
 * For modes of the sort float_number this is the largest value lower
 * than infinite.
 */
FIRM_API tarval *get_mode_max(ir_mode *mode);

/**
 * Returns the value Zero represented in this mode.
 *
 * Zero is the additive neutral element and as such
 * is defined only for modes allowing addition, i.e.
 * op_pin_state_floats and ints, and references (NULL-Pointer)
 * else returns tarval_bad.
 */
FIRM_API tarval *get_mode_null(ir_mode *mode);

/**
 * Returns the value One, represented in this mode.
 *
 * One, being the multiplicative neutral element,
 * is defined only for modes allowing multiplication,
 * i.e. ints and floats.
 */
FIRM_API tarval *get_mode_one(ir_mode *mode);

/**
 * Returns the value Minus One, represented in this mode.
 *
 * Minus One is defined only for modes allowing
 * multiplication with signed values, i.e. signed ints and floats.
 */
FIRM_API tarval *get_mode_minus_one(ir_mode *mode);

/**
 * Returns the value where all bits are One, represented in this mode.
 *
 * All One is defined only for modes integer, reference and boolean modes
 */
FIRM_API tarval *get_mode_all_one(ir_mode *mode);

/**
 * Returns the positive infinite value of a mode.
 *
 * This is only valid for float_numbers, other modes
 * will result in tarval_bad.
 */
FIRM_API tarval *get_mode_infinite(ir_mode *mode);

/**
 * Returns the NAN value of a given mode.
 *
 * This is only valid for float_numbers, other modes
 * will result in tarval_bad.
 */
FIRM_API tarval *get_mode_NAN(ir_mode *mode);

FIRM_API ir_mode *mode_M; /**< memory */

/* -- A set of predefined, numerical modes according to Techreport 1999-44 -- */
FIRM_API ir_mode *mode_F;	  /**< signed float(32) */
FIRM_API ir_mode *mode_D;   /**< signed double(64) */
FIRM_API ir_mode *mode_E;   /**< signed extended(80) */
FIRM_API ir_mode *mode_Bs;  /**< signed byte (former char) */
FIRM_API ir_mode *mode_Bu;  /**< unsigned byte (former char) */
FIRM_API ir_mode *mode_Hs;  /**< signed short integer */
FIRM_API ir_mode *mode_Hu;  /**< unsigned short integer */
FIRM_API ir_mode *mode_Is;  /**< signed integer */
FIRM_API ir_mode *mode_Iu;  /**< unsigned integer */
FIRM_API ir_mode *mode_Ls;  /**< signed long integer */
FIRM_API ir_mode *mode_Lu;  /**< unsigned long integer */
FIRM_API ir_mode *mode_LLs; /**< signed long long integer */
FIRM_API ir_mode *mode_LLu; /**< unsigned long long integer */

FIRM_API ir_mode *mode_P;   /**< pointer */
FIRM_API ir_mode *mode_P_code; /**< A pointer mode that is set by the client of libfirm.  This mode
                                  represents the pointer size of the target machine code addresses. Is initialized
                                  to mode_P. */
FIRM_API ir_mode *mode_P_data; /**< A pointer mode that is set by the client of libfirm.  This mode
                                  represents the pointer size of the target machine data addresses. Is initialized
                                  to mode_P. */

/* -- Auxiliary modes necessary for the Firm representation -- */
FIRM_API ir_mode *mode_b;  /**< internal boolean */

FIRM_API ir_mode *mode_X;  /**< execution */
FIRM_API ir_mode *mode_BB; /**< block */

FIRM_API ir_mode *mode_T;  /**< tuple (none) */
FIRM_API ir_mode *mode_ANY;/**< undefined mode */
FIRM_API ir_mode *mode_BAD;/**< bad mode */

/*@{*/
FIRM_API ir_mode *get_modeF(void);
FIRM_API ir_mode *get_modeD(void);
FIRM_API ir_mode *get_modeE(void);
FIRM_API ir_mode *get_modeBs(void);
FIRM_API ir_mode *get_modeBu(void);
FIRM_API ir_mode *get_modeHs(void);
FIRM_API ir_mode *get_modeHu(void);
FIRM_API ir_mode *get_modeIs(void);
FIRM_API ir_mode *get_modeIu(void);
FIRM_API ir_mode *get_modeLs(void);
FIRM_API ir_mode *get_modeLu(void);
FIRM_API ir_mode *get_modeLLs(void);
FIRM_API ir_mode *get_modeLLu(void);
FIRM_API ir_mode *get_modeP(void);
FIRM_API ir_mode *get_modeb(void);
FIRM_API ir_mode *get_modeX(void);
FIRM_API ir_mode *get_modeBB(void);
FIRM_API ir_mode *get_modeM(void);
FIRM_API ir_mode *get_modeT(void);
FIRM_API ir_mode *get_modeANY(void);
FIRM_API ir_mode *get_modeBAD(void);

/** Returns the machine specific pointer mode for code addresses. */
FIRM_API ir_mode *get_modeP_code(void);

/** Returns the machine specific pointer mode for data addresses. */
FIRM_API ir_mode *get_modeP_data(void);

/**
 * Sets the machine specific pointer mode for code addresses.
 * If not set, the predefined mode mode_P will be used.
 */
FIRM_API void set_modeP_code(ir_mode *p);

/**
 * Sets the machine specific pointer mode for data addresses.
 * If not set, the predefined mode mode_P will be used.
 */
FIRM_API void set_modeP_data(ir_mode *p);

/*@{*/
/**
   Functions to check, whether a mode is signed, float, int, character,
   reference, num, data, datab or dataM.

   For more exact definitions read the corresponding pages
   in the firm documentation or the following enumeration

   The set of "float" is defined as:
   float = {irm_F, irm_D, irm_E}

   The set of "int" is defined as:
   int   = {irm_Bs, irm_Bu, irm_Hs, irm_Hu, irm_Is, irm_Iu, irm_Ls, irm_Lu}

   The set of "reference" is defined as:
   reference  = {irm_P}

   The set of "num" is defined as:
   num   = {float || int}

   The set of "data" is defined as:
   data  =  {num || reference}

   The set of "datab" is defined as:
   datab =  {data || irm_b }

   The set of "dataM" is defined as:
   dataM =  {data || irm_M}

   Vector "int" and "float" are defined by the arithmetic and vector_elem > 1.
*/
/* Test for a certain class of modes. */
FIRM_API int mode_is_signed (const ir_mode *mode);
FIRM_API int mode_is_float (const ir_mode *mode);
FIRM_API int mode_is_int (const ir_mode *mode);
FIRM_API int mode_is_reference (const ir_mode *mode);
FIRM_API int mode_is_num (const ir_mode *mode);
FIRM_API int mode_is_data (const ir_mode *mode);
FIRM_API int mode_is_datab (const ir_mode *mode);
FIRM_API int mode_is_dataM (const ir_mode *mode);
FIRM_API int mode_is_float_vector (const ir_mode *mode);
FIRM_API int mode_is_int_vector (const ir_mode *mode);
/*@}*/

/**
 * Returns true if sm can be converted to lm without loss
 * according to firm definition.
 *
 * Note that mode_Iu is NOT smaller than mode_Is here.
 *
 * @see values_in_mode()
 */
FIRM_API int smaller_mode(const ir_mode *sm, const ir_mode *lm);

/**
 * Returns true if a value of mode sm can be converted into mode lm
 * and backwards without loss.
 *
 * Note that mode_Iu values CAN be converted in mode_Is and back.
 *
 * @see smaller_mode()
 */
FIRM_API int values_in_mode(const ir_mode *sm, const ir_mode *lm);

/**
 * Returns a matching unsigned mode for a given integer signed mode.
 * Returns NULL if no matching mode exists.
 */
FIRM_API ir_mode *find_unsigned_mode(const ir_mode *mode);

/**
 * Returns a matching signed mode for a given integer unsigned mode.
 * Returns NULL if no matching mode exists.
 */
FIRM_API ir_mode *find_signed_mode(const ir_mode *mode);

/**
 * Returns an integer mode with 2*n bits for a given integer mode with n bits.
 * Returns NULL if no matching mode exists.
 */
FIRM_API ir_mode *find_double_bits_int_mode(const ir_mode *mode);

/**
 * Returns non-zero if the given mode honors signed zero's, i.e.,
 * a +0 and a -0 exists and handled differently.
 */
FIRM_API int mode_honor_signed_zeros(const ir_mode *mode);

/**
 * Returns non-zero if the given mode might overflow on unary Minus.
 */
FIRM_API int mode_overflow_on_unary_Minus(const ir_mode *mode);

/**
 * Returns non-zero if the mode has a reversed wrap-around
 * logic, especially (a + x) - x == a.
 * This is normally true for integer modes, not for floating
 * point modes.
 */
FIRM_API int mode_wrap_around(const ir_mode *mode);

/**
 * Return the signed integer equivalent mode for an reference mode.
 */
FIRM_API ir_mode *get_reference_mode_signed_eq(ir_mode *mode);

/**
 * Sets the signed integer equivalent mode for an reference mode.
 */
FIRM_API void set_reference_mode_signed_eq(ir_mode *ref_mode, ir_mode *int_mode);

/**
 * Return the unsigned integer equivalent mode for an reference mode.
 */
FIRM_API ir_mode *get_reference_mode_unsigned_eq(ir_mode *mode);

/**
 * Sets the unsigned integer equivalent mode for an reference mode.
 */
FIRM_API void set_reference_mode_unsigned_eq(ir_mode *ref_mode, ir_mode *int_mode);

/**
 * Returns non-zero if the cast from mode src to mode dst is a
 * reinterpret cast (ie. only the bit pattern is reinterpreted,
 * no conversion is done)
 */
FIRM_API int is_reinterpret_cast(const ir_mode *src, const ir_mode *dst);

/**
 * Returns the primitive type matching the given mode
 */
FIRM_API ir_type *get_type_for_mode(const ir_mode *mode);

#include "end.h"

#endif
