#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    *)          machine="UNKNOWN:${unameOut}"
esac
echo Running Script on ${machine}

cp ~/.vimrc myVimRC
cp ~/.gitconfig gitconfig
cp ~/.ssh/config sshconf
cp ~/.bash_profile myBashProfile

if [${machine} == "Mac"]; then
    brew list > file
fi

git add myBashProfile myVimRC file sshconf

THEDATE=$(date +"%d.%m.%Y")
git commit -m "$THEDATE Refreshed vimrc, bash_profile, and list of brew tools"

git push
