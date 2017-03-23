CC = g++
AR = ar
ARFLAGS = rcs
CPPFLAGS = -Iinc -MMD -MP
CFLAGS = -ansi -pedantic -Wall -Wextra
LDFLAGS = -Llib -lUtil -lEngine -lGLEW -lGL
TARGET = bin/rhoen
TEST = bin/test
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
TESTDIR = test
UTILDIR = util
ENGINEDIR = engine
GAMEDIR = game

# Building from source requires GNU Make and gcc v3.0 or higher
# TODO: POSIX compatibility and precompiled headers? (Might get messy...)
# TODO: Pass flags via ./configure script (not using GNU Autoconfig, ugh)
# TODO: Generate automatic documentation for both libraries using Doxygen

# ====================================================================================

# Find all source files and rewrite paths to their respective object file
# Will list those sources by hand after I'm finished with this project (never).
_SRC_UTIL   = $(wildcard $(SRCDIR)/$(UTILDIR)/*.cpp $(SRCDIR)/$(UTILDIR)/**/*.cpp)
_SRC_ENGINE = $(wildcard $(SRCDIR)/$(ENGINEDIR)/*.cpp $(SRCDIR)/$(ENGINEDIR)/**/*.cpp)
_SRC_GAME   = $(wildcard $(SRCDIR)/$(GAMEDIR)/*.cpp $(SRCDIR)/$(GAMEDIR)/**/*.cpp)
_OBJ_UTIL   = $(subst $(SRCDIR)/,$(OBJDIR)/, $(subst .cpp,.o, $(_SRC_UTIL)))
_OBJ_ENGINE = $(subst $(SRCDIR)/,$(OBJDIR)/, $(subst .cpp,.o, $(_SRC_ENGINE)))
_OBJ_GAME   = $(subst $(SRCDIR)/,$(OBJDIR)/, $(subst .cpp,.o, $(_SRC_GAME)))
_SRC_TEST   = $(wildcard $(TESTDIR)/*.cpp $(TESTDIR)/**/*.cpp)

all: $(TARGET)
allclean: all clean
runclean: run clean
run: $(TARGET)
	@$<

# Pattern rule for all object files, creates new directories if necessary
# Object directory will mirror the structure of the source directory
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(if $(wildcard $(@D)),, @mkdir -p $(@D))
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

# Link game objects with both static libraries and compile
$(TARGET): $(_OBJ_GAME) $(LIBDIR)/libUtil.a $(LIBDIR)/libEngine.a
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(filter %.o, $^) $(LDFLAGS)

# Create static utility library from objects
$(LIBDIR)/libUtil.a: $(_OBJ_UTIL) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

# Create static engine library from objects
$(LIBDIR)/libEngine.a: $(_OBJ_ENGINE) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

# Compile test sources, it would be nice if this was handled by the
# pattern rule for objects (which currently only looks inside SRCDIR)
$(TEST): $(_SRC_TEST) $(_OBJ_UTIL) $(_OBJ_ENGINE) # FIXME: this sucks
	$(CC) -o $@ -Iinc $(CFLAGS) $^

$(LIBDIR):
	@mkdir -p $@

test: $(TEST)
	@$<

clean:
	rm -rf $(OBJDIR) $(LIBDIR)

.PHONY: all run test clean allclean runclean

# Include dependency files
-include $(_OBJ_UTIL:.o=.d)
-include $(_OBJ_ENGINE:.o=.d)
-include $(_OBJ_GAME:.o=.d)
