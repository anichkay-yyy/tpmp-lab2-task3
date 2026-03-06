# Makefile for task3 - CONTACT phonebook

CC = gcc
CFLAGS = -Wall -Wextra -I include

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/contact.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/contact.o
TARGET = $(BINDIR)/phonebook

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/main.o: $(SRCDIR)/main.c include/contact.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/contact.o: $(SRCDIR)/contact.c include/contact.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

check:
	@true

distcheck:
	@true

.PHONY: all clean check distcheck
