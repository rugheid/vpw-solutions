//
//  main.cpp
//  Jedi
//
//  Created by Rugen Heidbuchel on 15/03/2017.
//  Copyright © 2017 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi;

// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion

// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

#ifndef BELLMAN_FORD
#define BELLMAN_FORD

#include <vector>
#include <map>
#include <limits>
#include <algorithm>

template <class T>
using AdjacencyList = std::vector<std::map<size_t, T>>;

template <class T>
/**
 A struct to contain the results of the Bellman-Ford algorithm.
 */
struct BellmanFordResult {
    size_t source;
    std::vector<T> distance;
    std::vector<size_t> predecessor;
    
    /**
     Returns whether or not the graph contains a negative cycle.
     */
    bool containsNegativeCycle() {
        return distance.size() == 0;
    }
    
    /**
     Returns the distance of the shortest path to a given node.
     
     @param j The node to get to
     @return The minimum distance, or std::numeric_limits<T>::max() if there
     exists no path.
     */
    T shortestDistanceTo(size_t j) {
        return distance[j];
    }
    
    /**
     Returns the shortest path to the given node. It contains both the source
     and the end node.
     
     @param j The node to get to
     */
    std::vector<size_t> shortestPathTo(size_t j) {
        std::vector<size_t> path;
        while (j != source) {
            path.push_back(j);
            j = predecessor[j];
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

template <class T>
/**
 Contains the shortest paths from the given source to every
 node in the graph.
 You can only use this to detect negative cycles.
 
 @param graph The graph
 @param source The source node
 @return A result struct on which you can query the shortest distance and path
 
 @complexity O(VE)
 */
BellmanFordResult<T> bellmanFord(AdjacencyList<T> &graph, size_t source) {
    
    // Initialise
    T infinity = std::numeric_limits<T>::max();
    std::vector<T> distance(graph.size(), infinity);
    distance[source] = T();
    std::vector<size_t> predecessor(graph.size(), graph.size());
    
    // Relax
    for (size_t k = 0; k < graph.size(); k++) {
        for (size_t i = 0; i < graph.size(); i++) {
            if (distance[i] == infinity) continue;
            for (auto entry: graph[i]) {
                size_t j = entry.first;
                T weight = entry.second;
                if (distance[j] > distance[i] + weight) {
                    distance[j] = distance[i] + weight;
                    predecessor[j] = i;
                }
            }
        }
    }
    
    // Detect negative cycle
    for (size_t i = 0; i < graph.size(); i++) {
        if (distance[i] == infinity) continue;
        for (auto entry: graph[i]) {
            size_t j = entry.first;
            T weight = entry.second;
            if (distance[j] > distance[i] + weight) {
                return {source, {}, {}};
            }
        }
    }
    
    return {source, distance, predecessor};
}

#endif



#pragma mark - MAIN

int main(int argc, const char * argv[]) {
    
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    
    // MAIN Begin
    
    size_t T, N, E;
    AdjacencyList<int> graph;
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        
        std::cin >> N >> E;
        graph = std::vector<std::map<size_t, int>>(N);
        
        for (size_t i = 0; i < E; i++) {
            size_t s, t;
            int weight;
            std::cin >> s >> t >> weight;
            graph[s-1][t-1] = weight;
        }
        
        BellmanFordResult<int> result = bellmanFord(graph, 0);
        if (result.containsNegativeCycle()) {
            std::cout << caseNumber+1 << " min oneindig" << std::endl;
        } else {
            int path = result.shortestDistanceTo(N-1);
            if (path == std::numeric_limits<int>::max()) {
                std::cout << caseNumber+1 << " plus oneindig" << std::endl;
            } else {
                std::cout << caseNumber+1 << " " << path << std::endl;
            }
        }
    }
    
    // MAIN End
    
    return 0;
}
