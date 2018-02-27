//
//  main.cpp
//  Festivals
//
//  Created by Rugen Heidbuchel on 20/02/2017.
//  Copyright © 2017 Rugen Heidbuchel. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


#pragma mark - MAIN

struct Date {
    int hour, minutes;
};

bool inline operator < (Date lhs, Date rhs) {
    return lhs.hour < rhs.hour || (lhs.hour == rhs.hour && lhs.minutes < rhs.minutes);
}

bool inline operator == (Date lhs, Date rhs) {
    return lhs.hour == rhs.hour && lhs.minutes == rhs.minutes;
}

struct Event {
    Date start, end;
};

bool inline operator < (Event lhs, Event rhs) {
    return lhs.end < rhs.end;
}

int main(int argc, const char * argv[]) {
    
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    
    // MAIN Begin
    
    size_t T, N;
    std::cin >> T;
    for (size_t caseNumber = 0; caseNumber < T; caseNumber++) {
        scanf("%zi", &N);
        
        std::vector<Event> events(N);
        for (size_t i = 0; i < N; i++) {
            scanf("%i %i %i %i", &events[i].start.hour, &events[i].start.minutes, &events[i].end.hour, &events[i].end.minutes);
        }
        
        std::sort(events.begin(), events.end());
        
        int i = 0, count = 0;
        Date date = {0, 0};
        while (i < N) {
            
            Event event = events[i++];
            if (date < event.start || date == event.start) {
                date = event.end;
                count++;
            }
        }
        
        std::cout << caseNumber+1 << " " << count << "\n";
    }
    
    // MAIN End
    
    return 0;
}
