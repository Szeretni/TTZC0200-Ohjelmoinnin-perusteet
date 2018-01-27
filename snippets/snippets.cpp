#include <iostream>
using namespace std;

int main(void)
{
	char mj[10] = "1234";
	int luku = atoi(mj);
	cout << luku << endl;
	luku -= 1000;
	cout << luku << endl;
}