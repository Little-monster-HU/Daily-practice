#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		// ����+=��cur
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			// �ҳ��������ַ�����������ַ���
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
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];
		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};