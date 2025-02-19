Internal-External Exploit Development in C++

Overview

This project demonstrates how to develop an internal-external exploit in C++ using Qt, TlHelp32, and DLL Injection techniques. It showcases the process of injecting a dynamic-link library (DLL) into a target process for modification or control.

Features

Process Scanning: Uses TlHelp32 to list and identify target processes.

DLL Injection: Implements a method to inject a DLL into a target process.

External Memory Manipulation: Reads and writes memory externally using the Windows API.

Internal Hooking: Hooks into the process to execute specific functions.

Qt GUI (Optional): Provides a user-friendly graphical interface for selecting processes and injecting DLLs.

Prerequisites

System Requirements

Windows OS (Recommended: Windows 10 or later)

Visual Studio (Recommended: 2019 or later)

MinGW or MSVC compiler (for Qt and C++)

Qt Framework (if using GUI)

Administrator Privileges (for process injection)

Dependencies

Windows API (Kernel32, User32, TlHelp32)

Qt Framework (if using a GUI)

Usage

1. Running the Injector

Open the built executable.

Select the target process from the list.

Browse and select the DLL to inject.

Click Inject to load the DLL into the process.

2. Executing Internal Functions

After injection, the DLL will execute predefined functions inside the target process.

Modify DLLMain.cpp to customize payload execution.

3. External Memory Editing

Use ReadProcessMemory and WriteProcessMemory to manipulate values externally.

Security & Legal Disclaimer

This project is for educational purposes only. Any unauthorized usage of this software is strictly prohibited. The author holds no responsibility for any misuse.

Contribution

Feel free to contribute by submitting pull requests or opening issues for bug fixes and improvements.
