#include "DataLoader.hh"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace curves
{
    DataLoader::DataLoader(const std::string& filename)
    {
        std::ifstream data(filename);
        if (!data.is_open())
        {
            throw std::invalid_argument("Data file could not be opened");
        }

        std::string datum;
        while (getline(data, datum))
        {
            std::vector<double> pointData{};

            size_t pos = 0;
            while ((pos = datum.find(' ')) != std::string::npos)
            {
                std::string value = datum.substr(0, pos);
                pointData.push_back(std::stod(value));
                datum.erase(0, pos + 1);
            }
            pointData.push_back(std::stod(datum));

            if (pointData.size() != 6)
            {
                throw std::invalid_argument("Data file contains invalid points");
            }

            Point pt;
            pt.point   = { pointData[0], pointData[1], pointData[2] };
            pt.tangent = { pointData[3], pointData[4], pointData[5] };

            points_.push_back(pt);
        }
    }

    auto DataLoader::dumpPoints(const std::string& filename) const -> void
    {
        std::ofstream data(filename);
        if (!data.is_open())
        {
            throw std::invalid_argument("Data file could not be opened");
        }

        for (const auto& [p, t] : points_)
        {
            data << p.x() << " " << p.y() << " " << p.z() << "\n";
        }


        data.close();
    }
}
