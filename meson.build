project('libprojwrap', 'cpp', version: '1.4.0')

inc = [include_directories('include')]

#
# If PROJ is being built as a subproject via the PROJ-Meson-Meta-Wrapper
# (https://codeberg.org/mjziebarth/PROJ-Meson-Meta-Wrapper), we would
# typically prefer to use that version rather than any potential system
# version.
# So, check for its existence here.
#
# Note: Since ProjWrapCpp does not come with this subproject itself,
#       it needs to be provided in the root project *before* a call
#       to subproject('libprojwrap')!
#
proj_meta = subproject('proj-meta', required: false)
if proj_meta.found()
    dep_proj = proj_meta.get_variable('proj')
else
    # If the subproject does not exists
    dep_proj = dependency('proj')
endif

sources = ['src/projwrapper.cpp','src/projwrappertypes.cpp']

libprojwrap = static_library(
    'projwrap',
    sources : sources,
    include_directories : inc,
    dependencies : dep_proj,
    install : true
)

libprojwrap_dep = declare_dependency(
    include_directories : inc,
    link_with : libprojwrap,
    dependencies : dep_proj
)
