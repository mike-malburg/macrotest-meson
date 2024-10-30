project(
  'macrotest-meson',
  'cpp', 
  version: '1.0.0',
  default_options : ['cpp_std=c++20']
)

main_sources = ['main.cpp','osmacros.cpp']
main_exe = executable('macrotest-meson', main_sources, install : true)
test('Run macrotest-meson', main_exe)

pkg = import('pkgconfig')
pkg.generate(
  name : 'macrotest-meson',
  filebase : 'macrotest-meson',
  description : 'Meson-built c++ program that prints off whether or not OS version macros were defined at build time.',
  version : '1.0.0',
  libraries : 'macrotest-meson',
  subdirs : 'include',
  install_dir : join_paths(get_option('libdir'), 'pkgconfig')
)

