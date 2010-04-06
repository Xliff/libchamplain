#! /bin/sh
# Manually update headers in pychamplain.override and pychamplaingtk.override.
# Keep original version
cp champlain/pychamplain-base.defs /tmp/pychamplain-base.defs.bk
cp champlain-gtk/pychamplaingtk-base.defs /tmp/pychamplaingtk-base.defs.bk

# Update the list of headers from Makefile.am
cd ../../champlain
python /usr/share/pygobject/2.0/codegen/defsgen.py \
    -m champlain -l .libs/libchamplain-0.5.so \
    -f ../bindings/python/champlain/pychamplain-boxed-types.defs \
	champlain.h 			\
	champlain-defines.h		\
	champlain-point.h		\
	champlain-view.h		\
	champlain-layer.h 		\
	champlain-selection-layer.h 	\
	champlain-base-marker.h		\
	champlain-marker.h		\
	champlain-tile.h		\
	champlain-map-source.h		\
	champlain-map-source-chain.h	\
	champlain-tile-source.h		\
	champlain-tile-cache.h		\
	champlain-network-tile-source.h	\
	champlain-error-tile-source.h	\
	champlain-file-cache.h		\
	champlain-map-source-factory.h	\
	champlain-map-source-desc.h	\
	champlain-polygon.h		\
	champlain-version.h		\
	champlain-memphis-tile-source.h  \
	champlain-map-data-source.h	\
	champlain-local-map-data-source.h \
	champlain-network-map-data-source.h \
	champlain-bounding-box.h \
    > ../bindings/python/champlain/pychamplain-base.defs

# Update the list of headers from Makefile.am
cd ../champlain-gtk
python /usr/share/pygobject/2.0/codegen/defsgen.py	\
    -m champlain -l .libs/libchamplain-gtk-0.5.so \
	champlain-gtk.h				\
	gtk-champlain-embed.h			\
    > ../bindings/python/champlain-gtk/pychamplaingtk-base.defs
