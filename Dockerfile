FROM archlinux/base:latest

RUN pacman -Syu --noconfirm

RUN pacman -Sy gcc gdb make binutils ocaml --noconfirm
