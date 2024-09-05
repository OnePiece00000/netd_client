#ifndef AIDL_GENERATED_ANDROID_NET_MARK_MASK_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_MARK_MASK_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace net {

class MarkMaskParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)!=std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator<(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)<std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator<=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)<=std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator==(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)==std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator>(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)>std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator>=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask)>=std::tie(rhs.mark, rhs.mask);
  }
  int32_t mark = {};
  int32_t mask = {};
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class MarkMaskParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_MARK_MASK_PARCEL_H_
