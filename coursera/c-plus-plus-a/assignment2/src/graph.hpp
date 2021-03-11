#ifndef GRAPH_H_
#define GRAPH_H_
#include <map>
#include <set>
#include <utility>

using std::map;
using std::make_pair;
using std::pair;
using std::set;

template <typename V, typename E>
class Graph {
public:
  
  void AddVertex(V v) { 
    neighbors_.insert(std::make_pair(v, set<V>()));
  }

  void AddEdge(V v1, V v2, E weight) {
    weights_.insert({{v1, v2}, weight });
    weights_.insert({{v2, v1}, weight });
    neighbors_.at(v1).insert(v2);
    neighbors_.at(v2).insert(v1);
  }

  set<V> Vertices() {
    set<V> vertices;
    for (auto [key, value] : vertices) {
      vertices.insert(key);
    }
    return vertices;
  }

  set<V> Neighbors(V v) {
    return neighbors_.at(v);
  }

  E Edge(V v1, V v2) {
    return weights_.at({v1, v2});
  }

private:
  map<V, set<V>> neighbors_;
  map<pair<V, V>, E> weights_;
};

#endif