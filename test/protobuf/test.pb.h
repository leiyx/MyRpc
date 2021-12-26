// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto;
namespace test {
class People;
class PeopleDefaultTypeInternal;
extern PeopleDefaultTypeInternal _People_default_instance_;
class Profession;
class ProfessionDefaultTypeInternal;
extern ProfessionDefaultTypeInternal _Profession_default_instance_;
}  // namespace test
PROTOBUF_NAMESPACE_OPEN
template<> ::test::People* Arena::CreateMaybeMessage<::test::People>(Arena*);
template<> ::test::Profession* Arena::CreateMaybeMessage<::test::Profession>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace test {

enum People_Hobby : int {
  People_Hobby_STUDY = 0,
  People_Hobby_SLEEP = 1,
  People_Hobby_WORK = 2,
  People_Hobby_People_Hobby_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  People_Hobby_People_Hobby_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool People_Hobby_IsValid(int value);
constexpr People_Hobby People_Hobby_Hobby_MIN = People_Hobby_STUDY;
constexpr People_Hobby People_Hobby_Hobby_MAX = People_Hobby_WORK;
constexpr int People_Hobby_Hobby_ARRAYSIZE = People_Hobby_Hobby_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* People_Hobby_descriptor();
template<typename T>
inline const std::string& People_Hobby_Name(T enum_t_value) {
  static_assert(::std::is_same<T, People_Hobby>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function People_Hobby_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    People_Hobby_descriptor(), enum_t_value);
}
inline bool People_Hobby_Parse(
    const std::string& name, People_Hobby* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<People_Hobby>(
    People_Hobby_descriptor(), name, value);
}
// ===================================================================

class People :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test.People) */ {
 public:
  People();
  virtual ~People();

  People(const People& from);
  People(People&& from) noexcept
    : People() {
    *this = ::std::move(from);
  }

  inline People& operator=(const People& from) {
    CopyFrom(from);
    return *this;
  }
  inline People& operator=(People&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const People& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const People* internal_default_instance() {
    return reinterpret_cast<const People*>(
               &_People_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(People& a, People& b) {
    a.Swap(&b);
  }
  inline void Swap(People* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline People* New() const final {
    return CreateMaybeMessage<People>(nullptr);
  }

  People* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<People>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const People& from);
  void MergeFrom(const People& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(People* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test.People";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_test_2eproto);
    return ::descriptor_table_test_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef People_Hobby Hobby;
  static constexpr Hobby STUDY =
    People_Hobby_STUDY;
  static constexpr Hobby SLEEP =
    People_Hobby_SLEEP;
  static constexpr Hobby WORK =
    People_Hobby_WORK;
  static inline bool Hobby_IsValid(int value) {
    return People_Hobby_IsValid(value);
  }
  static constexpr Hobby Hobby_MIN =
    People_Hobby_Hobby_MIN;
  static constexpr Hobby Hobby_MAX =
    People_Hobby_Hobby_MAX;
  static constexpr int Hobby_ARRAYSIZE =
    People_Hobby_Hobby_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Hobby_descriptor() {
    return People_Hobby_descriptor();
  }
  template<typename T>
  static inline const std::string& Hobby_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Hobby>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Hobby_Name.");
    return People_Hobby_Name(enum_t_value);
  }
  static inline bool Hobby_Parse(const std::string& name,
      Hobby* value) {
    return People_Hobby_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kFriendsFieldNumber = 6,
    kNameFieldNumber = 1,
    kJobFieldNumber = 7,
    kAgeFieldNumber = 2,
    kHeightFieldNumber = 3,
    kWeightFieldNumber = 4,
    kHobbyFieldNumber = 5,
  };
  // repeated bytes friends = 6;
  int friends_size() const;
  private:
  int _internal_friends_size() const;
  public:
  void clear_friends();
  const std::string& friends(int index) const;
  std::string* mutable_friends(int index);
  void set_friends(int index, const std::string& value);
  void set_friends(int index, std::string&& value);
  void set_friends(int index, const char* value);
  void set_friends(int index, const void* value, size_t size);
  std::string* add_friends();
  void add_friends(const std::string& value);
  void add_friends(std::string&& value);
  void add_friends(const char* value);
  void add_friends(const void* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& friends() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_friends();
  private:
  const std::string& _internal_friends(int index) const;
  std::string* _internal_add_friends();
  public:

  // bytes name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .test.Profession job = 7;
  bool has_job() const;
  private:
  bool _internal_has_job() const;
  public:
  void clear_job();
  const ::test::Profession& job() const;
  ::test::Profession* release_job();
  ::test::Profession* mutable_job();
  void set_allocated_job(::test::Profession* job);
  private:
  const ::test::Profession& _internal_job() const;
  ::test::Profession* _internal_mutable_job();
  public:

  // int32 age = 2;
  void clear_age();
  ::PROTOBUF_NAMESPACE_ID::int32 age() const;
  void set_age(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_age() const;
  void _internal_set_age(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 height = 3;
  void clear_height();
  ::PROTOBUF_NAMESPACE_ID::int32 height() const;
  void set_height(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_height() const;
  void _internal_set_height(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 weight = 4;
  void clear_weight();
  ::PROTOBUF_NAMESPACE_ID::int32 weight() const;
  void set_weight(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_weight() const;
  void _internal_set_weight(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // .test.People.Hobby hobby = 5;
  void clear_hobby();
  ::test::People_Hobby hobby() const;
  void set_hobby(::test::People_Hobby value);
  private:
  ::test::People_Hobby _internal_hobby() const;
  void _internal_set_hobby(::test::People_Hobby value);
  public:

  // @@protoc_insertion_point(class_scope:test.People)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> friends_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::test::Profession* job_;
  ::PROTOBUF_NAMESPACE_ID::int32 age_;
  ::PROTOBUF_NAMESPACE_ID::int32 height_;
  ::PROTOBUF_NAMESPACE_ID::int32 weight_;
  int hobby_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_test_2eproto;
};
// -------------------------------------------------------------------

class Profession :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test.Profession) */ {
 public:
  Profession();
  virtual ~Profession();

  Profession(const Profession& from);
  Profession(Profession&& from) noexcept
    : Profession() {
    *this = ::std::move(from);
  }

  inline Profession& operator=(const Profession& from) {
    CopyFrom(from);
    return *this;
  }
  inline Profession& operator=(Profession&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Profession& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Profession* internal_default_instance() {
    return reinterpret_cast<const Profession*>(
               &_Profession_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Profession& a, Profession& b) {
    a.Swap(&b);
  }
  inline void Swap(Profession* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Profession* New() const final {
    return CreateMaybeMessage<Profession>(nullptr);
  }

  Profession* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Profession>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Profession& from);
  void MergeFrom(const Profession& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Profession* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test.Profession";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_test_2eproto);
    return ::descriptor_table_test_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kJobNameFieldNumber = 1,
    kSalaryFieldNumber = 2,
  };
  // bytes job_name = 1;
  void clear_job_name();
  const std::string& job_name() const;
  void set_job_name(const std::string& value);
  void set_job_name(std::string&& value);
  void set_job_name(const char* value);
  void set_job_name(const void* value, size_t size);
  std::string* mutable_job_name();
  std::string* release_job_name();
  void set_allocated_job_name(std::string* job_name);
  private:
  const std::string& _internal_job_name() const;
  void _internal_set_job_name(const std::string& value);
  std::string* _internal_mutable_job_name();
  public:

  // int64 salary = 2;
  void clear_salary();
  ::PROTOBUF_NAMESPACE_ID::int64 salary() const;
  void set_salary(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_salary() const;
  void _internal_set_salary(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:test.Profession)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr job_name_;
  ::PROTOBUF_NAMESPACE_ID::int64 salary_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_test_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// People

// bytes name = 1;
inline void People::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& People::name() const {
  // @@protoc_insertion_point(field_get:test.People.name)
  return _internal_name();
}
inline void People::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:test.People.name)
}
inline std::string* People::mutable_name() {
  // @@protoc_insertion_point(field_mutable:test.People.name)
  return _internal_mutable_name();
}
inline const std::string& People::_internal_name() const {
  return name_.GetNoArena();
}
inline void People::_internal_set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void People::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:test.People.name)
}
inline void People::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.People.name)
}
inline void People::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.People.name)
}
inline std::string* People::_internal_mutable_name() {
  
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* People::release_name() {
  // @@protoc_insertion_point(field_release:test.People.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void People::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:test.People.name)
}

// int32 age = 2;
inline void People::clear_age() {
  age_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::_internal_age() const {
  return age_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::age() const {
  // @@protoc_insertion_point(field_get:test.People.age)
  return _internal_age();
}
inline void People::_internal_set_age(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  age_ = value;
}
inline void People::set_age(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:test.People.age)
}

// int32 height = 3;
inline void People::clear_height() {
  height_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::_internal_height() const {
  return height_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::height() const {
  // @@protoc_insertion_point(field_get:test.People.height)
  return _internal_height();
}
inline void People::_internal_set_height(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  height_ = value;
}
inline void People::set_height(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:test.People.height)
}

// int32 weight = 4;
inline void People::clear_weight() {
  weight_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::_internal_weight() const {
  return weight_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 People::weight() const {
  // @@protoc_insertion_point(field_get:test.People.weight)
  return _internal_weight();
}
inline void People::_internal_set_weight(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  weight_ = value;
}
inline void People::set_weight(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_weight(value);
  // @@protoc_insertion_point(field_set:test.People.weight)
}

// .test.People.Hobby hobby = 5;
inline void People::clear_hobby() {
  hobby_ = 0;
}
inline ::test::People_Hobby People::_internal_hobby() const {
  return static_cast< ::test::People_Hobby >(hobby_);
}
inline ::test::People_Hobby People::hobby() const {
  // @@protoc_insertion_point(field_get:test.People.hobby)
  return _internal_hobby();
}
inline void People::_internal_set_hobby(::test::People_Hobby value) {
  
  hobby_ = value;
}
inline void People::set_hobby(::test::People_Hobby value) {
  _internal_set_hobby(value);
  // @@protoc_insertion_point(field_set:test.People.hobby)
}

// repeated bytes friends = 6;
inline int People::_internal_friends_size() const {
  return friends_.size();
}
inline int People::friends_size() const {
  return _internal_friends_size();
}
inline void People::clear_friends() {
  friends_.Clear();
}
inline std::string* People::add_friends() {
  // @@protoc_insertion_point(field_add_mutable:test.People.friends)
  return _internal_add_friends();
}
inline const std::string& People::_internal_friends(int index) const {
  return friends_.Get(index);
}
inline const std::string& People::friends(int index) const {
  // @@protoc_insertion_point(field_get:test.People.friends)
  return _internal_friends(index);
}
inline std::string* People::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:test.People.friends)
  return friends_.Mutable(index);
}
inline void People::set_friends(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:test.People.friends)
  friends_.Mutable(index)->assign(value);
}
inline void People::set_friends(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:test.People.friends)
  friends_.Mutable(index)->assign(std::move(value));
}
inline void People::set_friends(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friends_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:test.People.friends)
}
inline void People::set_friends(int index, const void* value, size_t size) {
  friends_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:test.People.friends)
}
inline std::string* People::_internal_add_friends() {
  return friends_.Add();
}
inline void People::add_friends(const std::string& value) {
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:test.People.friends)
}
inline void People::add_friends(std::string&& value) {
  friends_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:test.People.friends)
}
inline void People::add_friends(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:test.People.friends)
}
inline void People::add_friends(const void* value, size_t size) {
  friends_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:test.People.friends)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
People::friends() const {
  // @@protoc_insertion_point(field_list:test.People.friends)
  return friends_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
People::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:test.People.friends)
  return &friends_;
}

// .test.Profession job = 7;
inline bool People::_internal_has_job() const {
  return this != internal_default_instance() && job_ != nullptr;
}
inline bool People::has_job() const {
  return _internal_has_job();
}
inline void People::clear_job() {
  if (GetArenaNoVirtual() == nullptr && job_ != nullptr) {
    delete job_;
  }
  job_ = nullptr;
}
inline const ::test::Profession& People::_internal_job() const {
  const ::test::Profession* p = job_;
  return p != nullptr ? *p : *reinterpret_cast<const ::test::Profession*>(
      &::test::_Profession_default_instance_);
}
inline const ::test::Profession& People::job() const {
  // @@protoc_insertion_point(field_get:test.People.job)
  return _internal_job();
}
inline ::test::Profession* People::release_job() {
  // @@protoc_insertion_point(field_release:test.People.job)
  
  ::test::Profession* temp = job_;
  job_ = nullptr;
  return temp;
}
inline ::test::Profession* People::_internal_mutable_job() {
  
  if (job_ == nullptr) {
    auto* p = CreateMaybeMessage<::test::Profession>(GetArenaNoVirtual());
    job_ = p;
  }
  return job_;
}
inline ::test::Profession* People::mutable_job() {
  // @@protoc_insertion_point(field_mutable:test.People.job)
  return _internal_mutable_job();
}
inline void People::set_allocated_job(::test::Profession* job) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete job_;
  }
  if (job) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      job = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, job, submessage_arena);
    }
    
  } else {
    
  }
  job_ = job;
  // @@protoc_insertion_point(field_set_allocated:test.People.job)
}

