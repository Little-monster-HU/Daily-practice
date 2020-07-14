#include<iostream>
#include<string>
using namespace std;

class solution{
public:

	string reverseString(string s){
		if (s.empty())
			return s;

		size_t start = 0;
		size_t end = size_t() - 1;

		while (start < end){
			swap(s[start], s[end]);
			++start;
			--end;

		}
		return s;
	}
};

class B{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();

		for (int i = 0; i < size; i++)
		{
			count[s[i]] += 1;
		};

		for (int i = 0; i < size; i++)
		{
			if (1 == count[s[i]])
				return i;
		}
		return -1;



	}
};


class C{

};

////找第一个空格后的字符
//int main(){
//	string line("hello world");
//		size_t pos = line.rfind(" ");
//		cout << line.size()-pos-1 << endl;
//		system("pause");
//	return 0;
//	
//}


class D {
public:
	bool isPaLindrome(string s){
		if (s.empty()){
			return true;
		}
		size_t begin = 0;
		size_t end = s.size() - 1;
		char *p = (char *)s.c_str;

		while (begin < end){
			//从前往后找
			while (begin != end){
				if (isNumberorletter(s[begin]))
					break;

				++begin;
			}
			
			//从后往前找

			while (begin < end){
				if (isNumberorletter(s[end]))
					break;

				--end;
			}

			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
				return false;

			return true;
			
		}
	}
	
	
	bool isNumberorletter(char c)
	{
		if (c > 'a' && c < 'z' || c > 0 && c < 9 || c > 'A' && c < 'Z'){
			return true;
		}

		return false;

	}
};



