cmake_minimum_required(VERSION 3.0.0)
project(DesignPatterns VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "-fsanitize=undefined,address,leak -fno-omit-frame-pointer")

include(CTest)
enable_testing()

add_executable(FactoryMethod FactoryMethod.cpp)
add_executable(AbstractFactory AbstractFactory.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
