class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       // Sorting the meetings array based on their start times.
        sort(meetings.begin(), meetings.end());
        
        // now we will do merging of overlapping intervals
        int first = meetings[0][0]; // First meeting's start time
        int last = meetings[0][1];  // First meeting's end time
        
        // Iterating through the meetings from the second one
        int len = meetings.size();  // Storing the length of the meetings array
        for(int i = 1; i < len; i++) {
            // If there's an overlap with the current meeting and the last one
            if(last >= meetings[i][0]) {
                last = max(last, meetings[i][1]);// like[1,5],[5,9]=[1,9]
            }
  // If there's no overlap, calculate the non-overlapping days and update 
            // the first and last meeting's times.
            else {
                days -= (last - first + 1); // Subtracting the non-overlapping days
                first = meetings[i][0]; // Updating the start time of the new meeting
                last = meetings[i][1]; // Updating the end time of the new meeting
            }
        }
        
        // Subtracting the non-overlapping days for the last interval.
        days -= (last - first + 1);
        
        return days; // Returning the remaining days
    }
};
