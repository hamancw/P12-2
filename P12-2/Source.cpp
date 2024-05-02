#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);
bool readFromCSVFile(string filename);

bool containsLetter(const string& word) {
	for (char c : word) {
		if (std::isalpha(c)) {
			return true;
		}
	}
	return false;
}

int main() {

	string datafile;
	cout << "Lab 12: Intro to Text Files\n";
	cout << "Enter file name: ";
	getline(cin, datafile);

	ifstream inFile;
	inFile.open(datafile);

	ifstream file(datafile);
	if (!file.is_open()) {
		cerr << "Error: Unable to open file.\n";
		return 1;
	}

	int wordCount = 0;
	int charCount = 0;
	string word;
	while (file >> word) {
		if (containsLetter(word)) {
			wordCount++;
		}
		for (char c : word) {
			if (isalpha(c)) {
				charCount++;
			}
		}
	}

	cout << "Words: " << wordCount << endl;
	cout << "Characters: " << charCount << endl;
}

void pressEnterToContinue() {
	cout << "\nPress enter to contine . . .\n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
	ifstream inFile;
	string movieTitle;
	int year;

	inFile.open(filename);
	if (inFile.fail()) {
		cout << "Read error - sorry\n";
		return false;
	}

	while (true) {
		inFile >> movieTitle >> year;
		if (inFile.fail()) break;

		cout << movieTitle << ": " << year << endl;
	}
	inFile.close();
	return true;
}

bool readFromCSVFile(string filename) {
	ifstream inFile;
	istringstream thisLine;
	string movieInfo;
	string movieTitle;
	string year;
	string director;

	inFile.open(filename);
	if (inFile.fail()) {
		cout << "Read error - sorry\n";
		return false;
	}

	while (true) {
		getline(inFile, movieInfo);
		if (inFile.fail()) break;
		thisLine.clear();
		thisLine.str(movieInfo);
		getline(thisLine, movieTitle, ',');
		getline(thisLine, year, ',');

		vector<string> directorList;
		string dir;
		while (getline(thisLine, dir, ','))
			directorList.push_back(dir);

		director = directorList[0];
		for (int i = 1; i < directorList.size(); i++) {
			director = director + " and " + directorList[i];
		}

		cout << movieTitle << " is a " << year << " film directed by " << director << endl;
	}

	inFile.close();
	return true;
}