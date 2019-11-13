/*실습과제#5*/
/*2019년 4월 5일*/
/*김예원*/

#include <iomanip>
#include <iostream>
#include <climits>

using namespace std;

struct Subject {	//과목정보
	char Subname[30];	//과목이름
	int Hakjum;			//과목학점
	char Grade[10];		//과목등급
	float GPA;			//과목평점
};

struct Student {	//학생정보
	char StdName[30]; 	//학생 이름
	int Hakbun;			//학번
	Subject *Sub;		//과목
	int SubNum;			//과목 수
	float AveGPA;		//교과목 평균 평점 
};

void PrintMenu();										//메뉴출력
void InputData(Student *pSt, int StudentNum);			//학생의 신상정보, 성적정보 입력함수
float CalcGPA(Subject& Sub);							//평점계산
float CalcAveGPA(int S, Subject* Sub);					//평균평점계산
void PrintAllData(const Student* pSt, int StudentNum);	//모든 데이터 출력
void PrintOneData(const Student& rSt);					//학생 한명의 데이터 출력
void PrintAllStdList(Student *pSt, int StudentNum);		//전체 학생의 학번, 이름 출력
Student* StdSearch(Student*s, int StudentNum);			//찾는 학생의 정보
void remove(Student* pSt, int StudentNum);				//동적할당 해제

int main() {
	float sum = 0;
	int StudentNum = 0;

	cout << "입력할 학생 수를 입력 : ";
	cin >> StudentNum;
	Student *St = new Student[StudentNum]; //Student 동적할당
	Student* SearchStd;

	PrintMenu(); //선택메뉴를 출력한다

	int func;
	while (1) {
		cout << "\n";
		cout << "원하는 기능을 입력하세요 : ";
		cin >> func;

		if (func == 1) {							 // 1. 학생 성적 입력
			InputData(St, StudentNum);
		}
		else if (func == 2) {						 //2. 전체 학생 성적 보기
			cout << "\n            전체 학생 성적 보기" << "\n";
			cout << "======================================================" << "\n";
			PrintAllData(St, StudentNum); //모든 학생의 정보를 출력하는 함수를 호출한다
		}
		else if (func == 3) {						//3. 학생 이름 검색
			SearchStd = StdSearch(St, StudentNum); //StdSearch 함수는 문자열을 비교해준다 //??
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd); //학생 한명의 정보를 출력하는 함수를 호출한다
			}
			else
				cout << "일치하는 학생이 없습니다." << endl; //StdSearch 함수에서 NULL 값이 반환 되었을때
		}
		else if (func == 4) {						//4. 전체 학생 목록 보기
			PrintAllStdList(St, StudentNum);

		}
		else {										//5. 프로그램 종료
			cout << "종료합니다." << endl;
		
			remove(St, StudentNum);
			return 0;
		}
	}
}

void PrintMenu() { //메뉴출력
	cout << "=====메뉴=====" << "\n";
	cout << "1. 학생 성적 입력" << "\n";
	cout << "2. 전체 학생 성적 보기" << "\n";
	cout << "3. 학생 이름 검색" << "\n";
	cout << "4. 전체 학생 목록 보기" << "\n";
	cout << "5. 프로그램 종료" << "\n";

}

void InputData(Student *pSt, int StudentNum) { //학생정보와 과목정보를 받는 함수

	int i = 0;
	while (i < StudentNum) { //학생 n명의 데이터를 입력 받는다
		cout << "\n";
		cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << "\n";
		cout << "이름 ";
		cin >> pSt[i].StdName;
		cout << "학번 ";
		cin >> pSt[i].Hakbun;
		cout << endl;

		cout << "수강한 과목수를 입력 : ";
		cin >> pSt[i].SubNum;

		pSt[i].Sub = new Subject[pSt[i].SubNum]; //Subject에 대한 동적할당

		int j = 0;
		while (j < pSt[i].SubNum) { //학생의 과목 정보를 동적할당으로 입력받는다

			cout << "\n" << "* 수강한 과목 " << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요\n";
			cout << "교과목명 : ";
			cin >> pSt[i].Sub[j].Subname;

			cout << "과목학점수 : ";
			cin >> pSt[i].Sub[j].Hakjum;

			cout << "과목등급<A+ ~ F> : ";
			cin >> pSt[i].Sub[j].Grade;
			cout << endl;

			pSt[i].Sub[j].GPA = 0;
			pSt[i].Sub[j].GPA = CalcGPA(pSt[i].Sub[j]); //교과목 평균평점-즉시 초기화
			j++;
		}
		pSt[i].AveGPA = CalcAveGPA(pSt[i].SubNum, pSt[i].Sub); //즉시 초기화
		i++;

		cout << endl;

	}
}

float CalcGPA(Subject& Sub) { //학점 평점을 계산
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

float CalcAveGPA(int S, Subject* Sub) { //교과목 평점 계산 함수
	float sum = 0;
	for (int i = 0; i < S; i++) {
		sum += Sub[i].GPA;
	}
	return sum / S;
}

void PrintAllData(const Student* pSt, int StudentNum) { //전체 학생들의 성적 정보를 출력한다
	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintOneData(const Student& s) {//학생 한명의 성적 정보를 출력한다

	cout << "이름 : " << s.StdName << "  학번 : " << s.Hakbun << "\n";
	cout << "======================================================" << "\n";
	cout << "         과목명  과목학점  과목등급  과목평점" << "\n";
	cout << "======================================================" << "\n";

	for (int i = 0; i < s.SubNum; i++) { //학생 한명의 과목n개
		cout.width(10);
		cout << s.Sub[i].Subname;					//과목명 출력
		cout.width(10);
		cout << s.Sub[i].Hakjum;					//과목학점출력
		cout.width(10);
		cout << s.Sub[i].Grade;						//과목등급 출력
		cout.precision(2);
		cout << fixed;
		cout.width(10);
		cout << s.Sub[i].GPA << "\n";				//과목평점 출력
	}

	cout << "======================================================" << "\n";

	cout.width(20);
	cout << "        평균평점      " << s.AveGPA << "\n\n"; //평균평점을 출력

}

void PrintAllStdList(Student *pSt, int StudentNum) {
	cout << "*****************************" << endl;
	cout << "      학번" << "      이름" << endl;
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

Student* StdSearch(Student *pSt, int StudentNum) { //학생 이름을 검색해 맞으면 0, 아니면 NULL을 반환한다
	char stdname[20];
	cout << "검색할 이름을 입력하시오: ";
	cin >> stdname;
	for (int i = 0; i < StudentNum; i++) {
		if (strcmp(stdname, pSt[i].StdName) == 0) {
			return (pSt + i);
		}
	}

	return NULL;
}

void remove(Student* pSt,int StudentNum) { //동적배열을 해제한다
	for (int i = 0; i < StudentNum; i++) {
			delete[] pSt[i].Sub; //Subject에 대한 동적배열 해제
	}
	delete[] pSt; //Student에 대한 동적배열 해제
	pSt = NULL;
}