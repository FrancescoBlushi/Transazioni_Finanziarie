cmake_minimum_required(VERSION 3.23)
project(Transazioni_Finanziarie)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)

add_executable(Transazioni_Finanziarie main.cpp)
set(SOURCE_FILE Transazioni.cpp Transazioni.h Conto.cpp Conto.h)
add_library(core ${SOURCE_FILE})
target_link_libraries(Transazioni_Finanziarie core)
