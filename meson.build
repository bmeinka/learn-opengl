project('learn-opengl', 'c', default_options: ['c_std=c11'])
add_project_arguments('-Wall', '-Wextra', '-Werror','-Wpedantic', language: 'c')

# all the dependencies that we need
cc = meson.get_compiler('c')
m = cc.find_library('m', required: false)
subdir('glad')
sdl = dependency('sdl2')

dep = [m, glad, sdl]

src = [
  'src/events.c',
  'src/init.c',
  'src/main.c',
  'src/shaders.c'
]

executable('learngl', src, dependencies: dep)
