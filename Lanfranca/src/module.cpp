#include "module.hpp"
#include <iostream>

module::module(const char *s) {
	
	func=NULL;
	fd=NULL;
	
	info.modname=NULL;
	info.optstring=NULL;
	info.optchar=NULL;
	
	if(!s)
		return;
	
	loadmodule(s);

}

module::~module() {
	
	dlclose(fd);
	fd=NULL;
	func=NULL;

}

void module::callfoo() {

	mod_t *p;
	
	if(func==NULL) {

		mod_t e;
		e.code=NOFOO;
		e.msg=nocallfoomsg;
		throw e;

	}
	
	p=func();
	
	if(p!=NULL)
		throw *p;
		
	return;
	
}

void module::loadmodule(const char *s) {
	
	if(fd!=NULL || func!=NULL) {

		mod_t e;
		e.code=USED;
		e.msg=fdusedmsg;

	}	
	
	fd=dlopen(s,RTLD_LAZY);
	
	if(!fd) {
		mod_t e;
		e.code=NOLOAD;
		e.msg=noloadmsg;
		throw e;

	} 
	
	func=(mod_t *(*)())dlsym(fd,"foo");
	info.modname=(const char*)dlsym(fd,"modname");
	info.optstring=(const char*)dlsym(fd,"optstring");
	info.optchar=(const char*)dlsym(fd,"optchar");	
	
	if(!func || !info.modname || !info.optstring || !info.optchar) {

		mod_t e;
		e.code=INVALID;
		e.msg=invalidmsg;
		throw e;

	}
	

}
