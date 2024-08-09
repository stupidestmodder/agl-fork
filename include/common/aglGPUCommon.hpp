#pragma once

#include <common/aglGPUMemAddr.h>

namespace agl {

enum class MemoryAttribute : u32 {
    Default = 0,
    _00 = 1 << 0,
    _01 = 1 << 1,
    CompressibleMemory = 1 << 2,
    CpuCached = 1 << 3,
    _04 = 1 << 4,
    // PHYSICAL, no CPU and GPU access.
    MemoryReserved = 1 << 7,
    GpuCached = 1 << 8,

    // TODO: More?
};

using GPUMemVoidAddr = GPUMemAddr<void>;
using ConstGPUMemVoidAddr = const GPUMemVoidAddr;

}  // namespace agl
