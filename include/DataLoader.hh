#pragma once

#include <string>

#include <Eigen/Dense>

namespace curves
{
    struct Point
    {
        Eigen::Vector3d point;
        Eigen::Vector3d tangent;

        Point(Eigen::Vector3d p, Eigen::Vector3d t)
        {
            point   = std::move(p);
            tangent = std::move(t);
        }

        Point()
        {
            point   = {};
            tangent = {};
        }
    };

    class DataLoader
    {
    public:
        explicit DataLoader(const std::string& filename);
        explicit DataLoader(std::vector<Point> points)
        : points_(std::move(points))
        {
        }

        auto dumpPoints(const std::string& filename) const -> void;

        [[nodiscard]] auto getPoints() const -> const std::vector<Point> { return points_; }

    private:
        std::vector<Point> points_;
    };
}
