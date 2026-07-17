# Git - Why Do We Need Version Control?

> "Git is not just a tool for programmers.
> It is a time machine for researchers."

---

# What is Git?

Git is a distributed Version Control System (VCS).

It records the complete history of a project, allowing you to:

- save every important change,
- return to previous versions,
- collaborate with other researchers,
- experiment without fear of losing your work,
- synchronize projects between multiple computers.

---

# Why is Git important for a physicist?

As a researcher, you will constantly modify

- analysis scripts
- simulation code
- detector geometry
- ROOT macros
- Coffea processors
- Geant4 applications
- LaTeX notes
- papers

Without version control you quickly end up with files like

Analysis_Final.py

Analysis_Final_v2.py

Analysis_Final_REAL.py

Analysis_Final_REAL_LAST.py

Analysis_Final_REAL_LAST2.py

Git completely eliminates this problem.

---

# Git Workflow

Working Directory

↓

Staging Area

↓

Repository

↓

GitHub

---

## Working Directory

The place where you actively edit files.

Example

Research/

↓

analysis.py

↓

README.md

↓

notes.md

---

## Staging Area

The preparation area.

Here you decide

"What should be included in the next snapshot?"

Command

git add

---

## Repository

Permanent project history.

Every commit becomes part of your timeline.

Command

git commit

---

## GitHub

Cloud backup and collaboration.

Command

git push

---

# Why not simply copy files?

Because Git stores

- complete history
- author
- date
- differences
- branches
- rollback points

instead of duplicate files.

---

# Research Example

Day 1

analysis.py

↓

Commit

↓

Day 10

Added histogram normalization

↓

Commit

↓

Day 25

Implemented systematic uncertainties

↓

Commit

↓

Day 60

Optimized Coffea processor

↓

Commit

Every stage of the project can be restored.

---

# Commands learned today

Check repository status

git status

Initialize repository

git init

Configure Git

git config --global --list

Stage files

git add .

Commit changes

git commit -m "Initialize research workspace"

View history

git log

Compact history

git log --oneline

---

# Repository Structure

Research/

├── Physics
├── Mathematics
├── Programming
├── Electronics
├── Projects
├── Papers
├── Resources

↓

git init

↓

Repository created.

---

# What is .gitignore?

Some files should never be tracked.

Examples

__pycache__/

*.root

*.log

build/

workspace.json

These files are ignored by Git.

---

# Best Practices

✔ Commit often.

✔ Keep commit messages short.

✔ Use English.

✔ Make one logical change per commit.

✔ Check git status before every commit.

✔ Push regularly.

---

# What I learned

- What Git is
- Why version control matters
- Working Directory
- Staging Area
- Repository
- GitHub
- git status
- git add
- git commit
- git log
- .gitignore

---

# Next Lesson

Connecting Git to GitHub.

---

# Personal Notes

## Things I found difficult

-

-

-

## Things I understood well

-

-

-

## Questions to investigate

-

-

-

## Future applications

- ROOT
- Coffea
- Geant4
- CMS Analysis
- Dark Matter Research