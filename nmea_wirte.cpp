#include "nmea_write.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> nmea_write::push_string(string string1, vector<string> & vector1){
	vector1.push_back(string1);
	return vector1;
}

fstream nmea_write::set_file(vector<string> & vector4){
	fstream output;
	output.open("gga.txt" , ios::out);

	for (unsigned int i = 0; i < vector4.size(); i++)
		output  << vector4[i];
	return output;
	output.close();
}

string nmea_write::int_to_string(int i){
	string mystring;
	stringstream convert;
	convert << i;
	mystring = convert.str();

	return mystring;
}

int nmea_write::string_to_int(string mystring){
	int temp;
	temp = std::stoi(mystring);
	return temp;
}

int nmea_write::Exclusive_OR(vector<char *> myvector){
	int checksum = 0;
	for (unsigned int i = 0 ; i < myvector.size(); i++){
		checksum = checksum ^ * myvector[i];
	}
	return checksum;
   }

vector<char *> nmea_write::vstring_to_char(vector<string> myvector){
	vector<char *> mainchar;
	for (unsigned int i = 0 ; i < myvector.size(); i++)
{
	char *ch=new char[myvector[i].size()+1];
	ch[myvector[i].size()]=0;
	for (unsigned int j = 0 ; j < myvector[i].size(); j++)
	{
		memcpy(ch,myvector[i].c_str(),myvector[i].size());
	}
	mainchar.push_back(ch); 
}
	return mainchar;
}
