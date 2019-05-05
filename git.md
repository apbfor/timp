# Command line instructions

## Git global setup

git config --global user.name "Kuznetsov"

git config --global user.email "klexey@1.ru"

## Create a new repository
git clone http://gitlabnto/klexey/timp.git

cd timp

touch README.md

git add README.md

git commit -m "add README"

git push -u origin master

## Existing folder
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
