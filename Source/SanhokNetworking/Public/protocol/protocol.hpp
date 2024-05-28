// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PROTOCOL_SANHOK_GAME_PROTOCOL_H_
#define FLATBUFFERS_GENERATED_PROTOCOL_SANHOK_GAME_PROTOCOL_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

#include "client_join.hpp"
#include "client_leave.hpp"
#include "player_equipment.hpp"
#include "player_movement.hpp"

namespace sanhok {
namespace game {
namespace protocol {

struct Protocol;
struct ProtocolBuilder;

enum class ProtocolType : uint8_t {
  NONE = 0,
  ClientJoin = 1,
  ClientLeave = 2,
  PlayerEquipment = 3,
  PlayerMovement = 4,
  MIN = NONE,
  MAX = PlayerMovement
};

inline const ProtocolType (&EnumValuesProtocolType())[5] {
  static const ProtocolType values[] = {
    ProtocolType::NONE,
    ProtocolType::ClientJoin,
    ProtocolType::ClientLeave,
    ProtocolType::PlayerEquipment,
    ProtocolType::PlayerMovement
  };
  return values;
}

inline const char * const *EnumNamesProtocolType() {
  static const char * const names[6] = {
    "NONE",
    "ClientJoin",
    "ClientLeave",
    "PlayerEquipment",
    "PlayerMovement",
    nullptr
  };
  return names;
}

inline const char *EnumNameProtocolType(ProtocolType e) {
  if (::flatbuffers::IsOutRange(e, ProtocolType::NONE, ProtocolType::PlayerMovement)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesProtocolType()[index];
}

template<typename T> struct ProtocolTypeTraits {
  static const ProtocolType enum_value = ProtocolType::NONE;
};

template<> struct ProtocolTypeTraits<sanhok::game::protocol::ClientJoin> {
  static const ProtocolType enum_value = ProtocolType::ClientJoin;
};

template<> struct ProtocolTypeTraits<sanhok::game::protocol::ClientLeave> {
  static const ProtocolType enum_value = ProtocolType::ClientLeave;
};

template<> struct ProtocolTypeTraits<sanhok::game::protocol::PlayerEquipment> {
  static const ProtocolType enum_value = ProtocolType::PlayerEquipment;
};

template<> struct ProtocolTypeTraits<sanhok::game::protocol::PlayerMovement> {
  static const ProtocolType enum_value = ProtocolType::PlayerMovement;
};

bool VerifyProtocolType(::flatbuffers::Verifier &verifier, const void *obj, ProtocolType type);
bool VerifyProtocolTypeVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<ProtocolType> *types);

struct Protocol FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ProtocolBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PROTOCOL_TYPE = 4,
    VT_PROTOCOL = 6
  };
  sanhok::game::protocol::ProtocolType protocol_type() const {
    return static_cast<sanhok::game::protocol::ProtocolType>(GetField<uint8_t>(VT_PROTOCOL_TYPE, 0));
  }
  const void *protocol() const {
    return GetPointer<const void *>(VT_PROTOCOL);
  }
  template<typename T> const T *protocol_as() const;
  const sanhok::game::protocol::ClientJoin *protocol_as_ClientJoin() const {
    return protocol_type() == sanhok::game::protocol::ProtocolType::ClientJoin ? static_cast<const sanhok::game::protocol::ClientJoin *>(protocol()) : nullptr;
  }
  const sanhok::game::protocol::ClientLeave *protocol_as_ClientLeave() const {
    return protocol_type() == sanhok::game::protocol::ProtocolType::ClientLeave ? static_cast<const sanhok::game::protocol::ClientLeave *>(protocol()) : nullptr;
  }
  const sanhok::game::protocol::PlayerEquipment *protocol_as_PlayerEquipment() const {
    return protocol_type() == sanhok::game::protocol::ProtocolType::PlayerEquipment ? static_cast<const sanhok::game::protocol::PlayerEquipment *>(protocol()) : nullptr;
  }
  const sanhok::game::protocol::PlayerMovement *protocol_as_PlayerMovement() const {
    return protocol_type() == sanhok::game::protocol::ProtocolType::PlayerMovement ? static_cast<const sanhok::game::protocol::PlayerMovement *>(protocol()) : nullptr;
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_PROTOCOL_TYPE, 1) &&
           VerifyOffset(verifier, VT_PROTOCOL) &&
           VerifyProtocolType(verifier, protocol(), protocol_type()) &&
           verifier.EndTable();
  }
};

