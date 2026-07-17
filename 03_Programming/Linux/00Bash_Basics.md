# Bash Basics

> "The terminal is the native language of Linux."
>
> This note covers the fundamental Bash commands that every researcher,
> software developer and High Energy Physicist should know.

---

# What is Bash?

**Bash (Bourne Again SHell)** is the default command-line shell on most Linux distributions.

A shell acts as an interface between the user and the operating system.

Instead of clicking buttons, you communicate with the operating system by typing commands.

---

# Why Learn Bash?

As a High Energy Physics researcher you will use Bash every day.

Examples:

- Running Geant4 simulations
- Compiling ROOT
- Using CMake
- Managing Coffea workflows
- Running Python scripts
- Connecting to CERN servers
- Working on HPC clusters
- Automating repetitive tasks

Learning Bash is one of the highest return-on-investment skills in scientific computing.

---

# Linux File System

Everything begins from the root directory.

```
/
├── home
│   └── ekaradum
│       └── Research
├── usr
├── bin
├── etc
└── var
```

Your workspace:

```
/home/ekaradum/Research
```

---

# Absolute vs Relative Paths

Absolute path

```
/home/ekaradum/Research
```

Relative path

```
03_Programming
```

Go one level up

```
cd ..
```

Current directory

```
.
```

Home directory

```
cd ~
```

---

# pwd

## Purpose

Print Working Directory.

## Syntax

```bash
pwd
```

Example

```bash
pwd
```

Output

```
/home/ekaradum/Research
```

Research Example

Always verify where you are before running analysis scripts.

---

# ls

## Purpose

Lists files and folders.

Syntax

```bash
ls
```

Useful flags

```bash
ls -l
```

Long format.

```bash
ls -la
```

Show hidden files.

```bash
ls -lh
```

Human-readable sizes.

```bash
ls -lt
```

Sort by modification time.

```bash
ls -R
```

Recursive listing.

Research Example

```bash
cd ~/Research/05_Projects

ls -lh
```

Shows ROOT files and project outputs.

---

# cd

Change directory.

```bash
cd 03_Programming
```

Go to Programming.

```bash
cd ..
```

Go back.

```bash
cd ~
```

Go home.

```bash
cd -
```

Return to previous directory.

Research Example

Move between ROOT analysis and Coffea projects.

---

# tree

Visualize folder hierarchy.

```bash
tree
```

Depth

```bash
tree -L 2
```

Research Example

Display your Research workspace.

---

# mkdir

Create directory.

```bash
mkdir Notes
```

Create nested directories.

```bash
mkdir -p Projects/Coffea/Test
```

---

# touch

Create file.

```bash
touch README.md
```

---

# cp

Copy files.

```bash
cp file.txt backup.txt
```

Copy folders.

```bash
cp -r Folder Backup
```

Research Example

Duplicate a Geant4 example before editing.

---

# mv

Move or rename.

```bash
mv old.cpp new.cpp
```

Move

```bash
mv file.txt Documents/
```

---

# rm

Remove files.

```bash
rm file.txt
```

Recursive

```bash
rm -r Folder
```

Force

```bash
rm -rf Folder
```

⚠ Never use rm -rf carelessly.

---

# clear

Clear terminal.

```bash
clear
```

Shortcut

Ctrl + L

---

# history

Show command history.

```bash
history
```

Run previous command

```bash
!105
```

Search history

```
Ctrl + R
```

---

# man

Manual pages.

```bash
man ls
```

Exit

```
q
```

---

# which

Locate executable.

```bash
which python
```

Example

```
/usr/bin/python
```

---

# echo

Print text.

```bash
echo Hello
```

Display variable.

```bash
echo $HOME
```

---

# Important Environment Variables

HOME

```bash
echo $HOME
```

PATH

```bash
echo $PATH
```

PWD

```bash
echo $PWD
```

USER

```bash
echo $USER
```

---

# Research Examples

Locate ROOT files

```bash
find . -name "*.root"
```

Locate Python notebooks

```bash
find . -name "*.ipynb"
```

Run analysis

```bash
python analysis.py
```

Compile C++

```bash
g++ main.cpp -o main
```

Run executable

```bash
./main
```

Launch Geant4

```bash
./exampleB1
```

---

# Common Mistakes

❌ Running commands in the wrong directory.

Always check

```bash
pwd
```

---

❌ Deleting folders with

```bash
rm -rf
```

without checking.

---

❌ Forgetting executable permission.

```bash
chmod +x script.sh
```

---

# Useful Shortcuts

Tab

Auto-complete.

↑

Previous command.

↓

Next command.

Ctrl + C

Interrupt program.

Ctrl + D

Exit terminal.

Ctrl + L

Clear screen.

Ctrl + R

Search command history.

---

# Summary

Mastering Bash means mastering Linux.

Every modern scientific software stack relies heavily on the command line.

Invest time here—it will pay dividends throughout your research career.