// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include "Texture.h"

namespace ouzel
{
    class TextureOGL: public Texture
    {
    public:
        TextureOGL(const std::string& filename, Renderer* renderer);
        virtual ~TextureOGL();
    };
}
