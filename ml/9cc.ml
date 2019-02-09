let () =
  let multi_line_string list = List.fold_left (fun acc next -> acc ^ next ^ "\n") "" list in
  let asm = [
    ".intel_syntax noprefix";
    ".global main";
    "main:";
    "  mov rax, " ^ string_of_int (int_of_string Sys.argv.(1));
    "  ret"
  ] in
  print_string @@ multi_line_string asm
