#include <iostream>
using namespace std;
int main(){
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		//�ҵ���NС�Ҿ���N����������������
		if (f < N)
			l = N - f;
		else
		{
			//�ҵ���N���Ҿ���N����������������
			r = f - N;
			break;
		}
	}
	//ȡ��С����
	cout << min(l, r) << endl;
	return 0;
}
��