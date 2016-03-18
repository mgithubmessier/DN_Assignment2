#include <Parser.h>
#include <fstream>
#include <iostream>

string getExample() {
	cout << "main:getExample()" << endl;
	fstream inputFile;
	inputFile.open("example.txt");
	string line;
	string wholeFile;
	while(getline(inputFile,line)) {
    	remove(line.begin(),line.end(),' ');
    	wholeFile += line;
  }
  cout << "main:getExample():wholeFile: " << wholeFile << endl;
  return wholeFile.c_str();
}
void printHeaders(Headers headers) {
	cout << "main:printHeaders()" << endl;
	cout << "+-----------------------------------+-----------------------------------+" << endl;
	cout << "|        |        |        |        |        |        |        |        |" << endl;
	cout << "|Version |IHL     |Type of Service  |Total Length                       |" << endl;
}
int main(int argc, char *argv[]) {
	string zExample = getExample();
	char acExample [zExample.length() + 1];
	const char *convertString = zExample.c_str();
	strcpy(acExample,convertString);
	//Headers headers = parseTCPDump(*argv);
	Headers headers = parseTCPDump(acExample);
	printHeaders(headers);
}
