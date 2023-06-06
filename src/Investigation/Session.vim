let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/repos/algoritms/lab6/src/Storage
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +37 ~/repos/algoritms/lab6/src/Storage/Storage.hpp
badd +126 ~/repos/algoritms/lab6/src/Storage/Storage.cpp
badd +35 ~/repos/algoritms/lab6/src/Investigation/Investigation.hpp
badd +1 ~/repos/algoritms/lab6/src/Investigation/Storage.cpp
badd +73 ~/repos/algoritms/lab6/src/Investigation/Investigation.cpp
badd +40 ~/repos/algoritms/lab6/src/Date/Date.hpp
badd +1 ~/repos/algoritms/lab6/src/Date/Storage.hpp
badd +1 ~/repos/algoritms/lab6/src/Date/Storage.cpp
badd +102 ~/repos/algoritms/lab6/src/Date/Date.cpp
badd +24 ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp
badd +43 ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.cpp
argglobal
%argdel
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit ~/repos/algoritms/lab6/src/Storage/Storage.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 62 + 72) / 145)
exe 'vert 2resize ' . ((&columns * 82 + 72) / 145)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 35 - ((24 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 35
normal! 0
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/algoritms/lab6/src/Storage/Storage.cpp", ":p")) | buffer ~/repos/algoritms/lab6/src/Storage/Storage.cpp | else | edit ~/repos/algoritms/lab6/src/Storage/Storage.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/repos/algoritms/lab6/src/Storage/Storage.cpp
endif
balt ~/repos/algoritms/lab6/src/Storage/Storage.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 126 - ((24 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 126
normal! 05|
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
exe 'vert 1resize ' . ((&columns * 62 + 72) / 145)
exe 'vert 2resize ' . ((&columns * 82 + 72) / 145)
tabnext
edit ~/repos/algoritms/lab6/src/Investigation/Investigation.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
wincmd =
argglobal
balt ~/repos/algoritms/lab6/src/Storage/Storage.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 49 - ((10 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 49
normal! 05|
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/algoritms/lab6/src/Investigation/Investigation.cpp", ":p")) | buffer ~/repos/algoritms/lab6/src/Investigation/Investigation.cpp | else | edit ~/repos/algoritms/lab6/src/Investigation/Investigation.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/repos/algoritms/lab6/src/Investigation/Investigation.cpp
endif
balt ~/repos/algoritms/lab6/src/Investigation/Storage.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 73 - ((12 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 73
normal! 0194|
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
2wincmd w
wincmd =
tabnext
edit ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
wincmd =
argglobal
balt ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 42 - ((17 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 42
normal! 099|
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp", ":p")) | buffer ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp | else | edit ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/repos/algoritms/lab6/src/Investigation/Basis/Basis.hpp
endif
balt ~/repos/algoritms/lab6/src/Investigation/Investigation.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 24 - ((6 * winheight(0) + 5) / 11)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 24
normal! 0
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
wincmd =
tabnext
edit ~/repos/algoritms/lab6/src/Date/Date.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
wincmd =
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 41 - ((17 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 015|
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/algoritms/lab6/src/Date/Date.cpp", ":p")) | buffer ~/repos/algoritms/lab6/src/Date/Date.cpp | else | edit ~/repos/algoritms/lab6/src/Date/Date.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/repos/algoritms/lab6/src/Date/Date.cpp
endif
balt ~/repos/algoritms/lab6/src/Date/Storage.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 102 - ((27 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 102
normal! 0
lcd ~/repos/algoritms/lab6/src/Storage
wincmd w
wincmd =
tabnext 2
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
