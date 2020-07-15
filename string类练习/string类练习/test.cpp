//#include<iostream>
//#include<string>
//using namespace std;
//#include<algorithm>
//class solution{
//public:
//
//	string reverseString(string s){
//		if (s.empty())
//			return s;
//
//		size_t start = 0;
//		size_t end = size_t() - 1;
//
//		while (start < end){
//			swap(s[start], s[end]);
//			++start;
//			--end;
//
//		}
//		return s;
//	}
//};
//
//class B{
//public:
//	int firstUniqChar(string s)
//	{
//		int count[256] = { 0 };
//		int size = s.size();
//
//		for (int i = 0; i < size; i++)
//		{
//			count[s[i]] += 1;
//		};
//
//		for (int i = 0; i < size; i++)
//		{
//			if (1 == count[s[i]])
//				return i;
//		}
//		return -1;
//
//
//
//	}
//};
//
//
//class C{
//
//};
//
//////找第一个空格后的字符
////int main(){
////	string line("hello world");
////		size_t pos = line.rfind(" ");
////		cout << line.size()-pos-1 << endl;
////		system("pause");
////	return 0;
////	
////}
//
//
//class D {
//public:
//	bool isPaLindrome(string s){
//		if (s.empty()){
//			return true;
//		}
//		size_t begin = 0;
//		size_t end = s.size() - 1;
////		char* p = (char*)s.c_str;
//
//		while (begin < end){
//			//从前往后找
//			while (begin != end){
//				if (isNumberorletter(s[begin]))
//					break;
//
//				++begin;
//			}
//			
//			//从后往前找
//
//			while (begin < end){
//				if (isNumberorletter(s[end]))
//					break;
//
//				--end;
//			}
//
//			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//				return false;
//
//			return true;
//			
//		}
//	}
//	
//	
//	bool isNumberorletter(char c)
//	{
//		if (c > 'a' && c < 'z' || c > 0 && c < 9 || c > 'A' && c < 'Z'){
//			return true;
//		}
//
//		return false;
//
//	}
//};
//
//
//
//class E{
//public:
//	string addstring(string num1, string num2){
//		int Lsize = num1.size();
//		int Rsize = num2.size();
//
//		if (Lsize < Rsize){
//
//			num1.swap(num2);
//			swap(Lsize, Rsize);
//		}
//
//		string strRet;
//		strRet.reserve(Lsize + 1);
//
//		char cRet = 0;
//		char cStep =0;
//
//		for (size_t i = 0; i < Lsize; ++i)
//		{
//			cRet = num1[Lsize - 1 - i] - '0' + cStep;
//			cStep = 0;
//			if (i < Rsize)
//			{
//				cRet += num2[Rsize - i - 1] - '0' + cStep;
//				cStep = 0;
//			}
//			if (10 <= cRet)
//			{
//				cRet -= 10;
//				cStep = 1;
//			}
//
//			strRet += cRet + '0';
//
//
//
//		}
//		if (cStep){
//			strRet += 1;
//			
//		}
//
//		reverse(strRet.begin(), strRet.end());
//		return strRet;
//	}
//};
//
//int main(){
//	E my;
//	string num1(10, 'a');
//	string num2("hello world");
//	string s3 =my.addstring(num1, num2);
//	system("pause");
//}_


//浅拷贝 同一份地址数据
//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//class String{
//public:
//	String(const char* str = ""){
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//		~String(){
//			if (_str)
//			{
//				delete[]_str;
//				_str = nullptr;
//			}
//		}
//private:
//	char* _str;
//	
//};
//
//void TestString()
//{
//	String s1("hello world");
//	String s2(s1);
//}
//
//int main()
//{
//	TestString();
//
//}

//深拷贝
class String{
public:
	String(const char* str = ""){
		if (nullptr == str){
			str = "";
		}

	}
};
