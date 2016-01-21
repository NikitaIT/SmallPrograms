#include <iostream>
#include <cstring>
using namespace std;


bool argument(int argc, char *argv[], bool &BlackW, bool &Negative, bool &help){
	if (argc < 2){
		cout << "��������� �� ������" << endl;
		return false;
	}
	if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
		help = true;
		return true;
	}
	if ((argc < 3) && strcmp(argv[1], "-h") && strcmp(argv[1], "--help")){
		cout << "������� ������ ���������" << endl;
		return false;
	}

	// ���������� ��������� <options>
	for (int i = 1; i < argc - 2; i++){
		if (!strncmp(argv[i], "-b", 2) || !strncmp(argv[i], "--BlackW", 7))  BlackW = true;
		if (!strncmp(argv[i], "-n", 2) || !strncmp(argv[i], "--Negative", 8)) Negative = true;
		if (!strncmp(argv[i], "-h", 2) || !strncmp(argv[i], "--Help", 5)) help = true;
	}

	return true;
}