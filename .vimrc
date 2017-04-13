
" release autogroup in MyAutuCmd
augroup MyAutoCmd autocmd!
augroup END

" 構文チェック
syntax enable
" エンコーディング
set encoding=utf-8
set fileencodings=utf-8
"set fileencoding=UTF-8
"set termencoding=UTF-8
" スクロールするときに下が見えるようにする
set scrolloff=5

set noswapfile
set nowritebackup
set nobackup
" ビープ音を消す
set vb t_vb=
set novisualbell
" 行・列の番号を右下に表示する
set ruler
" compatibleオプションをオフにする
set nocompatible
" 移動コマンドを使ったとき、行頭に移動しない
set nostartofline
" 対応括弧に<と>のペアを追加
set matchpairs& matchpairs+=<:>

" クリップボードをデフォルトのレジスタとして指定する。後にYankRingを使うので、'unnamedplus'が存在しているかどうかで、設定を分ける必要がある
if has('unnamedplus')
	" set clipboard& clipboard+=unnamedplus
	set clipboard& clipboard+=unnamedplus,unnamed
else
	" set clipboard& clipboard+=unnamed
	set clipboard& clipboard+=unnamed
endif

" 対応括弧をハイライト表示する
set showmatch
" 対応括弧の表示秒数を3秒にする
set matchtime=3
" ウィンドウの幅より長い行は折り返され、次の行に続けて表示される
set wrap
" 入力されているテキストの最大幅を無効化する
set textwidth=0
" インデントをshiftwidthの倍数に丸める
set shiftround
" 補完の際に大文字小文字の区別しない
set infercase
" 文字がない場所にもカーソルを移動できるようにする
"set virtualedit=all
" 変更中のファイルでも、保存しないで他のファイルを表示
set hidden
" 新しく開く代わりにすでに開いてあるバッファを開く
set switchbuf=useopen
" 小文字の検索でも大文字も見つかるようにする
set ignorecase
" ただし、大文字も含めた検索の場合はその通りに検索する
set smartcase
" インクリメンタルサーチをおこなう
set incsearch
" 検索結果をハイライト表示
:set hlsearch
" Adding Apr/07/2017
" 画面上でタブ文字が占める幅
set tabstop=2
" 自動インデントでずれる幅
set shiftwidth=2
" タブ入力を複数の空白入力に置き換えない
set noexpandtab
" 行頭の余白内でTabを打ち込むと、shifthwidthの数だけインデントする
set smarttab
" 連続した空白に対してTab-keyやBackspace-keyでカーソルが動く幅
set softtabstop=2
" 改行時に前の行のインデントを継続する
set autoindent
" autoindentと同様であるが、C構文を認識
" 改行時に入力された行の末尾に合わせて次の行のインデントを増減する
set smartindent
" カラー設定
set t_Co=256
set background=dark
colorscheme molokai
" 行番号表示
set number
" タイトルをウィンドウ枠に表示
set title
set undolevels=300
" コマンド・検索パターンの履歴
set history=10000
" IME設定
set iminsert=0
set imsearch=0
set imdisable
" ステータスライン
set laststatus=2
" メッセージ表示欄
set cmdheight=1
" 置換の時にgオプションをデフォルトで有効にする
set gdefault
" カーソルが何行目の何列目に置かれているかを表示する
set ruler
" コマンドを画面下に表示させる
set showcmd
" タブ補完
set wildmenu
set wildmode=list:longest
" 最後まで検索を終えたら、次の検索で先頭に移る
set wrapscan

" カーソルの回り込みができるようにする
set whichwrap=b,s,h,l,<,>,[,]

set cindent
"set mouse=a
"set ttymouse=xterm2

" 行を強調表示
set cursorline

" Adding Apr/06/2017
hi Comment ctermfg=lightgray


" テンプレートファイル(拡張子ごとに設定)
autocmd BufNewFile *.py 0r ~/.vim/template/template.py setlocal tabstop=4 softtabstop=4 shiftwidth=4
autocmd BufNewFile *.c 0r ~/.vim/template/template.c setlocal tabstop=2 softtabstop=2 shiftwidth=2
autocmd BufNewFile *.cpp 0r ~/.vim/template/template.cpp setlocal tabstop=2 softtabstop=2 shiftwidth=2

