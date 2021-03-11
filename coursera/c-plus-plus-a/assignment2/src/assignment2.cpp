// assignment2.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <limits>
#include "djykstra.hpp"
#include "heap.hpp"
#include "graph.hpp"

const int nvertices = 50;

using std::vector;

inline float Random(float min, float max) {
	assert(min < max);
	float normalized = static_cast<float>(rand() / static_cast<float>(RAND_MAX));
	return normalized * (max - min) + min;
}

void InitializeGraph(Graph<int, float>& graph) {
	const float density = 0.4f;
	const float distance_max = 10;
	srand(0); // Intentional

	for (int i = 0; i < nvertices; ++i)
		graph.AddVertex(i);

	for (int i = 0; i < nvertices; ++i) {
		for (int j = i + 1; j < nvertices; ++j) {
			float r = Random(0, 1);
			if (r < density) {
				float distance = Random(1, distance_max);
				graph.AddEdge(i, j, distance);
				std::cout << "edge " << i << "," << j << "=" << distance << std::endl;
			}
		}
	}
}

int main()
{
	Graph<int, float> graph;
	InitializeGraph(graph);
	
	for (int i = 0; i < nvertices; ++i) {
		float distance = Djykstra(graph, 0, i, std::numeric_limits<float>::max());
		std::cout << 0 << "->" << i << " distance = " << distance << std::endl;
	}



	return 0;
}
