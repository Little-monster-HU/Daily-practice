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


int main(){
	solution a;
	string s1("hello");
	a.reverseString(s1);
}