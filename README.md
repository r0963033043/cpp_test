# CPP_Builder

## Introduction
### makefile
simple build
```bash
# Create Object file (*.o)
# Same group:
#   -c *.cpp
#   -o *.o

# Auto create obj as same name: test.o
g++ -c test.cpp

# Or create obj as different name: test2.o
g++ -o test2.o -c test.cpp



# Create Executable file (exe)
# Same group: -o (exe)

# Create exe, name test
g++ test.o -o test
# Or
# g++ -o test test.o


# Wrong way to create exe
# g++ -o test.o test
# g++ test.o test -o
# g++ test -o test.o
# g++ test test.o -o
```

Keyword  
`%`: 萬用配對字元  
`$@`: 代表目前的目標項目名稱/工作目標檔名  
`$<`: 代表第一個必要條件的檔名/目前的相依性項目  
`$^`: 代表所有必要條件的檔名，並以空格隔開這些檔名 (這份清單已移除重複的檔名)  
`$*`: 代表工作目標的主檔名/目前的相依性項目，但不含副檔名  
`$?`: 代表需要重建（被修改）的相依性項目  

函式  
`notdir`: 去除路徑    

`wildcard`:  
Format: `$(wildcard <src>)`  
Description: get `<src>` file  
Usage: `$(wildcard *.<file extension>)`  
Example:  
  `$(wildcard ./src/*.cpp)`: 獲取工作目錄`src`下的所有的`.cpp`檔案列表    

`patsubst`:  
Format: `$(patsubst <pattern>, <replacement>, <text>)`  
Description: check if `<test>` match `<pattern>`, and replace `<test>` file extension from `<pattern>` to `<replacement>`  
Usage: `$(patsubst %.cpp, %.o, $(dir))`  
Example:  
  `$(patsubst %.cpp, %.o, ./src/*.cpp)`: 把`src/*.cpp`中的變數符合字尾是`.cpp`的全部替換成`.o`    


Build Test1
```makefile
# Define
## Source code
TEST1_SRC = test1.cpp

## Object Directory
OBJ = ./obj
TEST_OBJ = $(OBJ)/test-obj

TEST1_SRCS = $(wildcard $(TEST)/$(TEST1_SRC))
TEST1_OBJS = $(patsubst $(TEST)/%.cpp, $(TEST_OBJ)/%.o, $(TEST1_SRCS))

## Target (Executable File)
BUILD_TEST1 = test1


# Build
$(BUILD_TEST1): $(OBJS) $(TEST1_OBJS)
	@echo "[BUILD] test1"
	@$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^

$(TEST_OBJ)/%.o: $(TEST)/%.cpp
	@echo [COMPILE] $(notdir  $@)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<
```

Build  
TEST_OBJ  
`$@`: 目前的目標項目名稱  
= $(TEST_OBJ)/%.o  
= ./obj/test-obj/test1.o && ./obj/test-obj/test2.o    

`$<`: 目前的相依性項目  
= $(TEST)/%.cpp  
= test/test1.cpp  && test/test2.cpp    

`$(CXX) $(CXXFLAGS) -o $@ -c $<`  
= g++ -g -std=c++11 -I./include -o obj/test-obj/test1.o -c test/test1.cpp    


BUILD_TEST1  
`$(BIN)/$@`  
= ./bin/test1    

`$^`: 代表所有必要條件的檔名，並以空格隔開這些檔名 (這份清單已移除重複的檔名)  
= obj/foo1.o obj/test-obj/test1.o    

`$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^`  
= g++ -g -std=c++11 -I./include -o ./bin/test1 obj/foo1.o obj/test-obj/test1.o


### Source Code
`src` folder    : source `.cpp` or `.c` file  
`include` folder: source `.h` file  
`util` folder   : main project file  
`test` folder   : test partial function  

### Executable file
place in `bin` folder

### Config file
place in `cfg` folder

### Library
`lib` folder include `.so` file



## Run
### How to build?
```
make
```

### How to run?
```
./bin/xxx
```

