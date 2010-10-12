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
 * @brief    Representation of and static computations on target machine
 *           values.
 * @date     2003
 * @author   Mathias Heil
 * @version  $Id$
 * @brief
 *   Tarvals represent target machine values.  They are typed by modes.
 *   Tarvals only represent values of mode_sort:
 *    - int_number,
 *    - float_number,
 *    - boolean,
 *    - reference,
 *    - character
 *
 *   In case of references the module accepts an entity to represent the
 *   value.
 *   Furthermore, computations and conversions of these values can
 *   be performed.
 *
 * HISTORY
 *    The original tv module originated in the fiasco compiler written ...
 *    This is the new version, described in the tech report 1999-14 by ...
 *
 * @sa
 *    Techreport 1999-14
 *    irmode.h for the modes definitions
 *    irnode.h for the pn_Cmp table
 */
#ifndef FIRM_TV_TV_H
#define FIRM_TV_TV_H

#include "firm_types.h"
#include "irnode.h"

#include "begin.h"

/* ************************ Constructors for tarvals ************************ */

/**
 * Constructor function for new tarvals.
 *
 * @param str   The string representing the target value
 * @param len   The length of the string
 * @param mode  The mode requested for the result tarval
 *
 * This function creates a new tarval representing the value represented
 * by a CString, aka char array. If a tarval representing this value already
 * exists, this tarval is returned instead of a new one. So tarvals are
 * directly comparable since their representation is unique.
 *
 * This function accepts the following strings:
 *
 * if mode is int_number:
 *  - 0(x|X)[0-9a-fA-F]+ (hexadecimal representation)
 *  - 0[0-7]*            (octal representation)
 *  - (+|-)?[1-9][0-9]*  (decimal representation)
 *
 * if mode is float_number:
 *  - (+|-)?(decimal int) (. (decimal int))? ((e|E)(+|-)?(decimal int))?
 *
 * if mode is boolean: true, True, TRUE ... False... 0, 1,
 *
 * if mode is reference: hexadecimal of decimal number as int
 *
 * if mode is character: hex or dec
 *
 * Leading and/or trailing spaces are ignored
 *
 * @return
 *   A tarval of proper type representing the requested value is returned.
 *   Tarvals are unique, so for any value/mode pair at most one tarval will
 *   exist, which will be returned upon further requests with an identical
 *   value/mode pair.
 *
 * @note
 *   If the string is not representable in the given mode an assertion is
 *   thrown in assert build.
 *
 * @sa
 *   irmode.h for predefined modes
 *   new_tarval_from_long()
 *   new_tarval_from_double()
 */
FIRM_API tarval *new_tarval_from_str(const char *str, size_t len,
                                     ir_mode *mode);

/**
 * Construct a new tarval from a given string.
 *
 * @param str   The string representing the target value
 * @param len   The length of the string
 * @param sign  is -1 or 1 depending on the numbers sign
 * @param base  number system base.
 *              binary(2), octal(8), decimal(10) and hexadecimal(16) numbers
 *              are supported.
 * @param mode  The mode requested for the result tarval
 *
 * @return
 *   A tarval with the given mode. If overflow settings are set to
 *   TV_OVERFLOW_BAD then a tarval_bad is returned if the number can't be
 *   represented in the given mode.
 *   Return bad if the number couldn't successfully be parsed.
 */
FIRM_API tarval *new_integer_tarval_from_str(const char *str, size_t len,
                                             char sign, unsigned char base,
                                             ir_mode *mode);

/**
 * Constructor function for new tarvals
 *
 * @param l     The long representing the value
 * @param mode  The mode requested for the result tarval
 *
 * This function creates a new tarval representing the value represented
 * by a long integer. If a tarval representing this value already exists,
 * this tarval is returned instead of a new one. So tarvals are directly
 * comparable since their representation is unique.
 *
 * @return
 *   A tarval of proper type representing the requested value is returned.
 *   Tarvals are unique, so for any value/mode pair at most one tarval will
 *   exist, which will be returned upon further requests with an identical
 *   value/mode pair.
 *
 * @note
 *   If the long is not representable in the given mode an assertion is
 *   thrown in assert build.
 *
 * @sa
 *   irmode.h for predefined modes
 *   new_tarval_from_str()
 *   new_tarval_from_double()
 *
 */
