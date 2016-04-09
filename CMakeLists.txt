cmake_minimum_required(VERSION 3.3)
project(EvolutionaryStringMatching C CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${EvolutionaryStringMatching_SOURCE_DIR}/cmake")
set(BIN_DIR ${EvolutionaryStringMatching_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(include)
add_executable(EvolutionaryStringMatching src/main.cpp src/pugixml.cpp src/InputOutput.cpp src/XMLManager.cpp src/LocalizationManager.cpp src/EvolutionManager.cpp)

install(TARGETS EvolutionaryStringMatching RUNTIME DESTINATION ${BIN_DIR})
