#ifndef NMEA_WRITE_H
#define nmea_write_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class nmea_write{
public:
	vector<string> push_string(string, vector<string>&);
	fstream set_file(vector<string> &);
	string int_to_string (int);
	int string_to_int(string);
	int Exclusive_OR(vector<char *>);
	vector<char*> vstring_to_char(vector<string>);
};

#endif

