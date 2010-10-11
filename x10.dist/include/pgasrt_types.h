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

#include <stdlib.h>
#include "pgasrt_config.h"

#ifndef __pgasrt_types_h__
#define __pgasrt_types_h__

/* ************************************************************************ */
/** @file pgasrt_types.h                                                    */
/* ************************************************************************ */

/* ************************************************************************ */
/** \brief type to describe UPC thread IDs, CAF image numbers               */
/* ************************************************************************ */

typedef unsigned int              __pgasrt_thread_t;

/* ************************************************************************ */
/** \brief type alias for generic local addresses                           */
/* ************************************************************************ */

typedef unsigned char *           __pgasrt_local_addr_t;

/* ************************************************************************ */
/** \brief type alias for UPC and CAF array indices                         */
/* ************************************************************************ */

#ifdef __PGASRT_LONGLONGINDICES
typedef long long                 __pgasrt_array_index_t;
#else
typedef long                      __pgasrt_array_index_t;
#endif

/* ************************************************************************ */
/** \brief UPC memory semantics: access flags                               */
/* ************************************************************************ */

typedef enum {
  UPC_ACCESS_STRICT=0,   /**< strict access */
  UPC_ACCESS_RELAXED=1   /**< relaxed access */
} __pgasrt_memory_semantics_t;

/* ************************************************************************ */
/** \brief SVD handles: index type for the SVD                              */
/* ************************************************************************ */
/* [GA] BlueGene Hack alert. The compiler thinks of SV handles as 32 bit    */
/* entities consisting of 16+16 bit values (partition ID + index). On       */
/* BlueGene 16 bits are not enough for partition IDs (>64K UPC threads).    */
/* Hence on BlueGene partition IDs are 20 bits each.                        */
/* Long term solution: make SV handles 64 bit entities.                     */
/* ************************************************************************ */
/* The compiler knows about the size and composition of this structure, but */
/* does not consult this header file. Be careful about modifying the struct.*/
/* ************************************************************************ */

typedef struct __pgasrt_svd_handle {
#if TRANSPORT == bgp
  unsigned int                    _partition:20;
  unsigned int                    _index:12;
#else
  unsigned short                  _partition;       /**< thread id or ALL */
  unsigned short                  _index;           /**< variable index */
#endif
} __pgasrt_svd_handle_t;


/* ************************************************************************ */
/** \brief remote address descriptors (used by memory registration)         */
/* ************************************************************************ */

#if TRANSPORT==lapi
typedef unsigned long long  __pgasrt_addrdesc_t;
#else
typedef void *              __pgasrt_addrdesc_t;
#endif

/* ************************************************************************ */
/** \brief Operation types in remote updates and in allreduce collectives   */
/* ************************************************************************ */

typedef enum 
  {
    PGASRT_OP_ADD = 0,       /**< addition */
    PGASRT_OP_MUL,           /**< multiplication */
    PGASRT_OP_DIV,           /**< division */
    PGASRT_OP_AND,           /**< logical and */
    PGASRT_OP_OR,            /**< logical or */
    PGASRT_OP_XOR,           /**< logical xor */
    PGASRT_OP_MAX,           /**< maximum */
    PGASRT_OP_MIN            /**< minimum */
  }
__pgasrt_ops_t;

/* ************************************************************************ */
/** \brief Data types used in remote updates and in allreduce collectives   */
/* ************************************************************************ */

typedef enum
  {
    PGASRT_DT_byte,    /**<  8 bits unsigned */
    PGASRT_DT_chr,     /**<  8 bits signed   */
    PGASRT_DT_srt,     /**< 16 bits signed   */
    PGASRT_DT_hwrd,    /**< 16 bits unsigned */
    PGASRT_DT_int,     /**< 32 bits signed   */
    PGASRT_DT_word,    /**< 32 bits unsigned */
    PGASRT_DT_llg,     /**< 64 bits signed   */
    PGASRT_DT_dwrd,    /**< 64 bits unsigned */
    PGASRT_DT_dbl,     /**< 64 bits, IEEE fp */
    PGASRT_DT_flt,     /**< 32 bits, IEEE fp */
    PGASRT_DT_dblint   /**< 96 bits, dbl+int */
  }
__pgasrt_dtypes_t;

/* ************************************************************************ */
/** \brief Runtime error codes (needs update)                               */
/* ************************************************************************ */

typedef enum
  {
    PGASRT_OK=0,                         /**< no error */
    PGASRT_ERR_NO_PRIVATE_MEM,           /**< local memory allocation error */
    PGASRT_ERR_NO_SHARED_MEM,            /**< shared memory allocation error */
    PGASRT_ERR_NO_MEM,                   /**< generic allocation error */
    PGASRT_ERR_SHARED_PTR,               /**< malformed pointer-to-shared */
    PGASRT_ERR_COMMUNICATION,            /**< generic communication error */
    PGASRT_ERR_NUM_THREADS,              /**< wrong number of threads */
    PGASRT_ERR_BARRIER,                  /**< barrier counter error */
    PGASRT_ERR_INDEX,                    /**< index arithmetic problem */
    PGASRT_ERR_CAST                      /**< UPC casting error */
  }
__pgasrt_error_t;

struct __pgasrt_AMHeader_t;

/* ************************************************************************ */
/** \brief Local completion handler function type                           */
/* ************************************************************************ */

typedef void (* __pgasrt_LCompHandler_t) (void *);

/* ************************************************************************ */
/** \brief AM header handler data type                                      */
/* ************************************************************************ */

typedef __pgasrt_local_addr_t
(* __pgasrt_AMHeaderHandler_t) (const struct __pgasrt_AMHeader_t *,
				void (** completionHandler)(void *, void *),
				void ** arg);

/* ************************************************************************ */
/** \brief Registered AM Header handler                                     */
/* ************************************************************************ */

typedef unsigned __pgasrt_AMHeaderReg_t;

/* ************************************************************************ */
/** \brief AM header data type                                              */
/* ************************************************************************ */

typedef struct __pgasrt_AMHeader_t
{
  __pgasrt_AMHeaderReg_t       handler;    /**< header handler registration */
  unsigned                     headerlen;  /**< total bytes in header */
  //  void                       * data[1];    /**< dummy */
}
__pgasrt_AMHeader_t __attribute__((__aligned__(16)));


#define ALL_PARTITION PGASRT_THREADS




#endif
