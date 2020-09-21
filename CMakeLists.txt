cmake_minimum_required(VERSION 3.0)
project(CodeCadetCompiler)
set(CMAKE_CSS_STANDARD 20)
add_library(Core src/lexer/lexer.cpp)
add_executable(Main ./main.cpp)
target_link_libraries(Main Core)

set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)
add_subdirectory(third_party/googletest)
target_compile_definitions(gtest
  PUBLIC
    GTEST_LANG_CXX20
    GTEST_HAS_TR1_TUPLE=0
)
add_executable(tests)
target_sources(tests
  PRIVATE
    unit_tests/lexerTest.cpp
)
set_target_properties(tests PROPERTIES COMPILE_FLAGS "${cxx_strict}")
target_link_libraries(tests gtest gtest_main Core)
