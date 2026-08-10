# Lab 1: Introduction to OOP Concepts

## Lab Details
* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Yashraj Singh Bisht

---

## Objectives
1. To compare procedural programming in C with the basics of C++ as an OOP language.
2. To write introductory programs in both C and C++ to identify key differences and OOP potential.

---

## Software Required
* C++ Compiler (GCC / MinGW)
* Visual Studio Code (VS Code)

---

## Core Concepts & Theory

### 1. Evolution of Programming Languages
* **Machine Language (1940s):** Binary code (e.g., `101010`).
* **Assembly Language (1950s):** Mnemonics (e.g., `ADD`, `MOV`).
* **High-Level Languages (1950s-60s):** Fortran, COBOL for human readability.
* **Procedural Languages (1970s):** C introduced structured programming with functions and manual memory management.
* **Object-Oriented Languages (1980s):** Smalltalk pioneered OOP; C++ (by Bjarne Stroustrup, 1983) extended C with OOP features.

### 2. Procedural (C) vs. Object-Oriented (C++)

#### Procedural Programming (C)
* Focuses on procedures (functions) and sequential execution.
* Data and functions are separate; data is passed to functions explicitly.
* **Example:** Calculating a rectangle’s area requires standalone variables and an external function.
* **Strengths:** Simple and fast for small programs.
* **Weaknesses:** Hard to manage in large systems; lacks data protection.

#### Object-Oriented Programming (C++)
* Organizes code around objects (instances of classes) that combine data and behavior.
* Introduces key concepts: **Encapsulation** (data hiding), **Inheritance** (code reuse), **Polymorphism** (flexible behavior), and **Abstraction** (simplified modeling).
* **Example:** A `Rectangle` class encapsulates `length`, `width`, and an `area()` method.
* **Strengths:** Highly modular, reusable, and scalable.
* **Weaknesses:** Steeper learning curve and minor performance overhead.

---

## Key Differences in Syntax: C vs. C++


| Feature | C Programming | C++ Programming |
| :--- | :--- | :--- |
| **Header Files** | `#include <stdio.h>` | `#include <iostream>` |
| **Namespaces** | Not supported | `using namespace std;` |
| **Standard Output**| `printf("Sum: %d\n", x);` | `cout << "Sum: " << x << endl;` |
| **Standard Input** | `scanf("%d", &x);` | `cin >> x;` |
| **Format Specifiers**| Required (e.g., `%d`, `%f`) | Not required (Streams handle type automatically) |
| **Newline/Buffer** | `\n` | `endl` (Adds newline and flushes stream buffer) |

---

## Lab Implementation Tasks
This repository contains the completed C++ program files implementing the introductory lab exercises:
* `LAB_1.cpp` - Basic layout and structural comparison.
* `LAB_1b.cpp` - Simple standard I/O implementations.
* `LAB_1c.cpp` - Repetitive loop tracking exercises.
