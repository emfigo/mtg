cmake_minimum_required(VERSION 3.11.3)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(mtg)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(third-party/Catch2)
add_subdirectory(third-party/yaml-cpp)

file(GLOB project_SRCS ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB graph_SRCS ${CMAKE_SOURCE_DIR}/src/graph_*.cpp)
file(GLOB chat_SRCS ${CMAKE_SOURCE_DIR}/src/chat_*.cpp)
file(GLOB tests_SRCS ${CMAKE_SOURCE_DIR}/tests/test_*.cpp)
file(GLOB integration_SRCS ${CMAKE_SOURCE_DIR}/tests/integration/test_*.cpp)

add_executable(mtg ${project_SRCS})

add_library(graph ${graph_SRCS})
target_link_libraries(graph PRIVATE yaml-cpp)

add_library(chat ${chat_SRCS})
target_link_libraries(chat
  PRIVATE
    yaml-cpp
    ${wxWidgets_LIBRARIES})

target_link_libraries(mtg
  PRIVATE
    yaml-cpp
    ${wxWidgets_LIBRARIES})

add_executable(tests ${tests_SRCS})
target_link_libraries(tests
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)

add_executable(integration ${integration_SRCS})
target_link_libraries(integration
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)
