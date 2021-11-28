#include "DataLoader.hh"
#include "SubdivisionCurve.hh"

#include <iostream>

auto main(int argc, char** argv) -> int
{
    std::string inFilename;
    std::string outFilename;

    double weight     = 6.0;
    size_t iterations = 10;

    if (argc == 1)
    {
        inFilename  = "initial_points";
        outFilename = "subd_points";
    }
    else if (argc == 3)
    {
        inFilename  = argv[1];
        outFilename = argv[2];
    }
    else if (argc == 5)
    {
        inFilename  = argv[1];
        outFilename = argv[2];
        weight      = std::stod(argv[3]);
        iterations  = std::stoi(argv[4]);
    }
    else
    {
        std::cerr << "subd inFile outFile [weight] [subdivisions]\n";
        return 1;
    }

    std::cout << "Reading points from \"" << inFilename << "\"\n";
    auto in               = curves::DataLoader(inFilename);

    std::cout << "Generating new points with weight = " << weight << " and iterations = " << iterations << "\n";
    auto sdvc             = curves::SubdivisionCurve(in.getPoints());
    auto subdividedPoints = sdvc.generate(weight, iterations);

    std::cout << "Saving new points to \"" << outFilename << "\"\n";
    auto out              = curves::DataLoader(subdividedPoints);
    out.dumpPoints(outFilename);

    return 0;
}
