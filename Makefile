CC = clang++
CFLAGS = -Wall -g -std=c++11

#找main
all: main

#找这几个 .o files
main: point.o line.o main.o pointset.o polygon.o
#最后把它们link起来,cc 命令必须用tab起行
	$(CC) $(CFLAGS) -o main point.o line.o main.o pointset.o polygon.o
###################################################################################
#生成main.o，用main.cpp和里面的.h文件，默认名称是cpp的名称，否则参考point.o
main.o: main.cpp point.h line.h pointset.h polygon.h

#生成point.o，用pointtt.cpp 和里面的.h文件，默认名称不是point，所以要在下面显示列出命令和参数 -o point.o
point.o: pointtt.cpp point.h
	$(CC) $(CFLAGS) -c -o point.o pointtt.cpp

#生成pointset.o	如果cpp名称和头文件名称一致，可以省略cpp名称
pointset.o: point.h line.h pointset.h polygon.h

polygon.o: polygon.cpp line.h pointset.h polygon.h

line.o: line.h pointset.h

clean: 
	rm -rf *.o main



