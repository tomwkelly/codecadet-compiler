all:
	mkdir -p ./out
	cd ./out; \
		mkdir -p ./benchmark-old && mv ./benchmarks ./benchmark-old; \
		cmake -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=Release .. && make

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
