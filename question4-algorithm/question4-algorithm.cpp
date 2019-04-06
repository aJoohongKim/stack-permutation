// question4-algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int *base = NULL;


// https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/
bool checkStackPermutation(int ip[], int op[], int n)
{
	// Input queue 
	queue<int> input;
	for (int i = 0; i < n; i++)
		input.push(ip[i]);

	// output queue 
	queue<int> output;
	for (int i = 0; i < n; i++)
		output.push(op[i]);

	// stack to be used for permutation 
	stack <int> tempStack;
	while (!input.empty())
	{
		int ele = input.front();
		input.pop();
		if (ele == output.front())
		{
			output.pop();
			while (!tempStack.empty())
			{
				if (tempStack.top() == output.front())
				{
					tempStack.pop();
					output.pop();
				}
				else
					break;
			}
		}
		else
			tempStack.push(ele);
	}

	// If after processing, both input queue and 
	// stack are empty then the input queue is 
	// permutable otherwise not. 
	return (input.empty() && tempStack.empty());
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(int *a, int l, int r) {
	int i;
	if (l == r) {
		if (checkStackPermutation(base, a, r+1)) {
			for (i = 0; i <= r; i++) {
				cout << a[i];
			}
			cout << endl;
		}
		else {
			cout << endl;
		}
		//std::cout << a << std::endl;
	}
	else {
		for (i = l; i <= r; i++) {
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i));
		}
	}
}

int main()
{
	int n;
	
	while (1) {
		cin >> n;

		if (n == 0) {
			return 0;
		}

		base = new int[n]();
		int *seed = new int[n]();
		for (int i = 0; i < n; i++) {
			seed[i] = base[i] = i + 1;
		}

		permute(seed, 0, n-1);

		cout << endl << endl;

		delete[] base;
		delete[] seed;
	}
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
