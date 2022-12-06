# Source and great guide at http://nuclear.mutantstargoat.com/articles/make/

CC=g++

csrc = $(wildcard *.c)
ccsrc = $(wildcard *.cc)
cppsrc = $(wildcard *.cpp)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o) $(cppsrc:.cpp=.o)
dep = $(obj:.o=.d)  # one dependency file for each source

CFLAGS= -Wall -std=c++11 -DNDEBUG
LDFLAGS= 

myprog: $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

-include $(dep)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) myprog

.PHONY: cleandep
cleandep:
	rm -f $(dep)

