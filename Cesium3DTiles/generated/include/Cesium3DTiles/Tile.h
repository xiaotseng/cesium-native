// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/BoundingVolume.h"
#include "Cesium3DTiles/Content.h"
#include "Cesium3DTiles/Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <optional>
#include <vector>

namespace Cesium3DTiles {
/**
 * @brief A tile in a 3D Tiles tileset.
 */
struct CESIUM3DTILES_API Tile final : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "Tile";

  /**
   * @brief Known values for Specifies if additive or replacement refinement is
   * used when traversing the tileset for rendering. This property is required
   * for the root tile of a tileset; it is optional for all other tiles. The
   * default is to inherit from the parent tile.
   */
  struct Refine {
    inline static const std::string ADD = "ADD";

    inline static const std::string REPLACE = "REPLACE";
  };

  /**
   * @brief The bounding volume that encloses the tile.
   */
  Cesium3DTiles::BoundingVolume boundingVolume;

  /**
   * @brief Optional bounding volume that defines the volume the viewer must be
   * inside of before the tile's content will be requested and before the tile
   * will be refined based on geometricError.
   */
  std::optional<Cesium3DTiles::BoundingVolume> viewerRequestVolume;

  /**
   * @brief The error, in meters, introduced if this tile is rendered and its
   * children are not. At runtime, the geometric error is used to compute screen
   * space error (SSE), i.e., the error measured in pixels.
   */
  double geometricError = double();

  /**
   * @brief Specifies if additive or replacement refinement is used when
   * traversing the tileset for rendering. This property is required for the
   * root tile of a tileset; it is optional for all other tiles. The default is
   * to inherit from the parent tile.
   *
   * Known values are defined in {@link Refine}.
   *
   */
  std::optional<std::string> refine;

  /**
   * @brief A floating-point 4x4 affine transformation matrix, stored in
   * column-major order, that transforms the tile's content--i.e., its features
   * as well as content.boundingVolume, boundingVolume, and
   * viewerRequestVolume--from the tile's local coordinate system to the parent
   * tile's coordinate system, or, in the case of a root tile, from the tile's
   * local coordinate system to the tileset's coordinate system. `transform`
   * does not apply to any volume property when the volume is a region, defined
   * in EPSG:4979 coordinates. `transform` scales the `geometricError` by the
   * maximum scaling factor from the matrix.
   */
  std::vector<double> transform =
      {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

  /**
   * @brief Metadata about the tile's content and a link to the content. When
   * this is omitted the tile is just used for culling.
   */
  std::optional<Cesium3DTiles::Content> content;

  /**
   * @brief An array of objects that define child tiles. Each child tile content
   * is fully enclosed by its parent tile's bounding volume and, generally, has
   * a geometricError less than its parent tile's geometricError. For leaf
   * tiles, the length of this array is zero, and children may not be defined.
   */
  std::vector<Cesium3DTiles::Tile> children;
};
} // namespace Cesium3DTiles
