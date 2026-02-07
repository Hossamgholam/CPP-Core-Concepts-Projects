# 🏦 Bank Management System – Extension 3  
## User Management & Permission System

This project is the third extension of the **Bank Management System** and focuses on
transforming the application from a single-user program into a **secure multi-user system**
with authentication and authorization.

---

## 📌 Overview

In this extension, the system introduces **user accounts**, **login functionality**, and
a **permission-based access control system**.  
Instead of allowing every user to access all features, each user is granted specific
permissions that control what they can see and do inside the system.

This extension focuses on **system design and security**, not on adding new client features.

---

## 🧠 System Architecture (High-Level)

The application follows this hierarchy:

1. **Login System**
   - Authenticate users using username & password
   - Load user data from a file
   - Set the current logged-in user

2. **Main Menu**
   - Client Management (permission-based)
   - Transactions
   - User Management (Admin only)
   - Logout

3. **User Management Module**
   - Add users
   - Delete users
   - Update users
   - Find users
   - Assign permissions

4. **Permission Control Layer**
   - Each action is checked before execution
   - Access denied message shown if permission is missing

---

## 🔐 Authentication & Authorization

### Authentication
- Users must log in using a **username and password**
- Credentials are validated from a text file
- Login repeats until valid credentials are provided

### Authorization
- Each user has a **permission value (integer)**
- Permissions are implemented using **bitmasking**
- Before accessing any feature, the system checks:
  - Does the user have permission?
- Admin users have full access using permission value `-1`

---

## 👥 User Management Features

- Add new users
- Delete existing users
- Update user data
- Find users by name
- Assign permissions dynamically
- Prevent duplicate usernames

---

## 📂 Data Storage

- **Clients** are stored in a separate file
- **Users** are stored in a dedicated users file
- Data is loaded into memory, modified, then saved back to files
- Deleted users are marked first, then excluded when saving

---

## 🧩 Permissions Model

Permissions are handled using an enum + bitmask logic:

- Show clients
- Add clients
- Delete clients
- Update clients
- Find clients
- Transactions menu
- Manage users

Each permission is checked at runtime before showing menus or executing operations.

---

## 🎯 Purpose of This Extension

The goal of Extension 3 is to practice and demonstrate:

- Authentication systems
- Authorization logic
- Permission handling using bitmask
- Secure menu navigation
- Separation between system users and bank clients
- Thinking in terms of **system-level design**

This extension reflects real-world backend concepts commonly used in professional software.

---


## 🚀 Learning Outcome

By completing this extension, I practiced:
- Designing multi-user systems
- Implementing role-based access control
- Managing system state securely
- Building scalable console applications

---

**Author:** Hossam  Gholam
**Language:** C++  
**Concepts:** File Handling, Functions, Enums, Structs, Bitmask, System Design
