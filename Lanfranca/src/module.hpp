#ifndef MODULE_HPP
#define MODULE_HPP

#include <dlfcn.h>
#include <iostream>
#include "Module/plugin.h"

enum {NOLOAD,INVALID,NOFOO,USED};

const char noloadmsg[]="--]FATAL: I did not find this module";
const char invalidmsg[]="--]FATAL: this is'nt a valid module";
const char nocallfoomsg[]="--]FATAL: I have'nt a foo(); function to call";
const char fdusedmsg[]="--]FATAL:this descriptor is just used";

struct modinfo {
	
	const char *modname;
	const char *optstring;
	const char *optchar;

};
	

class module {
	
	private:
	
	void *fd;
	mod_t *(*func)();
	struct modinfo info;
	
	public:
	
	module(const char *s=NULL);
	~module();
	void loadmodule(const char *s);
	void callfoo();

};


#endif
