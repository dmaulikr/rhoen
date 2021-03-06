CC = g++
AR = ar
ARFLAGS = rcs
CPPFLAGS = -Iinc -MMD -MP
CFLAGS = -ansi -pedantic -Wall -Wextra
LDFLAGS = -Llib -lUtil -lEngine -lm
TARGET = bin/rhoen
TEST = bin/test
# directories
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
DOCDIR = doc
TESTDIR = test
UTILDIR = util
COREDIR = core
GAMEDIR = game

# Building from source requires GNU Make and gcc v3.0 or higher
# TODO: POSIX compatibility and precompiled headers? (Might get messy...)
# TODO: Pass flags via ./configure script (not using GNU Autoconfig, ugh)

# ==============================================================================

# Find all source files and rewrite paths to their respective object file
# Will list those sources by hand after I'm finished with this project (never).
_SRC_UTIL = $(wildcard $(SRCDIR)/$(UTILDIR)/*.cpp $(SRCDIR)/$(UTILDIR)/**/*.cpp)
_SRC_CORE = $(wildcard $(SRCDIR)/$(COREDIR)/*.cpp $(SRCDIR)/$(COREDIR)/**/*.cpp)
_SRC_GAME = $(wildcard $(SRCDIR)/$(GAMEDIR)/*.cpp $(SRCDIR)/$(GAMEDIR)/**/*.cpp)
_SRC_TEST = $(wildcard $(TESTDIR)/*.cpp $(TESTDIR)/**/*.cpp)
_OBJ_UTIL = $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .cpp,.o,$(_SRC_UTIL)))
_OBJ_CORE = $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .cpp,.o,$(_SRC_CORE)))
_OBJ_GAME = $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .cpp,.o,$(_SRC_GAME)))
_OBJ_TEST = $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(_SRC_TEST)))

all: $(TARGET)
allclean: all clean
runclean: run clean
run: $(TARGET)
	@$<
test: $(TEST)
	@$<

# Pattern rule for object files, creates new directories if necessary
# Object directory will mirror the structure of the source directory
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(if $(wildcard $(@D)),, @mkdir -p $(@D))
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

# Link game objects with both static libraries
$(TARGET): $(_OBJ_GAME) $(LIBDIR)/libUtil.a $(LIBDIR)/libEngine.a
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(filter %.o, $^) $(LDFLAGS)

# Create static utility library from objects
$(LIBDIR)/libUtil.a: $(_OBJ_UTIL) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

# Create static core library from objects
$(LIBDIR)/libEngine.a: $(_OBJ_CORE) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

# Static pattern rule for test objects, would be nice if this
# rule could somehow be combined with the pattern rule above
$(_OBJ_TEST): $(OBJDIR)/$(TESTDIR)/%.o: $(TESTDIR)/%.cpp
	$(if $(wildcard $(@D)),, @mkdir -p $(@D))
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

# Link all objects required for running tests
$(TEST): $(_OBJ_TEST) $(_OBJ_UTIL) $(_OBJ_CORE)
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $^

# Generate Doxyfile from Makefile settings
$(DOCDIR)/Doxyfile.out: $(DOCDIR)/Doxyfile.in
	@cat $< > $@
	@echo OUTPUT_DIRECTORY = $(DOCDIR) >> $@
	@echo INPUT = $(SRCDIR)/$(UTILDIR) \
	              $(SRCDIR)/$(COREDIR) \
	              $(SRCDIR)/$(GAMEDIR) \
	              $(DOCDIR) >> $@

# Generate docs from Doxyfile
docs: $(DOCDIR)/Doxyfile.out
	doxygen $<; rm -f $<

# Publish docs
publish:
	$(DOCDIR)/publish.sh

# Clean
clean:
	rm -rf $(OBJDIR) $(LIBDIR) $(DOCDIR)/html

# Make lib directory
$(LIBDIR):
	@mkdir -p $@

.PHONY: all run test docs publish clean allclean runclean

# Include dependency files
-include $(_OBJ_UTIL:.o=.d)
-include $(_OBJ_CORE:.o=.d)
-include $(_OBJ_GAME:.o=.d)
-include $(_OBJ_TEST:.o=.d)
