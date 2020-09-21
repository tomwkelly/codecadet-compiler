SUBDIRS = lexer
OUTPUTS = lexer.o
subdirs:
	g++-10 -o main.o -c main.cpp
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
		mv ./$$dir/$$dir ./$$dir.o; \
		done
	g++-10 -Wall -o cccp.o main.o $(OUTPUTS)
	rm main.o $(OUTPUTS)

install:
	make
	cp cccp.o /usr/local/bin/cccp

clean:
	rm cccp
