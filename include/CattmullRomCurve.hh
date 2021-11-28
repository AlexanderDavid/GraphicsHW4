#pragma once

#include "DataLoader.hh"

#include <vector>

namespace curves
{
    class CattmullRomCurve
    {
    public:
        explicit CattmullRomCurve(const std::vector<Point>& points);

        [[nodiscard]] auto generate(size_t nPoints) const -> std::vector<Point>;

    private:
        std::vector<Point> points_;
    };
}
