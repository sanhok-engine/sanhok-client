// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PLAYERMOVEMENT_SANHOK_GAME_PROTOCOL_H_
#define FLATBUFFERS_GENERATED_PLAYERMOVEMENT_SANHOK_GAME_PROTOCOL_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

#include "types.hpp"

namespace sanhok {
namespace game {
namespace protocol {

struct PlayerMovement;
struct PlayerMovementBuilder;

enum class PlayerMovementType : uint8_t {
  IDLE = 0,
  STANDING_WALK = 1,
  STANDING_RUN = 2,
  STANDING_SPRINT = 3,
  CROUCH_WALK = 4,
  CROUCH_RUN = 5,
  CROUCH_SPRINT = 6,
  CRAWLING = 7,
  SWIMMING = 8,
  FALLING = 9,
  MIN = IDLE,
  MAX = FALLING
};

inline const PlayerMovementType (&EnumValuesPlayerMovementType())[10] {
  static const PlayerMovementType values[] = {
    PlayerMovementType::IDLE,
    PlayerMovementType::STANDING_WALK,
    PlayerMovementType::STANDING_RUN,
    PlayerMovementType::STANDING_SPRINT,
    PlayerMovementType::CROUCH_WALK,
    PlayerMovementType::CROUCH_RUN,
    PlayerMovementType::CROUCH_SPRINT,
    PlayerMovementType::CRAWLING,
    PlayerMovementType::SWIMMING,
    PlayerMovementType::FALLING
  };
  return values;
}

inline const char * const *EnumNamesPlayerMovementType() {
  static const char * const names[11] = {
    "IDLE",
    "STANDING_WALK",
    "STANDING_RUN",
    "STANDING_SPRINT",
    "CROUCH_WALK",
    "CROUCH_RUN",
    "CROUCH_SPRINT",
    "CRAWLING",
    "SWIMMING",
    "FALLING",
    nullptr
  };
  return names;
}

inline const char *EnumNamePlayerMovementType(PlayerMovementType e) {
  if (::flatbuffers::IsOutRange(e, PlayerMovementType::IDLE, PlayerMovementType::FALLING)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPlayerMovementType()[index];
}

enum class PlayerMovementDirection : uint8_t {
  FORWARD = 0,
  BACKWARD = 1,
  LEFT = 2,
  RIGHT = 3,
  MIN = FORWARD,
  MAX = RIGHT
};

inline const PlayerMovementDirection (&EnumValuesPlayerMovementDirection())[4] {
  static const PlayerMovementDirection values[] = {
    PlayerMovementDirection::FORWARD,
    PlayerMovementDirection::BACKWARD,
    PlayerMovementDirection::LEFT,
    PlayerMovementDirection::RIGHT
  };
  return values;
}

inline const char * const *EnumNamesPlayerMovementDirection() {
  static const char * const names[5] = {
    "FORWARD",
    "BACKWARD",
    "LEFT",
    "RIGHT",
    nullptr
  };
  return names;
}

inline const char *EnumNamePlayerMovementDirection(PlayerMovementDirection e) {
  if (::flatbuffers::IsOutRange(e, PlayerMovementDirection::FORWARD, PlayerMovementDirection::RIGHT)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPlayerMovementDirection()[index];
}

struct PlayerMovement FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PlayerMovementBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_ID = 4,
    VT_MOVEMENT_TYPE = 6,
    VT_MOVEMENT_DIRECTION = 8,
    VT_BODY_DIECTION = 10,
    VT_AIM_DIRECTION = 12
  };
  uint32_t client_id() const {
    return GetField<uint32_t>(VT_CLIENT_ID, 0);
  }
  sanhok::game::protocol::PlayerMovementType movement_type() const {
    return static_cast<sanhok::game::protocol::PlayerMovementType>(GetField<uint8_t>(VT_MOVEMENT_TYPE, 0));
  }
  sanhok::game::protocol::PlayerMovementDirection movement_direction() const {
    return static_cast<sanhok::game::protocol::PlayerMovementDirection>(GetField<uint8_t>(VT_MOVEMENT_DIRECTION, 0));
  }
  const sanhok::game::protocol::Vector3 *body_diection() const {
    return GetStruct<const sanhok::game::protocol::Vector3 *>(VT_BODY_DIECTION);
  }
  const sanhok::game::protocol::Vector3 *aim_direction() const {
    return GetStruct<const sanhok::game::protocol::Vector3 *>(VT_AIM_DIRECTION);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_CLIENT_ID, 4) &&
           VerifyField<uint8_t>(verifier, VT_MOVEMENT_TYPE, 1) &&
           VerifyField<uint8_t>(verifier, VT_MOVEMENT_DIRECTION, 1) &&
           VerifyField<sanhok::game::protocol::Vector3>(verifier, VT_BODY_DIECTION, 4) &&
           VerifyField<sanhok::game::protocol::Vector3>(verifier, VT_AIM_DIRECTION, 4) &&
           verifier.EndTable();
  }
};

struct PlayerMovementBuilder {
  typedef PlayerMovement Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client_id(uint32_t client_id) {
    fbb_.AddElement<uint32_t>(PlayerMovement::VT_CLIENT_ID, client_id, 0);
  }
  void add_movement_type(sanhok::game::protocol::PlayerMovementType movement_type) {
    fbb_.AddElement<uint8_t>(PlayerMovement::VT_MOVEMENT_TYPE, static_cast<uint8_t>(movement_type), 0);
  }
  void add_movement_direction(sanhok::game::protocol::PlayerMovementDirection movement_direction) {
    fbb_.AddElement<uint8_t>(PlayerMovement::VT_MOVEMENT_DIRECTION, static_cast<uint8_t>(movement_direction), 0);
  }
  void add_body_diection(const sanhok::game::protocol::Vector3 *body_diection) {
    fbb_.AddStruct(PlayerMovement::VT_BODY_DIECTION, body_diection);
  }
  void add_aim_direction(const sanhok::game::protocol::Vector3 *aim_direction) {
    fbb_.AddStruct(PlayerMovement::VT_AIM_DIRECTION, aim_direction);
  }
  explicit PlayerMovementBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<PlayerMovement> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<PlayerMovement>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<PlayerMovement> CreatePlayerMovement(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t client_id = 0,
    sanhok::game::protocol::PlayerMovementType movement_type = sanhok::game::protocol::PlayerMovementType::IDLE,
    sanhok::game::protocol::PlayerMovementDirection movement_direction = sanhok::game::protocol::PlayerMovementDirection::FORWARD,
    const sanhok::game::protocol::Vector3 *body_diection = nullptr,
    const sanhok::game::protocol::Vector3 *aim_direction = nullptr) {
  PlayerMovementBuilder builder_(_fbb);
  builder_.add_aim_direction(aim_direction);
  builder_.add_body_diection(body_diection);
  builder_.add_client_id(client_id);
  builder_.add_movement_direction(movement_direction);
  builder_.add_movement_type(movement_type);
  return builder_.Finish();
}

struct PlayerMovement::Traits {
  using type = PlayerMovement;
  static auto constexpr Create = CreatePlayerMovement;
};

inline const sanhok::game::protocol::PlayerMovement *GetPlayerMovement(const void *buf) {
  return ::flatbuffers::GetRoot<sanhok::game::protocol::PlayerMovement>(buf);
}

inline const sanhok::game::protocol::PlayerMovement *GetSizePrefixedPlayerMovement(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<sanhok::game::protocol::PlayerMovement>(buf);
}

inline bool VerifyPlayerMovementBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sanhok::game::protocol::PlayerMovement>(nullptr);
}

inline bool VerifySizePrefixedPlayerMovementBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<sanhok::game::protocol::PlayerMovement>(nullptr);
}

inline void FinishPlayerMovementBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::PlayerMovement> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPlayerMovementBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<sanhok::game::protocol::PlayerMovement> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace protocol
}  // namespace game
}  // namespace sanhok

#endif  // FLATBUFFERS_GENERATED_PLAYERMOVEMENT_SANHOK_GAME_PROTOCOL_H_
