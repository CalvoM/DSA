CFLAGS:=./source/*.cxx -I ./includes
LDFLAGS := `pkg-config catch2-with-main --libs`
tests:
	g++ $(CFLAGS) runner.cxx -o leetcode_test $(LDFLAGS)
	./leetcode_test -s -r console
clean:
	rm ./leetcode_test
