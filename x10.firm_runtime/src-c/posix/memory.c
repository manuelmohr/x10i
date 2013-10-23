/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 * Copyright (C) 2013-2013 Karlsruhe Institute of Technology.  All right reserved.
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

#include "xmalloc.h"

void *mem_allocate_tlm(size_t size) {
  return malloc(size);
}

void *mem_allocate_global(size_t size) {
  return malloc(size);
}
