#include <assert.h>
#include <string.h>

#include "ajcurr.h"

int
main(void)
{
	assert(ajcurrenc("ZZZ") == 0);
	assert(ajcurrenc("AAA") == 0);
	assert(ajcurrenc("AEX") == 0);
	assert(ajcurrenc("XED") == 0);
	assert(ajcurrenc("AQD") == 0);
	assert(ajcurrenc("AED") == 1);
	assert(ajcurrenc("BYR") == 24);
	assert(ajcurrenc("BYN") == 164);

	assert(ajcurrdec(0) == NULL);
	assert(ajcurrdec(255) == NULL);
	assert(ajcurrdec(AJCURRMAX) != NULL);
	assert(ajcurrdec(AJCURRMAX + 1) == NULL);
	assert(strcmp(ajcurrdec(1), "AED") == 0);
	assert(strcmp(ajcurrdec(24), "BYR") == 0);
	assert(strcmp(ajcurrdec(164), "BYN") == 0);

	assert(ajcurrenc("uSd") == ajcurrenc("UsD"));

	assert(ajcurrenc("AEDE") == 0);
	assert(ajcurrenc("AE") == 0);
	assert(ajcurrenc("AE1") == 0);
	assert(ajcurrenc("123") == 0);
	assert(ajcurrenc("") == 0);
	assert(ajcurrenc(NULL) == 0);
} 
