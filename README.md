# mini-kernel

Placeholder name, we have no creativity

## Dependencies

### Ubuntu/Debian

```
sudo apt install qemu-system-riscv gdb-multiarch clang meson ninja
```

### Arch Linux
```
sudo pacman -S qemu-full riscv64-elf-gdb clang meson ninja-build
```

### Fedora
TODO

## Building

This will configure `meson`, our build system, and create a directory called `build`
where all our compiled files will live.

```
meson setup --cross-file=meson-llvm-riscv.ini build
```

To compile, run:

```
meson compile -C build
```

To boot the kernel:

```
meson compile -C build boot
```
