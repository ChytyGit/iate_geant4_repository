cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(simple_sim)

find_package(Geant4 REQUIRED ui_all vis_all)

file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

add_executable(sim sim.cc ${headers} ${sources})
target_link_directories(sim PRIVATE include)
target_link_libraries(sim ${Geant4_LIBRARIES})