autocmd BufNewFile *.java 0r ~/.vim/template/template.java

" Load files
autocmd BufNewFile,BufRead *.md setfiletype markdown
"==============================================================================





" マクロおよびキー設定=========================================================
" 入力モード中に素早くjjと入力した場合はESCとみなす
inoremap jj <Esc>
cmap w!! w !sudo tee > /dev/null %
" ESCを二回押すことでハイライトを消す
nmap <silent> <Esc><Esc> :nohlsearch<CR>
" カーソル下の単語を*で検索
vnoremap <silent> * "vy/\V<C-r>=substitute(escape(@v, '\/'), "\n", '\\n', 'g')<CR><CR>
" 検索時にジャンプした際に、検索単語を画面中央に持ってくる
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap g* g*zz
nnoremap g# g#zz
" 行表示単位で行移動する
nnoremap j gj
nnoremap k gk
" vを二回で行末まで選択
vnoremap v $h
nnoremap &lt;Tab&gt; %
vnoremap &lt;Tab&gt; %
" 画面切り替え
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l

nnoremap <S-Left> <C-w><<CR>
nnoremap <S-Right> <C-w>><CR>
nnoremap <S-Up> <C-w>-<CR>
nnoremap <S-Down> <C-w>+<CR>

" :eなどでファイルを開く際に、フォルダが存在しない場合は自動生成
function! s:mkdir(dir, force)
	if !isdirectory(a:dir) && (a:force || input(printf('"%s" does not exist. Create? [y/N]',a:dir)) =~? '^y\%[es]$')
		call mkdir(iconv(a:dir, &encoding, &termencoding), 'p')
	endif
endfunction
"autocmd MyAutoCmd BufWritePre * call s:mkdir(expand('<afile>:p:h'), v:cmdbang)

" vim起動時のみカレントディレクトリを開いたファイルの親ディレクトリに指定
"autocmd MyAutoCmd VimEnter * call s:ChangeCurrentDir('', '')
"function! s:ChangeCurrentDir(directory, bang)
"	if a:directory == ''
"		lcd %:p:h
"	else
"		execute 'lcd' . a:directory
"	endif
"	if a:bang == ''
"		pwd
"	endif
"endfunction

" ~/.vimrc.localが存在する場合のみ設定を読み込む
let s:local_vimrc = expand('~/.vimrc.local')
if filereadable(s:local_vimrc)
	execute 'source ' . s:local_vimrc
endif
" /{pattern}の入力中は'/'をタイプすると'\/'が入力される
" ?`pattern}の入力中は'?'をタイプすると'\?'を入力される
cnoremap <expr> / getcmdtype() == '/' ? '\/' : '/'
cnoremap <expr> ? getcmdtype() == '?' ? '\?' : '?'
" 表示行単位で行移動する
nnoremap <silent> j gj
nnoremap <silent> k gk
" インサードモードにおいても移動
inoremap <c-d> <delete>
inoremap <c-j> <down>
inoremap <c-k> <up>
inoremap <c-h> <left>
inoremap <c-l> <right>
" <space>j, <space>kで画面送り
noremap [Prefix]j <c-f><cr><cr>
noremap [Prefix]k <c-b><cr><cr>

" make, grepなどのコマンド後に、自動的にQuickFixを開く
"autocmd MyAutoCmd QuickfixCmdPost make,grep,grepadd,vimgrep copen

" QuickFixおよびHelpでは q でバッファを閉じる
"autocmd MyAutoCmd FileType help,qf nnoremap <buffer> q <C-w>c

"==============================================================================



" NeoBundleの設定==============================================================
" Note: Skip initialization for vim-tiny or vim-small.
if 0 | endif

filetype off

if has('vim_starting')
	if &compatible
		set nocompatible
	endif

	set runtimepath+=~/.vim/bundle/neobundle.vim/
endif

