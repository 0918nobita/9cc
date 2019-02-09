FROM archlinux/base:latest

RUN pacman -Syu --noconfirm

RUN pacman -Sy gcc binutils nodejs npm ocaml --noconfirm

RUN npm i -g typescript
