/*
 * libdex.h
 *
 *  Created on: 2015��11��14��
 *      Author: peng
 */

#ifndef MODEL_DEX_DEXUTILS_H_
#define MODEL_DEX_DEXUTILS_H_

void hook();

typedef struct _DexUtils{
	void (*hook)();
}DexUtils;

#endif /* MODEL_DEX_DEXUTILS_H_ */
