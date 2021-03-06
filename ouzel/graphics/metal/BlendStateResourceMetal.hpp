// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include "core/Setup.h"

#if OUZEL_COMPILE_METAL

#include "graphics/BlendStateResource.hpp"

#if defined(__OBJC__)
#import <Metal/Metal.h>
#else
#include <objc/objc.h>
typedef NSUInteger MTLBlendFactor;
typedef NSUInteger MTLBlendOperation;
typedef NSUInteger MTLColorWriteMask;
#endif

namespace ouzel
{
    namespace graphics
    {
        class BlendStateResourceMetal: public BlendStateResource
        {
        public:
            BlendStateResourceMetal();

            virtual bool init(bool newEnableBlending,
                              BlendState::BlendFactor newColorBlendSource, BlendState::BlendFactor newColorBlendDest,
                              BlendState::BlendOperation newColorOperation,
                              BlendState::BlendFactor newAlphaBlendSource, BlendState::BlendFactor newAlphaBlendDest,
                              BlendState::BlendOperation newAlphaOperation,
                              uint8_t newColorMask) override;

            MTLBlendOperation getRGBBlendOperation() const { return rgbBlendOperation; }
            MTLBlendOperation getAlphaBlendOperation() const { return alphaBlendOperation; }
            MTLBlendFactor getSourceRGBBlendFactor() const { return sourceRGBBlendFactor; }
            MTLBlendFactor getDestinationRGBBlendFactor() const { return destinationRGBBlendFactor; }
            MTLBlendFactor getSourceAlphaBlendFactor() const { return sourceAlphaBlendFactor; }
            MTLBlendFactor getDestinationAlphaBlendFactor() const { return destinationAlphaBlendFactor; }
            MTLColorWriteMask getColorWriteMask() const { return colorWriteMask; }
            bool isMetalBlendingEnabled() const { return metalBlendingEnabled; }

        protected:
            MTLBlendOperation rgbBlendOperation;
            MTLBlendOperation alphaBlendOperation;
            MTLBlendFactor sourceRGBBlendFactor;
            MTLBlendFactor destinationRGBBlendFactor;
            MTLBlendFactor sourceAlphaBlendFactor;
            MTLBlendFactor destinationAlphaBlendFactor;
            MTLColorWriteMask colorWriteMask;
            bool metalBlendingEnabled;
        };
    } // namespace graphics
} // namespace ouzel

#endif
