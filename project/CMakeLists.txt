cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(simple_sim)

find_package(Geant4 REQUIRED ui_all vis_all)

file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB macros ${PROJECT_SOURCE_DIR}/macros/*.mac)

#копируем файлы макросов в СБОРКУ проекта, именно так наш .exe сможет их увидеть
file(COPY ${macros} DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(sim sim.cc ${headers} ${sources})
target_link_libraries(sim ${Geant4_LIBRARIES})
target_include_directories(sim PRIVATE include)