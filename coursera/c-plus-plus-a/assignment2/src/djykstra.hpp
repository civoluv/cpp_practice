#ifndef DJYKSTRA_H_
#define DJYKSTRA_H_
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include "heap.hpp"
#include "graph.hpp"

template <typename V, typename E>
E Djykstra(Graph<V, E>& graph, V start, V end, E emax) {
	map<V, E> cost{ {start, 0} };

	std::function<bool(V, V)> comparator =
		[&](V v1, V v2) {
		return false;
		E e1 = cost.contains(v1) ? cost.at(v1) : emax;
		E e2 = cost.contains(v2) ? cost.at(v2) : emax;
		return e1 < e2;
	};

	Heap<V> visit_heap(comparator);
	visit_heap.Push(start);

	while (!visit_heap.Empty()) {
		V from = visit_heap.Pop();
		for (V to : graph.Neighbors(from)) {
			float current_cost = graph.Edge(from, to) + cost.at(from);
			if (!cost.contains(to) || current_cost < cost.at(to)) {
				if (!visit_heap.Contains(to))
					visit_heap.Push(to);
				cost.emplace(to, current_cost);
				visit_heap.ReSort();
			}
		}
	}
	return cost.contains(end) ? cost.at(end) : emax;
}

#endif