"call neobundle#begin(expand('~/.vim/bundle/'))
"
"" originalrepos on github
"NeoBundleFetch 'Shougo/neobundle.vim'
"NeoBundle 'Shougo/neobundle.vim'
"NeoBundle 'Shougo/vimproc', {
"			\ 'build' : {
"				\ 'mac' : 'make -f make_mac.mak',
"				\ 'unix' : 'make -f make_unix.mak',
"			\ },
"			\ }
"
"
"
"" Insertモードに入るまでは、neocompleteはロードされない
"NeoBundleLazy 'Shougo/neocomplete.vim', {
"			\ "autoload": {"insert": 1}}
"" neocompleteのhooksを取得
"let s:hooks = neobundle#get_hooks("neocomplete.vim")
"" neocomplete用の設定関数を定義する。下記関数はneocompleteロード時に実行される
"function! s:hooks.on_source(bundle)
"	let g:acp_enableAtStartup = 0
"	let g:neocomplete#enable_at_startup = 1
"	let g:neocomplete#enable_smart_case = 1
"	let g:neocomplete#sources#syntax#min_keyword_length = 3
"	let g:neocomplete#lock_buffer_name_pattern = '\*ku\*'
"	let g:neocomplete#sources#dictionary#dictionaries = {
"				\ 'default' : '',
"				\ 'vimshell' : $HOME.'/.vimshell_hist',
"				\ 'scheme' : $HOME.'/.gosh_completions'
"				\ }
"	if !exists('g:neocomplete#keyword_patterns')
"		let g:neocomplete#keyword_patterns = {}
"	endif
"	let g:neocomplete#keyword_patterns['default'] = '\h\w*'
"	inoremap <expr><C-g>	neocomplete#undo_completion()
"	inoremap <expr><C-l>	neocomplete#complete_common_string()
"	"inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
"	"function! s:my_cr_function()
"	"	return (pumvisible() ? "\<C-y>" : "" ) . "\<CR>"
"	"endfunction
"	inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
"	inoremap <expr><C-h> neocomplete#smart_close_popup()."\<C-h>"
"	inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
"	autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
"	autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
"	autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
"	autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
"	autocmd FileType xml setlocal omnifunc=xmlcomplete#CompleteTags
"endfunction
"
"
"
"NeoBundle 'vim-scripts/YankRing.vim'
"
""NeoBundleLazy 'Shougo/neosnippet.vim', {
""			\ 'depends': ["honza/vim-snippets"],
""			\ 'autoload': {
""			\	'insert': 1,
""			\ }}
""let s:hooks = neobundle#get_hooks("neosnippet.vim")
""function! s:hooks.on_source(bundle)
"	" Plugin key-mappings.
""	imap <C-k>	<Plug>(neosnippet_expand_or_jump)
""	smap <C-k>	<Plug>(neosnippet_expand_or_jump)
""	xmap <C-k>	<Plug>(neosnippet_expand_target)
"	" SuperTab like snippets behavior.
""	imap <expr><TAB> neosnippet#expandable_or_jumpable() ?
""				\ "\<Plug>(neosnippet_expand_or_jump)"
""				\: "\<TAB>"
""	" For snippets_complete marker.
""	if has('conceal')
""		set conceallevel=2 concealcursor=i
""	endif
""	" Enable snipMate compatibility feature.
""	let g:neosnippet#enable_snipmate_compatibility = 1
""	" Tell Neosnippet about the other snippets
""	let g:neosnippet#snippets_directory=s:bundle_root . '/vim-snippets/snippets'
""endfunction
"
"
"
"NeoBundleLazy "thinca/vim-quickrun", {
"			\ "autoload": {
"			\	"mappings": [['nxo', '<Plug>(quickrun)']]
"			\ }}
"nmap <Leader>Q <Plug>(quickrun)
"let s:hooks = neobundle#get_hooks("vim-quickrun")
"function! s:hooks.on_source(bundle)
"	let g:quickrun_config = {
"				\ "*": {"runner": "remote/vimproc"},
"				\ }
"endfunction
"
"
"
"NeoBundleLazy 'majutsushi/tagbar', {
"			\ "autoload": {
"			\	"commands": ["TagbarToggle"],
"			\ },
"			\ "build": {
"			\	"mac": "brew install ctags",
"			\ }}
"nmap <Leader>t :TagbarToggle<CR>
"
"
"
"NeoBundle "scrooloose/syntastic", {
"			\ "build": {
"			\	"mac": ["pip install flake8", "npm -g install coffeelint"],
"			\	"unix": ["pip install flake8", "npm -g install coffeelint"],
"			\ }}
"set statusline+=%#warningmsg#
"set statusline+=%{SyntasticStatuslineFlag()}
"set statusline+=%*
"let g:syntastic_always_populate_loc_list = 1
"let g:syntastic_auto_loc_list = 1
"let g:syntastic_check_on_open = 1
"let g:syntastic_check_on_wq = 0
"
"
"
"NeoBundleLazy "davidhalter/jedi-vim", {
"			\ "autoload": {
"			\	"filetypes": ["python", "python3", "djangohtml"],
"			\ },
"			\ "build": {
"			\	"mac": "pip install jedi",
"			\	"unix": "pip install jedi",
"			\ }}
"let s:hooks = neobundle#get_hooks("jedi-vim")
"function! s:hooks.on_source(bundle)
"	" jediにvimの設定を任せると'completeopt+=preview'するので、自動設定機能をOFFにして手動で設定を行う
"	let g:jedi#auto_vim_configuration = 0
"	" 補完の最初の項目が選択された状態だと使いにくいためオフにする
"	let g:jedi#popup_select_first = 0
"	" quickrunと被るため大文字に変更
"	let g:jedi#rename_command = '<Leader>R'
"	" gundoと被るため大文字に変更
"	let g:jedi#goto_command = '<Leader>G'
"	" docstringを表示しない
"	autocmd FileType python setlocal completeopt-=preview
"endfunction
"
"
"
"NeoBundleLazy 'kana/vim-smartinput', {
"			\ "autoload": {"insert": 1}}
"let s:hooks = neobundle#get_hooks("vim-smartinput")
"function! s:hooks.on_source(bundle)
"	" 括弧内でのスペース入力
"	call smartinput#map_to_trigger('i', '<Space>', '<Space>', '<Space>')
"	call smartinput#define_rule({
"			\ 	'at'	: '(\%#)',
"			\	'char'	: '<Space>',
"			\	'input'	: '<Space><Space><Left>',
"			\	})
"	call smartinput#define_rule({
"			\	'at'	: '( \%# )',
"			\	'char'	: '<BS>',
"			\	'input'	: '<Del><BS>',
"			\	})
"	" 改行時に行末スペースの除去
"	call smartinput#define_rule({
"			\	'at'	: '\s\+\%#',
"			\	'char'	: '<CR>',
"			\	'input'	: "<C-o>:call setline('.', substitute(getline('.'), '\\s\\+$', '', ''))<CR><CR>",
"			\	})
"	" C++で;を忘れないようにする
"	" call smartinput#define_rule({
"			\	'at'	: '\%(\<struct\>\|\<class\>\|\<enum\>\)\s*\w\+.*\%#',
"			\	'char'	: '{',
"			\	'input'	: '{};<Letf><Left>',
"			\	'filetype'	: ['cpp'],
"			\	})
"endfunction
"
"
"
"NeoBundle 'itchyny/ightline.vim'
"let g:indentLine_faster = 1
"nmap <silent><Leader>i :<C-u>IndentLinesToggle<CR>
"let g:lightline = { 'colorscheme' : 'wombat' }
"
"
"
"
"
"NeoBundle 'scrooloose/nerdtree'
"" Ctrl+eでNERDTreeを表示
"map <C-e> :NERDTreeToggle<CR>
"" 隠しファイルをデフォルトで表示させる
"let NERDTreeShowHidden = 1
"
"
"call neobundle#end()
"
"filetype plugin indent on
"filetype indent on
"syntax on
"
"NeoBundleCheck
"==============================================================================

