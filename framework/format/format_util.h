/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_FORMAT_FORMAT_UTIL_H
#define BRIMSTONE_FORMAT_FORMAT_UTIL_H

#include "util/defines.h"
#include "format/format.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

// Utilities for converting API handles to the HandleId type.
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, HandleId>::type ToHandleId(const T& handle)
{
    return reinterpret_cast<uint64_t>(handle);
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, HandleId>::type ToHandleId(const T& handle)
{
    return static_cast<uint64_t>(handle);
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type FromHandleId(HandleId id)
{
    return reinterpret_cast<T>(id);
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type FromHandleId(HandleId id)
{
    return static_cast<T>(id);
}

bool ValidateFileHeader(const FileHeader& header);

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_FORMAT_UTIL_H
