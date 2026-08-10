# Lab 2: Basics of C++ Programming

---

## Lab Details

- **Course:** Object-Oriented Programming (OOP)
- **Institution:** HCOE (2081)
- **Student:** Aashray Karki
- **Roll No.:** HCE082BEI001

---

## Objectives

1. To refresh the basic concepts of C programming such as functions, arrays, and structures.
2. To understand the use of functions, arrays, and structures in C++.
3. To compare the syntax and usage difference between C and C++.
4. To prepare the foundation for learning object-oriented programming concepts in upcoming labs.

---

## Software Required

- C++ Compiler (GCC / MinGW)
- Visual Studio Code (VS Code)
- Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Introduction to C++ Programming

C++ is an extension of the C programming language. It supports both procedural programming and object-oriented programming. In this lab, the focus was on the basic procedural features of C++, such as functions, arrays, and structures.

These concepts are important because they act as the foundation for object-oriented programming. Later, functions become member functions, structures become classes, and data handling becomes more organized using objects.

---

### 2. Functions in C++

A function is a block of code that performs a specific task. It helps to divide a program into smaller and manageable parts.

Functions make the program easier to read, debug, and reuse. In C++, functions are written almost like C, but input and output are usually handled using `cin` and `cout`.

#### Example Concept

A function can be created to calculate the sum of array elements, convert currency, or calculate a bill.

---

### 3. Arrays in C++

An array is a collection of elements of the same data type stored in continuous memory locations.

Arrays are useful when we need to store multiple values under one variable name. For example, daily sales of seven days can be stored in an array of size 7.

#### Features of Arrays

- Stores multiple values of the same type.
- Uses index numbers to access elements.
- Index starts from 0.
- Useful for storing lists of data.
- Fixed size is usually declared at the beginning.

---

### 4. Structures in C++

A structure is a user-defined data type that groups different types of data under one name.

For example, a `Patient` structure can contain name, age, and disease. Similarly, an `Item` structure can contain item name and price.

Structures are useful because they help organize related data together.

---

## Difference Between C and C++

| Basis | C Programming | C++ Programming |
|---|---|---|
| Header File | `#include <stdio.h>` | `#include <iostream>` |
| Input | `scanf()` | `cin` |
| Output | `printf()` | `cout` |
| Format Specifier | Required | Not required |
| Structure Use | Uses `struct` keyword often | Easier structure usage |
| Function Support | Supported | Supported with extra features |
| Programming Style | Procedural | Procedural + Object-Oriented |

---

## Lab Implementation Tasks

The following programs were performed in this lab:

### Task 1: Weekly Sales Calculation

A program was written to store daily sales amounts for seven days using an array. The total and average sales were calculated and displayed.

---

### Task 2: Patient Record Using Structure

A structure named `Patient` was created with fields such as name, age, and disease. Records of three patients were stored using an array of structures and displayed.

---

### Task 3: Currency Conversion Using Function

A function named `convertCurrency(float amount, float rate)` was written to convert an amount from one currency to another using the given conversion rate.

---

### Task 4: Bill Calculation Using Structure and Function

A structure named `Item` was created with fields such as name and price. A function named `calculateBill(Item i)` was used to calculate the total bill after adding 10% tax.

---

## Observation

After completing this lab, it was observed that arrays are useful for storing multiple values, functions help reduce repeated code, and structures help group related information together.

It was also observed that C++ uses `cin` and `cout` instead of `scanf()` and `printf()`, making input and output simpler and more readable.

---

## Result Analysis

All programs were successfully written, compiled, and executed. The weekly sales program calculated the total and average correctly. The patient record program stored and displayed multiple records properly. The currency conversion program converted the amount based on the given rate, and the bill calculation program successfully added 10% tax to the item price.

---

## Discussion

This lab helped to understand how basic programming concepts from C are used in C++. Functions, arrays, and structures are still important in C++, but C++ provides a cleaner way to handle input and output.

These concepts are also important for future OOP topics. For example, structures are similar to classes, and functions later become methods inside classes. Therefore, this lab created a strong base for understanding objects and classes in upcoming experiments.

---
## Conclusion

In this lab, the basic concepts of C++ programming were studied and practiced. Functions, arrays, and structures were used to solve different programming problems. The difference between C and C++ syntax was also understood. Overall, this lab helped build the foundation required for learning object-oriented programming concepts in later labs.

---

## References

[1] HCOE, *Lab Manual on Object Oriented Programming [CT 151]*, 2081.

[2] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.