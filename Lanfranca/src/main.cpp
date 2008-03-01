#include <iostream>
#include <dlfcn.h>
#include "module.hpp"
#include <string>

void usage(char *arg0);	

int main() {
	
	class module mod;
    std::string path;
	
	usage(NULL);
	std::cout << "insert module namefile: ";
	
	try {
	
	std::cin >> path;
	
	mod.loadmodule(path.c_str());
	mod.callfoo();
	
	}
	
	catch (struct modexception e) {
		
		if(e.code>=NOLOAD && e.code<=USED) {
			
			std::cout << e.msg << '\n';
			return EXIT_FAILURE;
		
		}
		
	}
	
	return EXIT_SUCCESS;

}

void usage(char *arg0) {
	
const char banner[]=
	"--]LANFranca: LAN analyzer and security tool\n"
	"--] + Written by Traktopel\n"
	"--] + Powered by N1nj4 m0nk3y c0d3\n"
	"--] + www.hack-lab.net/LANFranca\n";
	
	std::cout << banner;
	
	return;
	
}
