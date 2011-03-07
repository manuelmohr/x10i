/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

#include <x10aux/config.h>
#include <x10aux/throw.h>

#include <x10/lang/Lock__ReentrantLock.h>

#include <x10/lang/IllegalMonitorStateException.h>

#include <errno.h>
#ifdef XRX_DEBUG
#include <iostream>
#endif /* XRX_DEBUG */

using namespace x10::lang;
using namespace x10aux;

x10aux::ref<Lock__ReentrantLock>
Lock__ReentrantLock::_make() {
    x10aux::ref<Lock__ReentrantLock> this_ = new (x10aux::alloc<Lock__ReentrantLock>()) Lock__ReentrantLock();
    this_->x10::lang::Object::_constructor();
    return this_;
}

void
Lock__ReentrantLock::raiseException() {
    throwException<IllegalMonitorStateException>();
}

RTT_CC_DECLS1(Lock__ReentrantLock, "x10.lang.Lock__ReentrantLock", RuntimeType::class_kind, Object)

// vim:tabstop=4:shiftwidth=4:expandtab
