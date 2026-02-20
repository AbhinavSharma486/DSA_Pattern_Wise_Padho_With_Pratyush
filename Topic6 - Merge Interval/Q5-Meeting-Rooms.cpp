// * Question :- Meeting Rooms II
// & Link :- https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minMeetingRooms(vector<int> &start, vector<int> &stop)
{
  int n = start.size();

  // sort the both start and stop arrays
  sort(start.begin(), start.end());
  sort(stop.begin(), stop.end());

  int result = 0;
  int room = 0;
  int i = 0, j = 0;

  // 2 pointer approach
  while (i < n && j < n)
  {
    // agar start[i] < stop[j] hai
    // start agar chota hota hai iss ka matlab hai ke room dene hai
    if (start[i] < stop[j])
    {
      room++;
      i++;
      result = max(result, room);
    }

    // agar start bda hai / stop chota hai iss ka matlab hai ke room toodna hai
    else
    { // agar start[i] >= stop[j] hai
      room--;
      j++;
    }
  }

  return result;
}
int main()
{
  vector<int> start = {1, 10, 7};
  vector<int> stop = {4, 15, 10};

  int result = minMeetingRooms(start, stop);

  cout << "The minimum no. of meeting rooms required are : " << result;

  return 0;
}