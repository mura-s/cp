# parameters
# e.g. atcoder/abc001 or atcoder/abc001/a
DIR :=

package = $(subst /,.,$(DIR))

# tasks
.PHONY: contest-cpp
contest-cpp: .check-dir
	mkdir -p $(DIR)
	cp -r cpp/template/ $(DIR)/a
	cp -r cpp/template/ $(DIR)/b
	cp -r cpp/template/ $(DIR)/c
	cp -r cpp/template/ $(DIR)/d
	cp -r cpp/template/ $(DIR)/e
	cp -r cpp/template/ $(DIR)/f

.PHONY: dir-cpp
dir-cpp: .check-dir
	mkdir -p $(DIR)
	cp -r cpp/template/ $(DIR)

.PHONY: contest-java
contest-java: .check-dir
	mkdir -p $(DIR)
	cp -r java/template/ $(DIR)/a
	sed -i '' 's|java.template|$(package).a|g' $(DIR)/a/Main.java
	sed -i '' 's|java/template|$(DIR)/a|g' $(DIR)/a/Makefile
	cp -r java/template/ $(DIR)/b
	sed -i '' 's|java.template|$(package).b|g' $(DIR)/b/Main.java
	sed -i '' 's|java/template|$(DIR)/b|g' $(DIR)/b/Makefile
	cp -r java/template/ $(DIR)/c
	sed -i '' 's|java.template|$(package).c|g' $(DIR)/c/Main.java
	sed -i '' 's|java/template|$(DIR)/c|g' $(DIR)/c/Makefile
	cp -r java/template/ $(DIR)/d
	sed -i '' 's|java.template|$(package).d|g' $(DIR)/d/Main.java
	sed -i '' 's|java/template|$(DIR)/d|g' $(DIR)/d/Makefile
	cp -r java/template/ $(DIR)/e
	sed -i '' 's|java.template|$(package).e|g' $(DIR)/e/Main.java
	sed -i '' 's|java/template|$(DIR)/e|g' $(DIR)/e/Makefile
	cp -r java/template/ $(DIR)/f
	sed -i '' 's|java.template|$(package).f|g' $(DIR)/f/Main.java
	sed -i '' 's|java/template|$(DIR)/f|g' $(DIR)/f/Makefile

.PHONY: dir-java
dir-java: .check-dir
	mkdir -p $(DIR)
	cp -r java/template/ $(DIR)
	sed -i '' 's|java.template|$(package)|g' $(DIR)/Main.java
	sed -i '' 's|java/template|$(DIR)|g' $(DIR)/Makefile

# internal tasks
.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif
