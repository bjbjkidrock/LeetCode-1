// 681. Next Closest Time
// https://leetcode.com/problems/next-closest-time/

/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

#include <iostream>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
	string nextClosestTime(string time) {
		array<int, 2> curr;
		curr[0] = stoi(time.substr(0, 2));
		curr[1] = stoi(time.substr(3));
		array<int, 10> A;
		A.fill(0);
		++A[time[0] - '0'];
		++A[time[1] - '0'];
		++A[time[3] - '0'];
		++A[time[4] - '0'];
		do {
			f1(curr);
		} while(!f2(curr, A));
		time[0] = curr[0] / 10 + '0';
		time[1] = curr[0] % 10 + '0';
		time[3] = curr[1] / 10 + '0';
		time[4] = curr[1] % 10 + '0';
		return time;
	}
private:
	void f1(array<int, 2> & curr) {
		++curr[1];
		if (curr[1] >= 60) {
			++curr[0];
			curr[1] = 0;
			if (curr[0] >= 24) {
				curr[0] = 0;
			}
		}
	}
	bool f2(const array<int, 2> & curr, const array<int, 10> & A) {
		return A[curr[0] / 10] and A[curr[0] % 10] and A[curr[1] / 10] and A[curr[1] % 10];
	}
};

int main(void) {
	Solution solution;
	string time, result;
	
	time = "19:34";
	result = solution.nextClosestTime(time);
	cout << result << '\n';

	time = "23:59";
	result = solution.nextClosestTime(time);
	cout << result << '\n';

	return 0;
}