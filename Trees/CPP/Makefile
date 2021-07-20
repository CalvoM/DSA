BINFILE := bst
TESTFILE := test
build:
	@g++ includes/*.cpp main.cpp -I includes/ -o $(BINFILE)
run:build
	@./$(BINFILE)
testing:
	@g++ includes/*.cpp Tree_test.cpp -o $(TESTFILE)
	@./$(TESTFILE) -s -r compact
clean:
	@rm $(BINFILE) $(TESTFILE)
