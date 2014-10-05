OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := ./LeapSDK/lib/x64/libLeap.so -Wl,-rpath,../lib/x64
  else
    LEAP_LIBRARY := ./LeapSDK/lib/x86/libLeap.so -Wl,-rpath,../lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := ./LeapSDK/lib/libLeap.dylib
endif

all: main.cpp rpsg.h dora.h human.h monster.h datingsims.h
	$(CXX) -Wall -g -I./LeapSDK/include main.cpp -o main $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ./LeapSDK/lib/libLeap.dylib main
endif


clean:
	rm -rf main main.dSYM
