#ifndef _IO_SYSTEM_H_
#define _IO_SYSTEM_H_
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "parameter.h"
#include "explicit_euler.h"
/**
 * In the header file, we will implement IO system class, in other words, this class write down result that solving tharmal diffusion 
 * equation time by time,and you can select file, .dat, .csv, .txt take for example.
 * */

class IOsystem{
	public:
		std::ofstream file;
		IOsystem(std::string _filename):file{_filename}{}
		inline void write_data(explicit_euler&)const;
};

void IOsystem::write_data(explicit_euler &e)const{

