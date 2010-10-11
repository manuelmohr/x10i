/* ************************************************************************* */
/*                            IBM Confidential                               */
/*                          OCO Source Materials                             */
/*                      IBM XL UPC Alpha Edition, V0.9                       */
/*                                                                           */
/*                      Copyright IBM Corp. 2005, 2007.                      */
/*                                                                           */
/* The source code for this program is not published or otherwise divested   */
/* of its trade secrets, irrespective of what has been deposited with the    */
/* U.S. Copyright Office.                                                    */
/* ************************************************************************* */

#ifndef __PGASRT_MSG_H_
#define __PGASRT_MSG_H_

#undef EXTERN
#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif

#include "pgasrt_config.h"
#include "pgasrt_types.h"

#include <stdarg.h>
#include <stddef.h>

/* ************************************************************************ */
/**
 * @file pgasrt_msg.h
 * @brief localizable error reporting subsystem
 *
 * The error reporting system reports all errors to stderr. There is support
 * for localization based on the user's locale setting.
 *
 * There are three types of messages handled by the reporting system:
 *  1. fatal errors meaningful to the user
 *  2. warnings meaningful to the user
 *  3. fatal errors only meaningful to a PGASRT developer
 *
 * Only the first two benefit from localization and will go through the
 * message catalogue. The third allows the developer to specify the format
 * of the message at the call site. All three use printf-style formatting.
 *
 * Messages in the catalogue are formatted in printf-style syntax. The best
 * practice is to use the %$-extension allowing the message format to change
 * without requiring the call-site to change also. This gives additional
 * flexability during localization.
 *
 * For example; instead of using a format string like "Node %u, thread %u",
 * use "Node %1$u, thread %2$u" instead. That way if the string needs to
 * change to "Thread %2$u, node %1$u" (or its equivalent in another language,
 * it can).
 */
/* ************************************************************************ */


/* ************************************************************************ */
/**
 * \brief display a substituted message from the catalog and abort
 * \param msg_idx       the index of the message in the catalog
 * \param ...           the values to substitute into the message
 */
/* ************************************************************************ */

EXTERN void __pgasrt_msg_fatal(int msg_idx, ...);

/* ************************************************************************ */
/**
 * \brief display a substituted message from the catalog
 * \param msg_idx       the index of the message in the catalog
 * \param ...           the values to substitute into the message
 */
/* ************************************************************************ */

EXTERN void __pgasrt_msg_warning(int msg, ...);

/* ************************************************************************ */
/**
 * \brief In the DEBUG version display the message and then abort. In
 *        the production version display a localized generic failure message
 *        and abort.
 * \param msg       a printf-formatted message
 * \param ...       values to substitute in
 */
/* ************************************************************************ */

EXTERN void __pgasrt_msg_dev_abort(int code, const char *msg, ...);


/* ************************************************************************ */
/**
 * \brief this gets the raw message out of the localized message catalog.
 * \param msg_idx       index into the message catalog.
 */
/* ************************************************************************ */

EXTERN int __pgasrt_msg_read (int msg_idx, char *buf, size_t buf_len);

/* These are error codes for __pgasrt_msg_fatal and __pgasrt_msg_warning */

/* message indicies into catalog */

#define PGASRT_MSG_INTERNAL_ERROR           1
    // %1$d: error code
#define PGASRT_MSG_ALLOC_ERROR              2
#define PGASRT_MSG_DEALLOC_ERROR            3

#define PGASRT_MSG_NODES_CONFLICT                   101
    // %1$u - some cu compiled for this many nodes
    // %2$u - some cu compiled for this many nodes
    // note - %1$u != %2$u
#define PGASRT_MSG_THREADS_CONFLICT                 102
    // %1$u - some cu compiled for this many threads
    // %2$u - some cu compiled for this many threads
    // note - %1$u != %2$u
#define PGASRT_MSG_NODES_EXE_CONFLICT               103
    // %1$u - optimized for this many nodes
    // %2$u - run with this many nodes
    // note - %1$u != %2$u 
#define PGASRT_MSG_THREADS_EXE_CONFLICT             104
    // %1$u - optimized for this many threads
    // %2$u - run with this many threads
    // note - %1$u != %2$u
#define PGASRT_MSG_THREADS_PER_NODE_OVERFLOW        105
    // %1$u - program run with this many threads/node
    // %2$u - max number of threads/node
    // note - $1%u > %2$u
#define PGASRT_MSG_THREADS_PER_NODE_INVALID         106
    // %1$u - program run with this many threads
    // %2$u - program run with this many nodes
    // note - %2$u mod %1$u != 0
#define PGASRT_MSG_SHARED_VARS_OVERFLOW             107
    // %1$u - number of shared vars registered
    // %2$u - partition
    // %3$u - max shared vars per partition

#define UPCRT_MSG_NTHREADS_INVALID                  201
    // %1$s - env-var UPC_NTHREADS value
#define UPCRT_MSG_NTHREADS_CONFLICT                 202
    // %1$u - run with this many threads
    // %2$u - optimized for this many threads
    // note - %1$u != %2$u
#define UPCRT_MSG_LOCALSTACKSIZE_INVALID            203
    // %1$s - env-var UPC_LOCALSTACKSIZE value
#define UPCRT_MSG_SHARED_ARRAY_ALLOC                204
    // %1$u - nelts of shared array
    // %2$u - bytes/elt of shared array
    // %3$u - node failure occurred on
