#include "day_08.h"
#include "aoc.h"
#include <bits/stdc++.h>

#define ll long long

int deleted = 0;

struct Node {
  std::string value;
  Node *left;
  Node *right;

  Node(const std::string &val) : value(val), left(nullptr), right(nullptr) {}
};

Node *Build_Tree(const std::vector<std::string> *input) {
  std::unordered_map<std::string, Node *> node_map;
  for (int i = 2; i < (*input).size(); i++) {
    const std::string &line = (*input)[i];
    const std::string &node_value = line.substr(0, 3);
    node_map[node_value] = new Node(node_value);
  }

  for (int i = 2; i < (*input).size(); i++) {
    const std::string &line = (*input)[i];
    const std::string &node_value = line.substr(0, 3);
    size_t open_paren_idx = line.find('(');
    std::string left_node_value = line.substr(open_paren_idx + 1, 3);
    size_t comma_idx = line.find(',');
    std::string right_node_value = line.substr(comma_idx + 2, 3);
    if (node_value != left_node_value) {
      node_map[node_value]->left = node_map[left_node_value];
    }
    if (node_value != right_node_value) {
      node_map[node_value]->right = node_map[right_node_value];
    }
  }

  return node_map["AAA"];
}

void Day_08::Solution_01(const std::vector<std::string> *input) {
  const std::string instructions = (*input)[0];
  Node *root_node = Build_Tree(input);

  int steps = 0;
  while (root_node->value != "ZZZ") {
    char ins = instructions[steps % instructions.size()];
    steps++;
    if (ins == 'L')
      root_node = root_node->left;
    if (ins == 'R') {
      root_node = root_node->right;
    }
  }
  std::cout << steps << "\n";
}

std::vector<Node *> Build_Tree_2(const std::vector<std::string> *input) {
  std::unordered_map<std::string, Node *> node_map;
  for (int i = 2; i < (*input).size(); i++) {
    const std::string &line = (*input)[i];
    const std::string &node_value = line.substr(0, 3);
    node_map[node_value] = new Node(node_value);
  }

  for (int i = 2; i < (*input).size(); i++) {
    const std::string &line = (*input)[i];
    const std::string &node_value = line.substr(0, 3);
    size_t open_paren_idx = line.find('(');
    std::string left_node_value = line.substr(open_paren_idx + 1, 3);
    size_t comma_idx = line.find(',');
    std::string right_node_value = line.substr(comma_idx + 2, 3);
    if (node_value != left_node_value) {
      node_map[node_value]->left = node_map[left_node_value];
    }
    if (node_value != right_node_value) {
      node_map[node_value]->right = node_map[right_node_value];
    }
  }

  std::vector<Node *> root_nodes;
  for (std::pair<std::string, Node *> n : node_map) {
    if (n.second->value[2] == 'A') {
      root_nodes.push_back(n.second);
    }
  }
  return root_nodes;
}

void Day_08::Solution_02(const std::vector<std::string> *input) {
  const std::string instructions = (*input)[0];
  std::vector<Node *> root_nodes = Build_Tree_2(input);
  std::vector<ll> step_totals;

  for (Node *node : root_nodes) {
    ll steps = 0;
    while (node->value[2] != 'Z') {
      char ins = instructions[steps % instructions.size()];
      steps++;
      if (ins == 'L')
        node = node->left;
      if (ins == 'R') {
        node = node->right;
      }
    }
    std::cout << steps << "\n";
    step_totals.push_back(steps);
  }

  std::cout << AOC::LCM(step_totals) << "\n";
}
