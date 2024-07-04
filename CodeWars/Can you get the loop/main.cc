/*
  author: MrS4g0
  created: 27.06.2024 08:53:20
  kata link: https://www.codewars.com/kata/52a89c2ea8ddc5547a000863/cpp
*/

#include <bits/stdc++.h>

int getLoopSize(Node* startNode) {
  std::map<Node*, int> node_idx;
  int cur_idx = 0;
  Node* prevNode = startNode;

  while (!node_idx.count(startNode)) {
    node_idx.insert({startNode, cur_idx++});
    prevNode = startNode;
    startNode = startNode->getNext();
  }

  return node_idx[prevNode] - node_idx[startNode] + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}
