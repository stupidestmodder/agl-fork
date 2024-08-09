#pragma once

#include "common/aglGPUMemBlock.h"
#include "detail/aglGPUMemBlockMgr.h"
#include "detail/aglMemoryPoolHeap.h"

namespace sead {
class Heap;
}

namespace agl {

class GPUMemAddrBase {
public:
    GPUMemAddrBase()
        : mpGPUMemPool(nullptr)
        , mByteOffset(0)
        , mpGPUMemBlock(nullptr)
    {
    }

    GPUMemAddrBase(const GPUMemBlockBase& memory, u64 byteOffset);

    bool isValid() const
    {
        return mpGPUMemPool != nullptr;
    }

    detail::MemoryPool* getGPUMemPool()
    {
        return mpGPUMemPool;
    }

    u32 getByteOffset() const
    {
        return mByteOffset;
    }

    GPUMemBlockBase* getGPUMemBlock()
    {
        return mpGPUMemBlock;
    }

    // GPUMemAddrBase byteOffset() const
    // {
    // }

    void* ptr()
    {
        if (isValid())
            return nvnMemoryPoolMap(mpGPUMemPool->getNVNmemoryPool());

        return nullptr;
    }

    u32 getAlignmentAddress() const;
    void setByteOffsetByPtr(void* ptr);
    void roundUp(s32 alignment);

    void invalidate();
    void deleteGPUMemBlock() const;
    void flushCPUCache(u64 size) const;
    void invalidateCPUCache(u64 size) const;

private:
    u32 verify_() const;

private:
    detail::MemoryPool* mpGPUMemPool;
    u32 mByteOffset;
    GPUMemBlockBase* mpGPUMemBlock;
};

// TODO
template <typename T>
class GPUMemAddr : public GPUMemAddrBase {};

}  // namespace agl
