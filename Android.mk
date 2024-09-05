LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NetdClient
LOCAL_SRC_FILES := main.cpp
LOCAL_SHARED_LIBRARIES := \
        libbinder \
        liblog \
        libutils

LOCAL_STATIC_LIBRARIES := \
	netd_aidl_interface-unstable-cpp

#LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../system/netd/server

include $(BUILD_EXECUTABLE)
