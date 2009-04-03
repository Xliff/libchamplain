#! /bin/sh
#Manually update headers in pychamplain.override and pychamplaingtk.override.

# Update the list of headers from Makefile.am
cd ../../champlain
python /usr/share/pygobject/2.0/codegen/h2def.py	\
	-m champlain				\
	champlain.h				\
	champlain-view.h			\
	champlain-defines.h			\
	champlain-layer.h			\
	champlain-map-source.h			\
	champlain-network-map-source.h		\
	champlain-marker.h			\
	champlain-tile.h			\
	champlain-zoom-level.h			\
 > ../bindings/python/champlain/pychamplain.defs

# Update the list of headers from Makefile.am
cd ../champlain-gtk
python /usr/share/pygobject/2.0/codegen/h2def.py	\
	-m champlain				\
	champlain-gtk.h				\
	champlain-view-embed.h			\
 > ../bindings/python/champlain-gtk/pychamplaingtk.defs

# Keep original version
cd ../bindings/python
cp champlain/pychamplain.defs /tmp
cp champlain-gtk/pychamplaingtk.defs /tmp

# Apply patches
#patch -p0 < pychamplain.patch
#patch -p0 < pychamplaingtk.patch

# Make modification then run that:
#diff -up /tmp/pychamplain.defs champlain/pychamplain.defs > pychamplain.patch
#diff -up /tmp/pychamplaingtk.defs champlain-gtk/pychamplaingtk.defs > pychamplaingtk.patch
