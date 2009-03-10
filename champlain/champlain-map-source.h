/*
 * Copyright (C) 2008-2009 Pierre-Luc Beaudoin <pierre-luc@pierlux.com>
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

#if !defined (__CHAMPLAIN_CHAMPLAIN_H_INSIDE__) && !defined (CHAMPLAIN_COMPILATION)
#error "Only <champlain/champlain.h> can be included directly."
#endif

#ifndef CHAMPLAIN_MAP_SOURCE_H
#define CHAMPLAIN_MAP_SOURCE_H

#include <champlain/champlain-defines.h>
#include <champlain/champlain-tile.h>
#include <champlain/champlain-zoom-level.h>

#include <glib-object.h>

#define CHAMPLAIN_TYPE_MAP_SOURCE     (champlain_map_source_get_type())
#define CHAMPLAIN_MAP_SOURCE(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), CHAMPLAIN_TYPE_MAP_SOURCE, ChamplainMapSource))
#define CHAMPLAIN_MAP_SOURCE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  CHAMPLAIN_TYPE_MAP_SOURCE, ChamplainMapSourceClass))
#define CHAMPLAIN_IS_MAP_SOURCE(obj)  (G_TYPE_CHECK_INSTANCE_TYPE((obj), CHAMPLAIN_TYPE_MAP_SOURCE))
#define CHAMPLAIN_IS_MAP_SOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  CHAMPLAIN_TYPE_MAP_SOURCE))
#define CHAMPLAIN_MAP_SOURCE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  CHAMPLAIN_TYPE_MAP_SOURCE, ChamplainMapSourceClass))

typedef struct _ChamplainMapSource ChamplainMapSource;
typedef struct _ChamplainMapSourceClass ChamplainMapSourceClass;
typedef struct _ChamplainMapSourcePrivate ChamplainMapSourcePrivate;

typedef enum
{
  CHAMPLAIN_MAP_PROJECTION_MERCATOR
} ChamplainMapProjection;

struct _ChamplainMapSource
{
  GObject parent;
  ChamplainMapSourcePrivate *priv;
};

struct _ChamplainMapSourceClass
{
  GObjectClass parent_class;

  void (*get_tile) (ChamplainMapSource *map_source,
                    ChamplainView *view,
                    ChamplainZoomLevel *zoom_level,
                    ChamplainTile *tile);
};

GType champlain_map_source_get_type (void);

gint champlain_map_source_get_min_zoom_level (ChamplainMapSource *map_source);

gint champlain_map_source_get_max_zoom_level (ChamplainMapSource *map_source);

guint champlain_map_source_get_tile_size (ChamplainMapSource *map_source);

guint champlain_map_source_get_x (ChamplainMapSource *map_source,
    gint zoom_level, gdouble longitude);

guint champlain_map_source_get_y (ChamplainMapSource *map_source,
    gint zoom_level, gdouble latitude);

gdouble champlain_map_source_get_longitude (ChamplainMapSource *map_source,
    gint zoom_level, guint x);

gdouble champlain_map_source_get_latitude (ChamplainMapSource *map_source,
    gint zoom_level, guint y);

guint champlain_map_source_get_row_count (ChamplainMapSource *map_source,
    gint zoom_level);

guint champlain_map_source_get_column_count (ChamplainMapSource *map_source,
    gint zoom_level);

void champlain_map_source_get_tile (ChamplainMapSource *map_source,
    ChamplainView *view, ChamplainZoomLevel *level, ChamplainTile *tile);

void champlain_map_source_set_name (ChamplainMapSource *map_source,
    const char *name);
const gchar * champlain_map_source_get_name (ChamplainMapSource *map_source);

void champlain_map_source_set_license (ChamplainMapSource *map_source,
    const char *license);
const gchar * champlain_map_source_get_license (ChamplainMapSource *map_source);


#endif