FIRM_API tarval *new_tarval_from_long(long l, ir_mode *mode);

/** Return value as long if possible.
 *
 * This returns a long int with the value represented value, or
 * gibberish, depending on the size of long int and the size of the
 * stored value. It works for e.g. 1 as mode_Ls, but might not work for
 * get_mode_max(mode_Ls).
 * This will overflow silently, so use only if you know what
 * you are doing! (better check with tarval_is_long()...)
 * Works only for int modes, even not for character modes!
 */
FIRM_API long get_tarval_long(tarval *tv);

/**
 * This validates if get_tarval_long() will return a satisfying
 * result. I.e. if tv is an int_number and between min, max
 * of long int (signed!)
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_long(tarval *tv);

/**
 * Constructor function for new tarvals.
 *
 * @param d     The (long) double representing the value
 * @param mode  The mode requested for the result tarval
 *
 * This function creates a new tarval representing the value represented
 * by a (long) double. If a tarval representing this value already exists,
 * this tarval is returned instead of a new one. So tarvals are directly
 * comparable since their representation is unique.
 * Only modes of sort float_number can be constructed this way.
 *
 * @return
 *   A tarval of proper type representing the requested value is returned.
 *   Tarvals are unique, so for any value/mode pair at most one tarval will
 *   exist, which will be returned upon further requests with an identical
 *   value/mode pair.
 *
 * @note
 *   If the (long) double is not representable in the given mode an assertion
 *   is thrown. This will happen for any mode not of sort float_number.
 *
 * @sa
 *   irmode.h for predefined values
 *   new_tarval_from_str()
 *   new_tarval_from_long()
 */
FIRM_API tarval *new_tarval_from_double(long double d, ir_mode *mode);

/**
 * This returns a double with the value represented value, or
 * gibberish, depending on the size of double and the size of the
 * stored value.
 * This will overflow silently, so use only if you know what
 * you are doing! (better check with tarval_is_long...)
 *
 * @param tv    the tarval
 */
FIRM_API long double get_tarval_double(tarval *tv);

/**
 * This validates if tarval_to_double() will return a satisfying
 * result. I.e. if tv is an float_number and between min, max
 * of double
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_double(tarval *tv);


/** ********** Access routines for tarval fields ********** **/

/*
 * NAME
 *   get_tarval_mode
 *   get_tarval_ ...
 *
 * SYNOPSIS
 *   ir_mode *get_tarval_mode(tarval *tv)
 *   ...
 *
 * DESCRIPTION
 *    These are access function for tarval struct members. It is encouraged
 *   to use them instead of direct access to the struct fields.
 *
 * PARAMETERS
 *   tv - The tarval to access fields of
 *
 * RESULT
 *   get_tv_mode: The mode of the tarval
 *
 * SEE ALSO
 *   the struct tarval
 */

/**
 * Returns the mode of the tarval.
 *
 * @param tv    the tarval
 */
FIRM_API ir_mode *get_tarval_mode(const tarval *tv);

/** Returns the contents of the 'link' field of the tarval */
/* void *get_tarval_link (tarval*); */

/* Testing properties of the represented values */

/**
 * Returns 1 if tv is negative
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_negative(tarval *tv);

/**
 * Returns 1 if tv is null
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_null(tarval *tv);

/**
 * Returns 1 if tv is the "one"
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_one(tarval *tv);

/**
 * Returns 1 if tv is the "minus one"
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_minus_one(tarval *tv);

/**
 * returns non-zero if all bits in the tarval are set
 */
FIRM_API int tarval_is_all_one(tarval *tv);

/**
 * Return non-zero if the tarval is a constant (ie. NOT
 * a reserved tarval like bad, undef, reachable etc.)
 */
FIRM_API int tarval_is_constant(tarval *tv);

/** The 'bad' tarval. */
FIRM_API tarval *tarval_bad;
/** Returns the 'bad' tarval. */
FIRM_API tarval *get_tarval_bad(void);

