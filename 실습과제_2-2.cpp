/*�ǽ�����#2-2*/
/*2019�� 3�� 8��*/
/*�迹��*/

//A
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	const int* pInt1; //����� ���� ������ (Pointer to Vonstant)

	pInt1 = &i1;
	*pInt1 = 30; //����� ����Ű�� �������̹Ƿ� �Ұ�

	return 0;
}

//B
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	int* const pInt2 = &i1; //���������(Const Pointer)

	pInt2 = &i2; //�ٸ� �� ����Ű�� �Ұ���
	*pInt2 = 50;

	return 0;
}


//C
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2; //����� ���� ��� ������(Const Pointer to Constant

	p = &i1; //��� �������̹Ƿ� �Ұ�
	*p = 40; //����� ���� �������̹Ƿ� �Ұ�

	return 0;
}*/