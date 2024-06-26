// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENTJOIN_SANHOK_GAME_PROTOCOL_H_
#define FLATBUFFERS_GENERATED_CLIENTJOIN_SANHOK_GAME_PROTOCOL_H_

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

struct ClientJoin;
struct ClientJoinBuilder;

struct ClientJoin FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ClientJoinBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_ID = 4,
    VT_UDP_PORT = 6
  };
  uint32_t client_id() const {
    return GetField<uint32_t>(VT_CLIENT_ID, 0);
  }
  uint16_t udp_port() const {
    return GetField<uint16_t>(VT_UDP_PORT, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_CLIENT_ID, 4) &&
           VerifyField<uint16_t>(verifier, VT_UDP_PORT, 2) &&
           verifier.EndTable();
  }
};

struct ClientJoinBuilder {
  typedef ClientJoin Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client_id(uint32_t client_id) {
    fbb_.AddElement<uint32_t>(ClientJoin::VT_CLIENT_ID, client_id, 0);
  }
  void add_udp_port(uint16_t udp_port) {
    fbb_.AddElement<uint16_t>(ClientJoin::VT_UDP_PORT, udp_port, 0);
  }
  explicit ClientJoinBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ClientJoin> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ClientJoin>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ClientJoin> CreateClientJoin(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t client_id = 0,
    uint16_t udp_port = 0) {
  ClientJoinBuilder builder_(_fbb);
  builder_.add_client_id(client_id);
  builder_.add_udp_port(udp_port);
  return builder_.Finish();
}

struct ClientJoin::Traits {
  using type = ClientJoin;
  static auto constexpr Create = CreateClientJoin;
};

inline const sanhok::game::protocol::ClientJoin *GetClientJoin(const void *buf) {
  return ::flatbuffers::GetRoot<sanhok::game::protocol::ClientJoin>(buf);
}

inline const sanhok::game::protocol::ClientJoin *GetSizePrefixedClientJoin(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<sanhok::game::protocol::ClientJoin>(buf);
}

inline bool VerifyClientJoinBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sanhok::game::protocol::ClientJoin>(nullptr);
}

inline bool VerifySizePrefixedClientJoinBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<sanhok::game::protocol::ClientJoin>(nullptr);
}

inline void FinishClientJoinBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::ClientJoin> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedClientJoinBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::ClientJoin> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace protocol
}  // namespace game
}  // namespace sanhok

#endif  // FLATBUFFERS_GENERATED_CLIENTJOIN_SANHOK_GAME_PROTOCOL_H_
