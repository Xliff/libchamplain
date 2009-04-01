/*
 * Copyright (C) 2008 Pierre-Luc Beaudoin <pierre-luc@pierlux.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef MAP_H
#define MAP_H

#include "champlain.h"
#include "champlainview.h"
#include "champlainprivate.h"
#include "zoomlevel.h"
#include "tile.h"

#include <glib.h>
#include <clutter/clutter.h>

struct _Map
{
  guint zoom_levels;
  const gchar *name;
  const gchar *license;
  const gchar *license_uri;
  int tile_size;

  ZoomLevel *current_level;
  ZoomLevel *previous_level;

  guint (* get_row_count) (Map *map, guint zoom_level);
  guint (* get_column_count) (Map *map, guint zoom_level);

  gint (* longitude_to_x) (Map *map, gdouble longitude, guint zoom_level);
  gint (* latitude_to_y) (Map *map, gdouble latitude, guint zoom_level);
  gdouble (* x_to_longitude) (Map *map, gint x, guint zoom_level);
  gdouble (* y_to_latitude) (Map *map, gint y, guint zoom_level);

  gchar *(* get_tile_filename) (Map *map, Tile *tile);
  gchar *(* get_tile_uri) (Map *map, Tile *tile);
};

Map *map_new (ChamplainMapSource source);

void map_load_visible_tiles (Map *map, ChamplainRectangle viewport, gboolean offline);

void map_free (Map *map);

gboolean map_zoom_in (Map *map);

gboolean map_zoom_out (Map *map);

gboolean map_zoom_to (Map *map, guint zoomLevel);

void map_load_level(Map *map, gint zoom_level);

#endif