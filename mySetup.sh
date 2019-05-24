#!/bin/bash
mkdir -p ~/.vim/autoload ~/.vim/bundle && \
curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim

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

wget -O ~/.vimrc "https://raw.githubusercontent.com/lizziemac/liz_vim/master/liz_vimrc"