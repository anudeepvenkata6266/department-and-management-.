# Department Management System  
Last Updated: This Week  

---

## ✅ Standard Supported  
**C Standards:** C89 / C99 / C11  

---

## 📚 Header Files Required  
# 📁 DATA STORAGE  
✔ No file handling (in-memory storage)  
✔ Uses **parallel arrays**  
✔ Maximum records: 50 departments  

Stored fields:
- Department Name  
- HOD Name  
- Faculty Count  

---

## 📌 FUNCTIONAL REQUIREMENTS  

### 🖥 User Interface  
- Terminal-based CLI  
- Clean, simple menu navigation  
- Accepts string input (fgets)  
- Handles empty/invalid searches gracefully  

---

## 🏫 Department Management Operations  

### ➕ Add Department  
User enters:

- Department Name  
- HOD Name  
- Faculty Count  

Record stored using global parallel arrays.

---

### 📋 View All Departments  
Displays all department records in a formatted table:

ID | Department Name | HOD Name | Faculty Count

yaml
Copy code

---

### 🔍 Search Department  
Search using **Department Name** (exact match).

Displays:

- ID  
- Department Name  
- HOD  
- Faculty Count  

Shows **“not found”** message if no record exists.

---

## 🔧 DATA MANAGEMENT  
- Data stored in memory (not permanent)  
- Supports up to 50 departments  
- Allows multi-word names (via fgets)  
- Uses `strcspn()` to remove newline characters  

---

## 🔄 PROGRAM FLOW  
- Menu runs in continuous loop  
- Clear options:
Add Department

View All Departments

Search Department

Exit

yaml
Copy code
- Shows success/failure messages  
- Exit option ends application safely  

---

## ▶️ Running the Program  

### 1️⃣ Compile  
gcc department.c -o department

shell
Copy code

### 2️⃣ Run  
Linux / macOS:
./department

makefile
Copy code

Windows:
department.exe

yaml
Copy code

---

## 📸 Screenshots (Optional)

### ➕ Add Department  
*(Screenshot can be placed here)*  
Enter Department Name:
Enter HOD Name:
Enter Faculty Count:
Department Added Successfully!

markdown
Copy code
![1](https://github.com/user-attachments/assets/8e016d7f-8171-4bc0-af87-ecaaf28f26b0)
![2](https://github.com/user-attachments/assets/e9eafbfc-1b1a-4497-8ac7-91bfdcff7204)
![3](https://github.com/user-attachments/assets/dea00f4d-1aea-4fae-9afb-09c22a9e3cae)
![4](https://github.com/user-attachments/assets/f9bbb3e9-e354-47ff-aab7-d065d35e287b)

### 📋 View Departments  
*(Screenshot can be placed here)*  
ID Dept Name HOD Name Faculty
1 CSE Dr. Ramesh 40
2 ECE Dr. Kavitha 35

markdown
Copy code

### 🔍 Search Department  
*(Screenshot can be placed here)*  
Enter Department Name to search:
--- Record Found ---
ID: 1
Department: CSE
HOD: Dr. Ramesh
Faculty Strength: 40

yaml
Copy code

---

## 📝 Notes  
- Increase MAX_DEPTS to add more departments  
- Be careful with trailing newline characters while using `fgets()`  

---

## ✨ Future Enhancements  
- Add File Handling (binary storage)  
- Add Update/Delete department  
- Convert to Structure-Based Storage  
- Add Sorting (A–Z / by faculty count)  
- Input validation system  

---

## 📜 License  
Free to use for academic and learning purposes.
