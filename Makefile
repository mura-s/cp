# parameters
# e.g. atcoder/abc001 or atcoder/abc001/a
DIR :=
# e.g. cpp or java
LANG :=

# tasks
.PHONY: contest
contest: .check-dir .check-lang
	mkdir -p $(DIR)
	cp -r $(LANG)/template/ $(DIR)/a
	cp -r $(LANG)/template/ $(DIR)/b
	cp -r $(LANG)/template/ $(DIR)/c
	cp -r $(LANG)/template/ $(DIR)/d
	cp -r $(LANG)/template/ $(DIR)/e
	cp -r $(LANG)/template/ $(DIR)/f

.PHONY: dir
dir: .check-dir .check-lang
	mkdir -p $(DIR)
	cp -r $(LANG)/template/ $(DIR)

# internal tasks
.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif

.check-lang:
ifeq ($(LANG),)
	$(error LANG is required.)
endif