#define UPCRT_MSG_SHARED_MBARRAY_ALLOC              205
    // %1$u - nelts of shared array
    // %2$u - bytes/elt of shared array
    // %3$u - node failure occurred on
#define UPCRT_MSG_UNLOCK_INVALID                    206
    // %1$u - thread owning lock
    // %2$u - thread attemping to unlock
    // note - %1$u != %2$u
#define UPCRT_MSG_NOTIFY_OUT_OF_SEQUENCE            207
    // %1$u - thread issuing error
#define UPCRT_MSG_WAIT_OUT_OF_SEQUENCE              208
    // %1$u - thread issuing error
#define UPCRT_MSG_BARRIER_EXPRESSION_MISMATCH       209
    // %1$u - upc_barrier expr
    // %2$u - thread w/ barrier
    // %3$u - another upc_barrier expr
    // %4%u - thread of other barrier
#define UPCRT_MSG_COLLECTIVE_NBYTES_EMPTY           210
    // %1$s - collective name
#define UPCRT_MSG_COLLECTIVE_SRC_AFFINITY_NONZERO   211
    // %1$s - collective name
#define UPCRT_MSG_COLLECTIVE_DST_AFFINITY_NONZERO   212
    // %1$s - collective name
#define UPCRT_MSG_CAST_NONLOCAL                     213
    // %1$u - thread issuing error
#define UPCRT_MSG_NULL_INCR                         214
    // %1$u - thread issuing error


#define CAFRT_MSG_NUM_IMAGES_INVALID        301
    // %1$s - env_var CAF_NUM_IMAGES value
#define CAFRT_MSG_NUM_IMAGES_CONFLICT       302
    // %1$u - running with this many images
    // %2$u - optimized for this many images
    // note - %1$u != %2$u
#define CAFRT_MSG_LOCALSTACKSIZE_INVALID    303
    // %2$s - env_var CAF_LOCALSTACKSIZE value
#define CAFRT_MSG_COARRAY_ALLOC             304
    // %1$u - nelts per node
    // %2$u - nbytes per elt

/* These are error code for __pgasrt_dev_abort */
/* 4 digit number
 *  first digit: problem in codebase
 *      1 for common section
 *      2 for upc
 *      3 for caf
 *      4 for x10
 *  second digit: problem during
 *      1 assign / deref (access)
 *      2 synchronization
 *      3 allocation
 *      4 collectives
 *      5 casting
 *      9 miscillaneous (i.e., tools)
 *  third digit: problem in transport
 *      1 Sockets
 *      2 LAPI
 *      3 BG
 *  fourth digit: problem type
 *      1 invalid state for action
 *      2 malformed data
 */

#define ABORT_COMMON        1000
#define ABORT_UPC           2000
#define ABORT_CAF           3000
#define ABORT_X10           4000

#define ABORT_ACCESS        100
#define ABORT_SYNC          200
#define ABORT_ALLOC         300
#define ABORT_COLLECTIVE    400
#define ABORT_CAST          500
#define ABORT_MISC          900

#define ABORT_STATE         10
#define ABORT_MALFORMED     20
#define ABORT_UNINITIALIZED 30
#define ABORT_INPUT         40
#define ABORT_UNSUPPORTED   90

#if TRANSPORT == sockets
#define ABORT_TRANSPORT     1
#elif TRANSPORT == lapi
#define ABORT_TRANSPORT     2
#elif TRANSPORT == bgp
#define ABORT_TRANSPORT     3
#elif TRANSPORT == mx
#define ABORT_TRANSPORT     4
#elif TRANSPORT == ompi
#define ABORT_TRANSPORT     5
#elif TRANSPORT == pane
#define ABORT_TRANSPORT     6
#elif TRANSPORT == notransport
#define ABORT_TRANSPORT     7
#endif

#define ABORT_COMMON_ACCESS(type)       (ABORT_COMMON + ABORT_ACCESS + type + ABORT_TRANSPORT)
#define ABORT_COMMON_SYNC(type)         (ABORT_COMMON + ABORT_SYNC + type + ABORT_TRANSPORT)
#define ABORT_COMMON_ALLOC(type)        (ABORT_COMMON + ABORT_ALLOC + type + ABORT_TRANSPORT)
#define ABORT_COMMON_COLLECTIVE(type)   (ABORT_COMMON + ABORT_COLLECTIVE + type + ABORT_TRANSPORT)

#define ABORT_UPC_ACCESS(type)          (ABORT_UPC + ABORT_ACCESS + type + ABORT_TRANSPORT)
#define ABORT_UPC_SYNC(type)            (ABORT_UPC + ABORT_SYNC + type + ABORT_TRANSPORT)
#define ABORT_UPC_ALLOC(type)           (ABORT_UPC + ABORT_ALLOC + type + ABORT_TRANSPORT)
#define ABORT_UPC_COLLECTIVE(type)      (ABORT_UPC + ABORT_COLLECTIVE + type + ABORT_TRANSPORT)
#define ABORT_UPC_CAST(type)            (ABORT_UPC + ABORT_CAST + type + ABORT_TRANSPORT)
#define ABORT_UPC_MISC(type)            (ABORT_UPC + ABORT_MISC + type + ABORT_TRANSPORT)

#endif /* __PGASRT_MSG_H_ */
