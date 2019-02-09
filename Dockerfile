FROM archlinux/base:latest

RUN pacman -Syu --noconfirm

RUN pacman -Sy gcc binutils nodejs ocaml --noconfirm
