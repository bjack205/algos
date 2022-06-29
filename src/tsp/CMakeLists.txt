add_library(tsp
  tsp_problem_generator.hpp
  tsp_problem_generator.cpp
)
target_link_libraries(tsp
  PUBLIC
  Eigen3::Eigen 

  PRIVATE
  fmt::fmt
)
target_include_directories(tsp
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(test)