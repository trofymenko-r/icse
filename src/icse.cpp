//============================================================================
// Name        : icse.cpp
// Author      : Ruslan Trofymenko
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <stdlib.h>

#include <ICSEControl.h>

using namespace std;
using namespace sys;

void PrintUsage(const char* cName)
{
   	cout << "usage: " << cName << " [options]"         << endl
         << "options: "                                << endl
         << "\t-l/--list     list of tests "           << endl
         << "\t-t/--test     specify test by name"     << endl
   		 << "\t-h/--help     print this message"       << endl;
}

int main(int argc, char** argv) {
	int Channel;
	bool State;

	if (argc != 3) {
		cerr << "error parameters" << endl;
		exit(EXIT_FAILURE);
	}

	Channel = atoi(argv[1]);
	State = atoi(argv[2]);

	CICSEControl ICSEControl;
	if (!ICSEControl.Init()) {
		cerr << "error init ICSE device" << endl;
		exit(EXIT_FAILURE);
	}

	ICSEControl.SetChanel(Channel, State);

	return 0;
}
