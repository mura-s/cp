.PHONY: build
build:
	@cd ~/src/github.com/mura-s/cp && \
		javac template/java/lib/adjacencylist/Main.java

.PHONY: run
run:
	@cd ~/src/github.com/mura-s/cp && \
		java -Xss256M template/java/lib/adjacencylist/Main

.PHONY: test
test:
	./test.sh

.PHONY: copy
copy:
	cat Main.java | tail -n +3 | pbcopy

.PHONY: clean
clean:
	rm -rf *.class
