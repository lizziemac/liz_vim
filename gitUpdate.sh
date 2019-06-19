#!/bin/bash

cp ~/.vimrc myVimRC
cp ~/.gitconfig gitconfig
cp ~/.ssh/config sshconf
cp ~/.bash_profile myBashProfile

brew list > file

git add myBashProfile myVimRC file

THEDATE=$(date +"%d.%m.%Y")
git commit -m "$THEDATE Refreshed vimrc, bash_profile, and list of brew tools"

git push
