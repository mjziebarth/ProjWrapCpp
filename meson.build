project('libprojwrap', 'cpp', version: '1.3.0')

inc = [include_directories('include')]

dep_proj = dependency('proj')

sources = ['src/projwrapper.cpp','src/projwrappertypes.cpp']

libprojwrap = static_library('projwrap',
    sources : sources,
    include_directories : inc,
    dependencies : dep_proj,
    install : true)

libprojwrap_dep = declare_dependency(
    include_directories : inc,
    link_with : libprojwrap,
    dependencies : dep_proj
)
