find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(curves_lib
            "../include/DataLoader.hh"
            DataLoader.cc
            "../include/SubdivisionCurve.hh"
            SubdivisionCurve.cc
            "../include/CattmullRomCurve.hh"
            CattmullRomCurve.cc)

add_library(curves::lib ALIAS curves_lib)
target_link_libraries(curves_lib PUBLIC Eigen3::Eigen)
target_include_directories(curves_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_executable(subd "subd.cc")
target_link_libraries(subd PRIVATE curves::lib)

add_executable(catrom "catrom.cc")
target_link_libraries(catrom PRIVATE curves::lib)
