# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello-jni.c \
                    test/common/test.cpp \
                    src/utils/log/DLog.cpp \
                    src/utils/log/android/DAndroidLog.cpp \
                    src/utils/time/android/DAndroidTime.cpp \
                    src/utils/file/DFile.cpp \
                    src/utils/safty/md5/DMD5.c \
                    src/utils/safty/md5/cifs/md5.c \
                    src/utils/safty/md5/cifs/cifs_block.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/test/common/android \
                    $(LOCAL_PATH)/src/base \
                    $(LOCAL_PATH)/src/utils/log \
                    $(LOCAL_PATH)/src/utils/time \
                    $(LOCAL_PATH)/src/utils/file \
                    $(LOCAL_PATH)/src/utils/safty/md5 \
                    $(LOCAL_PATH)/src/utils/safty/md5/cifs

LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)
