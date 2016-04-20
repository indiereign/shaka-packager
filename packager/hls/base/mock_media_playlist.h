// Copyright 2016 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_
#define PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_

#include <gmock/gmock.h>

#include "packager/hls/base/media_playlist.h"

namespace edash_packager {
namespace hls {

class MockMediaPlaylist : public MediaPlaylist {
 public:
  // The actual parameters to MediaPlaylist() (parent) constructor doesn't
  // matter because the return value can be mocked.
  MockMediaPlaylist(MediaPlaylistType type,
                    const std::string& file_name,
                    const std::string& name,
                    const std::string& group_id);
  ~MockMediaPlaylist() override;

  MOCK_METHOD1(SetMediaInfo, bool(const MediaInfo& media_info));
  MOCK_METHOD3(AddSegment,
               void(const std::string& file_name,
                    uint64_t duration,
                    uint64_t size));
  MOCK_METHOD0(RemoveOldestSegment, void());
  MOCK_METHOD5(AddEncryptionInfo,
               void(EncryptionMethod method,
                    const std::string& url,
                    const std::string& iv,
                    const std::string& key_format,
                    const std::string& key_format_versions));
  MOCK_METHOD1(WriteToFile, bool(media::File* file));
  MOCK_CONST_METHOD0(Bitrate, uint64_t());
  MOCK_CONST_METHOD0(GetLongestSegmentDuration, double());
  MOCK_METHOD1(SetTargetDuration, bool(uint32_t target_duration));
};

}  // namespace hls
}  // namespace edash_packager

#endif  // PACKAGER_HLS_BASE_MOCK_MEDIA_PLAYLIST_H_
