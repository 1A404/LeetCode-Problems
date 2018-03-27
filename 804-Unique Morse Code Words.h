#include"MySource.h"

class Solution {

private:
	vector<string> AlphaMorseCodeTable;

public:
	vector<string>* TestCase;

public:
	Solution() {
		AlphaMorseCodeTable = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	}

public:
	vector<string>& BuildTestCase() {
		TestCase = new vector<string>;

		int CaseSize = rand() % 19 + 1;
		for (int i = 0; i < CaseSize; ++i) {
			string word;
			int WordSize = rand() % 11 + 1;
			for (int j = 0; j < WordSize; ++j) {
				word.push_back((char)(rand() % 26 + 'a'));
			}
			word.push_back('\0');
			TestCase->push_back(word);
		}

		return *TestCase;
	}

public:

	string & StringToMorse(string& course) {
		string* result = new string;

		for (const char *p = course.c_str(); *p != '\0'; *p++) {
			*result += AlphaMorseCodeTable[*p - 'a'];
		}

		return *result;
	}

	/* 本意是将morse编码转换成唯一对应的二进制数 但是完全没有考虑到上限的问题-.- 最终还是选择了map
	int MorseToInt(string& course) {
		int result = 2, i = 1;
		for (const char *p = course.c_str(); *p != '\0'; *p++) {
			result = result * i + (*p == '-' ? 1 : 0);
			i = i * 2;
		}
		return result;
	}
	*/

	int uniqueMorseRepresentations(vector<string>& words) {

		map<string, int> ResultTable;

		for (vector<string>::iterator i = words.begin(); i != words.end(); i++) {
			ResultTable.insert(pair<string,int>(StringToMorse(*i),1));
		}

		return ResultTable.size();
	}
};
