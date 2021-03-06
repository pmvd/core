/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh. It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed). All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).

 Generated on 2017-09-20 22:54:01 using:
 ./bin/update_pch sot sot --cutoff=5 --exclude:system --exclude:module --include:local

 If after updating build fails, use the following command to locate conflicting headers:
 ./bin/update_pch_bisect ./sot/inc/pch/precompiled_sot.hxx "make sot.build" --find-conflicts
*/

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <memory>
#include <new>
#include <ostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <osl/doublecheckedlocking.h>
#include <osl/endian.h>
#include <osl/file.hxx>
#include <osl/getglobalmutex.hxx>
#include <osl/interlck.h>
#include <osl/mutex.hxx>
#include <osl/process.h>
#include <osl/thread.h>
#include <rtl/alloc.h>
#include <rtl/character.hxx>
#include <rtl/digest.h>
#include <rtl/instance.hxx>
#include <rtl/ref.hxx>
#include <rtl/string.h>
#include <rtl/string.hxx>
#include <rtl/stringutils.hxx>
#include <rtl/textenc.h>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.h>
#include <rtl/ustring.hxx>
#include <sal/config.h>
#include <sal/detail/log.h>
#include <sal/log.hxx>
#include <sal/saldllapi.h>
#include <sal/types.h>
#include <vcl/errcode.hxx>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.h>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/Type.h>
#include <com/sun/star/uno/genfunc.hxx>
#include <cppu/unotype.hxx>
#include <o3tl/typed_flags_set.hxx>
#include <tools/lineend.hxx>
#include <tools/ref.hxx>
#include <tools/stream.hxx>
#include <tools/toolsdllapi.h>
#include <typelib/typedescription.h>
#include <uno/data.h>
#include <uno/sequence2.h>
#include <unotools/unotoolsdllapi.h>
#include <sot/exchange.hxx>
#include <sot/stg.hxx>
#include <sot/storinfo.hxx>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
