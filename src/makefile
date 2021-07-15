target = webServer 

CC = gcc

SRCS = $(wildcard *.c) #寻找所有.c文件
SRCH = $(wildcard *.h) #寻找所有.h文件
OBJS = $(patsubst %.c,%.o,$(SRCS)) #将SRCS中.c换成.o

.PHONY:all clean #伪目标

all: $(target)

$(target): $(SRCS)
	$(CC) $(SRCS) -o $@ -Wall -lpthread

clean:
	rm -f $(target)
