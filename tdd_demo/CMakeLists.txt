cmake_minimum_required(VERSION 3.11)

project(TDD_DEMO)

set(CMAKE_CXX_STANDARD 14)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_MakeAvailable(googletest)

# Add the source files
add_executable(${PROJECT_NAME} main.cpp)

# Link Google Test with the testsInit_done_in_CMake_main)

#avoid main to init googletest and run all test
    # int main(int argc, char* argv[])
    # {
    # 	testing::InitGoogleTest(&argc, argv);
    # 	return RUN_ALL_TESTS();
    # }

#set(Init_done_in_CMake 1)
# include(GoogleTest)
# gtest_discover_tests(${PROJECT_NAME})