// -------------------------------------------------------------------

// Profession

// bytes job_name = 1;
inline void Profession::clear_job_name() {
  job_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Profession::job_name() const {
  // @@protoc_insertion_point(field_get:test.Profession.job_name)
  return _internal_job_name();
}
inline void Profession::set_job_name(const std::string& value) {
  _internal_set_job_name(value);
  // @@protoc_insertion_point(field_set:test.Profession.job_name)
}
inline std::string* Profession::mutable_job_name() {
  // @@protoc_insertion_point(field_mutable:test.Profession.job_name)
  return _internal_mutable_job_name();
}
inline const std::string& Profession::_internal_job_name() const {
  return job_name_.GetNoArena();
}
inline void Profession::_internal_set_job_name(const std::string& value) {
  
  job_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Profession::set_job_name(std::string&& value) {
  
  job_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:test.Profession.job_name)
}
inline void Profession::set_job_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  job_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.Profession.job_name)
}
inline void Profession::set_job_name(const void* value, size_t size) {
  
  job_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.Profession.job_name)
}
inline std::string* Profession::_internal_mutable_job_name() {
  
  return job_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Profession::release_job_name() {
  // @@protoc_insertion_point(field_release:test.Profession.job_name)
  
  return job_name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Profession::set_allocated_job_name(std::string* job_name) {
  if (job_name != nullptr) {
    
  } else {
    
  }
  job_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), job_name);
  // @@protoc_insertion_point(field_set_allocated:test.Profession.job_name)
}

// int64 salary = 2;
inline void Profession::clear_salary() {
  salary_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Profession::_internal_salary() const {
  return salary_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Profession::salary() const {
  // @@protoc_insertion_point(field_get:test.Profession.salary)
  return _internal_salary();
}
inline void Profession::_internal_set_salary(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  salary_ = value;
}
inline void Profession::set_salary(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_salary(value);
  // @@protoc_insertion_point(field_set:test.Profession.salary)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace test

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::test::People_Hobby> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::test::People_Hobby>() {
  return ::test::People_Hobby_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_2eproto