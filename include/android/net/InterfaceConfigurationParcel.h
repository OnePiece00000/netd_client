#ifndef AIDL_GENERATED_ANDROID_NET_INTERFACE_CONFIGURATION_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_INTERFACE_CONFIGURATION_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace android {

namespace net {

class InterfaceConfigurationParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)!=std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator<(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)<std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator<=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)<=std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator==(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)==std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator>(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)>std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator>=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags)>=std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  ::std::string ifName;
  ::std::string hwAddr;
  ::std::string ipv4Addr;
  int32_t prefixLength = {};
  ::std::vector<::std::string> flags;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class InterfaceConfigurationParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_INTERFACE_CONFIGURATION_PARCEL_H_
