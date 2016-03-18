#include <Parser.h>
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdio.h>

void setIterator(char *acInput, int *iIterator, int iLineNumber) {
	iLineNumber *= 10;
	string zlineNumber = to_string(iLineNumber);
	//the hex beginning the line that we are searching for
	const int MAX_HEX_LEN = 6;
	char lineHex [MAX_HEX_LEN];
	lineHex[0] = '0';
	lineHex[1] = 'x';

	int bound = MAX_HEX_LEN - zlineNumber.length();
	for(int i = 2; i < bound; i++) {
		lineHex[i] = '0';
	} 
	strncpy((lineHex + bound),zlineNumber.c_str(), zlineNumber.length());
	string zEasytoSearch = acInput;
	//align the iterator with the beginning of the next hex number on the inputted line number
	(*iIterator) = zEasytoSearch.find(lineHex) + 10;
}
IPHeader parseIPHeader(char *acInput, int *iIterator) {
	IPHeader ipHeader;
	//first 16 bits
	ipHeader.version = &acInput[(*iIterator)++];
	ipHeader.IHL = &acInput[(*iIterator)++];
	strncpy(ipHeader.typeOfService,acInput + (*iIterator),2);
	(*iIterator) += 3;
	//second 16 bits
	strncpy(ipHeader.totalLength,acInput + (*iIterator),4);
	(*iIterator) += 5; 
	//third 16 bits
	strncpy(ipHeader.identification,acInput + (*iIterator),4);
	(*iIterator) += 5;
	//fourth 16 bits
	strncpy(ipHeader.fragmentOffset,acInput + (*iIterator),4);
	(*iIterator) += 5;
	//fifth 16 bits
	strncpy(ipHeader.timeToLive,acInput + (*iIterator),2);
	(*iIterator) += 2;
	strncpy(ipHeader.protocol,acInput + (*iIterator),2);
	(*iIterator) += 3;
	//sixth 16 bits
	strncpy(ipHeader.headerChecksum,acInput + (*iIterator),4);
	(*iIterator) += 5;
	//seventh 16 bits
	strncpy(ipHeader.sourceAddress1,acInput + (*iIterator),4);
	(*iIterator) += 5;
	//eigth 16 bits
	strncpy(ipHeader.sourceAddress2,acInput + (*iIterator),4);
	(*iIterator) += 5;

	//need to get to the start of the next line
	setIterator(acInput,iIterator,1);

	//ninth 16 bits
	strncpy(ipHeader.destinationAddress1,acInput + (*iIterator),4);
	(*iIterator) += 5;
	//tenth 16 bits
	strncpy(ipHeader.destinationAddress2,acInput + (*iIterator),4);
	(*iIterator) += 5;
	return ipHeader;
}
UDPHeader parseUDPHeader(char *acInput, int *iIterator) {
	UDPHeader udpHeader;

	//eleventh 16 bits
	strncpy(udpHeader.sourcePort,acInput + (*iIterator),4);
	(*iIterator) += 5;	
	//twelfth 16 bits
	strncpy(udpHeader.destinationPort,acInput + (*iIterator),4);
	(*iIterator) += 5;	
	//thirteenth 16 bits
	strncpy(udpHeader.length,acInput + (*iIterator),4);
	(*iIterator) += 5;		
	//fourteenth 16 bits
	strncpy(udpHeader.checksum,acInput + (*iIterator),4);
	(*iIterator) += 5;	

	//get the last max of two groups of 16 bits of data left on this line 
	//char data[]

	//go to the next line and loop for the rest of the data
	int lineNumber = 2;

	return udpHeader;
}

Headers parseTCPDump(char *acInput) {
	cout << "Parser:parseTCPDump()" << endl;
	cout << "Parser:parseTCPDump():acInput: " << acInput << endl;
	Headers headers;
	//holds the cursor's value that is iterating through the input
	int iIterator = 0;
	//move an iterator right up to the start of the hexadecimal numbers
	setIterator(acInput,&iIterator,0);

	headers.ipHeader = parseIPHeader(acInput,&iIterator);
	headers.udpHeader = parseUDPHeader(acInput,&iIterator);

	//third lines and on are UDP data segement, loop through this


	return headers;
}