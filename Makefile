ifeq ($(OS),Windows_NT)
SHELL = cmd
endif

CC= gcc -std=c99

CFLAGS= -W -Wall -pedantic

ifeq ($(OS),Windows_NT)
	LIBS = -lallegro -lallegro_main -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro -lallegro_font -lallegro_image -lopencv_core300 -lopencv_highgui300
else
	LIBS = -lallegro -lallegro_main -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro -lallegro_font -lallegro_image -lopencv_core -lopencv_highgui
endif

SOURCEDIR = src

SOURCES = $(wildcard $(SOURCEDIR)/*.c)

BUILDDIR = bin

ifeq ($(OS),Windows_NT)
	EXECUTABLE = main.exe
else
	EXECUTABLE = main
endif

OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

all: dir $(BUILDDIR)/$(EXECUTABLE)

ifeq ($(OS),Windows_NT)
dir:
else
dir:
		mkdir -p $(BUILDDIR)
endif

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

ifeq ($(OS),Windows_NT)

.PHONY: cls

clean:
		RMDIR /S $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE)
else

.PHONY: clean

clean:
		rm -f $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE)
endif