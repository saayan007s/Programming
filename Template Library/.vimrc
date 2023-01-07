" weird stuff
set nocompatible
syntax on
filetype plugin indent on

set clipboard+='unnamedplus'
set termguicolors
set number relativenumber

" backspace and mouse
set bs=2
set mouse=a

" indentation
set autoindent
set smartindent

set tabstop=4
set expandtab
set shiftwidth=4
set softtabstop=4

" miscellaneous
let mapleader=" "
nnoremap <leader>t :tabnew<cr>
nnoremap <C-n> :norm
nnoremap <Tab> %

" commenting
nnoremap gcc I// <Esc>
vnoremap gcc :'<, '>norm I// <cr>
nnoremap gcu ^xxx
vnoremap gcu :'<, '>norm ^xxx<cr>

" writing and quiting
nnoremap W :w<cr>
nnoremap Q :q<cr>
nnoremap S :s//g<Left><Left>

" navigating between windows
nnoremap <C-l> <C-w>l
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k

" new file
autocmd BufNewFile *.cpp 0r ~/Templates/Template.cpp
" compiling and submitting
nnoremap <F4> :!gedit %<cr>
autocmd filetype cpp nnoremap <buffer> <F5> :!g++ % -o %:r -Wall -lm -DEVAL -std=c++17<cr>
autocmd filetype cpp nnoremap <buffer> <F6> :!./%:r <in >out<cr>

" curly braces
inoremap { {}<Left><cr><cr><Up>
inoremap } {}<Left>

" colorscheme
colo desert
