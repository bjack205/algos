# algos_test(bfs gridsearch)
add_executable(bfs_test
  bfs_test.cpp
)
target_link_libraries(bfs_test
  PRIVATE
  gtest_main
  Eigen3::Eigen
  fmt::fmt
  gridsearch
)