project('learn-opengl', 'c', default_options: ['c_std=c11'])
add_project_arguments('-Wall', '-Wextra', '-Werror','-Wpedantic', language: 'c')

# all the dependencies that we need
subdir('glad')
sdl = dependency('sdl2')

src = [
  'src/events.c',
  'src/init.c',
  'src/shaders.c'
]

dep = [glad, sdl]

triangle_src =['src/hello_triangle.c'] + src
executable('hello_window', triangle_src, dependencies: dep)
executable('hello_triangle', ['src/hello_triangle.c'] + src, dependencies: dep)
executable('hello_elements', ['src/hello_triangle_elements.c'] + src, dependencies: dep)
executable('hello_triangle_e1', ['src/hello_triangle_exercise_1.c'] + src, dependencies: dep)
executable('hello_triangle_e2', ['src/hello_triangle_exercise_2.c'] + src, dependencies: dep)
executable('hello_triangle_e3', ['src/hello_triangle_exercise_3.c'] + src, dependencies: dep)

executable('red_triangle', triangle_src,
  dependencies: dep,
  c_args: [
    '-DVERT_PATH="shaders/red_triangle.vert"',
    '-DFRAG_PATH="shaders/red_triangle.frag"'
])
