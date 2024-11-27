# Multi-Threaded Web Crawler

<p align="center">
    <img src="https://img.shields.io/badge/Language-C/C++-blue" alt="Language">
    <img src="https://img.shields.io/badge/Build-Makefile-lightblue" alt="Build">
    <img src="https://img.shields.io/badge/Status-Active-success" alt="Status">
</p>


## 👨‍💻 Authors

- [Tales Oliveira](https://github.com/TalesLimaOliveira)

---

## 📖 Overview
This project consists of a **generic Makefile** that can be used on any operating system to compile C/C++ programs. It provides an organized folder structure and automates the process of compiling and cleaning temporary binary files.

---

## 📦 Requirements
> GCC/G++ (MinGW.org GCC Build-2) - Versão 9.2.0

> GNU Make - Versão 3.82.90

---

## 📂 Project Structure

| **Directory/File**    | **Description**                             |
|-----------------------|---------------------------------------------|
| `app/`                | Main application directory.                 |
| └── `main.c/cpp`      | Entry point of the application.             |
| `src/`                | Source code for core functionalities.       |
| └── `*.c/cpp`         |                                             |
| `inc/`                | Header files for declarations.              |
| └── `*.h`             |                                             |
| `resources/`          | Folder for your imgs, audio, and others     |
| `Makefile`            | Build automation script.                    |
| `README.md`           | File containing project documentation.      |

---

## 🚀 How to Run

### 🔨 Build the Project
> make

### ▶️ Run the Application
> make run-'app_name' argr1 argr2

Replace **<app_name>** with the name of the file located in the app folder that you want to compile.

### 🧹 Clean Build Files
> make clean
