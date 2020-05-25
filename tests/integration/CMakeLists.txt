file(GLOB integration_SRCS ${CMAKE_SOURCE_DIR}/tests/integration/test_*.cpp)

add_executable(integration ${integration_SRCS})
target_link_libraries(integration
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)
