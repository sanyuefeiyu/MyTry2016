SRC_DIR = ../../src
TARGET_DIR = ./objs

$(TARGET_DIR)/test.exe : $(SRC_DIR)/jni/test.cpp
	-mkdir $(TARGET_DIR)
	g++ $(SRC_DIR)/jni/test.cpp -c -o $(TARGET_DIR)/test.o
	g++ $(TARGET_DIR)/test.o -o $(TARGET_DIR)/test.exe

.PHONY: test clean

clean :
	-rm $(TARGET_DIR)/test.exe $(TARGET_DIR)/test.o

test :
	@echo $(SRC_DIR)
	@echo $(TARGET_DIR)
