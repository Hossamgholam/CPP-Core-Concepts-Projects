# ATM System (Procedural C++)

A console-based **ATM simulation** implemented using **procedural programming**
to demonstrate core C++ fundamentals such as file handling, functions,
control flow, and data validation.

This project simulates basic ATM operations using a persistent data file
to store client information and balances.

---

## 📌 Features

- User login using **Account Number & PIN**
- Quick Withdraw (predefined amounts)
- Normal Withdraw (custom amount – multiples of 5)
- Deposit funds
- Check account balance
- Logout and re-login
- Persistent data storage using text files

---

## 📂 Data Storage

Client data is stored in a text file using the following format:

AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance


Example:


A1001#//#1234#//#John Doe#//#0123456789#//#1500

---

## 🛠️ Concepts Demonstrated

- Procedural programming design
- Enums for menu options
- Structs for data modeling
- File I/O (`fstream`)
- Input validation
- Menu-driven console applications
- Reusable functions
- Basic error handling

---

## 📖 Design Notes

- Withdraw operations are handled by passing **negative values**
  to a shared deposit/update function to reduce code duplication.
- Client data is reloaded from the file when updates are made
  to ensure persistence.
- This project intentionally avoids OOP to focus on
  **procedural programming fundamentals**.

---



## 🚀 Future Improvements

- Refactor into an OOP-based design
- Encrypt PIN codes
- Improve input validation
- Add transaction history
- Replace text file storage with a database

---

## 👤 Author

**Hossam Gholam**  
Computer Science Student | Aspiring Backend Developer