.PHONY: build
build:
	@cd ~/src/github.com/mura-s/cp && \
		javac atcoder/abc164/a/Main.java

.PHONY: run
run:
	@cd ~/src/github.com/mura-s/cp && \
		java -Xss256M atcoder/abc164/a/Main

.PHONY: test
test:
	./test.sh

.PHONY: copy
copy:
	cat Main.java | grep -v "package atcoder" | pbcopy

.PHONY: clean
clean:
	rm -rf *.class
