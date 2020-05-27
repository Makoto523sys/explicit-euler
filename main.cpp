#include<iostream>
#include"explicit_euler.h"
#include"IOsystem.h"
#include<string>

int main(void){
	explicit_euler e;
	IOsystem io{"test.txt"};
	e.solve();
	std::cout << std::endl;
	io.write_data(e);
	return 0;
}
