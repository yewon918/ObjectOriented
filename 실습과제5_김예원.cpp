/*�ǽ�����#5*/
/*2019�� 4�� 5��*/
/*�迹��*/

#include <iomanip>
#include <iostream>
#include <climits>

using namespace std;

struct Subject {	//��������
	char Subname[30];	//�����̸�
	int Hakjum;			//��������
	char Grade[10];		//������
	float GPA;			//��������
};

struct Student {	//�л�����
	char StdName[30]; 	//�л� �̸�
	int Hakbun;			//�й�
	Subject *Sub;		//����
	int SubNum;			//���� ��
	float AveGPA;		//������ ��� ���� 
};

void PrintMenu();										//�޴����
void InputData(Student *pSt, int StudentNum);			//�л��� �Ż�����, �������� �Է��Լ�
float CalcGPA(Subject& Sub);							//�������
float CalcAveGPA(int S, Subject* Sub);					//����������
void PrintAllData(const Student* pSt, int StudentNum);	//��� ������ ���
void PrintOneData(const Student& rSt);					//�л� �Ѹ��� ������ ���
void PrintAllStdList(Student *pSt, int StudentNum);		//��ü �л��� �й�, �̸� ���
Student* StdSearch(Student*s, int StudentNum);			//ã�� �л��� ����
void remove(Student* pSt, int StudentNum);				//�����Ҵ� ����

int main() {
	float sum = 0;
	int StudentNum = 0;

	cout << "�Է��� �л� ���� �Է� : ";
	cin >> StudentNum;
	Student *St = new Student[StudentNum]; //Student �����Ҵ�
	Student* SearchStd;

	PrintMenu(); //���ø޴��� ����Ѵ�

	int func;
	while (1) {
		cout << "\n";
		cout << "���ϴ� ����� �Է��ϼ��� : ";
		cin >> func;

		if (func == 1) {							 // 1. �л� ���� �Է�
			InputData(St, StudentNum);
		}
		else if (func == 2) {						 //2. ��ü �л� ���� ����
			cout << "\n            ��ü �л� ���� ����" << "\n";
			cout << "======================================================" << "\n";
			PrintAllData(St, StudentNum); //��� �л��� ������ ����ϴ� �Լ��� ȣ���Ѵ�
		}
		else if (func == 3) {						//3. �л� �̸� �˻�
			SearchStd = StdSearch(St, StudentNum); //StdSearch �Լ��� ���ڿ��� �����ش� //??
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd); //�л� �Ѹ��� ������ ����ϴ� �Լ��� ȣ���Ѵ�
			}
			else
				cout << "��ġ�ϴ� �л��� �����ϴ�." << endl; //StdSearch �Լ����� NULL ���� ��ȯ �Ǿ�����
		}
		else if (func == 4) {						//4. ��ü �л� ��� ����
			PrintAllStdList(St, StudentNum);

		}
		else {										//5. ���α׷� ����
			cout << "�����մϴ�." << endl;
		
			remove(St, StudentNum);
			return 0;
		}
	}
}

void PrintMenu() { //�޴����
	cout << "=====�޴�=====" << "\n";
	cout << "1. �л� ���� �Է�" << "\n";
	cout << "2. ��ü �л� ���� ����" << "\n";
	cout << "3. �л� �̸� �˻�" << "\n";
	cout << "4. ��ü �л� ��� ����" << "\n";
	cout << "5. ���α׷� ����" << "\n";

}

void InputData(Student *pSt, int StudentNum) { //�л������� ���������� �޴� �Լ�

	int i = 0;
	while (i < StudentNum) { //�л� n���� �����͸� �Է� �޴´�
		cout << "\n";
		cout << "*" << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << "\n";
		cout << "�̸� ";
		cin >> pSt[i].StdName;
		cout << "�й� ";
		cin >> pSt[i].Hakbun;
		cout << endl;

		cout << "������ ������� �Է� : ";
		cin >> pSt[i].SubNum;

		pSt[i].Sub = new Subject[pSt[i].SubNum]; //Subject�� ���� �����Ҵ�

		int j = 0;
		while (j < pSt[i].SubNum) { //�л��� ���� ������ �����Ҵ����� �Է¹޴´�

			cout << "\n" << "* ������ ���� " << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���\n";
			cout << "������� : ";
			cin >> pSt[i].Sub[j].Subname;

			cout << "���������� : ";
			cin >> pSt[i].Sub[j].Hakjum;

			cout << "������<A+ ~ F> : ";
			cin >> pSt[i].Sub[j].Grade;
			cout << endl;

			pSt[i].Sub[j].GPA = 0;
			pSt[i].Sub[j].GPA = CalcGPA(pSt[i].Sub[j]); //������ �������-��� �ʱ�ȭ
			j++;
		}
		pSt[i].AveGPA = CalcAveGPA(pSt[i].SubNum, pSt[i].Sub); //��� �ʱ�ȭ
		i++;

		cout << endl;

	}
}

