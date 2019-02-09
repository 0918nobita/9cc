FROM archlinux/base:latest

RUN pacman -Syu --noconfirm

RUN pacman -Sy gcc make binutils nodejs ocaml --noconfirm