" Adding Apr/06/2017

" Adding Apr/05/2017
call plug#begin('~/.vim/plugged')
Plug 'junegunn/vim-easy-align'
" On-demand loading
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'jistr/vim-nerdtree-tabs'
Plug 'itchyny/lightline.vim'
Plug 'Shougo/neocomplete.vim'
Plug 'kana/vim-smartinput'
Plug 'miyakogi/seiya.vim'
Plug 'Yggdroot/IndentLine'
call plug#end()

let s:plug = {
			\ "plugs": get(g:, 'plugs', {})
			\ }

function! s:plug.is_installed(name)
	return has_key(self.plugs, a:name) ? isdirectory(self.plugs[a:name].dir) : 0
endfunction


if s:plug.is_installed("lightline.vim")
	let g:indentLine_faster = 1
	nmap <silent><Leader>i :<C-u>IndentLinesToggle<CR>
	let g:lightline = { 'colorscheme' : 'wombat', }
endif

if s:plug.is_installed("neocomplete.vim")
	let g:acp_enableAtStartup = 0
	let g:neocomplete#enable_at_startup = 1
	let g:neocomplete#enable_smart_case = 1
	let g:neocomplete#sources#syntax#min_keyword_length = 3

	" Define dictionary.
	let g:neocomplete#sources#dictionary#dictionaries = {
				\'default' : '',
				\'vimshell' : $HOME.'/.vimshell_hist',
				\'scheme' : $HOME.'/.gosh_completions'
				\}

	" Define keyword.
	if !exists('g:neocomplete#keyword_patterns')
		let g:neocomplete#keyword_patterns = {}
	endif
	let g:neocomplete#keyword_patterns['default'] = '\h\w'
	
	" Recommended key-mappings.
	" <CR>: close popup and save indent.
	inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
	function! s:my_cr_function()
		return (pumvisible() ? "\<C-y>" : "" ) . "\<CR>"
		" For no inserting <CR> key.
	endfunction
	" <TAB>: completion.
	inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
	inoremap <expr><C-h> neocomplete#smart_close_popup()."\<C-h>"
	inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
	" Close popup by <Space>
	"inoremap <expr><Space> pumvisible() ? "\<C-y>" : "\<Space>"
	
	" Enable omni completion.
	autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
	" options.
	"	let g:neocomplete#lock_buffer_name_pattern = '\*ku\*'
	"	inoremap <expr><C-g>	neocomplete#undo_completion()
	"	inoremap <expr><C-l>	neocomplete#complete_common_string()
