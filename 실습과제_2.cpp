/*실습과제#2-1*/
/*2019년 3월 8일*/
/*김예원*/

#include<iostream>
#include <cstring> //int strlen(const char*);
using namespace std;

int short_word(char **arr);

int main(){
	char *ptr_ary[5]; //포인터배열 
	char animal[5][20]; //문자배열 

	for (int i = 0; i < 5; i++) { //반복문으로 5번 반복
		cout << "문자열을 입력하세요 : ";
		cin >> animal[i];
		ptr_ary[i] = animal[i]; //포인터배열을 문자배열로 초기화
		cout << "입력된 문자열 : " << animal[i] << "\n\n";
	}

	cout << "입력된 문자열 중 문자열의 길이가 가장 짧은 문자열은? " << animal[short_word(ptr_ary)]; 
	//short_world 함수 호출, 반환된 값은 즉시 animal의 인덱스가 됨

	return 0;
}

int short_word(char **arr) { //문자열 길이 비교하고 짧은 문자열의 인덱스를 반환하는 함수
	int min_index = 0;
	
	for (int i = 1; i < 5; i++) {
		if (strlen(arr[min_index]) > strlen(arr[i])) 
			min_index = i; //인덱스 찾기 및 변경
	}
	
	return min_index;
}
