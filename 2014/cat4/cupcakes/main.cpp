//
//  main.cpp
//  Cupcakes
//
//  Created by Rugen Heidbuchel on 12/03/2018.
//Copyright © 2018 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
typedef std::vector<vi> vvi;
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

using namespace std;

/**
 Uitleg van de oplossing:
 
 Het is duidelijk een knapsack-achtig probleem dat met dynamic programming opgelost moet worden.
 We definieren de functie F(s, i) als de minimale kost om een bestelling van grootte s
 te verpakken met de dozen tot en met index i.
 We kunnen deze functie recursief uitwerken:
 Neem size[i] als de grootte van de i'de doos en cost[i] als de kost van de i'de doos.
 We bekijken doos i. We kunnen dan 0 van die dozen gebruiken, of 1, ...
 Vanaf we genoeg hebben heeft het geen zin meer om meer dozen te nemen.
 Dus we nemen het minimum over alle aantallen k van F(s - k * size[i], i-1) + k * cost[i].
 We hebben immers k * size[i] kunnen inpakken met een kost van k * cost[i].
 De basisgevallen van de recursie zijn de volgende:
 Als de grootte van de bestelling <= 0 is, dan is de kost 0.
 Als i < 0, dan hebben we alle dozen bekeken.
 Als we dan nog een bestelling hebben, dus s > 0, dan hebben we hem gewoon niet ingepakt.
 De kost is dan dus oneindig.
 Als we geen bestelling meer hebben, dus s <= 0, dan is de kost weer 0.
 Aangezien we vaak dezelfde gevallen gaan bekijken, slaan we tussenresultaten op in een memo.
 */

#pragma mark - MAIN

int N, nrBoxes;
vi size, cost;
vvi memo;

int F(int s, int i) {
    if (s <= 0) return 0;
    if (i < 0) return (s <= 0 ? 0 : INF);
    if (memo[s][i] > 0) return memo[s][i];
    int k = 0, best = INF;
    while (true) {
        best = min(best, F(s - k * size[i], i-1) + k * cost[i]);
        if (k * size[i] > s) break;
        k++;
    }
    memo[s][i] = best;
    return best;
}

int main(int argc, const char * argv[]) {
    
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    
    // MAIN Begin
    
    int n;
    cin >> n;
    for (int geval = 1; geval < n+1; geval++) {
        
        cin >> N >> nrBoxes;
        size = vi(nrBoxes);
        cost = vi(nrBoxes);
        memo = vvi(N+1, vi(nrBoxes, -1));
        
        for (size_t i = 0; i < nrBoxes; i++) {
            cin >> size[i] >> cost[i];
        }
        
        cout << geval << " " << F(N, nrBoxes-1);
        if (geval < n) cout << endl;
    }
    
    // MAIN End
    
    return 0;
}
