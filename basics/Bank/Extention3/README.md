## 🔐 Extension 3 – System Users & Permissions

### 📌 Overview

Extension 3 adds a **login system** to the bank application.
Instead of allowing direct access, users must authenticate before
performing any operation.

Each user has specific permissions that control what actions they can perform.

---

### 👤 User Structure

Each user has:

- Username
- Password
- Permissions (bitmask or flags)

Example permissions:
- Show clients
- Add clients
- Delete clients
- Update clients
- Transactions
- Full access (Admin)

---

### 📂 Data Storage

- **users.txt** → stores system users
- **clients.txt** → stores bank clients

Each file uses a structured delimiter-based format.

---

### 🔑 Authentication Flow

1. Program starts
2. Login screen is displayed
3. Username & password are validated
4. User permissions are loaded
5. Menu options are enabled/disabled based on permissions

---

### 🧠 Authorization Logic

Before executing any operation:

- The system checks the logged-in user's permissions
- If permission is missing → access is denied
- Admin users have full access

---

### 🧱 Design Goals of Extension 3

- Separate **authentication logic** from business logic
- Prevent unauthorized access
- Simulate real-world banking systems
- Prepare the codebase for OOP refactoring

---

## 🎯 Learning Objectives

By the end of Extension 3, the project demonstrates:

- Real-world console application flow
- File-based authentication system
- Permission-based access control
- Clean separation of responsibilities
- Scalable design ready for OOP

---

## 🚀 Future Improvements

- Convert `struct` logic into classes
- Apply SOLID principles
- Replace text files with a database
- Add logging and audit trails
- Improve UI and error handling

---

## 🧠 Author

**Hossam ElSayed**  
Faculty of Computers – Backend Track  
Focused on mastering core programming concepts before frameworks

---