/** The 'undefined' tarval. */
FIRM_API tarval *tarval_undefined;
/** Returns the 'undefined' tarval. */
FIRM_API tarval *get_tarval_undefined(void);

/** The mode_b tarval 'false'. */
FIRM_API tarval *tarval_b_false;
/** Returns the mode_b tarval 'false'. */
FIRM_API tarval *get_tarval_b_false(void);

/** The mode_b tarval 'true'. */
FIRM_API tarval *tarval_b_true;
/** Returns the mode_b tarval 'true'. */
FIRM_API tarval *get_tarval_b_true(void);

/** The mode_X tarval 'unreachable'. */
FIRM_API tarval *tarval_unreachable;
/** Returns the mode_X tarval 'unreachable'. */
FIRM_API tarval *get_tarval_unreachable(void);

/** The mode_X tarval 'reachable'. */
FIRM_API tarval *tarval_reachable;
/** Returns the mode_X tarval 'reachable'. */
FIRM_API tarval *get_tarval_reachable(void);

/** The 'top' tarval. This is just another name for the 'undefined' tarval. */
#define tarval_top          tarval_undefined
/** Returns the 'top' tarval. */
#define get_tarval_top()    get_tarval_undefined()

/** The 'bottom' tarval. This is just another name for the 'bad' tarval. */
#define tarval_bottom       tarval_bad
/** Returns the 'bottom' tarval. */
#define get_tarval_bottom() get_tarval_bad()

/* These functions calculate and return a tarval representing the requested
 * value.
 * The functions get_mode_{Max,Min,...} return tarvals retrieved from these
 * functions, but these are stored on initialization of the irmode module and
 * therefore the irmode functions should be preferred to the functions below. */

/** Returns the maximum value of a given mode. */
FIRM_API tarval *get_tarval_max(ir_mode *mode);

/** Returns the minimum value of a given mode. */
FIRM_API tarval *get_tarval_min(ir_mode *mode);

/** Returns the 0 value (additive neutral) of a given mode.
    For reference modes, the NULL value is returned (old tarval_P_void) */
FIRM_API tarval *get_tarval_null(ir_mode *mode);

/** Returns the 1 value (multiplicative neutral) of a given mode. */
FIRM_API tarval *get_tarval_one(ir_mode *mode);

/** Returns the -1 value (multiplicative neutral) of a given mode.
 *  Returns tarval bad for unsigned modes */
FIRM_API tarval *get_tarval_minus_one(ir_mode *mode);

/** returns the value where all bits are 1 of a given mode.
 * returns tarval_bad for float modes */
FIRM_API tarval *get_tarval_all_one(ir_mode *mode);

/** Return quite nan for float_number modes. */
FIRM_API tarval *get_tarval_nan(ir_mode *mode);

/** Return +inf for float_number modes. */
FIRM_API tarval *get_tarval_plus_inf(ir_mode *mode);

/** Return -inf for float_number modes. */
FIRM_API tarval *get_tarval_minus_inf(ir_mode *mode);

/* ******************** Arithmetic operations on tarvals ******************** */

typedef enum _tarval_int_overflow_mode_t {
	TV_OVERFLOW_BAD,      /**< tarval module will return tarval_bad if a overflow occurs */
	TV_OVERFLOW_WRAP,     /**< tarval module will overflow will be ignored, wrap around occurs */
	TV_OVERFLOW_SATURATE  /**< tarval module will saturate the overflow */
} tarval_int_overflow_mode_t;

/**
 * Sets the overflow mode for integer operations.
 *
 * @param ov_mode  one of teh overflow modes
 */
FIRM_API void tarval_set_integer_overflow_mode(tarval_int_overflow_mode_t ov_mode);

/**
 * Get the overflow mode for integer operations.
 */
FIRM_API tarval_int_overflow_mode_t tarval_get_integer_overflow_mode(void);

