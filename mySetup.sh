#!/bin/bash

#Homebrew
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
#Python
brew install python
#Link Directories
echo "export PATH="/usr/local/bin:/usr/local/sbin:~/bin:$PATH"" >> ~/.bash_profile
#Ceedling
sudo gem install ceedling
#AVR-GCC
brew tap osx-cross/avr
brew install avr-libc
brew install avrdude
#ShellCheck (sees is bash script is compatible across OS's
brew install shellcheck
#Mosquitto (for MQTT), saves output to text in case there are important things needed
brew install mosquitto &> mosquitto_reqs.txt
#PanDoc
brew install pandoc
#Tmux
brew install tmux
#Kubernetes
brew install kubectl
#Pipes markdown file to localhost
pip install grip
#Pylint
pip install pylint
#Move configs from git over
cp gitconfig ~/.gitconfig
#Move premade bash_profile to the correct location
cp myBashProfile ~/.bash_profile
#Reload bash_profile
source ~/.bash_profile
#Setup .vim for pathogen
mkdir -p ~/.vim/autoload ~/.vim/backups ~/.vim/swaps ~/.vim/bundle && \
curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim
#Move premade vimrc to the correct location
cp myVimRC ~/.vimrc
#Move to bundle folder created for pathogen and get all of the plugins
cd ~/.vim/bundle  || exit
#a
wget -O a.vim "https://www.vim.org/scripts/download_script.php?src_id=7218"
#dispatch
git clone https://tpope.io/vim/dispatch.git
#nerdtree
git clone https://github.com/scrooloose/nerdtree.git
#supertab
git clone https://github.com/ervandew/supertab.git
#syntastic
git clone --depth=1 https://github.com/vim-syntastic/syntastic.git
#tagbar
git clone https://github.com/majutsushi/tagbar.git
#vim-fugitive
git clone https://github.com/tpope/vim-fugitive.git
#vim-gitgutter
git clone git://github.com/airblade/vim-gitgutter.git
#vim-markdown
git clone https://github.com/plasticboy/vim-markdown.git
#vim-signify
git clone https://github.com/mhinz/vim-signify.git
#vim-colorschemes
git clone https://github.com/flazz/vim-colorschemes
#SSH-Keygen
ssh-keygen
cat ~/.ssh/id_rsa.pub | pbcopy
#Notification of Completion
osascript -e 'display notification "Your ssh key has been copied to your clipboard.\nVim plugins added to path ~/.vim/bundle" with title "Installations Complete" sound name "funk"'
