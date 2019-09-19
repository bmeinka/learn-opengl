dl = cc.find_library('dl', required: false)
opengl = dependency('gl')

glad_inc = include_directories('include')
glad_src = ['src/glad.c']
glad_lib = static_library('glad', glad_src,
  include_directories: glad_inc,
  dependencies: [opengl, dl]
)

glad = declare_dependency(
  link_with: glad_lib,
  include_directories: glad_inc
)
