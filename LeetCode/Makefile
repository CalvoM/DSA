CFLAGS:= -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wno-unused ./source/*.cxx -I ./includes
LDFLAGS := `pkg-config catch2-with-main --libs`
tests:
	g++ $(CFLAGS) runner.cxx -o leetcode_test $(LDFLAGS)
	./leetcode_test $(TESTS) -s -r console 
clean:
	rm ./leetcode_test
