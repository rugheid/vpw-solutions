//
//  main.cpp
//  Bezienswaardigheden
//
//  Created by Rugen Heidbuchel on 03/02/2017.
//  Copyright © 2017 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <algorithm>

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

struct Point {
    double x, y;
    
    Point() {
        x = 0; y = 0;
    }
};

inline bool operator<(const Point& lhs, const Point& rhs) {
    return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));
}

double distance(Point &lhs, Point &rhs) {
    return std::sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}


#pragma mark - MAIN

int main(int argc, const char * argv[]) {
    
    #ifdef USE_INPUT_FILE
    freopen("input_competition.txt", "r", stdin);
    #endif
    
    // MAIN Begin
    
    size_t aantalSteden;
    std::cin >> aantalSteden;
    std::vector<Point> points;
    std::vector<double> minDistance;
    for (size_t caseNumber = 0; caseNumber < aantalSteden; caseNumber++) {
        
        size_t n;
        std::cin >> n;
        points.resize(n);
        
        for (size_t i = 0; i < n; i++) {
            std::cin >> points[i].x >> points[i].y;
        }
        
        std::sort(points.begin(), points.end());
        
        minDistance.resize(n-1);
        minDistance[0] = distance(points[0], points[1]);
        
        for (size_t i = 1; i < n-1; i++) {
            double minimum = std::numeric_limits<int>::max();
            for (size_t j = 0; j < i; j++) {
                double dist = distance(points[i+1], points[j]) + minDistance[j];
                for (size_t k = j+1; k < i; k++) {
                    dist += distance(points[k], points[k+1]);
                }
                minimum = std::min(minimum, dist);
            }
            minDistance[i] = minimum;
        }
        
        std::cout << caseNumber+1 << " " << std::round(minDistance[n-2] + distance(points[n-2], points[n-1])) << std::endl;
    }
    
    // MAIN End
    
    return 0;
}
