project('learn-opengl', 'c', default_options: ['c_std=c11'])
add_project_arguments('-Wall', '-Wextra', '-Werror','-Wpedantic', language: 'c')

glfw = dependency('glfw3')
subdir('glad')

sources = ['src/main.c']

executable('getting_started', sources,
  dependencies: [glad, glfw]
)