float CalcGPA(Subject& Sub) { //���� ������ ���
	if (Sub.Grade[0] == 'A') {
		if (Sub.Grade[1] == '0') {
			Sub.GPA = Sub.Hakjum * 4.0;
		}
		else {
			Sub.GPA = Sub.Hakjum * 4.5;
		}
		return Sub.GPA;
	}
	else if (Sub.Grade[0] == 'B') {
		if (Sub.Grade[1] == '0') {
			Sub.GPA = Sub.Hakjum * 3.0;
		}
		else {
			Sub.GPA = Sub.Hakjum * 3.5;
		}
		return Sub.GPA;
	}
	else if (Sub.Grade[0] == 'C') {
		if (Sub.Grade[1] == '0') {
			Sub.GPA = Sub.Hakjum * 2.0;
		}
		else {
			Sub.GPA = Sub.Hakjum * 2.5;
		}
		return Sub.GPA;
	}
	else if (Sub.Grade[0] == 'D') {
		if (Sub.Grade[1] == '0') {
			Sub.GPA = Sub.Hakjum * 1.0;
		}
		else {
			Sub.GPA = Sub.Hakjum * 1.5;
		}
		return Sub.GPA;
	}
	else {
		Sub.GPA = Sub.Hakjum * 0.0;
		return Sub.GPA;
	}

}

float CalcAveGPA(int S, Subject* Sub) { //������ ���� ��� �Լ�
	float sum = 0;
	for (int i = 0; i < S; i++) {
		sum += Sub[i].GPA;
	}
	return sum / S;
}

void PrintAllData(const Student* pSt, int StudentNum) { //��ü �л����� ���� ������ ����Ѵ�
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintOneData(const Student& s) {//�л� �Ѹ��� ���� ������ ����Ѵ�

	cout << "�̸� : " << s.StdName << "  �й� : " << s.Hakbun << "\n";
	cout << "======================================================" << "\n";
	cout << "         �����  ��������  ������  ��������" << "\n";
	cout << "======================================================" << "\n";

	for (int i = 0; i < s.SubNum; i++) { //�л� �Ѹ��� ����n��
		cout.width(10);
		cout << s.Sub[i].Subname;					//����� ���
		cout.width(10);
		cout << s.Sub[i].Hakjum;					//�����������
		cout.width(10);
		cout << s.Sub[i].Grade;						//������ ���
		cout.precision(2);
		cout << fixed;
		cout.width(10);
		cout << s.Sub[i].GPA << "\n";				//�������� ���
	}

	cout << "======================================================" << "\n";

	cout.width(20);
	cout << "        �������      " << s.AveGPA << "\n\n"; //��������� ���

}

void PrintAllStdList(Student *pSt, int StudentNum) {
	cout << "*****************************" << endl;
	cout << "      �й�" << "      �̸�" << endl;
	cout << "*****************************" << endl;

	for (int i = 0; i < StudentNum; i++) {
		cout.width(10);
		cout << pSt[i].Hakbun;
		cout.width(10);
		cout << pSt[i].StdName << endl;
	}
	cout << endl;
	cout << "*****************************" << endl;

}

Student* StdSearch(Student *pSt, int StudentNum) { //�л� �̸��� �˻��� ������ 0, �ƴϸ� NULL�� ��ȯ�Ѵ�
	char stdname[20];
	cout << "�˻��� �̸��� �Է��Ͻÿ�: ";
	cin >> stdname;
	for (int i = 0; i < StudentNum; i++) {
		if (strcmp(stdname, pSt[i].StdName) == 0) {
			return (pSt + i);
		}
	}

	return NULL;
}

void remove(Student* pSt,int StudentNum) { //�����迭�� �����Ѵ�
	for (int i = 0; i < StudentNum; i++) {
			delete[] pSt[i].Sub; //Subject�� ���� �����迭 ����
	}
	delete[] pSt; //Student�� ���� �����迭 ����
	pSt = NULL;
}