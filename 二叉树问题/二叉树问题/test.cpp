#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1("hello Bit");
	const string s2("Hello Bit");
	
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'S';
	cout << s1 << " " << s2 << endl;
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
	s1.push_back(' ');
	s1.append("bbibi");
	s1 += 'q';
	s1 += "DBB";
	cout << s1.c_str() << endl;
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	string url("http://www.cplusplus.com/reference/string/string/find/");
	rsize_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	system("pause");
}