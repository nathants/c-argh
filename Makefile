.PHONY: all clean
ALL=clean example

all: $(ALL)

clean:
	rm -f example

example:
	gcc example.c -o example
