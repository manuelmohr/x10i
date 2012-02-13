#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#ifdef XRX_DEBUG
#define __xrxDPr() \
do { \
		fprintf(stderr, "%s: <<...called...>>\n", __func__); \
} while(0)

#define __xrxDPrStart() \
do { \
		fprintf(stderr, "%s: <<...call begin\n", __func__); \
} while(0)

#define __xrxDPrEnd() \
do { \
		fprintf(stderr, "%s: call end...>>\n", __func__); \
} while(0)

#define __xrxDPrMesg(message) \
do { \
		fprintf(stderr, "%s: <<%s>>\n", __func__, message); \
} while(0)

#else /* !XRX_DEBUG */

#define __xrxDPr() \
do { \
	/* do nothing */ \
} while(0)

#define __xrxDPrStart() \
do { \
	/* do nothing */ \
} while(0)

#define __xrxDPrEnd() \
do { \
	/* do nothing */ \
} while(0)

#define __xrxDPrMesg(message) \
do { \
	/* do nothing */ \
} while(0)

#endif /* XRX_DEBUG */

#endif
