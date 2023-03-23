cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(eram_charge_function)

# Include ROOT stuff
find_package(ROOT CONFIG REQUIRED)
find_package(GSL REQUIRED)

add_library(ion_charge_function ion_charge_function.cc)
target_link_libraries(ion_charge_function PUBLIC GSL::gsl ROOT::Graf)

add_executable(test_main test_main.cc)
target_link_libraries(test_main PUBLIC ROOT::Core ROOT::Graf ROOT::Gpad ion_charge_function)