file(GLOB tests_SRCS ${CMAKE_SOURCE_DIR}/tests/test_*.cpp)

add_executable(tests ${tests_SRCS})
target_link_libraries(tests
  PRIVATE
    Catch2::Catch2
    yaml-cpp
    graph
    chat)
