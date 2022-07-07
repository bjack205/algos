#pragma once

#include <eigen3/Eigen/Dense>
#include <vector>
#include <queue>

namespace algos {

class BFS {

 public:
  struct State {
    int x;
    int y;
  };

  void Solve();
  void SetGrid(const Eigen::MatrixXi& grid) { grid_ = grid; }
  void SetStart(const State& start) { start_ = start; }
  void SetGoal(const State& goal ) { goal_ = goal; }
  int GetCost(const State& state) const;
  const std::vector<State>& GetPath() const { return path_; }

 private:
  struct StateWithCost {
    State state;
    int cost;
  };

  void AddNeighbors(const State& state, std::vector<StateWithCost>& neighbors);

  // Problem data 
  Eigen::MatrixXi grid_;     // 1 is an obstacle, 0 is open
  State goal_;
  State start_;

  // Solution data
  Eigen::MatrixXi visited_;  // 1 is an obstacle, 0 is open
  Eigen::MatrixXi cost_;  // 1 is an obstacle, 0 is open
  std::queue<State> to_visit_;
  std::vector<StateWithCost> neighbors_;
  std::vector<State> path_;
};

}