# Git Basics

> "Git is not just a backup tool.
> It is the memory of a project."

---

# What is Git?

Git is a **Distributed Version Control System (DVCS)** created by **Linus Torvalds** in 2005.

Instead of saving only the latest version of your work, Git stores the complete history of your project.

Every important change can be restored at any time.

Git allows you to

- Track every modification
- Restore previous versions
- Work on multiple features simultaneously
- Collaborate with other researchers
- Synchronize projects with GitHub

For research projects, Git is one of the most important tools because analyses often evolve over months or years.

---

# Why is Git Important?

Imagine writing a physics analysis.

```
analysis.py
```

You change one line.

The plots become wrong.

Without Git:

```
analysis.py
analysis_old.py
analysis_old2.py
analysis_FINAL.py
analysis_FINAL_LAST.py
analysis_FINAL_REALLYLAST.py
```

Eventually you have no idea which file is correct.

With Git:

```
analysis.py

↓

Commit

↓

analysis.py

↓

Commit

↓

analysis.py
```

Git remembers every version.

Nothing is ever truly lost.

---

# Git vs GitHub

Many beginners think Git and GitHub are the same thing.

They are not.

## Git

Git is the software installed on your computer.

It tracks versions.

It works completely offline.

Think of Git as your personal laboratory notebook.

---

## GitHub

GitHub is an online platform.

It stores Git repositories.

Think of GitHub as an online backup and collaboration platform.

```
Computer
   │
   │ Git
   ▼
Repository

   │
git push

   ▼

GitHub Repository
```

Git manages versions.

GitHub stores them online.

---

# Important Terminology

## Repository (Repo)

A repository is the entire project.

Example:

```
Research/
```

contains

```
Notes

Projects

Papers

Code

Diary

Git History
```

Everything together is called a repository.

---

## Commit

A commit is a snapshot.

Imagine pressing

"Save Progress"

inside your project.

Every commit has

- unique ID
- author
- date
- message

Example

```
Initialize research workspace

↓

Added Linux notes

↓

Configured GitHub

↓

Started Modern C++
```

---

## Branch

A branch is an independent line of development.

The default branch is

```
main
```

Later we will learn branching in detail.

---

## Remote

A remote is another repository.

Usually

```
origin
```

points to GitHub.

Example

```
origin

↓

github.com/username/project
```

---

# Git Workflow

Almost every project follows the same workflow.

```
Modify files

↓

git status

↓

git add

↓

git commit

↓

git push
```

This cycle repeats throughout the life of the project.

---

# Commands We Learned

---

## git init

Creates a new Git repository.

```
git init
```

Output

```
Initialized empty Git repository...
```

A hidden folder is created.

```
.git/
```

This folder stores the entire Git history.

Never delete it.

---

## git status

Shows the current state of the repository.

```
git status
```

Example

```
modified:

README.md

Untracked files:

notes.md
```

This is probably the most frequently used Git command.

---

## git add

Stages files for the next commit.

Single file

```
git add README.md
```

Entire project

```
git add .
```

Notice the space.

Correct

```
git add .
```

Incorrect

```
git add.
```

---

## git commit

Creates a permanent snapshot.

```
git commit -m "Added Linux notes"
```

Always write meaningful messages.

Good

```
Added Bash Basics

Implemented histogram plotting

Configured SSH authentication
```

Bad

```
Update

Fix

asdf

123
```

---

## git log

Shows commit history.

```
git log
```

Example

```
commit 7574f0...

Author

Date

Message
```

---

## git log --oneline

Compact commit history.

```
git log --oneline
```

Example

```
7574f0 Added Linux notes

21d0ca Configured Git

8ee038 Initial commit
```

---

## git diff

Shows modifications that are not committed.

```
git diff
```

Very useful before committing.

---

## git show

Displays the contents of a commit.

```
git show
```

Shows

- changed files
- inserted lines
- deleted lines

---

## git restore

Discard changes.

Restore one file

```
git restore README.md
```

Very useful after accidental edits.

---

## git remote add

Connect local repository to GitHub.

Example

```
git remote add origin git@github.com:username/project.git
```

Usually performed only once.

---

## git remote -v

Shows configured remote repositories.

Example

```
origin

(fetch)

(push)
```

---

## git push

Uploads commits to GitHub.

```
git push
```

First push

```
git push -u origin main
```

After that

```
git push
```

is sufficient.

---

# Understanding git push -u origin main

This command looks complicated.

Actually it has four parts.

```
git
```

Git program

```
push
```

Upload commits

```
origin
```

GitHub repository

```
main
```

Branch name

```
-u
```

Remember this connection for future pushes.

---

# SSH Authentication

Instead of typing a password every time,

GitHub can identify your computer using SSH keys.

Workflow

```
SSH Key

↓

GitHub

↓

Authentication

↓

Push
```

This is the recommended method.

---

# The .gitignore File

Some files should never be tracked.

Example

```
__pycache__/

*.pyc

.ipynb_checkpoints/

.vscode/

*.root

workspace.json
```

Git ignores these automatically.

---

# Our Research Workflow

Every study session follows this pattern.

```
Study

↓

Take Notes

↓

Write Code

↓

git status

↓

git add .

↓

git commit -m "Meaningful message"

↓

git push
```

This keeps the entire research history organized.

---

# Best Practices

✔ Commit frequently.

✔ Write meaningful commit messages.

✔ Always check `git status`.

✔ Use `.gitignore`.

✔ Push regularly.

✔ Never delete the `.git` folder.

✔ Keep your repository organized.

✔ Treat Git as the history of your scientific work.

---

# What We Have Learned

At this stage we know how to

- Create repositories
- Track changes
- Stage files
- Create commits
- Read commit history
- Restore files
- Connect GitHub
- Push projects online
- Use SSH authentication
- Manage ignored files

Later we will learn

- Branches
- Merge
- Pull
- Clone
- Rebase
- Conflict resolution
- Tags
- GitHub Pull Requests

---

# Final Thoughts

Git is much more than a backup system.

For a researcher, Git becomes the complete history of ideas, analyses, notes, and code.

Every figure, every simulation, every notebook, and every project can be traced back to its origin.

In scientific computing, reproducibility is essential.

Git makes reproducibility possible.

That is why Git is one of the most important tools in modern research.