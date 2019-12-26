LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder 

LOCAL_MODULE    := XpClient

LOCAL_SRC_FILES := \
    XpClient.cpp \
    IXpService.cpp 

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder 

LOCAL_MODULE    := XpServer

LOCAL_SRC_FILES := \
    XpServer.cpp \
    IXpService.cpp 

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
