
# C++ Compiler Setup Guide

This course uses C++ for assignments and projects. Because C++ compilers differ by operating system, follow the section below that matches your machine (**macOS**, **Windows**, or **Linux**).

---

## macOS

On macOS, you have two main options: **Clang** (recommended for most students, built directly into Apple Developer Tools) or **GCC via Homebrew** (if you specifically require `g++`).

### Option 1: Apple Clang (Recommended)

This installs Apple's official C++ toolchain via the terminal.

1. Open the **Terminal** app (press `Cmd + Space`, type `Terminal`, and press `Enter`).
2. Run the following command:
```bash
xcode-select --install

```


3. A pop-up window will appear asking if you want to install the command line developer tools. Click **Install** and accept the license agreement.
4. Once installation completes, verify it by checking the version:
```bash
clang++ --version

```


*(Note: macOS also symlinks `g++` to `clang++`, so running `g++ --version` will work as well.)*

---

### Option 2: GCC / `g++` via Homebrew (Optional)

If you need true GNU `g++` instead of Apple Clang:

1. Install [Homebrew](https://brew.sh) if you do not have it already:
```bash
/bin/bash -c "$(curl -sSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

```


2. Install GCC:
```bash
brew install gcc

```


3. Verify installation:
```bash
g++-13 --version   # Replace 13 with the installed version number if newer

```



---

## Windows (MinGW-w64)

MinGW-w64 provides a native C++ compiler (`g++`) for Windows.

### Step 1: Download MinGW-w64

1. Go to the [WinLibs standalone release page](https://winlibs.com/).
2. Under the **Download** section, select the latest **Win64** release in **UCRT** mode formatted as a **Zip archive** (e.g., *GCC + LLVM/Clang/lld/LLDB + MinGW-w64 ... Zip archive*).

### Step 2: Extract the Files

1. Open the downloaded `.zip` file.
2. Extract the `mingw64` folder directly to the root of your C drive so that its path becomes:
```text
C:\mingw64

```



### Step 3: Add MinGW to your System PATH

Adding the `bin` folder to your PATH allows Windows to run `g++` from any terminal prompt.

**Via Command Prompt (Quickest):**

1. Open **Command Prompt** as Administrator.
2. Run the following command:
```cmd
setx /M PATH "%PATH%;C:\mingw64\bin"

```



**Via Windows GUI Settings (Alternative):**

1. Press the `Windows Key`, type **env**, and select **Edit the system environment variables**.
2. Click **Environment Variables...** at the bottom right.
3. Under **System variables**, select `Path` and click **Edit...**.
4. Click **New**, enter `C:\mingw64\bin`, and click **OK** on all windows.

### Step 4: Verify the Installation

1. Close all open Command Prompt or PowerShell windows.
2. Open a **new** Command Prompt window.
3. Run:
```cmd
g++ --version

```



If configured correctly, you will see output detailing the installed version of `g++`.

---

## Linux (Ubuntu / Debian)

Most Linux distributions can install the full development toolchain in a single command.

1. Open your terminal and update package lists:
```bash
sudo apt update

```


2. Install the `build-essential` package (includes `g++`, `gcc`, and `make`):
```bash
sudo apt install build-essential

```


3. Verify installation:
```bash
g++ --version

```



---

## Quick Test: Compiling Your First Program

To confirm everything is working across all operating systems:

1. Create a file named `hello.cpp` with the following code:
```cpp
#include <iostream>

int main() {
    std::cout << "C++ is successfully configured!" << std::endl;
    return 0;
}

```


2. Open your terminal/command prompt, navigate to the folder containing `hello.cpp`, and run:
```bash
g++ hello.cpp -o hello

```


3. Execute the compiled program:
* **macOS / Linux:** `./hello`
* **Windows:** `hello.exe`



---

## Troubleshooting

* **`'g++' is not recognized as an internal or external command...` (Windows)**
* You likely did not restart your Command Prompt window after updating PATH, or the path specified (`C:\mingw64\bin`) does not match where you extracted the folder.


* **`command not found: g++` (macOS / Linux)**
* Re-run the installation command for your system and ensure the process finishes without error messages.