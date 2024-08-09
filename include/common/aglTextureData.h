#pragma once

#include <prim/seadSafeString.h>
#include "common/aglGPUCommon.hpp"
#include "detail/aglSurface.h"
#include "driver/aglNVNtexture.h"

namespace agl {

class TextureData {
public:
    class CompressToWork {
    public:
        explicit CompressToWork(const TextureData&);

        void* _0;
        void* _8;
        void* _10;
        void* _18;
        u32 _20;
        void* _28;
        void* _30;
        u32 _38;
        void* _40;
        detail::Surface mSurface;
        driver::NVNtexture_ mTexture;
    };

    TextureData();

    void setMipLevelNum_(s32, bool);
    u16 getMinSlice_() const;
    void getTextureFormatName() const;
    u32 calcMipByteSize(u32) const;
    bool isCompressedFormat() const;
    bool isRenderTargetCompressAvailable() const;
    bool isDepthFormat() const;
    bool hasStencil() const;
    void invalidateCPUCache();
    void flushCPUCache() const;
    void setDebugLabel(const sead::SafeString& debug_label);
    void getDebugLabel() const;

    void setImagePtr(GPUMemVoidAddr image_ptr, u32);
    void setMipPtr(GPUMemVoidAddr mip_ptr);

private:
    GPUMemVoidAddr mImagePtr;
    GPUMemVoidAddr mMipPtr;
    detail::Surface mSurface;
    TextureFormat mTextureFormat;
    u8 _56;
    driver::NVNtexture_ mNVNtexture
    const char* mDebugLabel;  // "agl::TextureData" string
};
static_assert(sizeof(TextureData) == 0x128);

}  // namespace agl
