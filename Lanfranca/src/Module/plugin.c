#include <stdio.h>
#include "plugin.h"
/*
 * 
 * module Skeleton:
 * const char modname[] <- name of the module; 
 * const char optchar  <- needed for getopt selection
 * const char opstring[] <- output of getopt for this plugin
 * mod_t error; <- needed for the core to handle the exception
 *  mod_t *foo(fooarg a); <- function linked to the core
 * 
 * 
 */

const char modname[]="test v0.1";
const char optchar[]="z";
const char optstring[]="this is only a test module";

mod_t err;

mod_t *foo() {
	err.code=2;
	err.msg="buahahhaha";
	printf("Yeah, i'm your favourite foo(); function\n");
	
	return NULL;
}

