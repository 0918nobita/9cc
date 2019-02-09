if (process.argv.length > 3) {
  throw new Error('引数の個数が正しくありません');
}

const integer = parseInt(process.argv[2]);
if (isFinite(integer) === false) {
  throw new Error('整数値ではありません');
}

let asm = `.intel_syntax noprefix
.global main
main:
  mov rax, ${integer}
  ret
`;

console.log(asm);
