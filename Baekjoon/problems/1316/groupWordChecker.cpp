#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Inputs
{
	vector<string> words;
	int numberOfWords;
};
Inputs	getInputFromUser();
string	getWordFromUser();
int		getNumberOfGroupWords(Inputs &userInput);
bool 	isGroupWord(string &word);
int 	skipSequenceCharacter(string &word, int charIdx);
bool 	isReappearCharacter(string &word, int charIdx, char targetCharacter);
void	solver();

int main(void)
{
	solver();
}

void	solver()
{
	Inputs userInput = getInputFromUser();
	int numberOfGroupWords = getNumberOfGroupWords(userInput);

	cout << numberOfGroupWords;
}

Inputs	getInputFromUser()
{
	Inputs newInput;

	cin >> newInput.numberOfWords;
	for (int inputN = 0; inputN < newInput.numberOfWords; ++inputN)
	{
		newInput.words.push_back(getWordFromUser());
	}
	return (newInput);
}

string getWordFromUser()
{
	string newWord;

	cin >> newWord;
	return (newWord);
}

int getNumberOfGroupWords(Inputs &userInput)
{
	vector<string> &words = userInput.words;
	int numberOfGroupWords = 0;

	for (string &word : words)
	{
		numberOfGroupWords += isGroupWord(word);
	}
	return (numberOfGroupWords);
}


bool isGroupWord(string &word)
{
	const int WORD_LENGTH = word.length();
	int searchIdx = 0;
	bool isGroupped = true;

	while (searchIdx < WORD_LENGTH && isGroupped)
	{
		const char targetCharacter = word[searchIdx];
		searchIdx = skipSequenceCharacter(word, searchIdx);
		isGroupped = isReappearCharacter(word, searchIdx, targetCharacter);
	}
	return (isGroupped);
}

int skipSequenceCharacter(string &word, int charIdx)
{
	int searchIdx = charIdx + 1;

	while (searchIdx < word.length() && word[searchIdx] == word[charIdx])
	{
		++searchIdx;
	}
	return (searchIdx);
}

bool isReappearCharacter(string &word, int charIdx, char targetCharacter)
{
	int searchIdx = charIdx;

	while (searchIdx < word.length())
	{
		if (word[searchIdx] == targetCharacter)
			return (false);
		++searchIdx;
	}
	return (true);
}
