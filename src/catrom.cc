#include "DataLoader.hh"
#include "CattmullRomCurve.hh"

#include <iostream>

auto main(int argc, char** argv) -> int
{
    std::string inFilename;
    std::string outFilename;
    size_t      nPoints = 100;

    if (argc == 1)
    {
        inFilename  = "initial_points";
        outFilename = "catrom_points";
    }
    else if (argc == 3)
    {
        inFilename  = argv[1];
        outFilename = argv[2];
    }
    else if (argc == 4)
    {
        inFilename  = argv[1];
        outFilename = argv[2];
        nPoints     = std::stoi(argv[3]);
    }
    else
    {
        std::cerr << "catrom inFile outFile [points]\n";
        return 1;
    }



    std::cout << "Reading points from \"" << inFilename << "\"\n";
    auto in                 = curves::DataLoader(inFilename);

    std::cout << "Generating new points with itermediate points = " << nPoints << "\n";
    auto cms                = curves::CattmullRomCurve(in.getPoints());
    auto interpolatedPoints = cms.generate(nPoints);

    std::cout << "Saving new points to \"" << outFilename << "\"\n";
    auto out                = curves::DataLoader(interpolatedPoints);
    out.dumpPoints(outFilename);

    return 0;
}