template<> inline const sanhok::game::protocol::ClientJoin *Protocol::protocol_as<sanhok::game::protocol::ClientJoin>() const {
  return protocol_as_ClientJoin();
}

template<> inline const sanhok::game::protocol::ClientLeave *Protocol::protocol_as<sanhok::game::protocol::ClientLeave>() const {
  return protocol_as_ClientLeave();
}

template<> inline const sanhok::game::protocol::PlayerEquipment *Protocol::protocol_as<sanhok::game::protocol::PlayerEquipment>() const {
  return protocol_as_PlayerEquipment();
}

template<> inline const sanhok::game::protocol::PlayerMovement *Protocol::protocol_as<sanhok::game::protocol::PlayerMovement>() const {
  return protocol_as_PlayerMovement();
}

struct ProtocolBuilder {
  typedef Protocol Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_protocol_type(sanhok::game::protocol::ProtocolType protocol_type) {
    fbb_.AddElement<uint8_t>(Protocol::VT_PROTOCOL_TYPE, static_cast<uint8_t>(protocol_type), 0);
  }
  void add_protocol(::flatbuffers::Offset<void> protocol) {
    fbb_.AddOffset(Protocol::VT_PROTOCOL, protocol);
  }
  explicit ProtocolBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Protocol> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Protocol>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Protocol> CreateProtocol(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    sanhok::game::protocol::ProtocolType protocol_type = sanhok::game::protocol::ProtocolType::NONE,
    ::flatbuffers::Offset<void> protocol = 0) {
  ProtocolBuilder builder_(_fbb);
  builder_.add_protocol(protocol);
  builder_.add_protocol_type(protocol_type);
  return builder_.Finish();
}

struct Protocol::Traits {
  using type = Protocol;
  static auto constexpr Create = CreateProtocol;
};

inline bool VerifyProtocolType(::flatbuffers::Verifier &verifier, const void *obj, ProtocolType type) {
  switch (type) {
    case ProtocolType::NONE: {
      return true;
    }
    case ProtocolType::ClientJoin: {
      auto ptr = reinterpret_cast<const sanhok::game::protocol::ClientJoin *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProtocolType::ClientLeave: {
      auto ptr = reinterpret_cast<const sanhok::game::protocol::ClientLeave *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProtocolType::PlayerEquipment: {
      auto ptr = reinterpret_cast<const sanhok::game::protocol::PlayerEquipment *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProtocolType::PlayerMovement: {
      auto ptr = reinterpret_cast<const sanhok::game::protocol::PlayerMovement *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyProtocolTypeVector(::flatbuffers::Verifier &verifier, const ::flatbuffers::Vector<::flatbuffers::Offset<void>> *values, const ::flatbuffers::Vector<ProtocolType> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (::flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyProtocolType(
        verifier,  values->Get(i), types->GetEnum<ProtocolType>(i))) {
      return false;
    }
  }
  return true;
}

inline const sanhok::game::protocol::Protocol *GetProtocol(const void *buf) {
  return ::flatbuffers::GetRoot<sanhok::game::protocol::Protocol>(buf);
}

inline const sanhok::game::protocol::Protocol *GetSizePrefixedProtocol(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<sanhok::game::protocol::Protocol>(buf);
}

inline bool VerifyProtocolBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sanhok::game::protocol::Protocol>(nullptr);
}

inline bool VerifySizePrefixedProtocolBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<sanhok::game::protocol::Protocol>(nullptr);
}

inline void FinishProtocolBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::Protocol> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedProtocolBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::Protocol> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace protocol
}  // namespace game
}  // namespace sanhok

#endif  // FLATBUFFERS_GENERATED_PROTOCOL_SANHOK_GAME_PROTOCOL_H_