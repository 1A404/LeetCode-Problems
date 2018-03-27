#include"MySource.h"

class Solution {

public:
	struct TestCaseType{
		string J;
		string S;

		TestCaseType(string& J, string& S) { this->J = J; this->S = S; }
	};

public:
	TestCaseType* TestCase;

public:
	TestCaseType& BuildTestCases() {

		string J, S;



		TestCase = new TestCaseType(J,S);
	}

public:
	int numJewelsInStones(string J, string S) {
		
		int result = 0;

		map<char, int> Jewels;

		for (const char *p = J.c_str(); *p != '\0'; p++) {
			Jewels.insert(pair<char, int>(*p, 1));
		}

		map<char, int>::iterator JewelsEnd = Jewels.end();
		for (const char *p = S.c_str(); *p != '\0'; p++) {
			if (Jewels.find(*p) != JewelsEnd) result++;
		}

		return result;
	}
};