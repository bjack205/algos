#include <gtest/gtest.h>
#include <fmt/core.h>

#include "tsp_problem_generator.hpp"

namespace algos {

TEST(TravelingSalesman, ProblemGeneration) {
  TravelingSalesmanProblemGenerator generator;
  const int cost_max = 10;
  const int cost_min = 1;
  generator.SetCostRange(cost_min, cost_max);

  const int N = 10;
  Matrix adj = generator.GenerateProblem(N);
  EXPECT_EQ(adj.rows(), N);
  EXPECT_EQ(adj.cols(), N);
  for (int i = 0; i < N * N; ++i) {
    EXPECT_LE(adj(i), cost_max);
    EXPECT_GE(adj(i), cost_min);
  }
}

}