# Report

## Question 1: Explain the linking rule in the Makefile

The linking rule is:

$(TARGET): $(OBJECTS)

This rule tells Make that the final target depends on all the object files.

The object files are created from the C source files. After all object files are available, the compiler links them together to create the final executable `bin/client`.

In this project, the object files are:

- main.o
- mystrfunctions.o
- myfilefunctions.o

The final executable is:

`bin/client`

A Makefile rule that links against a library is different because it uses a library file, such as a `.a` or `.so` file, during the linking process. In our project, the functions are linked directly from our own object files instead of linking against a separate library.

---

## Question 2: What is a git tag and why is it useful?

A Git tag is a name given to a specific commit in a Git repository.

Tags are useful for marking important versions of a project. For example, we created the tag:

`v0.1.1-multifile`

This tag represents the stable version of our multi-file project.

There are two common types of tags:

### Simple Tag

A simple tag is a lightweight reference to a specific commit. It mainly acts as a name or pointer to that commit.

### Annotated Tag

An annotated tag is stored as a Git object and contains additional information such as the tag message, tagger, and date.

In this project, we created an annotated tag using:

`git tag -a v0.1.1-multifile -m "Version 1.0 - Basic multifile compilation"`

---

## Question 3: What is the purpose of creating a Release on GitHub?

A GitHub Release provides a way to distribute a specific version of a project.

It is connected to a Git tag and can include information about that version.

In this project, the release represents the first stable version of the multi-file build.

Attaching the `bin/client` executable to the release allows users to download and run the compiled program without compiling the source code themselves.

Therefore, the GitHub Release provides both the version information and the compiled executable for distribution.
