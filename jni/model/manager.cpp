/*
 * manager.cpp
 *
 *  Created on: 2015Äê11ÔÂ14ÈÕ
 *      Author: peng
 */

#include "dex/dexUtils.h"

DexUtils *dexUtils = {0};

int start(){
	dexUtils->hook();
}
