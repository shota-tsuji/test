
# .zshrc

# 環境変数
export LANG=ja_JP.UTF-8
#export PATH=$PATH:/usr/include/c++/4.8/
export PATH=/usr/local/bin:/usr/bin:$PATH


#補完機能======================================================================
autoload -U compinit
compinit

# 補完に関するオプション
setopt auto_param_slash
setopt mark_dirs
setopt list_types
setopt auto_menu
setopt auto_param_keys
# '#' 以降をコメントとして扱う
setopt interactive_comments
# '=' 以降も補完する
setopt magic_equal_subst

setopt complete_in_word
setopt always_last_prompt

# Shift-Tabで補完候補を逆順する
bindkey "^[[Z" reverse-menu-complete

# 日本語ファイル名を表示可能にする
setopt print_eight_bit
setopt extended_glob
setopt globdots
setopt list_packed

# 補完において、小文字入力に対して大文字もマッチさせる
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Z}'

# 補完候補を、矢印でも選択できるようにする
zstyle ':completion:*:default' menu select=2


# ../ の後は今いるディレクトリを補完しない
zstyle ':completion:*' ignore-parents parent pwd ..

zstyle ':completion:*:sudo:*' command-path /usr/local/sbin /usr/local/bin /usr/sbin /usr/bin /sbin /bin


# 単語の区切り文字を指定する
autoload -Uz select-word-style
select-word-style default
# 以下で指定した文字は単語区切りとみなされる
zstyle ':zle:*' word-chars " /=;@:{},|"
zstyle ':zle:*' word-style unspecified

#===============================================================================


#History設定===================================================================
# ヒストリを保存するファイル
HISTFILE=~/.zsh_history
# メモリに保存されるヒストリの件数
HISTSIZE=1000000
# 保存されるヒストリの件数
SAVEHIST=1000000


# 重複したディレクトリを追加しない
setopt pushd_ignore_dups

# 同時に起動したzsh間においてヒストリを共有する
setopt share_history

# 同じコマンドをヒストリに残さない
setopt hist_ignore_all_dups

# スペースから始まるコマンド行はヒストリに残さない
setopt hist_ignore_space
# ヒストリに保存するときに余分なスペースを削除する
setopt hist_reduce_blanks

#===============================================================================


#色付け等の設定=================================================================
# 色の設定(プロンプトに色付けをおこなう)
autoload -U colors ; colors
# Adding Mar/22/2017
#local DEFAULT=%{$reset_color%}
#local RED=%{$fg[red]%}
#local GREEN=%{$fg[green]%}
#local YELLOW=%{$fg[yellow]%}
#local BLUE=%{$fg[blue]%}
#local PURPLE=%{$fg[purple]%}
#local CYAN=%{$fg[cyan]%}
#local WHITE=%{$fg[white]%}

# プロンプトの色付け
#PROMPT='${fg[cyan]}[%n]${reset_color}
#%~'
# Adding Mar/22/2017
#PROMPT='[%F{cyan}%B%n%b%f]%# '
#RPROMPT='[%F{green}%B%~%b%f]'
PROMPT='[%B%n%b]%# '
RPROMPT='[%B%~%b]'

# lsコマンドでの色付け
# Adding Mar/22/2017
export LSCOLORS=exfxcxdxbxegedabagacad
export LS_COLORS='di=94:ln=35:so=32:pi=33:ex=92:bd=46;34:cd=43;34:su=41;30:sg=46;30:tw=42;30:ow=43;30'

# ファイル補完候補にも色付けをおこなう
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}


#==============================================================================

#その他オプション==============================================================
# beepを無効化
setopt no_beep

# フローコントロールを無効化
setopt no_flow_control

# Ctrl+Dでのzsh終了を無効化
setopt ignore_eof

# ディレクトリ名のみでもcdする
setopt auto_cd

# cdしたら自動的にpushdする
setopt auto_pushd



#エイリアス設定================================================================
# linux用の設定
alias ls='ls -F --color'
alias la='ls --all'
alias ll='ls -l'
alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'
alias mkdir='mkdir -p'
# Adding Mar/22/2017
alias g++='g++ -std=c++11'
alias clang++='clang++ -std=c++11'
alias platex='platex -shell-escape'

# sudoの後ろのコマンドでのエイリアスを有効化
alias sudo='sudo '

# グローバルエイリアス
alias -g L='| less'
alias -g G="| grep"



export PYENV_ROOT="$HOME/.pyenv"
export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init -)"

#export PATH=~/CodeSourcery/Sourcery_G++_Lite/bin:$PATH

# for OpenCV2.4.11
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export PKG_CONFIG_PATH
#パスを通す====================================================================
# open-mpi

# Adding Mar/22/2017
export HISTTIMEFORMAT='%F %T '
