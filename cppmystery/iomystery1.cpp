#include <iostream>
#include <string>
#include <fstream>

int writeAppend(std::string writeThis);

int writeTrunc(std::string writeThis);

int readAppendHere();

int main()
{
	std::string inputString;
	std::cout << "Writing Test to stream!";
	inputString = "Test";
	writeAppend(inputString);
	inputString = "Test2";
	writeAppend(inputString);
	readAppendHere();
//	inputString = "Test3";
//	writeTrunc(inputString);
//	readAppendHere();

// c test

}

int writeAppend(std::string writeThis) {
	// Opens AppendHere.txt and sets a flag.  Setting multiple flags is allowed via |
	//I added binary mode as well, since from what I hear, text mode is inconsistent and I don't want to worry about it
	std::ofstream appendToThisFile("AppendHere.txt", std::ios::out | std::ios::app | std::ios::binary); 
	appendToThisFile << writeThis << std::endl;
	return 0;
}

int writeTrunc(std::string writeThis)
{
	std::ofstream appendToThisFile("AppendHere.txt", std::ios::out | std::ios::trunc);
	appendToThisFile << writeThis << std::endl;
	return 0;
}

int readAppendHere()
{
	std::string TempString;
	// Opens 
	std::ifstream readThisFile("AppendHere.txt", std::ios::in | std::ios::binary);
	if (readThisFile.is_open()){
		while (!readThisFile.eof()){
			std::getline(readThisFile, TempString);
			std::cout << TempString;
		}
	}
	readThisFile.close();
	return 0;
}
