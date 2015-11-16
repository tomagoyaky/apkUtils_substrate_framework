/*
 * libdex.h
 *
 *  Created on: 2015Äê11ÔÂ14ÈÕ
 *      Author: peng
 */

#ifndef MODEL_DEX_DEXUTILS_H_
#define MODEL_DEX_DEXUTILS_H_

void hook();

typedef struct _DexUtils{
	void (*hook)();
}DexUtils;

#endif /* MODEL_DEX_DEXUTILS_H_ */
