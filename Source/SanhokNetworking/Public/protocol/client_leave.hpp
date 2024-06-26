// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENTLEAVE_SANHOK_GAME_PROTOCOL_H_
#define FLATBUFFERS_GENERATED_CLIENTLEAVE_SANHOK_GAME_PROTOCOL_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace sanhok {
namespace game {
namespace protocol {

struct ClientLeave;
struct ClientLeaveBuilder;

struct ClientLeave FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ClientLeaveBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_ID = 4
  };
  uint32_t client_id() const {
    return GetField<uint32_t>(VT_CLIENT_ID, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_CLIENT_ID, 4) &&
           verifier.EndTable();
  }
};

struct ClientLeaveBuilder {
  typedef ClientLeave Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client_id(uint32_t client_id) {
    fbb_.AddElement<uint32_t>(ClientLeave::VT_CLIENT_ID, client_id, 0);
  }
  explicit ClientLeaveBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ClientLeave> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ClientLeave>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ClientLeave> CreateClientLeave(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t client_id = 0) {
  ClientLeaveBuilder builder_(_fbb);
  builder_.add_client_id(client_id);
  return builder_.Finish();
}

struct ClientLeave::Traits {
  using type = ClientLeave;
  static auto constexpr Create = CreateClientLeave;
};

inline const sanhok::game::protocol::ClientLeave *GetClientLeave(const void *buf) {
  return ::flatbuffers::GetRoot<sanhok::game::protocol::ClientLeave>(buf);
}

inline const sanhok::game::protocol::ClientLeave *GetSizePrefixedClientLeave(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<sanhok::game::protocol::ClientLeave>(buf);
}

inline bool VerifyClientLeaveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sanhok::game::protocol::ClientLeave>(nullptr);
}

inline bool VerifySizePrefixedClientLeaveBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<sanhok::game::protocol::ClientLeave>(nullptr);
}

inline void FinishClientLeaveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::ClientLeave> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedClientLeaveBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::ClientLeave> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace protocol
}  // namespace game
}  // namespace sanhok

#endif  // FLATBUFFERS_GENERATED_CLIENTLEAVE_SANHOK_GAME_PROTOCOL_H_
