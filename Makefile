src=$(wildcard *.c)

objects = $(patsubst %.c, %, $(src))

all: $(objects)
	@echo "\033[36mdone!\033[0m"

%: %.c
	cc $< -o $@

.PHONY: clean all

clean:
	-rm $(objects)
