cmake_minimum_required(VERSION 3.11.3)

add_definitions(-std=c++17)

set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-Wall -Wshadow -Wc++17-extensions")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(mtg)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

file(GLOB graph_SRCS ${CMAKE_SOURCE_DIR}/src/graph_*.cpp)
file(GLOB chat_SRCS ${CMAKE_SOURCE_DIR}/src/chat_*.cpp)

add_subdirectory(third-party/Catch2)
add_subdirectory(third-party/yaml-cpp)

add_executable(mtg ${graph_SRCS} ${chat_SRCS})

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

add_subdirectory(tests)
