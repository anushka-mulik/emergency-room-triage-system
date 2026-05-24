# 🚑 Emergency Room Triage System (C Language Project)

---

## 📌 Project Overview
The Emergency Room Triage System is a console-based application developed in C that simulates hospital emergency room operations.

It prioritizes patients based on severity using a **Max Heap data structure**, ensuring that critical patients are treated first. The system also supports login authentication and file handling for data persistence.

---

## 🧠 Core Concept

This project is based on a **Priority Queue using Max Heap**.

### Priority Rules:
- Higher severity → Higher priority
- If severity is same → Earlier arrival gets priority

This ensures fair and efficient patient management in emergency situations.

---

## 🎯 Features

- 🔐 Login system (Doctor & Nurse)
- 🧑‍⚕️ Add patient with details:
  - ID
  - Name
  - Age
  - Disease
  - Severity (1–5)
- 📊 Display all patients
- 🔍 Search patient by ID
- 🏥 Treat highest priority patient
- ⚡ Automatic priority management using Heap
- 🚨 Emergency alert for severity = 5
- 💾 File handling (data saved in patients.txt)
- 📈 Dashboard showing system status

---

## 🏥 Patient Management

- Patients are stored in a **heap-based priority queue**
- Each patient has:
  - Unique ID
  - Name
  - Age
  - Disease
  - Severity level
  - Arrival order (for tie-breaking)

- The system automatically arranges patients based on priority.

---

## ⚙️ System Functionalities

- Add new patient
- View all patients
- Search patient by ID
- Treat patient (remove highest priority)
- Login system (Doctor/Nurse)
- Dashboard display

---

## ⚡ Priority System (Heap Logic)

The system uses **Binary Max Heap**:

- heapifyUp() → Maintains order after insertion  
- heapifyDown() → Maintains order after deletion  

### Priority Decision:
1. Severity comparison
2. Arrival order (FIFO for same severity)

---

## 💾 File Handling

Patient data is stored in:
patients.txt

### Functions:
- saveToFile() → Saves data after every operation  
- loadFromFile() → Loads data at program start  

✔ Ensures data is not lost after closing program

---

## 🏗️ Project Structure

EMERGENCYROOMTRIAGE/
│
├── main.c              → Program execution & menu system
├── functions.c         → Core logic (heap, patient operations)
├── functions.h         → Function declarations & structure
├── patients.txt        → Stored patient data file
└── README.md

---

## 🔄 System Workflow

1. Program starts
2. Patient data is loaded from file
3. User logs in (Doctor or Nurse)
4. Dashboard is displayed
5. User selects an option:
   - Add Patient
   - Display Patients
   - Search Patient
   - Treat Patient
   - Exit
6. Heap updates automatically after every operation
7. Data is saved to file

---

## 🔁 GitHub Workflow

This project was developed using GitHub collaboration with feature branching.

### Workflow:

Branch → Code → Add → Commit → Push → Pull Request → Merge

### Steps Followed:
- Repository created on GitHub
- Team members added as collaborators
- Each member worked on a separate branch
- Code was committed with meaningful messages
- Pull Requests were created
- Final merge into main branch

---

## 🌿 Branch Strategy

- main → Final stable version  
- feature/patient-registration → Patient input system  
- feature/triage-priority-system → Heap logic  
- feature/patient-queue-display → Display system  

---

## 💡 Example Commit Messages

- Implemented max heap for priority queue  
- Added patient registration module  
- Created file handling system for data persistence  
- Implemented treat patient functionality using heapify  
- Added login authentication system  

---

## ⚙️ How to Run Project

### Compile:
gcc main.c functions.c -o triage

### Run (Windows):
triage.exe

---

## 🔑 Login Credentials

Doctor:
Username: doctor  
Password: 1234  

Nurse:
Username: nurse  
Password: 1234  

---

## 📚 Concepts Used

- C Programming  
- Structures (struct)  
- Heap Data Structure (Priority Queue)  
- File Handling (fopen, fprintf, fscanf)  
- Modular Programming  
- String Handling  
- Authentication System  
- Menu-driven application design  

---

## 🎯 Learning Outcomes

- Real-world hospital triage simulation  
- Priority queue implementation using heap  
- File handling in C  
- Git & GitHub collaboration workflow  
- Modular system design  
- Team-based software development  

---

## 👨‍💻 Contributors

- Member 1 – Patient Registration Module  
- Member 2 – Triage Priority System (Heap Logic)  
- Member 3 – Display & Queue Management  

---

## ⭐ Acknowledgement

We sincerely thank our faculty and mentors for their guidance and support in completing this project successfully.
