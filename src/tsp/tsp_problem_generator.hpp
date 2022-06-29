#pragma once

#include <cstdlib>

#include <eigen3/Eigen/Dense>

namespace algos {

using Matrix = Eigen::MatrixXd;

class TravelingSalesmanProblemGenerator {
public:
  Matrix GenerateProblem(int N);

  void SetCostRange(int min, int max);

private:
  int cost_min_ = 1;
  int cost_max_ = 10;
};

}  // algos