/**
 * Compares two tarvals
 *
 * Compare a with b and return a pn_Cmp describing the relation
 * between a and b.  This is either pn_Cmp_Uo, pn_Cmp_Lt, pn_Cmp_Eq, pn_Cmp_Gt,
 * or pn_Cmp_False if a or b are symbolic pointers which can not be compared at all.
 *
 * @param a   the first tarval to be compared
 * @param b   the second tarval to be compared
 *
 * @return
 *   The pn_Cmp best describing the relation between a and b is returned.
 *   This means the mode with the least bits set is returned, e.g. if the
 *   tarvals are equal the pn_Cmp 'pn_Cmp_Eq' is returned, not 'pn_Cmp_Ge' which
 *   indicates 'greater or equal'
 *
 * @sa
 *    irnode.h for the definition of pn_Cmp
 */
FIRM_API pn_Cmp tarval_cmp(tarval *a, tarval *b);

/**
 * Converts a tarval to another mode.
 *
 * Convert tarval 'src' to mode 'mode', this will succeed if and only if mode
 * 'mode' is wider than the mode of src, as defined in the firm documentation
 * and as returned by the function mode_is_smaller defined in irmode.h.
 *
 * @param src    The tarval to convert
 * @param mode   Tho mode to convert to
 *
 * @return
 *   If a tarval of mode 'mode' with the result of the conversion of the 'src'
 *   tarvals value already exists, it will be returned, else a new tarval is
 *   constructed and returned
 *
 * @note
 *    Illegal convertions will trigger a panic
 *
 * @sa
 *    FIRM documentation for conversion rules
 *    mode_is_smaller defined in irmode.h
 */
FIRM_API tarval *tarval_convert_to(tarval *src, ir_mode *mode);

/*
 * These function implement basic computations representable as opcodes
 * in FIRM nodes.
 *
 * PARAMETERS
 *    tarval_neg:
 *    traval_abs:
 *      a - the tarval to operate on
 *
 *    all others:
 *      a - the first operand tarval
 *      b - the second operand tarval
 *
 * RESULT
 *    If necessary a new tarval is constructed for the resulting value,
 *   or the one already carrying the computation result is retrieved and
 *   returned as result.
 *
 * NOTES
 *   The order the arguments are given in is important, imagine postfix
 *   notation.
 *   Illegal operations will trigger an assertion.
 *   The sort member of the struct mode defines which operations are valid
 */

/**
 * Bitwise Negation of a tarval.
 *
 * @param a  the first tarval
 *
 * @return ~a or tarval_bad
 */
FIRM_API tarval *tarval_not(tarval *a);

/**
 * Arithmetic Negation of a tarval.
 *
 * @param a  the first tarval
 *
 * @return -a or tarval_bad
 */
FIRM_API tarval *tarval_neg(tarval *a);

/**
 * Addition of two tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a + b or tarval_bad
 */
FIRM_API tarval *tarval_add(tarval *a, tarval *b);

/**
 * Subtraction from a tarval.
 *
 * @param a         the first tarval
 * @param b         the second tarval
 * @param dst_mode  the mode of the result, needed for mode_P - mode_P, else NULL
 *
 * @return a - b or tarval_bad
 */
FIRM_API tarval *tarval_sub(tarval *a, tarval *b, ir_mode *dst_mode);

/**
 * Multiplication of tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a * b or tarval_bad
 */
FIRM_API tarval *tarval_mul(tarval *a, tarval *b);

/**
 * Division of two floating point tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a / b or tarval_bad
 */
FIRM_API tarval *tarval_quo(tarval *a, tarval *b);

/**
 * Integer division of two tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a / b or tarval_bad
 */
FIRM_API tarval *tarval_div(tarval *a, tarval *b);

/**
 * Remainder of integer division.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a % b or tarval_bad
 */
FIRM_API tarval *tarval_mod(tarval *a, tarval *b);

/**
 * Integer division AND remainder.
 *
 * @param a        the first tarval
 * @param b        the second tarval
 * @param mod_res  after return, contains the remainder result, a % b or tarval_bad
 *
 * @return a / b or tarval_bad
 */
FIRM_API tarval *tarval_divmod(tarval *a, tarval *b, tarval **mod_res);

/**
 * Absolute value of a tarval.
 *
 * @param a  the first tarval
 *
 * @return |a| or tarval_bad
 */
FIRM_API tarval *tarval_abs(tarval *a);

/**
 * Bitwise and of two integer tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a & b or tarval_bad
 */
