#include "SubdivisionCurve.hh"
#include <iostream>

namespace curves
{
    SubdivisionCurve::SubdivisionCurve(const std::vector<Point>& points) { points_ = points; }


    auto SubdivisionCurve::generate(double weight, size_t iterations) const -> std::vector<Point>
    {
        // Generate a copy of the copying of the points array
        std::vector<Point> points = points_;

        // Loop over the number of iterations
        while (iterations--)
        {
            // Generate intermediate points
            std::vector<Point> splits{};
            for (int i = 0; i < points.size() - 1; i++)
            {
                splits.push_back({ (points[i].point + points[i + 1].point) / 2, { 0, 0, 0 } });
            }

            // Combine the two arrays
            std::vector<Point> combined{};
            for (int i = 0; i < points.size() + splits.size(); i++)
            {
                combined.push_back((i % 2 == 0) ? points[i / 2] : splits[i / 2]);
            }

            // Average the pre-existing points (exept endpoints)
            for (int i = 2; i < combined.size() - 1; i += 2)
            {
                combined[i].point
                    = (combined[i - 1].point + (weight * combined[i].point) + combined[i + 1].point)
                      / (weight + 2);
            }

            points = combined;
        }

        // Return the new points
        return points;
    }
}
