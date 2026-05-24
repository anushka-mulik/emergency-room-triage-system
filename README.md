# 🚑 Emergency Room Triage System (C Language Project)

## 📌 Project Overview
The Emergency Room Triage System is a console-based application developed in C that simulates hospital emergency room operations.

The system prioritizes patients based on severity using a **Max Heap data structure**, ensuring that critical patients are treated first. It also includes login authentication, file handling, and persistent patient storage.

---

## 🧠 Core Concept

This system is built using a:

### 🔺 Max Heap Priority Queue
Patients are prioritized based on:

1. Higher severity → higher priority
2. If severity is equal → earlier arrival order gets priority

This ensures fair and efficient emergency treatment management.

---

## 🎯 Features

### 🔐 Login System
- Doctor login (`doctor / 1234`)
- Nurse login (`nurse / 1234`)
- Role-based authentication before system access

---

### 🧑‍⚕️ Patient Management
- Add new patient:
  - ID
  - Name
  - Age
  - Disease
  - Severity (1–5)
- Automatic arrival order tracking
- Critical alert for severity level 5 patients

---

### 📊 System Functionalities
- Display all patients in queue
- Search patient by ID
- Treat highest priority patient
- Real-time dashboard display

---

### ⚡ Priority System (Heap-Based)
- Implemented using Binary Max Heap
- Heap operations:
  - `heapifyUp()` → maintains order after insertion
  - `heapifyDown()` → maintains order after deletion

---

### 💾 File Handling
- Patient data stored in: `patients.txt`
- Functions:
  - `saveToFile()` → saves data after every update
  - `loadFromFile()` → loads data at program start
- Ensures data persistence even after restart

---

## 🏗️ Project Structure
