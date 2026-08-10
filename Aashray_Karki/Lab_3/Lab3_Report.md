# Lab 3: Basics of C++ Programming II

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Objectives

1. To reinforce the understanding of functions, arrays, and structures from C and C++.
2. To understand advanced C++ function features.
3. To study function overloading, inline functions, and default arguments.
4. To understand pass-by-reference and return-by-reference in C++.
5. To improve basic procedural programming skills before moving toward object-oriented programming.

---

## Software Required

* C++ Compiler such as GCC / MinGW
* Visual Studio Code / Dev-C++
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Recap of C++ Basics

C++ is an extension of the C programming language. It supports procedural programming as well as object-oriented programming. Before learning advanced object-oriented concepts, it is important to understand basic programming concepts such as functions, arrays, and structures.

In this lab, these basic concepts were revised and then extended using advanced C++ function features. These features make programs easier to write, reuse, and manage.

---

### 2. Functions in C++

A function is a block of code that performs a specific task. It helps to divide a large program into smaller parts.

Functions make a program easier to read, debug, and reuse. For example, instead of writing the same calculation again and again, we can create a function and call it whenever needed.

Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

### 3. Arrays in C++

An array is a collection of elements of the same data type stored in continuous memory locations.

Arrays are useful when we need to store multiple values under one variable name. For example, marks of five students can be stored in an array instead of creating five separate variables.

Example:

```cpp
int marks[5] = {80, 75, 90, 85, 70};
```

---

### 4. Structures in C++

A structure is a user-defined data type that groups different types of data under one name.

For example, a `Student` structure can store roll number, name, and marks together. This makes related data easier to organize.

Example:

```cpp
struct Student {
    int roll;
    float marks;
};
```

---

## Advanced C++ Function Features

### 1. Function Overloading

Function overloading allows multiple functions to have the same name but different parameter lists. The difference may be in the number, type, or order of parameters.

It improves readability because the same function name can be used for similar operations.

Example:

```cpp
int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}
```

Here, both functions are named `add`, but one works with integers and the other works with floating-point numbers.

---

### 2. Inline Function

An inline function is a small function defined using the `inline` keyword. It reduces function call overhead by expanding the function code at the place where it is called.

Inline functions are useful for small and frequently used functions.

Example:

```cpp
inline int square(int x) {
    return x * x;
}
```

Instead of jumping to the function every time, the compiler may directly replace the function call with the function body.

---

### 3. Default Arguments

Default arguments allow function parameters to have predefined values. If the user does not pass a value for that parameter, the default value is used.

This makes function calls flexible and shorter.

Example:

```cpp
int multiply(int a, int b = 2) {
    return a * b;
}
```

Here, if only one value is passed, `b` automatically becomes 2.

---

### 4. Pass by Reference

Pass by reference allows a function to access and modify the original variable directly. This is done using the reference symbol `&`.

In normal pass by value, only a copy of the value is passed. But in pass by reference, changes made inside the function affect the original variable.

Example:

```cpp
void changeValue(int &x) {
    x = x + 10;
}
```

This is useful when we need to update actual values inside a function.

---

### 5. Return by Reference

Return by reference means a function returns a reference to a variable instead of returning a copy.

This is useful when we want to modify the original variable through the returned reference. However, care must be taken because returning reference to a local variable is not safe.

Example:

```cpp
int& getValue(int &x) {
    return x;
}
```

---

## Lab Implementation Tasks

The following programs were performed in this lab:

### Task 1: Function Overloading

A program was written to demonstrate function overloading. Multiple functions with the same name were created but with different parameter types or numbers.

This helped to understand how C++ selects the correct function based on the arguments passed during the function call.

---

### Task 2: Inline Function

An inline function was created to perform a small calculation such as finding the square of a number.

This task helped to understand how inline functions reduce function call overhead for small and frequently used functions.

---

### Task 3: Default Arguments

A program was written using a function with default arguments. The function was called with both full arguments and fewer arguments.

This showed how default values are automatically used when some arguments are not provided.

---

### Task 4: Pass by Reference

A program was written to demonstrate pass-by-reference. A function was used to modify the actual value of a variable passed to it.

This helped to understand the difference between passing a value and passing a reference.

---

### Task 5: Return by Reference

A program was written to demonstrate return-by-reference. The function returned a reference to a variable, allowing direct modification of the original value.

This task helped to understand how references can be used to avoid unnecessary copying and directly work with original data.

---

## Observation

After completing this lab, it was observed that C++ provides more flexible function features than C.

Function overloading allows the same function name to be used for different types of inputs. Inline functions are useful for small operations. Default arguments make function calls easier because not all values need to be passed every time.

It was also observed that pass-by-reference can directly modify original variables, while return-by-reference can return the actual variable instead of a copy.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The function overloading program correctly selected the required function based on the given arguments. The inline function program successfully performed the calculation. The default argument program worked properly with both complete and incomplete argument lists.

The pass-by-reference program successfully modified the original variable, and the return-by-reference program demonstrated how a reference can be returned from a function.

---

## Discussion

This lab helped to understand advanced function features in C++. These features are important because they make programs shorter, cleaner, and more efficient.

Function overloading improves program readability because similar operations can use the same function name. Inline functions are useful when a small function is called many times. Default arguments make functions more flexible by reducing the need to pass every value manually.

Pass-by-reference and return-by-reference are also important because they allow direct access to original variables. This becomes very useful in larger programs where copying data again and again may reduce efficiency.

Overall, this lab strengthened the basic procedural programming concepts needed before learning deeper object-oriented programming topics.

---

## Conclusion

In this lab, the basic concepts of C++ programming were revised and advanced function features were studied. Functions, arrays, and structures were reviewed, while function overloading, inline functions, default arguments, pass-by-reference, and return-by-reference were practiced.

This lab helped to understand how C++ improves procedural programming by adding more flexible and efficient function features. These concepts are important for building a strong foundation in object-oriented programming.

---

## References

[1] HCOE, *Lab Manual on Object Oriented Programming [CT 151]*, 2081.

[2] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.
