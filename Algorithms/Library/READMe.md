# C++ Core Concepts – Utility & Algorithms Framework

## 📌 Project Overview

This repository represents a structured C++ learning journey focused on
building foundational programming skills through manual implementation
of core utilities, algorithms, and helper libraries.

Instead of relying heavily on the C++ Standard Library, this project
emphasizes understanding how common features work internally.

The project is organized as a small educational framework composed of
reusable utility libraries.

---

## 🧠 Learning Philosophy

This project was built to:

- Strengthen algorithmic thinking
- Practice object-oriented programming (OOP)
- Implement core logic manually
- Understand separation of concerns
- Build reusable utility libraries
- Prepare for advanced backend/system development

This repository reflects the **Core Concepts & Algorithms stage**
of the learning journey.

---

## 📚 Project Structure

The project consists of the following libraries:

### 1️⃣ clsString
A reusable string utility class that provides:

- Case manipulation (upper/lower/invert)
- Word and letter counting
- Trim / Split / Join
- Word replacement
- Punctuation removal
- Vowel detection
- Character frequency analysis

Supports both:
- Static utility usage
- Object-based string manipulation

---

### 2️⃣ mathe (Math Utility Namespace)

A lightweight mathematical utility namespace providing:

- Custom ceil, floor, and round
- Absolute value
- Recursive power
- Factorial
- Geometry calculations (rectangle, triangle, circle)
- Prime number check
- Odd/Even detection
- Array numeric operations

Designed primarily for algorithm practice.

---

### 3️⃣ clsDate

A custom Date handling class that supports:

- Date validation
- Date comparison
- Date swapping
- Range checks
- Integration with validation layer

Acts as the core date engine for the framework.

---

### 4️⃣ clsInputValidate

Responsible for safe user input and validation:

- Safe integer and double reading
- Range validation using templates
- Date validation using clsDate
- Date range checking

Acts as the Validation Layer of the framework.

---

### 5️⃣ clsUtil

A comprehensive utility toolkit including:

#### 🔹 Random & Key Generation
- Random numbers
- Random characters
- Word generation
- License-style key generation

#### 🔹 Encryption (Educational)
- Simple character-shift encryption
- Decryption

#### 🔹 Array Utilities
- Shuffle
- Copy
- Search
- Palindrome check

#### 🔹 Matrix Utilities
- Matrix sum
- Row/column sum
- Identity matrix check
- Scalar matrix check
- Matrix comparison
- Palindrome rows
- Max/Min value

#### 🔹 Number Utilities
- Perfect number detection
- Number reversal
- Palindrome number check
- Digit frequency

---




## ⚠️ Educational Notes

This project prioritizes learning over production optimization.

Some implementations are intentionally manual to:

- Understand internal logic
- Practice recursion and loops
- Avoid overreliance on STL

Known limitations:

- Encryption uses simple character shifting (not secure).
- Some functions assume fixed array sizes.
- Random seeding must be called once at program start.
- Some naming inconsistencies reflect learning evolution.



## 🎯 Purpose of This Repository

This repository demonstrates:

- Strong fundamentals in C++
- Understanding of OOP
- Algorithmic problem solving
- Clean structural thinking
- Reusable library design

It represents a major milestone in mastering
C++ Core Concepts before moving into advanced system and backend development.

---

## 👨‍💻 Author

Built as part of a structured C++ learning journey
focused on mastering programming fundamentals and backend foundations.