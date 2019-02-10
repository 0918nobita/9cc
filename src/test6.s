.intel_syntax noprefix
.global main
main:
        push 2
        push 3
        pop rdi
        pop rax
        add rax, rdi
        push rax

        push 4
        push 5
        pop rdi
        pop rax
        add rax, rdi
        push rax

        pop rdi
        pop rax
        mul rdi
        push rax

        pop rax
        ret
