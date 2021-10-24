add_executable(shell-app main.cpp ik.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(shell-app GL GLU glut)
