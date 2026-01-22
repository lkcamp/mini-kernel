#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
    echo "usage: qemu.sh <path-to-kernel-elf>" >&2
    exit 1
fi

exec qemu-system-riscv64 -nographic -machine virt -bios none -serial mon:stdio -kernel "$1"
