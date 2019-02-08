FROM archlinux/base:latest

RUN pacman -Syu --noconfirm

RUN pacman -Sy gcc binutils --noconfirm

WORKDIR /root

COPY ./test1.c ./test1.c
