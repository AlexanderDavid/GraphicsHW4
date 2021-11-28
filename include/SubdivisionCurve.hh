#pragma once

#include "DataLoader.hh"

#include <vector>

namespace curves
{
    class SubdivisionCurve
    {
    public:
        explicit SubdivisionCurve(const std::vector<Point>& points);

        [[nodiscard]] auto generate(double weight, size_t iterations) const -> std::vector<Point>;

    private:
        std::vector<Point> points_;
    };
}
