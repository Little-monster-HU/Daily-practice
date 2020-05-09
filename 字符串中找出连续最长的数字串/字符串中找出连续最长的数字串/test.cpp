#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		// 数字+=到cur
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// 找出更长的字符串，则更新字符串
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res;
	return 0;
}


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];
		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};