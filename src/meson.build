add_project_arguments(['-Wall', '-Wextra', '-Wconversion', '-ffreestanding', '-nostdlib'], language : 'c')

sources = ['kernel.c', 'entry.S', 'csr.S', 'printf.c']

kernel_img = executable('kernel.elf',
  sources,
  c_args: ['-ffreestanding', '-nostdlib'],
  link_args : ['-T' + linker_script],
  link_depends: [linker_script],
  include_directories: kernel_include_dir,
)
