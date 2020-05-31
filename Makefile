# parameters
# e.g. atcoder/abc001 or atcoder/abc001/a
DIR :=
# e.g. cpp or java
LANG :=

package = $(subst /,.,$(DIR))

# tasks
.PHONY: contest
contest: .check-dir
	mkdir -p $(DIR)
	cp -r template/$(LANG)/tmpl/ $(DIR)/a
	cp -r template/$(LANG)/tmpl/ $(DIR)/b
	cp -r template/$(LANG)/tmpl/ $(DIR)/c
	cp -r template/$(LANG)/tmpl/ $(DIR)/d
	cp -r template/$(LANG)/tmpl/ $(DIR)/e
	cp -r template/$(LANG)/tmpl/ $(DIR)/f

.PHONY: dir
dir: .check-dir
	mkdir -p $(DIR)
	cp -r template/$(LANG)/tmpl/ $(DIR)

# internal tasks
.check-dir:
ifeq ($(DIR),)
	$(error DIR is required.)
endif

.check-lang:
ifeq ($(LANG),)
	$(error LANG is required.)
endif
