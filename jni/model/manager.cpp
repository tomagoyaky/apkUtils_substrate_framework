/*
 * manager.cpp
 *
 *  Created on: 2015��11��14��
 *      Author: peng
 */

#include "dex/dexUtils.h"

DexUtils *dexUtils = {0};

int start(){
	dexUtils->hook();
}
