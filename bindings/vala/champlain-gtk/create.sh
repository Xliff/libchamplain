export PKG_CONFIG_PATH=$(readlink -f ../../../)
echo $PKG_CONFIG_PATH
vala-gen-introspect champlain-gtk-0.6 champlain-gtk-0.6
vapigen --library champlain-gtk-0.6 --pkg clutter-gtk-0.10 --pkg gtk+-2.0 --pkg champlain-0.6 --vapidir=../champlain champlain-gtk-0.6/champlain-gtk-0.6.gi --metadata champlain-gtk-0.6/champlain-gtk-0.6.metadata
