#include "CattmullRomCurve.hh"

namespace curves
{
    CattmullRomCurve::CattmullRomCurve(const std::vector<Point>& points) { points_ = points; }

    auto CattmullRomCurve::generate(size_t nPoints) const -> std::vector<Point>
    {
        std::vector<Point> points{};

        for (size_t i = 1; i < points_.size(); i++)
        {
            auto A = points_[i - 1].point;
            auto B = points_[i - 1].tangent;
            auto C = 3 * (points_[i].point - points_[i - 1].point) - points_[i].tangent
                     - 2 * points_[i - 1].tangent;
            auto D = points_[i - 1].tangent + points_[i].tangent
                     - 2 * (points_[i].point - points_[i - 1].point);

            for (size_t j = 0; j <= nPoints; j++)
            {
                auto t = static_cast<float>(j) / static_cast<float>(nPoints);

                points.emplace_back(A + t * B + std::pow(t, 2) * C + std::pow(t, 3) * D,
                                    B + 2 * t * C + 3 * std::pow(t, 2) * D);
            }
        }

        return points;
    }

}
