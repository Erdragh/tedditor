tedditor_resources = gnome.compile_resources('tedditor_resources',
    'tedditor.gresource.xml',
    source_dir: '.')

tedditor_schemas = gnome.compile_schemas()

executable('tedditor',
    'tedditor.c', 'tedditorwin.c', 'main.c', tedditor_resources, tedditor_schemas,
    dependencies: libgtk_dep,
    c_args: common_cflags)