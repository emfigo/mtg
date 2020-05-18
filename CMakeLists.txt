cmake_minimum_required(VERSION 3.11.3)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(mtg)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(third-party/yaml-cpp)

file(GLOB project_SRCS src/*.cpp)

add_executable(mtg ${project_SRCS})
target_link_libraries(mtg
  PRIVATE yaml-cpp
  ${wxWidgets_LIBRARIES})
target_include_directories(mtg PRIVATE ${wxWidgets_INCLUDE_DIRS})
