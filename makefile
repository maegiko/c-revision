CC = gcc
SRCS = $(shell find . -path ./build -prune -o -name "*.c" -print)
OUTS = $(addprefix build/, $(basename $(notdir $(SRCS))))

all: $(OUTS)

define make_rule
build/$(basename $(notdir $(1))): $(1)
	mkdir -p build
	$(CC) $(1) -o build/$(basename $(notdir $(1)))
endef

$(foreach src,$(SRCS),$(eval $(call make_rule,$(src))))

clean:
	rm -rf build/
