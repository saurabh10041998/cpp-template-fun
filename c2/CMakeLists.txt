set(EXECUTABLE c2)
add_executable(${EXECUTABLE} main.cc)
target_include_directories(${EXECUTABLE} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")