FIRM_API tarval *tarval_and(tarval *a, tarval *b);

/**
 * Bitwise and not of two integer tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a & ~b or tarval_bad
 */
FIRM_API tarval *tarval_andnot(tarval *a, tarval *b);

/**
 * Bitwise or of two integer tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a | b or tarval_bad
 */
FIRM_API tarval *tarval_or(tarval *a, tarval *b);

/**
 * Bitwise exclusive or of two integer tarvals.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a ^ b or tarval_bad
 */
FIRM_API tarval *tarval_eor(tarval *a, tarval *b);

/**
 * Logical Left shift.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a << b or tarval_bad
 */
FIRM_API tarval *tarval_shl(tarval *a, tarval *b);

/**
 * Unsigned (logical) right shift.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a >>u b or tarval_bad
 */
FIRM_API tarval *tarval_shr(tarval *a, tarval *b);

/**
 * Signed (arithmetic) right shift.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a >>s b or tarval_bad
 */
FIRM_API tarval *tarval_shrs(tarval *a, tarval *b);

/**
 * Rotation to left.
 *
 * @param a  the first tarval
 * @param b  the second tarval
 *
 * @return a \<\<L\>\> b or tarval_bad
 */
FIRM_API tarval *tarval_rotl(tarval *a, tarval *b);

/**
 * Returns the carry flag of the last operation.
 */
FIRM_API int tarval_carry(void);

/* *********** Output of tarvals *********** */

/**
 * The output mode for tarval values.
 *
 * Some modes allow more that one representation, for instance integers
 * can be represented hex or decimal. Of course it would be enough to have
 * one and let every backend convert it into the 'right' one.
 * However, we can do this in the tarval much simpler...
 */
typedef enum {
	TVO_NATIVE,       /**< the default output mode, depends on the mode */
	TVO_HEX,          /**< use hex representation, always possible */
	TVO_DECIMAL,      /**< use decimal representation */
	TVO_OCTAL,        /**< use octal representation */
	TVO_BINARY,       /**< use binary representation */
	TVO_FLOAT,        /**< use floating point representation (i.e 1.342e-2)*/
	TVO_HEXFLOAT      /**< use hexadecimal floating point representation (i.e 0x1.ea32p-12)*/
} tv_output_mode;

/**
 * This structure contains helper information to format the output
 * of a tarval of a mode.
 */
typedef struct tarval_mode_info {
	tv_output_mode mode_output;  /**< if != TVO_NATIVE select a special mode */
	const char *mode_prefix;     /**< if set, this prefix will be printed
	                                  before a value of this mode */
	const char *mode_suffix;     /**< if set, this suffix will be printed
	                                  after a value of this mode */
} tarval_mode_info;

/**
 * Specify the output options of one mode.
 *
 * This functions stores the mode info, so DO NOT DESTROY it.
 *
 * @param mode      a ir_mode that should be associated
 * @param modeinfo  the output format info
 *
 * @return zero on success.
 */
FIRM_API int set_tarval_mode_output_option(ir_mode *mode,
                                           const tarval_mode_info *modeinfo);

/**
 * Returns the output options of one mode.
 *
 * This functions returns the mode info of a given mode.
 *
 * @param mode      a ir_mode that should be associated
 *
 * @return the output option
 */
FIRM_API const tarval_mode_info *get_tarval_mode_output_option(ir_mode *mode);

/**
 * Returns Bit representation of a tarval value, as string of '0' and '1'
 *
 * @param tv   The tarval
 *
 * This function returns a printable bit representation of any value
 * stored as tarval. This representation is a null terminated C string.
 *
 * @return
 *   As usual in C a pointer to a char is returned. The length of the
 *   returned string if fixed, just read as many chars as the mode defines
 *   as size.
 *
 * @note
 *   The string is allocated using malloc() and is free()ed on the next call
 *   of this function.
 *   The string consists of the ASCII characters '0' and '1' and is
 *   null terminated
 *
 * @sa
 *    irmode.h for the definition of the ir_mode struct
 *    the size member of aforementioned struct
 */
FIRM_API char *get_tarval_bitpattern(tarval *tv);

