# Source and great guide at http://nuclear.mutantstargoat.com/articles/make/

CC=g++

csrc = $(wildcard *.c)
ccsrc = $(wildcard *.cc)
cppsrc = $(wildcard *.cpp)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o) $(cppsrc:.cpp=.o)
dep = $(obj:.o=.d)  # one dependency file for each source

LDFLAGS = 

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(dep)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) myprog

.PHONY: cleandep
cleandep:
	rm -f $(dep)

