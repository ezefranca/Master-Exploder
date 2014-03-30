CC= gcc -std=c99

CFLAGS= -W -Wall -pedantic

LIBS = -lallegro -lallegro_main -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lopencv_core -lopencv_highgui

SOURCEDIR = src

SOURCES = $(wildcard $(SOURCEDIR)/*.c)

BUILDDIR = bin

EXECUTABLE = main

OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

all: dir $(BUILDDIR)/$(EXECUTABLE)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE)