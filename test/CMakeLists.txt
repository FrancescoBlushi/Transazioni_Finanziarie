cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TransazioniTest.cpp Transazione_Fixture.cpp ContoTest.cpp ClientTest.cpp CalendarioTest.cpp)
add_executable(FinanziareTests ${TEST_SOURCE_FILES})
target_link_libraries(FinanziareTests gtest gtest_main core)