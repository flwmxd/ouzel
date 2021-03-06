// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include "assets/Loader.hpp"

namespace ouzel
{
    namespace assets
    {
        class LoaderParticleSystem: public Loader
        {
        public:
            LoaderParticleSystem();
            virtual bool loadAsset(const std::string& filename, const std::vector<uint8_t>& data) override;
        };
    } // namespace assets
} // namespace ouzel
