# Projeto 2 de MC504 (Sistemas Operacionais): implementação de uma syscall no kernel Linux seguindo o [tutorial do **Lkcamp**](https://docs.lkcamp.dev/intro_tutorials/boot/)

---
## Objetivos das chamadas de sistema:
A `sleep_proc` busca implantar uma syscall de sleep, a qual recebe um `unsigned int` que representar por quantos segundos uma thread irá dormir.
---
## Tutorial de uso:
Primeiramente, clone o repositório e o submodule (kernel linux):
```bash
git clone --recurse-submodules -j$(nproc) https://github.com/Sholum1/MC504-Syscall
```
Então siga o [tutorial da LKcamp](https://docs.lkcamp.dev/intro_tutorials/boot/), pulando a parte [2.0. Getting the Linux source tree](https://docs.lkcamp.dev/intro_tutorials/boot/#20-getting-the-linux-source-tree)
