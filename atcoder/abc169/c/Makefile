.PHONY: build
build:
	@javac Main.java

.PHONY: run
run:
	@java -Xss256M Main

.PHONY: test
test:
	./test.sh

.PHONY: copy
copy:
	cat Main.java | tail -n +3 | pbcopy

.PHONY: clean
clean:
	rm -rf *.class
