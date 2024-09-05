#ifndef AIDL_GENERATED_ANDROID_NET_ROUTE_INFO_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_ROUTE_INFO_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>

namespace android {

namespace net {

class RouteInfoParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)!=std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator<(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)<std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator<=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)<=std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator==(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)==std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator>(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)>std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator>=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu)>=std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  ::std::string destination;
  ::std::string ifName;
  ::std::string nextHop;
  int32_t mtu = {};
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class RouteInfoParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_ROUTE_INFO_PARCEL_H_
