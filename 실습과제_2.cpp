/*�ǽ�����#2-1*/
/*2019�� 3�� 8��*/
/*�迹��*/

#include<iostream>
#include <cstring> //int strlen(const char*);
using namespace std;

int short_word(char **arr);

int main(){
	char *ptr_ary[5]; //�����͹迭 
	char animal[5][20]; //���ڹ迭 

	for (int i = 0; i < 5; i++) { //�ݺ������� 5�� �ݺ�
		cout << "���ڿ��� �Է��ϼ��� : ";
		cin >> animal[i];
		ptr_ary[i] = animal[i]; //�����͹迭�� ���ڹ迭�� �ʱ�ȭ
		cout << "�Էµ� ���ڿ� : " << animal[i] << "\n\n";
	}

	cout << "�Էµ� ���ڿ� �� ���ڿ��� ���̰� ���� ª�� ���ڿ���? " << animal[short_word(ptr_ary)]; 
	//short_world �Լ� ȣ��, ��ȯ�� ���� ��� animal�� �ε����� ��

	return 0;
}

int short_word(char **arr) { //���ڿ� ���� ���ϰ� ª�� ���ڿ��� �ε����� ��ȯ�ϴ� �Լ�
	int min_index = 0;
	
	for (int i = 1; i < 5; i++) {
		if (strlen(arr[min_index]) > strlen(arr[i])) 
			min_index = i; //�ε��� ã�� �� ����
	}
	
	return min_index;
}
