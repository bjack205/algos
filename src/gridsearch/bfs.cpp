#include "bfs.hpp"

#include <limits>

namespace algos {

int BFS::GetCost(const State& state) const {
  return cost_(state.x, state.y);
}

void BFS::Solve() {
  cost_.setConstant(std::numeric_limits<int>::max());

  // Start by adding the start state to the queue
  to_visit_.emplace(start_);

  while (to_visit_.size() > 0) {
    // Get the next node
    const State& state = to_visit_.front();
    int node_cost = GetCost(state);
    to_visit_.pop();

    // Loop over neighbors
    neighbors_.clear();
    AddNeighbors(state, neighbors_);
    for (const StateWithCost& neighbor_with_cost : neighbors_) {
      const State& neighbor = neighbor_with_cost.state;
      int cost_to_move_neighbor = neighbor_with_cost.cost;
      bool has_been_visited = visited_(neighbor.x, neighbor.y);
      if (has_been_visited) continue;
      int cur_neighbor_cost = GetCost(neighbor);
    }

  }
}

}  // namespace algos