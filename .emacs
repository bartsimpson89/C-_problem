
(global-unset-key (kbd "C-SPC"))
(global-set-key (kbd "C-z") 'set-mark-command)
(global-set-key (kbd "C-c C-g") 'goto-line)
(global-set-key (kbd "C-c h") 'hs-minor-mode) ;code expand constract


(setq c-default-style '((java-mode . "java")
					    (awk-mode . "awk")
						(other . "linux")))

(setq-default c-electric-flag nil)
(setq-default indent-tabs-mode nil)
(setq-default tab-wdith 4)
(setq c-set-style "k&r")
(setq c-basic-offset 4)

;auto-complete
(add-to-list 'load-path "~/.emacs.d/lisp/popup")
(load "popup.el")

(add-to-list 'load-path "~/.emacs.d/lisp/auto-complete")
(load "auto-complete.el")
(load "auto-complete-config.el")
(ac-config-default)
;auto-complete end

;flycheck
(add-to-list 'load-path "~/.emacs.d/lisp/seq")
(load "seq.el")

(add-to-list 'load-path "~/.emacs.d/lisp/dash")
(load "dash.el")
	
(add-to-list 'load-path "~/.emacs.d/lisp/let-alist")
(load "let-alist.el")

(add-to-list 'load-path "~/.emacs.d/lisp/flycheck")
(load "flycheck.el")
(flycheck-mode 0)
;flycheck end

;helm
(add-to-list 'load-path "~/.emacs.d/lisp/emacs-async")
(load "async.el")


(add-to-list 'load-path "~/.emacs.d/lisp/helm")
(load "helm-config.el")

(global-set-key (kbd "C-x b") 'helm-buffers-list)
(global-set-key (kbd "C-x r b") 'helm-bookmarks)
(global-set-key (kbd "C-x m") 'helm-M-x)
(global-set-key (kbd "M-y") 'helm-show-kill-ring)
(global-set-key (kbd "C-x C-f") 'helm-find-files)
(helm-mode 1)
;helm end

;gtags
(add-to-list 'load-path "~/.emacs.d/lisp/emacs-helm-gtags")
(load "helm-gtags.el")
(gtags-mode 1)
(global-unset-key (kbd "C-x f"))
(global-set-key (kbd "C-x f t") 'helm-gtags-find-tag) ;input tags name and move to definition 


;(require 'package)
;(setq package-archives '(
			;("melpa". "http://mirrors.tuna.tsinghua.edu.cn/elpa/me;lpa/")
;			("gnu". "http://mirrors.tuna.tsinghua.edu.cn/elpa/gnu/;")
;			("org"."http://mirrors.tuna.tsinghua.edu.cn/elpa/org/";)))
;(package-initialize)

;(require 'auto-complete-config)
;(ac-config-default)

;(require 'package)
;(add-to-list 'package-archives
;			 '("MELPA Stable" . "http://stable.melpa.org/packages/;") t)
;(package-initialize)
;(package-refresh-contents)
;(package-install 'flycheck)
;(global-flycheck-mode)




