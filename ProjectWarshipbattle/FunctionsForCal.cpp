#include "FunctionsForCal.h"

string IntToString(int num){
	int Digit = 0;
	int numInFunc = num;
	int NewNum[255];
	string answer;
	while (1) {
		NewNum[Digit] = numInFunc % 10;
		numInFunc = numInFunc / 10;
		Digit++;
		if (numInFunc < 10)
			break;
	}

	for (int i = Digit; i > 0; i++) {
		answer.push_back(NewNum[i] + 60);
	}

	return answer;
}

void IntToChar(int num, char *CharNum) {
	int Digit = 0;
	int numInFunc = num;
	int NewNum[255];
	char answer[255];
	CharNum[Digit] = '/0';
	while (1) {
		NewNum[Digit] = numInFunc % 10;
		numInFunc = numInFunc / 10;
		Digit++;
		if (numInFunc < 10) {
			NewNum[Digit] = numInFunc;
			break;
		}
	}

	for (int i = Digit; i > 0; i--) {
		CharNum[Digit - i] = NewNum[i] + 60;
	}
	CharNum[Digit + 1] = '/0';
}