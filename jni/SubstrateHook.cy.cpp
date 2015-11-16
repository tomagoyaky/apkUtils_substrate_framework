#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "substrate.h"
#include "Mcro_Common.h"

char *BinaryMemoryPrint(const void *buf, int size){

	return (char*)buf;
}

ssize_t (*send)(int sockfd, const void *buf, size_t len, int flags);
ssize_t replace_send(int sockfd, const void *buf, size_t len, int flags){

	if(sockfd)	LOGD("=|   sockfd=0x%08X", (unsigned int)sockfd);
	if(buf)		LOGD("=|   buffer=0x%08X", (unsigned int)buf);
	if(len)		LOGD("=|   length=0x%08X", (unsigned int)len);
	if(flags)	LOGD("=|    flags=%d", flags);
	LOGD("=|  content=%s", BinaryMemoryPrint(buf, 30));
	LOGD("=| ======================");
	return send(sockfd, buf, len, flags);
}

int (*dexfileopen)(const void * addr,int len,void ** dvmdex);
int replace_dvmdexfileopen(const void *addr,int len, void **dvmdex){

	if(addr)	LOGD("=|     addr=0x%08X", (unsigned int)addr);
	if(len)		LOGD("=|   length=0x%08X", (unsigned int)len);
	if(dvmdex)	LOGD("=|   dvmdex=0x%08X", (unsigned int)dvmdex);
	LOGD("=| ======================");
	return dexfileopen(addr, len, dvmdex);
}

MSConfig(MSFilterLibrary, "/system/bin/libc.so")
MSConfig(MSFilterLibrary, "/system/lib/libdvm.so")

MSInitialize{

	_FUNC_START
	do {
	    MSImageRef imageHandle = MSGetImageByName("/system/bin/libc.so");
	    if(imageHandle == NULL)											{_BREAK_DOWHILE}

	    void *func = MSFindSymbol(imageHandle, "send");
	    if(func == NULL)												{_BREAK_DOWHILE}

	    LOGD("%s: name=%s address=%p", "send", "send", func);
	    MSHookFunction(imageHandle, "send", (void*)&replace_send, (void**)send);
	} while (0);
	_JUDGE_RETFLAG_VALUE

	do {
		MSImageRef imageHandle = MSGetImageByName("/system/lib/libdvm.so");
		if(imageHandle == NULL)											{_BREAK_DOWHILE}

		void *func = MSFindSymbol(imageHandle, "_Z21dvmDexFileOpenPartialPKviPP6DvmDex");
		if(func == NULL)												{_BREAK_DOWHILE}

		LOGD("%s: name=%s address=%p", "dexParseOptData", "_Z21dvmDexFileOpenPartialPKviPP6DvmDex", func);
		MSHookFunction(imageHandle, "send", (void*)&replace_dvmdexfileopen, (void**)dexfileopen);
	} while (0);
	_JUDGE_RETFLAG_VALUE
	_FUNC_END
}


