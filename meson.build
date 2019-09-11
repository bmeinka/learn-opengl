project('learn-opengl', 'c', default_options: ['c_std=c11'])
add_project_arguments('-Wall', '-Wextra', '-Werror','-Wpedantic', language: 'c')

# all the dependencies that we need
subdir('glad')
sdl = dependency('sdl2')

sources = ['src/init.c']

hello_window_sources = ['src/hello_window.c']
executable('hello_window', hello_window_sources + sources,
  dependencies: [glad, sdl]
)
