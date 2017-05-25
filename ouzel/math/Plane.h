// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

namespace ouzel
{
    class Plane
    {
    public:
        float v[4];

        Plane()
        {
        }

        Plane(float aX, float aY, float aZ, float aW)
        {
            v[0] = aX;
            v[0] = aY;
            v[0] = aZ;
            v[0] = aW;
        }

        void flip()
        {
            v[0] = -v[0];
            v[1] = -v[1];
            v[2] = -v[2];
            v[3] = -v[3];
        }

        inline bool operator==(const Plane& plane) const
        {
            return v[0] == plane.v[0] && v[1] == plane.v[1] && v[2] == plane.v[2] && v[3] == plane.v[3];
        }

        inline bool operator!=(const Plane& plane) const
        {
            return v[0] != plane.v[0] || v[1] != plane.v[1] || v[2] != plane.v[2] || v[3] != plane.v[3];
        }
    };
}