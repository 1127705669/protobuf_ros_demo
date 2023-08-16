#pragma once

#include <ros/message_traits.h>
#include <ros/serialization.h>
#include "proto/message.pb.h" // 引入 Protocol Buffers 消息头文件

namespace ros {
namespace message_traits {

// 为 Protocol Buffers 消息类型提供 traits
template <>
struct IsMessage<test::ShortMessage> : TrueType {};

// 提供获取消息名称的函数
template <>
struct MD5Sum<test::ShortMessage> {
    static const char* value() { return "d41d8cd98f00b204e9800998ecf8427e"; }
    static const char* value(const test::ShortMessage&) { return value(); }
};

// 提供获取消息数据类型的函数
template <>
struct DataType<test::ShortMessage> {
    static const char* value() { return "test::ShortMessage"; }
    static const char* value(const test::ShortMessage&) { return value(); }
};

// 提供获取消息数据的函数
template <>
struct Definition<test::ShortMessage> {
    static const char* value() { return ""; }
    static const char* value(const test::ShortMessage&) { return value(); }
};

}  // namespace message_traits
}  // namespace ros

namespace ros
{
namespace serialization
{
namespace mt = message_traits;
namespace mpl = boost::mpl;

/**
 * \brief Templated serialization class.  Default implementation provides backwards compatibility with
 * old message types.
 *
 * Specializing the Serializer class is the only thing you need to do to get the ROS serialization system
 * to work with a type.
 */
template<>
struct Serializer<test::ShortMessage>
{
  /**
   * \brief Write an object to the stream.  Normally the stream passed in here will be a ros::serialization::OStream
   */
  template<typename Stream>
  inline static void write(Stream& stream, const test::ShortMessage& t)
  {
    uint32_t size = t.ByteSizeLong();
    uint8_t buffer[size];
    t.SerializeToArray(buffer, size);
    stream.advance(size);
    memcpy(stream.getData(), buffer, size);
  }

  /**
   * \brief Read an object from the stream.  Normally the stream passed in here will be a ros::serialization::IStream
   */
  template<typename Stream>
  inline static void read(Stream& stream, test::ShortMessage& t)
  {
    uint32_t size = stream.getLength();
    uint8_t buffer[size];
    memcpy(buffer, stream.getData(), size);
    t.ParseFromArray(buffer, size);
    stream.advance(size);
  }

  /**
   * \brief Determine the serialized length of an object.
   */
  inline static uint32_t serializedLength(const test::ShortMessage& t)
  {
    return t.ByteSizeLong();
  }
};

}  // namespace serialization
}  // namespace ros