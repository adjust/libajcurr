#include <stdint.h>

#include "ajcurr.h"

static const char codes[][4] = {
#include "codes.h"
};

#define upper(s) ((s) & ~0x20202020)

static int
isalphaC(const char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static int
isvalid(const char *code)
{
	return code &&
		isalphaC(code[0]) && isalphaC(code[1]) && isalphaC(code[2]) &&
		code[3] == 0;
}

ajcurr
ajcurrenc(const char *code)
{
	/* All this casting is to avoid string comparisons for extra speed */
	uint32_t hash;

	if(!isvalid(code))
		return 0;
	
	hash = upper(*(uint32_t *)code);

	for(unsigned i = 0; i < AJCURRMAX; ++i){
		if(*(uint32_t *)(codes[i]) == hash)
			return i + 1;
	}
	return 0;
}

const char *
ajcurrdec(ajcurr curr)
{
	if(curr == 0)
		return 0;
	if(curr > AJCURRMAX)
		return 0;
	return (const char *)(codes + curr - 1);
}
