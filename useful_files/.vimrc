" UI Configurations
set ruler         " Shows the cursor location at the bottom.
set number        " Shows the line numbers on the side.
set showcmd       " Shows the current command at the bottom.
set cursorline    " Underlines current line.
set wildmenu      " shows an autocomplete for possible commands.
set lazyredraw    " prevents Vim from redrawing things automatically.
set showmatch     " useful tool that highlights corresponding {[]}
syntax on         " hopefully this is self-explanatory
:imap jk <esc>    " remaps the escape key to the "jk" sequence.
set laststatus=2  " makes the filename visible.
set mouse=a				" this enables mouse support

" Searching
set ignorecase		" ignores case while searching
set incsearch     " searches while inputting characters
set hlsearch      " highlights current search entry

" Styling for Code (Currently optimized for C++)
set tabstop=2     " sets tab size to 2
set autoindent    " keeps autoindention while writing
set expandtab

" These get rid of various bells and whistles
set noerrorbells
set nostartofline
