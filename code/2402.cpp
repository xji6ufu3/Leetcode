#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0); // Meeting count for each room
        
        // Min-heap: (available_time, room_id) for rooms in use
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        
        // Min-heap: available room numbers
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // Initialize all rooms as free
        for(int i = 0; i < n; ++i){
            freeRooms.push(i);
        }

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for(auto meeting: meetings){
            int start = meeting[0], end = meeting[1];
            
            // Release rooms that are now free
            while(!busyRooms.empty() && busyRooms.top().first <= start){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            int roomNum;

            if(!freeRooms.empty()){
                // Assign the meeting to the smallest available room
                roomNum = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, roomNum});
            } else {
                // Delay the meeting until the earliest room is free
                long long availTime = busyRooms.top().first;
                roomNum = busyRooms.top().second;
                busyRooms.pop();
                busyRooms.push({availTime + (end - start), roomNum});
            }
            cnt[roomNum]++;
        }
        
        // Find the room with the most meetings
        int maxCnt = 0, maxRoomNum = 0;
        for(int i = 0; i < n; i++){
            if(cnt[i] > maxCnt){
                maxCnt = cnt[i];
                maxRoomNum = i;
            }
        }
        return maxRoomNum;
    }
};