@echo off
cd %~dp0
@echo ">> CurrentPath: + %~dp0"
@echo ">> Start Create .h Header File."
javah -jni -classpath "..\bin\classes" -o jniInterface.h com.tomagoyaky.Native.Bridge

echo ">> finish"

pause