#!/bin/bash

cp ~/.vimrc myVimRC
cp ~/.gitconfig gitconfig
cp ~/.bash_profile myBashProfile

git add myBashProfile myVimRC

THEDATE=$(date +"%d.%m.%Y")
git commit -m "$THEDATE Standard refresh of vimrc and bash_profile"

git push
