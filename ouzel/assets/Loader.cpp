// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "Loader.hpp"
#include "Cache.hpp"

namespace ouzel
{
    namespace assets
    {
        Loader::~Loader()
        {
            if (cache)
            {
                cache->removeLoader(this);
            }
        }
    } // namespace assets
} // namespace ouzel
