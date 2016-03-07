#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <clocale>
#include <locale.h>
#include <iomanip>
#include <vector>
using namespace std;
bool sravnenie(const char *comand[],int i){
		for (size_t j = 0; j < string(comand[i]).size(); ++j) if (*(comand[i]+j) !='-') if (!isdigit(*(comand[i]+j)))return 0;
		return 1;
}
int razlichie(const char *comand,const char *st){
	int longg;
	if (string(comand).size()>string(st).size()) longg=string(st).size();
	else longg=string(comand).size();
	for (int j = 0; j < longg; ++j) if (*(comand+j) !=*(st+j)) return j;
	return longg;
}

bool alfschetf(int &razmer,const char *comand[], int &colcomand){
	for (int i = 1; i < razmer-1; i++){
		if (((2 == razlichie(comand[i],"-a"))&&(1 != razlichie(comand[i+1],"-")))){colcomand=colcomand+2;return 0;}
		if(11 == razlichie(comand[i],"--alphabet=")){colcomand++;return 0;}
	}
	return 1;
}
int kf(int &razmer,const char *comand[], bool &k, int &colcomand){
    	for (int i = razmer-1; i > 0; i--) 
    		if (sravnenie(comand,i)){ colcomand++; k=0; return atoi(comand[i]);}
}
string af(int &razmer,const char *comand[],int &contyr){
	for (int i = 1; i < razmer-1; i++){
		if ((2 == razlichie(comand[i],"-a"))&&(1 != razlichie(comand[i+1],"-"))&&(11 != razlichie(comand[i],"--alphabet="))){contyr=0;return comand[i+1];}
		if (11 == razlichie(comand[i],"--alphabet=")){contyr=11;return comand[i];}
	}
}
bool SHIFRf(int &razmer,const char *comand[], int &colcomand){
	for (int i = 1; i < razmer-1; i++){ 
		if ((13 == razlichie(comand[i],"--type=decode"))){colcomand++;return 0;}
		if ((2 == razlichie(comand[i],"-t"))&&(6 == razlichie(comand[i+1],"decode"))){colcomand=colcomand+2;return 0;}
		if ((2 == razlichie(comand[i],"-t"))&&(6 == razlichie(comand[i+1],"encode"))){colcomand=colcomand+2;return 1;}
	}
	return 1;
}
string norma(){ return "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";}

void code(bool SHIFR,int KL,string &alphabet,int contyr,std::vector<char> &v){
	alphabet=alphabet.erase (0,contyr); 
	if (SHIFR){
		for (size_t i = 0; i < v.size(); ++i)
			for (size_t a = 0; a < alphabet.length(); ++a)
				if (v[i] == alphabet[a]){ v[i]=alphabet[(a+KL)%alphabet.length()]; break; }
	}
	else
	for (size_t i = 0; i < v.size(); ++i)
		for (int a = 0; a < alphabet.length(); ++a) 
			if (v[i] == alphabet[a]){v[i]=alphabet[(a-KL+alphabet.length()*KL)%alphabet.length()];break;}
}
const char * inputf(int &razmer, const char *comand[], int &colcomand){
	for (int i = 1; i < razmer; i++)
		if (sravnenie(comand,i)){
			if (i==razmer-1)return "0";
			else{
				if (i==razmer-2)return "0";
				else 
				if(i==razmer-3){colcomand++;return comand[i+2];}
			}
		}
}
const char * PUTf(int &razmer, const char *comand[], int &colcomand){
	for (int i = 1; i < razmer; i++)
		if (sravnenie(comand,i))
			if (i==razmer-1) return "0";
			else if ((i==razmer-2)||(i==razmer-3)){colcomand++;return comand[i+1];}
}
bool co(bool SHIFR,int KL,string alphabet, const int contyr, const char * PUT){
	std::vector<char> v;
	if (FILE *BHOD = fopen(PUT, "r")){
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), BHOD))
			v.insert(v.end(), buf, buf + len);
		fclose(BHOD);
		}
		else return 1;
		ofstream BHOD;
		BHOD.open(PUT);
		code(SHIFR,KL,alphabet,contyr,v);
		for (size_t i = 0; i < v.size(); i++){BHOD << v[i];}
		BHOD.close();
		return 0;
}
void help(int &razmer,const char *comand[],int &colcomand){
	for (int i = 1; i < razmer; i++)
		if ((2 == razlichie("-h",comand[i]))||(6 == razlichie("--help",comand[i]))){	
			colcomand++;
			cout <<"$ crypt [options] <Key> <source> [<dest>]\n"
			<<"options:\n"
			<<"    -a, --alphabet=<alphabet>  alphabet — алфавит для работы алгоритма (по умолчанию \n"
			<<"                               содержит буквы из латниского алфавита и цифры: AaBbCc..Zz0..9)\n"
			<<"    -t, --type=<type>          type может быть 'encode\' или \'decode\', по умолчанию — encode\n"       
			<<"    -h, --help                 выводит эту справку\n"
			<<"     \n"
			<<"Key:\n"
			<<"    ключ для шифрования/дешифрования\n"
			<<" \n"
			<<"source:\n"
			<<"    исходный файл для шифрования/дешифрования\n"
			<<"     \n"
			<<"dest:\n"
			<<"    файл, куда будет записан новый, зашифрованный текст. Если не указан, то переписывает source"<< endl;
		}
}
bool coco(bool SHIFR,int KL,string &alphabet, int contyr, const char * PUT, const char * input){
	std::vector<char> v;
	if (FILE *BHOD = fopen(PUT, "r")){
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), BHOD))
			v.insert(v.end(), buf, buf + len);
		fclose(BHOD);
	}
	else return 1;
	ofstream BHOD;
	BHOD.open(input);
	if (!BHOD.is_open()){cout << "oshibka";return 1;}
	code(SHIFR,KL,alphabet,contyr,v);
	for (size_t i = 0; i < v.size(); i++){BHOD <<v[i];}
	BHOD.close();
	return 0;
}

int main(int razmer, const char *comand[]){
	if (razmer > 1){
		string alphabet;
		int colcomand=0;
		help(razmer,comand,colcomand);
		int contyr = 0;
		bool congruence;
		bool k = 1;
		int KL = kf(razmer,comand,k,colcomand);
		bool SHIFR = SHIFRf(razmer,comand,colcomand);
		bool alfschet = alfschetf(razmer,comand,colcomand); 
		if ((KL<0)||(k)){cout << "Net klucha" << endl;return 0;}
		if (alfschet) alphabet = norma();
		else alphabet = af(razmer,comand,contyr);
		const char *PUT = PUTf(razmer,comand,colcomand);
		const char *input= inputf(razmer,comand,colcomand);
		if (PUT != "0")
			if (input != "0") congruence = coco(SHIFR,KL,alphabet,contyr,PUT,input);
			else congruence = co(SHIFR,KL,alphabet,contyr,PUT);
		else {cout << "pyt ne naiden" << endl;return 0;}
		if(congruence) {cout << "oshibka" << endl;return 0;}
		if (razmer-1 != colcomand){cout<<" plohie comandi"<<" \n";return 0;}
		return 0;
	}
}