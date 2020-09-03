#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    *)          machine="UNKNOWN:${unameOut}"
esac
echo Running Script on ${machine}

package_installations()
{
    if [[ ${machine} == "Mac" ]]; then
        #Homebrew
        ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
        #Link Directories
        echo "export PATH="/usr/local/bin:/usr/local/sbin:~/bin:$PATH"" >> ~/.bash_profile
        #Place all current brew tools in a file, then download all
        cat file-mac | xargs brew install

        #Ceedling
        #install npm and node.js, both used for a lot of stuff (most that I don't know about)
        brew install node
        sudo gem install ceedling

        #Install ngrok, used for serving local files from a local server
        wget -O ngrok.zip "https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-darwin-amd64.zip"
        unzip ngrok.zip
        chmod 777 ngrok
        sudo mv ngrok /usr/local/bin
        rm -rf ngrok.zip

        #lists all information/caveats pertaining to all brew packages
        cat file-mac | xargs brew info > caveats.txt

    elif [[ ${machine} == "Linux" ]]; then
        #Download all tools from the linux file
        < file-linux xargs sudo apt-get install -y
    fi

    sudo npm -g install static-server

    #Pipes markdown file to localhost
    pip install grip
    #Pylint
    pip install pylint
}

git_setup()
{
    #Move configs from git over
    cp gitconfig ~/.gitconfig
    cp sshconf ~/.ssh/config
    #Move premade bash_profile to the correct location
    cp myBashProfile ~/.bash_profile
    #Reload bash_profile
    source ~/.bash_profile
    #SSH-Keygen

    if [ ! -f ~/.ssh/id_rsa ]; then
        ssh-keygen
        if [[ ${machine} == "Mac" ]]; then
            cat ~/.ssh/id_rsa.pub | pbcopy
        elif [[ ${machine} == "Linux" ]]; then
            cat ~/.ssh/id_rsa.pub | xclip -selection clipboard
        fi
    else
        echo "SSH key already made"
    fi
}

vim_setup()
{
    #Setup .vim for pathogen
    mkdir -p ~/.vim/autoload ~/.vim/backups ~/.vim/swaps ~/.vim/bundle && \
    curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim
    #Move premade vimrc to the correct location
    cp myVimRC ~/.vimrc

    #Move to bundle folder created for pathogen and get all of the plugins
    cd ~/.vim/bundle  || exit
    #a
    git clone https://github.com/vim-scripts/a.vim.git
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

    source ~/.vimrc

    #return to main directory
    cd ~
}

package_installations
git_setup
vim_setup

#Notification of Completion
if [[ ${machine} == "Mac" ]]; then
    terminal-notifier "Operation Complete"
    osascript -e 'tell app "Terminal" to display dialog "Your ssh key has been copied to your clipboard.\nVim plugins added to path ~/.vim/bundle\nBrew info saved to caveats.txt" with title "Installations Complete"' 
elif [[ ${machine} == "Linux" ]]; then
    notify-send 'Operation Complete' '"Your ssh key has been copied to your clipboard.\nVim plugins added to path ~/.vim/bundle\n"' -a 'mySetup.sh' -u normal -i gnome-terminal
fi
