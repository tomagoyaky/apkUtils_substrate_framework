LOCAL_PATH := $(call my-dir)
# substrate »·¾³
include $(CLEAR_VARS)
LOCAL_MODULE:= substrate-dvm
LOCAL_SRC_FILES := libsubstrate-dvm.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:= substrate
LOCAL_SRC_FILES := libsubstrate.so
include $(PREBUILT_SHARED_LIBRARY)

# MAIN
include $(CLEAR_VARS)
LOCAL_MODULE    := SubstrateHook.cy
LOCAL_SRC_FILES := SubstrateHook.cy.cpp

LOCAL_LDLIBS := -llog
LOCAL_ARM_MODE := arm
LOCAL_LDLIBS += -L$(LOCAL_PATH) -lsubstrate-dvm -lsubstrate 
include $(BUILD_SHARED_LIBRARY)