endif

if s:plug.is_installed("nerdtree")
	" Open NERDTree with Ctrl+e
	map <C-e> :NERDTreeToggle<CR>
	" 隠しファイルをデフォルトで表示させる
	"let NERDTreeShowHidden = 1
endif

if s:plug.is_installed('vim-smartinput')
	call smartinput#map_to_trigger('i', '<Space>', '<Space>', '<Space>')
	call smartinput#define_rule({
			\ 	'at'	: '(\%#)',
			\	'char'	: '<Space>',
			\	'input'	: '<Space><Space><Left>',
			\	})
	call smartinput#define_rule({
			\	'at'	: '( \%# )',
			\	'char'	: '<BS>',
			\	'input'	: '<Del><BS>',
			\	})
	" 改行時に行末スペースの除去
	call smartinput#define_rule({
			\	'at'	: '\s\+\%#',
			\	'char'	: '<CR>',
			\	'input'	: "<C-o>:call setline('.', substitute(getline('.'), '\\s\\+$', '', ''))<CR><CR>",
			\	})
	" C++で;を忘れないようにする
	call smartinput#define_rule({
			\	'at'	: '\%(\<struct\>\|\<class\>\|\<enum\>\)\s*\w\+.*\%#',
			\	'char'	: '{',
			\	'input'	: '{};<Letf><Left>',
			\	'filetype'	: ['cpp'],
			\	})
endif


" ハイライト色設定
"highlight Pmenu ctermbg=4
"highlight PmenuSel ctermbg=1
"highlight PMenuSbar ctermbg=4
" AutoComplPopの設定
"let g:acp_enableAtStartup = 0
" Shellのように振る舞う
"set completeopt=menu,preview

