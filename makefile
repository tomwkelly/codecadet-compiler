all:
	mkdir -p ./out
	cd ./out; \
		cmake .. && make

dev:
	mkdir -p ./out
	cd ./out; \
	CXX=g++-10	cmake .. && make

test:
	make && ./out/tests

install:
	make && cp ./out/Main /usr/local/bin/cccp

uninstall:
	rm /usr/local/bin/cccp

clean:
	rm -rf ./out/*