/**
 * Returns the bitpattern of the bytes_ofs byte.
 *
 * This function succeeds even if the mode of the tarval uses lesser bits
 * than requested, in that case the bitpattern is filled with zero bits.
 *
 * To query a 32bit value the following code can be used:
 *
 * val0 = tarval_sub_bits(tv, 0);  <- lowest bits
 * val1 = tarval_sub_bits(tv, 1);
 * val2 = tarval_sub_bits(tv, 2);
 * val3 = tarval_sub_bits(tv, 3);  <- highest bits
 *
 * Because this is the bit representation of the target machine, only the following
 * operations are legal on the result:
 *
 * - concatenation (endian dependence MUST be handled by the CALLER)
 * - bitwise logical operations to select/mask bits
 *
 * @param tv        the tarval
 * @param byte_ofs  the byte offset from lower to higher
 *
 * @note
 *   The result of this function is undefined if the mode is neither integer nor float.
 */
FIRM_API unsigned char get_tarval_sub_bits(tarval *tv, unsigned byte_ofs);

/**
 * Returns non-zero if a given (integer) tarval has only one single bit
 * set.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_single_bit(tarval *tv);

/**
 * Return the number of set bits in a given (integer) tarval.
 *
 * @param tv    the tarval
 *
 * @return number of set bits or -1 on error
 */
FIRM_API int get_tarval_popcount(tarval *tv);

/**
 * Return the number of the lowest set bit in a given (integer) tarval.
 *
 * @param tv    the tarval
 *
 * @return number of lowest set bit or -1 on error
 */
FIRM_API int get_tarval_lowest_bit(tarval *tv);

/**
 * Output a tarval to a string buffer.
 *
 * @param buf     the output buffer
 * @param buflen  the length of the buffer
 * @param tv      the tarval
 */
FIRM_API int tarval_snprintf(char *buf, size_t buflen, tarval *tv);

/**
 * Output a tarval to stdio.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_printf(tarval *tv);

/**
 * Returns non-zero if the mantissa of a floating point IEEE-754
 * tarval is zero (i.e. 1.0Exxx)
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_ieee754_zero_mantissa(tarval *tv);

/**
 * Returns the exponent of a floating point IEEE-754
 * tarval.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_ieee754_get_exponent(tarval *tv);

/**
 * Check if the tarval can be converted to the given mode without
 * precision loss.
 *
 * @param tv    the tarval
 * @param mode  the mode to convert to
 */
FIRM_API int tarval_ieee754_can_conv_lossless(tarval *tv, ir_mode *mode);

/**
 * Set the immediate precision for IEEE-754 results. Set this to
 * 0 to get the same precision as the operands.
 * For x87 compatibility, set this to 80.
 *
 * @return the old setting
 */
FIRM_API unsigned tarval_ieee754_set_immediate_precision(unsigned bits);

/**
 *  Returns non-zero if the result of the last IEEE-754 operation was exact.
 */
FIRM_API unsigned tarval_ieee754_get_exact(void);

/**
 * Return the size of the mantissa in bits (including possible
 * implicit bits) for the given mode.
 */
FIRM_API unsigned tarval_ieee754_get_mantissa_size(const ir_mode *mode);

/**
 * Enable/Disable floating point constant folding.
 */
FIRM_API void tarval_enable_fp_ops(int enable);

/** returns 0/1 if floating point folding is enable/disabled */
FIRM_API int tarval_fp_ops_enabled(void);

/**
 * Check if its the a floating point NaN.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_NaN(tarval *tv);

/**
 * Check if its the a floating point +inf.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_plus_inf(tarval *tv);

/**
 * Check if its the a floating point -inf.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_minus_inf(tarval *tv);

/**
 * Check if the tarval represents a finite value, ie neither NaN nor inf.
 *
 * @param tv    the tarval
 */
FIRM_API int tarval_is_finite(tarval *tv);

/**
 *   Checks whether a pointer points to a tarval.
 *
 *   @param thing     an arbitrary pointer
 *
 *   @return
 *       true if the thing is a tarval, else false
 */
FIRM_API int is_tarval(const void *thing);

#include "end.h"

#endif
