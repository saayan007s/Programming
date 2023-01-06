set nocompatible
syntax on
filetype plugin indent on

set bs=2
set mouse=a

set clipboard+=unnamedplus
set termguicolors
set number relativenumber

set autoindent
set smartindent

set tabstop=4
set expandtab
set shiftwidth=4
set softtabstop=4

let mapleader="\<Space>"
nnoremap <leader>t :tabnew<cr>
noremap <C-a> <Esc>ggVG
vnoremap <C-n> :norm 
nnoremap <Tab> %

" commentting
nnoremap gcc I// <Esc>
vnoremap gcc :'<, '>norm I// <Esc>
nnoremap gcu ^xxx
vnoremap gcu :'<, '>norm ^xxx<cr>

nnoremap W :w<cr>
nnoremap Q :wq<cr>
nnoremap S :%s//g<Left><Left>

" navigating between windows
nnoremap <C-l> <C-w>l
nnoremap <C-h> <C-w>h
nnoremap <C-k> <C-w>k
nnoremap <C-j> <C-w>j

autocmd filetype cpp nnoremap <buffer> <F4> :!gedit %<cr>
autocmd filetype cpp nnoremap <buffer> <F5> :!g++ -Wall -lm -static -DEVAL -o %:r -O2 % -std=c++17<cr>
autocmd filetype cpp nnoremap <buffer> <F6> :!./%:r <in >out<cr>

autocmd BufNewFile *.cpp 0r ~/Templates/C++.cpp

inoremap { {}<Left><cr><cr><Up>
inoremap } {}<Left>

colo desert
