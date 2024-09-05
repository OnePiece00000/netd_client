LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NetdClient

LOCAL_SRC_FILES := main.cpp \
        android/net/INetd.cpp \
        android/net/INetdUnsolicitedEventListener.cpp \
        android/net/InterfaceConfigurationParcel.cpp \
        android/net/MarkMaskParcel.cpp \
        android/net/RouteInfoParcel.cpp \
        android/net/TetherConfigParcel.cpp \
        android/net/TetherOffloadRuleParcel.cpp \
        android/net/TetherStatsParcel.cpp \
        android/net/UidRangeParcel.cpp



LOCAL_SHARED_LIBRARIES := \
        libbinder \
        liblog \
        libutils

#LOCAL_STATIC_LIBRARIES := \
	netd_aidl_interface-unstable-cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include

LOCAL_LDLIBS := -L/usr/local/lib -ljsoncpp

include $(BUILD_EXECUTABLE)
