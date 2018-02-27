//
//  main.cpp
//  Delphi
//
//  Created by Rugen Heidbuchel on 15/03/2017.
//  Copyright © 2017 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>

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


#pragma mark - MAIN

ll IforM(ll M, ll N) {
    
    if (N == 1) return M;
    if (M == 1) return N;
    
    ll totalI = 0;
    for (ll i = 1; i <= M; i++) {
        ll I = IforM(M-i+1, N-1);
        totalI += I+1;
    }
    
    return totalI;
}

int main(int argc, const char * argv[]) {
    
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    
    // MAIN Begin
    
    size_t T, N;
    ll I;
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        std::cin >> N >> I;
        
        for (size_t m = 0; m <= I; m++) {
            if (IforM(m, N) >= I) {
                std::cout << caseNumber+1 << " " << m << std::endl;
                break;
            }
        }
    }
    
    // MAIN End
    
    return 0;
}
