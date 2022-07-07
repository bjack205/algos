#include <gtest/gtest.h>
#include <fmt/core.h>
#include <eigen3/Eigen/Dense>

#include "bfs.hpp"

namespace algos {

TEST(GridWorldTests, BFS_DiagonalLine) {
  BFS bfs;
  int N = 5;
  Eigen::MatrixXi grid = Eigen::MatrixXi::Zero(N, N);
  bfs.SetStart({0,0});
  bfs.SetGoal({N-1,N-1});
  bfs.Solve();
}

}