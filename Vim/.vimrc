syntax on

let &number = 0
set relativenumber
set wrap

set tabstop=4
set shiftwidth=4

set autoindent
set smartindent

nnoremap <C-p> :wq<CR>
nnoremap <C-q> :w<CR>

"comentario
set mouse=a "ativa o mouse

autocmd FileType css set tabstop=2 shiftwidth=2

autocmd FileType c iabbrev boiler int main(){<esc>oreturn 0;<CR>}<esc>kko

set laststatus=2
set statusline=\ %f\ -\ %y\ %m
set statusline+=%=
set statusline+=%6l/%-4L\ \ %P\ \ 
