add_library(gridsearch
  bfs.hpp
  bfs.cpp
)
target_link_libraries(gridsearch
  PUBLIC
  Eigen3::Eigen

  PRIVATE
  fmt::fmt
)
target_include_directories(gridsearch
  INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(test)