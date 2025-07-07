//************GOVIND**********/

//MOTIVATION: PUSH YOURSELF BECAUSE NO ONE ELSE IS GOING TO DO IT FOR YOU.

// ***** QUESTION DESCRIPTION *****//

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

// Return the maximum number of events you can attend.

 

// Example 1:


// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.
// Example 2:

// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4
 

// Constraints:

// 1 <= events.length <= 105
// events[i].length == 2
// 1 <= startDayi <= endDayi <= 105



// Sort the Events on the basis of satrting day
// For any day.. If i have an option to select among events. I will choose the one that ends earlier.

// Skip the events whose end day < current Day

//Start day with ; day = events[0][0];  Don't need to start it from day 1 if the event starting smaller one from day n.

// Solution: 

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
         priority_queue<int, vector<int>, greater<int>>pq; //min-heap
        //Sort the events on the basis of Starting day

        sort(begin(events), end(events));


        int day = events[0][0];
        int i = 0;
        int count = 0; // result number of events attended

        while(!pq.empty() || i < n){
            if(pq.empty()){
             day = events[i][0];
            }
            while(i<n && events[i][0]  == day){
            pq.push(events[i][1]);
            i++;
            }

            if(!pq.empty()){
            pq.pop();
            count++;
            }

            day++;
            //skip those events whose endDay < day

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }

        return count;

    }
};

//T.C -> n(logn)