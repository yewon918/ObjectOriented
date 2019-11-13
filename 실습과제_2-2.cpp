/*실습과제#2-2*/
/*2019년 3월 8일*/
/*김예원*/

//A
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	const int* pInt1; //상수에 대한 포인터 (Pointer to Vonstant)

	pInt1 = &i1;
	*pInt1 = 30; //상수를 가리키는 포인터이므로 불가

	return 0;
}

//B
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	int* const pInt2 = &i1; //상수포인터(Const Pointer)

	pInt2 = &i2; //다른 값 가리키기 불가능
	*pInt2 = 50;

	return 0;
}


//C
#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2; //상수에 대한 상수 포인터(Const Pointer to Constant

	p = &i1; //상수 포인터이므로 불가
	*p = 40; //상수에 대한 포인터이므로 불가

	return 0;
}*/