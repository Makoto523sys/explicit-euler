#ifndef _IO_SYSTEM_H_
#define _IO_SYSTEM_H_
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
/**
 * In the header file, we will implement IO system class, in other words, this class write down result that solving tharmal diffusion 
 * equation time by time,and you can select file, .dat, .csv, .txt take for example.
 * */

class IOsystem{
	public:
		std::string filename;
