.PHONY: build
build:
	@cd ~/src/github.com/mura-s/cp && \
		javac java/template/Main.java

.PHONY: run
run:
	@cd ~/src/github.com/mura-s/cp && \
		java -Xss256M java/template/Main

.PHONY: test
test:
	./test.sh

.PHONY: copy
copy:
	cat Main.java | grep -v "package atcoder" | pbcopy

.PHONY: clean
clean:
	rm -rf *.class
