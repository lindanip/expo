/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ABI45_0_0React/ABI45_0_0renderer/core/PropsParserContext.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/RawProps.h>
#include <ABI45_0_0React/ABI45_0_0renderer/graphics/ColorComponents.h>
#include <ABI45_0_0React/ABI45_0_0renderer/graphics/ABI45_0_0RCTPlatformColorUtils.h>

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

inline ColorComponents parsePlatformColor(
    const PropsParserContext &context,
    const RawValue &value) {
  if (value.hasType<butter::map<std::string, RawValue>>()) {
    auto items = (butter::map<std::string, RawValue>)value;
    if (items.find("semantic") != items.end() &&
        items.at("semantic").hasType<std::vector<std::string>>()) {
      auto semanticItems = (std::vector<std::string>)items.at("semantic");
      return ABI45_0_0RCTPlatformColorComponentsFromSemanticItems(semanticItems);
    }
  }

  return {0, 0, 0, 0};
}

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook
