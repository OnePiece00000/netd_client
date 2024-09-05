#ifndef AIDL_GENERATED_ANDROID_NET_TETHER_STATS_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_TETHER_STATS_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>

namespace android {

namespace net {

class TetherStatsParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)!=std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator<(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)<std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator<=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)<=std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator==(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)==std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator>(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)>std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator>=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex)>=std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  ::std::string iface;
  int64_t rxBytes = {};
  int64_t rxPackets = {};
  int64_t txBytes = {};
  int64_t txPackets = {};
  int32_t ifIndex = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TetherStatsParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_TETHER_STATS_PARCEL_H_
