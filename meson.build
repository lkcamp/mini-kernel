project('riscv-barebones', 'c',
  # default_options: ['buildtype=plain'],
)

linker_script = meson.current_source_dir() + '/linker.ld'

subdir('src')

run_target('boot',
  command : ['qemu.sh', kernel_img],
  depends : kernel_img,
)
