# Linux Cheat Sheet

## Navigation

```bash
pwd
ls
ls -l
ls -la
ls -lh
tree
tree -L 2
cd folder
cd ..
cd ~
cd -
```

---

## File Operations

```bash
touch file.txt
mkdir Folder
mkdir -p A/B/C

cp file backup
cp -r Folder Backup

mv old new

rm file
rm -r Folder
rm -rf Folder
```

---

## Search

```bash
find . -name "*.cpp"

find . -name "*.root"

find . -name "*.md"

which python

locate geant4
```

---

## Environment

```bash
echo $HOME

echo $PATH

echo $PWD

echo $USER
```

---

## Permissions

```bash
chmod +x script.sh

chmod 755 file

chown user file
```

---

## Compression

```bash
tar -xzf archive.tar.gz

tar -czf archive.tar.gz Folder

zip -r project.zip Folder

unzip project.zip
```

---

## Networking

```bash
wget URL

curl URL

ssh user@server

scp file user@server:
```

---

## Process

```bash
top

htop

ps

kill PID
```

---

## Git

```bash
git status

git add .

git commit -m "message"

git log

git push

git pull
```

---

## Research Commands

Find ROOT files

```bash
find . -name "*.root"
```

Compile C++

```bash
g++ main.cpp -o main
```

Run executable

```bash
./main
```

Run Python

```bash
python script.py
```

List ROOT files

```bash
ls -lh *.root
```

Show project tree

```bash
tree -L 3
```

---

## Keyboard Shortcuts

| Shortcut | Description |
|----------|-------------|
| Tab | Auto-complete |
| Ctrl+C | Stop current process |
| Ctrl+D | Exit shell |
| Ctrl+L | Clear terminal |
| Ctrl+R | Search history |
| ↑ | Previous command |
| ↓ | Next command |

---

## Daily Workflow

```bash
cd ~/Research

git status

code .

# Work...

git add .

git commit -m "Today's progress"

git push
```

---

> Learn commands by using them, not by memorizing them.