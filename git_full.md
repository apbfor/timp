# Command line instructions

## Git Help

git help (command)

git (command) --help

man git-(command)

## Git global setup

git config --global user.name "Kuznetsov"

git config --global user.email "klexey@1.ru"

git config --global core.editor mcedit

git config --list

## Create a new repository from remote

git clone http://gitlabnto/klexey/timp.git

cd timp

touch README.md

git add README.md

git commit -m "add README"

git push -u origin master

## Create a new repository from local Existing folder

cd existing_folder

git init

git remote add origin http://gitlabnto/klexey/timp.git

git add .

git commit -m "Initial commit"

git push -u origin master


## Existing Git repository

cd existing_repo

git remote rename origin old-origin

git remote add origin http://gitlabnto/klexey/timp.git

git push -u origin --all

git push -u origin --tags

## View remote repositories

git remote -v

git remote show origin

## Fetch Pull Merge
Pull = Fetch + Merge

git fetch origin

git status

git merge

or

git pull origin

## Merge

git merge

git merge (branch)

git mergetool -- remove conflicts

## Untracked-Unmodified-Modified-Staged

### Untracked to Tracked (Staged)

git add 

### Staged to Unmodified

git commit

### Unmodified to Modified

Just edit file

### Modified to Staged

git add

## Status

git status

git status -s   (short)


## Diff

git diff

git diff --staged

## Commit

git commit

-m "committext"  -- comit w/o editor

-u  -- show untracked files

--amend -- add files to commit without new commit

## Remove files

git rm (file)  -- remove file

git rm --cahced (file) -- remove from cached/staged

## Move files

git mv (file) (newfile)

## LOG

git log

git log --oneline --decorate --graph --all

-p -- diff in commits

-2 -- show 2 commits

--stat -- stistic for commit

--oneline -- one line for commit

--graph -- tree of commits

--all

## Branches

git branch -- show branches (*-current)

git branch -v -- show with commits

git branch --merged

git branch --no-merged

git branch (newbranch) -- create newbranch

git checkout (branch) -- go to branch and work with it

git branch -d (branch) -- delete branch

