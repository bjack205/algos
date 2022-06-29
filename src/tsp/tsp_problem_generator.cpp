#include "tsp_problem_generator.hpp"

namespace algos {

int RandIntBetween(int lo, int hi) {
  int range = hi - lo + 1;
  return rand() % range + lo;
}

Matrix TravelingSalesmanProblemGenerator::GenerateProblem(int N) {
  Matrix adj = Matrix::Zero(N, N);
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i < N; ++i) {
      int cost = RandIntBetween(cost_min_, cost_max_);
      adj(i, j) = cost;
    }
  }

  return adj;
}

void TravelingSalesmanProblemGenerator::SetCostRange(int min, int max) {
  cost_min_ = min;
  cost_max_ = max;
}

} // namespace algos