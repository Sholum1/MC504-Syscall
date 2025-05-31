# Projeto 2 de MC504 (Sistemas Operacionais): implementação de uma syscall no kernel Linux seguindo o [tutorial do **Lkcamp**](https://docs.lkcamp.dev/intro_tutorials/boot/)

## Objetivos das chamadas de sistema:
A `sleep_proc` busca implementar uma syscall de sleep, a qual recebe um `unsigned int` que representa por quantos segundos uma thread irá dormir.

---
## Tutorial de uso:
1. Clone o repositório e o submodule (kernel linux):
```bash
git clone --recurse-submodules -j$(nproc) https://github.com/Sholum1/MC504-Syscall
```

2. Siga o [tutorial da LKcamp](https://docs.lkcamp.dev/intro_tutorials/boot/), pulando a parte [2.0. Getting the Linux source tree](https://docs.lkcamp.dev/intro_tutorials/boot/#20-getting-the-linux-source-tree).
**DICA**: Durante o [passo](https://docs.lkcamp.dev/intro_tutorials/boot/#121-inside-the-new-system), rode `apt-get gcc` para obter o compilador `gcc`, que será necessário no 6º passo.

3. Rode em seu terminal:
```bash
cd MC504-Syscall/linux
```

4. Então:
```bash
qemu-system-x86_64 \
    -drive file=../my_disk.raw,format=raw,index=0,media=disk \
    -m 2G -nographic \
    -kernel ./arch/x86_64/boot/bzImage \
    -append "root=/dev/sda rw console=ttyS0 loglevel=6" \
    -fsdev local,id=fs1,path=../shared_folder,security_model=none \
    -device virtio-9p-pci,fsdev=fs1,mount_tag=shared_folder \
    --enable-kvm
```

5. Na VM, acesse o usuário `root` com a senha definida no [passo](https://docs.lkcamp.dev/intro_tutorials/boot/#121-inside-the-new-system).

6. Adcione a seguinte linha em `/etc/fstab` usando `vi` ou `nano`: 
```shared_folder /root/host_folder 9p trans=virtio 0 0```

7. Rode o comando `reboot`
   
9. Vá para o diretório `host_folders` com:
```bash
cd host_folders
```

10. Compile o arquivo `teste_syscall.c` com:
```bash
gcc teste_syscall.c -o teste
```

11. Por fim, rode:
```bash
./teste
```

O terminal mostrará:
```bash
Sleeping for 5 seconds...
```
E, após 5 segundos:
```bash
Slept for 5 seconds
```
