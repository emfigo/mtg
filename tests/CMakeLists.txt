file(GLOB unit_SRCS ${CMAKE_SOURCE_DIR}/tests/test_*.cpp)
file(GLOB integration_SRCS ${CMAKE_SOURCE_DIR}/tests/integration/test_*.cpp)

add_executable(unit ${unit_SRCS} ${graph_SRCS})
target_link_libraries(unit
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)

add_executable(integration ${integration_SRCS} ${graph_SRCS})
target_link_libraries(integration
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)
