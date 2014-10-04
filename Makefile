OS := $(shell uname)
ARCH := $(shell uname -m)

Main: main.cpp
	$(CXX) -Wall -g -I ./LeapSDK/include main.cpp -o main $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ../lib/libLeap.dylib main
endif

clean:
	rm -rf main main.dSYM
