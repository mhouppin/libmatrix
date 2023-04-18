CFLAGS ?= -O2 -g
CPPFLAGS ?= -Werror
LDFLAGS ?=

CFLAGS += -std=c11 -fPIC
CPPFLAGS += -Wall -Wextra -Wvla -Wshadow -I include -MMD
LDFLAGS += -lm

PMT_SOURCES := \
	pmt_vec_copy.c \
	pmt_vec_fill.c

VEC_SOURCES := \
	vector_allocate.c \
	vector_destroy.c \
	vector_init_zero.c \
	vector_init_from_value.c \
	vector_init_from_array.c \
	vector_fill.c

MAT_SOURCES := \
	matrix_allocate.c \
	matrix_destroy.c \
	matrix_init_zero.c \
	matrix_init_from_value.c \
	matrix_init_from_array.c \
	matrix_fill.c

SOURCES := \
	$(addprefix sources/primitives/,$(PMT_SOURCES)) \
	$(addprefix sources/vector/,$(VEC_SOURCES)) \
	$(addprefix sources/matrix/,$(MAT_SOURCES)) \
	sources/version/libmatrix_get_version.c

OBJECTS := $(SOURCES:%.c=%.o)
DEPENDS := $(SOURCES:%.c=%.d)

all: libmatrix.so libmatrix.a

shared: libmatrix.so

static: libmatrix.a

libmatrix.so: $(OBJECTS)
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LDFLAGS)

libmatrix.a: $(OBJECTS)
	$(AR) -rcs $@ $^

-include $(DEPENDS)

clean:
	rm -f $(OBJECTS) $(DEPENDS)
	rm -f libmatrix.so libmatrix.a

.PHONY: all shared static clean
