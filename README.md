# lsbtw 🚀

`lsbtw` is a lightweight, custom alternative to the standard Linux `ls` command written in C. It gives you a clean list of directory contents while instantly showing you what is a file and what is a directory using clear visual markers and automatic color formatting.

## Features 
* **Visual Indicators:** Automatically appends `/` to directories and `*` to regular files.
* **Modern Colors:** Displays directories in bold blue and files in bold green.
* **Shell Agnostic:** Works perfectly out-of-the-box in **Fish**, **Bash**, **Zsh**, and other modern terminal shells.
* **Smart Piping:** Automatically detects if the output is redirected (like `lsbtw | grep`) and strips ANSI colors to prevent formatting issues.

## Installation 

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd lsbtw
   ```


3. **Install it globally:**
   Move the compiled binary to your local bin path so you can use it anywhere without typing `./`:
   ```bash
   sudo cp lsbtw /usr/local/bin/
   ```

## Usage 

Simply type `lsbtw` in your terminal:
```bash
lsbtw
```

You can also pass a specific path as an argument:
```bash
lsbtw /var/log
```
