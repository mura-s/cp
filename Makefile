# parameters
# e.g. atcoder/abc001 or atcoder/abc001/a
DIR :=

package = $(subst /,.,$(DIR))

# tasks
.PHONY: contest-cpp
contest-cpp: .check-dir
	mkdir -p $(DIR)
	cp -r template/cpp/tmpl/ $(DIR)/a
	cp -r template/cpp/tmpl/ $(DIR)/b
	cp -r template/cpp/tmpl/ $(DIR)/c
	cp -r template/cpp/tmpl/ $(DIR)/d
	cp -r template/cpp/tmpl/ $(DIR)/e
	cp -r template/cpp/tmpl/ $(DIR)/f

.PHONY: dir-cpp
dir-cpp: .check-dir
	mkdir -p $(DIR)
	cp -r template/cpp/tmpl/ $(DIR)

.PHONY: contest-java
contest-java: .check-dir
	mkdir -p $(DIR)
	cp -r template/java/tmpl/ $(DIR)/a
	sed -i '' 's|template.java.tmpl|$(package).a|g' $(DIR)/a/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/a|g' $(DIR)/a/Makefile
	cp -r template/java/tmpl/ $(DIR)/b
	sed -i '' 's|template.java.tmpl|$(package).b|g' $(DIR)/b/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/b|g' $(DIR)/b/Makefile
	cp -r template/java/tmpl/ $(DIR)/c
	sed -i '' 's|template.java.tmpl|$(package).c|g' $(DIR)/c/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/c|g' $(DIR)/c/Makefile
	cp -r template/java/tmpl/ $(DIR)/d
	sed -i '' 's|template.java.tmpl|$(package).d|g' $(DIR)/d/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/d|g' $(DIR)/d/Makefile
	cp -r template/java/tmpl/ $(DIR)/e
	sed -i '' 's|template.java.tmpl|$(package).e|g' $(DIR)/e/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/e|g' $(DIR)/e/Makefile
	cp -r template/java/tmpl/ $(DIR)/f
	sed -i '' 's|template.java.tmpl|$(package).f|g' $(DIR)/f/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)/f|g' $(DIR)/f/Makefile

.PHONY: dir-java
dir-java: .check-dir
	mkdir -p $(DIR)
	cp -r template/java/tmpl/ $(DIR)
	sed -i '' 's|template.java.tmpl|$(package)|g' $(DIR)/Main.java
	sed -i '' 's|template/java/tmpl|$(DIR)|g' $(DIR)/Makefile

# internal tasks
.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif
