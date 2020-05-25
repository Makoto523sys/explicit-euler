#ifndef _IO_SYSTEM_H_
#define _IO_SYSTEM_H_
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "explicit_euler.h"
/**
 * In the header file, we will implement IO system class, in other words, this class write down result that solving tharmal diffusion 
 * equation time by time,and you can select file, .dat, .csv, .txt take for example.
 * */

class IOsystem{
	public:
		std::string filename;
		IOsystem(std::string _filename): filename(_filename){}
		~IOsystem(){}
		inline void write_data(explicit_euler&)const;
};

void IOsystem::write_data(explicit_euler &e)const{
	double x = 0.0;
	std::ofstream out{filename};
	/*for(auto&& k: e.u){
		file << x << " " << std::scientific << k << std::endl;
		x += e.dt;
	}*/
	for(int i = 0; i < 100; i++) out << i << " ";
	out.close();
}
#endif
