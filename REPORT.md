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
---------------------------------------------------------------------------------------------------------------------
Feature--3
Question 1

Compare the Makefile changes between Part 2 and Part 3.

Simple answer:

In Part 2, the Makefile directly compiled the source files into object files and then linked those object files to create bin/client.

In Part 3, the Makefile is modified to first create the static library lib/libmyutils.a using the object files. The final executable bin/client_static is then linked against this static library using -Llib -lmyutils.

Question 2

What is the purpose of ar and ranlib when creating a static library?

ar is used to create and manage static library archive files (.a). It combines object files such as mystrfunctions.o and myfilefunctions.o into libmyutils.a.

ranlib creates or updates the symbol index of a static library so that the linker can efficiently find the required functions.

In our command, ar rcs was used. The s option creates the symbol index, so a separate ranlib command was not required.

Question 3

What does nm show when inspecting a static executable?

nm displays the symbols contained in an executable or object file. It can show functions and variables along with their symbol types and addresses.

In our static library, nm showed functions such as mystrlen, mystrcpy, mystrncpy, mystrcat, wordCount, and mygrep.
--------------------------------------------------------------------------------------------------------------------
Feature-4 Question & Answers
## Feature-4: Dynamic Library

### 1. What is `-fPIC` and why is it fundamental for shared libraries?

`-fPIC` means Position Independent Code. It creates code that can run correctly regardless of where the shared library is loaded in memory.

It is important for shared libraries because the dynamic loader can load the library at different memory addresses without modifying the library code.

### 2. Explain the difference in file size between `bin/client_static` and `bin/client_dynamic`.

`client_static` is larger because the required library code is copied into the executable during static linking.

`client_dynamic` is smaller because the library code is stored separately in `libmyutils.so`. The executable only contains references to the shared library.

In this project:

- `client_static` = 24K
- `client_dynamic` = 20K

### 3. What is `LD_LIBRARY_PATH`? Why was it necessary, and what does this demonstrate about the dynamic loader's responsibility?

`LD_LIBRARY_PATH` is an environment variable that tells the dynamic loader additional directories where it should search for shared libraries.

It was necessary because `libmyutils.so` was inside the project's `lib/` directory, which was not in the loader's default search paths.

We used:

`export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH`

This allowed `client_dynamic` to find and load `libmyutils.so`.

This demonstrates that the dynamic loader is responsible for finding and loading the required shared libraries when a dynamically linked program starts.

---Feature 5
---

## Feature-5: Man Pages and Installation

### Task 1: Man Pages

Man pages were created for all utility functions in the `man/man3/` directory.

The following man pages were created:

- `mystrlen.1`
- `mystrcpy.1`
- `mystrncpy.1`
- `mystrcat.1`
- `wordCount.1`
- `mygrep.1`

Each man page contains the required `.TH`, `.SH NAME`, `.SH SYNOPSIS`, `.SH DESCRIPTION`, and `.SH AUTHOR` sections.

### Task 2: Installation

An `install` target was added to the Makefile.

The install target copies:

- `bin/client` to `/usr/local/bin/client`
- Man pages to `/usr/local/share/man/man3/`

Installation was tested using:

```bash
sudo make install
