#include <android/net/INetd.h>
#include <android/net/BpNetd.h>

namespace android {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(Netd, "android.net.INetd")

const ::android::String16& INetd::IPSEC_INTERFACE_PREFIX() {
  static const ::android::String16 value(::android::String16("ipsec"));
  return value;
}

const ::android::String16& INetd::NEXTHOP_NONE() {
  static const ::android::String16 value(::android::String16(""));
  return value;
}

const ::android::String16& INetd::NEXTHOP_UNREACHABLE() {
  static const ::android::String16 value(::android::String16("unreachable"));
  return value;
}

const ::android::String16& INetd::NEXTHOP_THROW() {
  static const ::android::String16 value(::android::String16("throw"));
  return value;
}

const ::android::String16& INetd::IF_STATE_UP() {
  static const ::android::String16 value(::android::String16("up"));
  return value;
}

const ::android::String16& INetd::IF_STATE_DOWN() {
  static const ::android::String16 value(::android::String16("down"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_BROADCAST() {
  static const ::android::String16 value(::android::String16("broadcast"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_LOOPBACK() {
  static const ::android::String16 value(::android::String16("loopback"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_POINTOPOINT() {
  static const ::android::String16 value(::android::String16("point-to-point"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_RUNNING() {
  static const ::android::String16 value(::android::String16("running"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_MULTICAST() {
  static const ::android::String16 value(::android::String16("multicast"));
  return value;
}

}  // namespace net

}  // namespace android
#include <android/net/BpNetd.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

BpNetd::BpNetd(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<INetd>(_aidl_impl){
}

std::function<void(const Json::Value&)> BpNetd::logFunc;

::android::binder::Status BpNetd::isAlive(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* isAlive */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->isAlive(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("isAlive");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallReplaceUidChain(const ::std::string& chainName, bool isWhitelist, const ::std::vector<int32_t>& uids, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "chainName";
      _log_arg_element["value"] = Json::Value(chainName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "isWhitelist";
      _log_arg_element["value"] = Json::Value(isWhitelist? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(chainName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(isWhitelist);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* firewallReplaceUidChain */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallReplaceUidChain(chainName, isWhitelist, uids, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallReplaceUidChain");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthEnableDataSaver(bool enable, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "enable";
      _log_arg_element["value"] = Json::Value(enable? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 2 /* bandwidthEnableDataSaver */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthEnableDataSaver(enable, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthEnableDataSaver");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCreatePhysical(int32_t netId, int32_t permission) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "permission";
      _log_arg_element["value"] = Json::Value(permission);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 3 /* networkCreatePhysical */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCreatePhysical(netId, permission);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkCreatePhysical");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCreateVpn(int32_t netId, bool secure) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "secure";
      _log_arg_element["value"] = Json::Value(secure? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(secure);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 4 /* networkCreateVpn */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCreateVpn(netId, secure);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkCreateVpn");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkDestroy(int32_t netId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 5 /* networkDestroy */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkDestroy(netId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkDestroy");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddInterface(int32_t netId, const ::std::string& iface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "iface";
      _log_arg_element["value"] = Json::Value(iface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(iface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 6 /* networkAddInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddInterface(netId, iface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkAddInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveInterface(int32_t netId, const ::std::string& iface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "iface";
      _log_arg_element["value"] = Json::Value(iface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(iface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 7 /* networkRemoveInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveInterface(netId, iface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRemoveInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 8 /* networkAddUidRanges */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddUidRanges(netId, uidRanges);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkAddUidRanges");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 9 /* networkRemoveUidRanges */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveUidRanges(netId, uidRanges);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRemoveUidRanges");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRejectNonSecureVpn(bool add, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "add";
      _log_arg_element["value"] = Json::Value(add? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(add);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 10 /* networkRejectNonSecureVpn */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRejectNonSecureVpn(add, uidRanges);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRejectNonSecureVpn");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::socketDestroy(const ::std::vector<::android::net::UidRangeParcel>& uidRanges, const ::std::vector<int32_t>& exemptUids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "exemptUids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: exemptUids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(exemptUids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 11 /* socketDestroy */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->socketDestroy(uidRanges, exemptUids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("socketDestroy");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherApplyDnsInterfaces(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 12 /* tetherApplyDnsInterfaces */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherApplyDnsInterfaces(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherApplyDnsInterfaces");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 13 /* tetherGetStats */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherGetStats(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherGetStats");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceAddAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "addrString";
      _log_arg_element["value"] = Json::Value(addrString);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "prefixLength";
      _log_arg_element["value"] = Json::Value(prefixLength);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addrString);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(prefixLength);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 14 /* interfaceAddAddress */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceAddAddress(ifName, addrString, prefixLength);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceAddAddress");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceDelAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "addrString";
      _log_arg_element["value"] = Json::Value(addrString);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "prefixLength";
      _log_arg_element["value"] = Json::Value(prefixLength);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addrString);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(prefixLength);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 15 /* interfaceDelAddress */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceDelAddress(ifName, addrString, prefixLength);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceDelAddress");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ipversion";
      _log_arg_element["value"] = Json::Value(ipversion);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "which";
      _log_arg_element["value"] = Json::Value(which);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifname";
      _log_arg_element["value"] = Json::Value(ifname);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "parameter";
      _log_arg_element["value"] = Json::Value(parameter);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ipversion);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(which);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifname);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(parameter);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 16 /* getProcSysNet */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getProcSysNet(ipversion, which, ifname, parameter, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8FromUtf16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("getProcSysNet");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return);
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, const ::std::string& value) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ipversion";
      _log_arg_element["value"] = Json::Value(ipversion);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "which";
      _log_arg_element["value"] = Json::Value(which);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifname";
      _log_arg_element["value"] = Json::Value(ifname);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "parameter";
      _log_arg_element["value"] = Json::Value(parameter);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "value";
      _log_arg_element["value"] = Json::Value(value);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ipversion);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(which);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifname);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(parameter);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(value);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 17 /* setProcSysNet */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setProcSysNet(ipversion, which, ifname, parameter, value);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("setProcSysNet");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecSetEncapSocketOwner(const ::android::os::ParcelFileDescriptor& socket, int32_t newUid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "newUid";
      _log_arg_element["value"] = Json::Value(newUid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(newUid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 18 /* ipSecSetEncapSocketOwner */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecSetEncapSocketOwner(socket, newUid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecSetEncapSocketOwner");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAllocateSpi(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "sourceAddress";
      _log_arg_element["value"] = Json::Value(sourceAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destinationAddress";
      _log_arg_element["value"] = Json::Value(destinationAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 19 /* ipSecAllocateSpi */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAllocateSpi(transformId, sourceAddress, destinationAddress, spi, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecAllocateSpi");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return);
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddSecurityAssociation(int32_t transformId, int32_t mode, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t underlyingNetId, int32_t spi, int32_t markValue, int32_t markMask, const ::std::string& authAlgo, const ::std::vector<uint8_t>& authKey, int32_t authTruncBits, const ::std::string& cryptAlgo, const ::std::vector<uint8_t>& cryptKey, int32_t cryptTruncBits, const ::std::string& aeadAlgo, const ::std::vector<uint8_t>& aeadKey, int32_t aeadIcvBits, int32_t encapType, int32_t encapLocalPort, int32_t encapRemotePort, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mode";
      _log_arg_element["value"] = Json::Value(mode);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "sourceAddress";
      _log_arg_element["value"] = Json::Value(sourceAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destinationAddress";
      _log_arg_element["value"] = Json::Value(destinationAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "underlyingNetId";
      _log_arg_element["value"] = Json::Value(underlyingNetId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markValue";
      _log_arg_element["value"] = Json::Value(markValue);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markMask";
      _log_arg_element["value"] = Json::Value(markMask);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "authAlgo";
      _log_arg_element["value"] = Json::Value(authAlgo);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "authKey";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: authKey) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "authTruncBits";
      _log_arg_element["value"] = Json::Value(authTruncBits);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "cryptAlgo";
      _log_arg_element["value"] = Json::Value(cryptAlgo);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "cryptKey";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: cryptKey) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "cryptTruncBits";
      _log_arg_element["value"] = Json::Value(cryptTruncBits);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "aeadAlgo";
      _log_arg_element["value"] = Json::Value(aeadAlgo);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "aeadKey";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: aeadKey) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "aeadIcvBits";
      _log_arg_element["value"] = Json::Value(aeadIcvBits);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "encapType";
      _log_arg_element["value"] = Json::Value(encapType);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "encapLocalPort";
      _log_arg_element["value"] = Json::Value(encapLocalPort);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "encapRemotePort";
      _log_arg_element["value"] = Json::Value(encapRemotePort);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(underlyingNetId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(authAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(authKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(authTruncBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(cryptAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(cryptKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(cryptTruncBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(aeadAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(aeadKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(aeadIcvBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapType);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapLocalPort);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapRemotePort);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 20 /* ipSecAddSecurityAssociation */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddSecurityAssociation(transformId, mode, sourceAddress, destinationAddress, underlyingNetId, spi, markValue, markMask, authAlgo, authKey, authTruncBits, cryptAlgo, cryptKey, cryptTruncBits, aeadAlgo, aeadKey, aeadIcvBits, encapType, encapLocalPort, encapRemotePort, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecAddSecurityAssociation");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecDeleteSecurityAssociation(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "sourceAddress";
      _log_arg_element["value"] = Json::Value(sourceAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destinationAddress";
      _log_arg_element["value"] = Json::Value(destinationAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markValue";
      _log_arg_element["value"] = Json::Value(markValue);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markMask";
      _log_arg_element["value"] = Json::Value(markMask);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 21 /* ipSecDeleteSecurityAssociation */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecDeleteSecurityAssociation(transformId, sourceAddress, destinationAddress, spi, markValue, markMask, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecDeleteSecurityAssociation");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecApplyTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket, int32_t transformId, int32_t direction, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "direction";
      _log_arg_element["value"] = Json::Value(direction);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "sourceAddress";
      _log_arg_element["value"] = Json::Value(sourceAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destinationAddress";
      _log_arg_element["value"] = Json::Value(destinationAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 22 /* ipSecApplyTransportModeTransform */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecApplyTransportModeTransform(socket, transformId, direction, sourceAddress, destinationAddress, spi);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecApplyTransportModeTransform");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecRemoveTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 23 /* ipSecRemoveTransportModeTransform */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecRemoveTransportModeTransform(socket);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecRemoveTransportModeTransform");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "selAddrFamily";
      _log_arg_element["value"] = Json::Value(selAddrFamily);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "direction";
      _log_arg_element["value"] = Json::Value(direction);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "tmplSrcAddress";
      _log_arg_element["value"] = Json::Value(tmplSrcAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "tmplDstAddress";
      _log_arg_element["value"] = Json::Value(tmplDstAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markValue";
      _log_arg_element["value"] = Json::Value(markValue);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markMask";
      _log_arg_element["value"] = Json::Value(markMask);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplSrcAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplDstAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 24 /* ipSecAddSecurityPolicy */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecAddSecurityPolicy");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecUpdateSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "selAddrFamily";
      _log_arg_element["value"] = Json::Value(selAddrFamily);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "direction";
      _log_arg_element["value"] = Json::Value(direction);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "tmplSrcAddress";
      _log_arg_element["value"] = Json::Value(tmplSrcAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "tmplDstAddress";
      _log_arg_element["value"] = Json::Value(tmplDstAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "spi";
      _log_arg_element["value"] = Json::Value(spi);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markValue";
      _log_arg_element["value"] = Json::Value(markValue);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markMask";
      _log_arg_element["value"] = Json::Value(markMask);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplSrcAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplDstAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 25 /* ipSecUpdateSecurityPolicy */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecUpdateSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecUpdateSecurityPolicy");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecDeleteSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "transformId";
      _log_arg_element["value"] = Json::Value(transformId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "selAddrFamily";
      _log_arg_element["value"] = Json::Value(selAddrFamily);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "direction";
      _log_arg_element["value"] = Json::Value(direction);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markValue";
      _log_arg_element["value"] = Json::Value(markValue);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "markMask";
      _log_arg_element["value"] = Json::Value(markMask);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 26 /* ipSecDeleteSecurityPolicy */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecDeleteSecurityPolicy(transformId, selAddrFamily, direction, markValue, markMask, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecDeleteSecurityPolicy");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "deviceName";
      _log_arg_element["value"] = Json::Value(deviceName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "localAddress";
      _log_arg_element["value"] = Json::Value(localAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "remoteAddress";
      _log_arg_element["value"] = Json::Value(remoteAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "iKey";
      _log_arg_element["value"] = Json::Value(iKey);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "oKey";
      _log_arg_element["value"] = Json::Value(oKey);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(localAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(remoteAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(iKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(oKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 27 /* ipSecAddTunnelInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecAddTunnelInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecUpdateTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "deviceName";
      _log_arg_element["value"] = Json::Value(deviceName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "localAddress";
      _log_arg_element["value"] = Json::Value(localAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "remoteAddress";
      _log_arg_element["value"] = Json::Value(remoteAddress);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "iKey";
      _log_arg_element["value"] = Json::Value(iKey);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "oKey";
      _log_arg_element["value"] = Json::Value(oKey);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "interfaceId";
      _log_arg_element["value"] = Json::Value(interfaceId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(localAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(remoteAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(iKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(oKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 28 /* ipSecUpdateTunnelInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecUpdateTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecUpdateTunnelInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecRemoveTunnelInterface(const ::std::string& deviceName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "deviceName";
      _log_arg_element["value"] = Json::Value(deviceName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 29 /* ipSecRemoveTunnelInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecRemoveTunnelInterface(deviceName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipSecRemoveTunnelInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::wakeupAddInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "prefix";
      _log_arg_element["value"] = Json::Value(prefix);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mark";
      _log_arg_element["value"] = Json::Value(mark);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mask";
      _log_arg_element["value"] = Json::Value(mask);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mark);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 30 /* wakeupAddInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->wakeupAddInterface(ifName, prefix, mark, mask);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("wakeupAddInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::wakeupDelInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "prefix";
      _log_arg_element["value"] = Json::Value(prefix);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mark";
      _log_arg_element["value"] = Json::Value(mark);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mask";
      _log_arg_element["value"] = Json::Value(mask);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mark);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 31 /* wakeupDelInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->wakeupDelInterface(ifName, prefix, mark, mask);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("wakeupDelInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setIPv6AddrGenMode(const ::std::string& ifName, int32_t mode) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mode";
      _log_arg_element["value"] = Json::Value(mode);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 32 /* setIPv6AddrGenMode */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setIPv6AddrGenMode(ifName, mode);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("setIPv6AddrGenMode");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::idletimerAddInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "timeout";
      _log_arg_element["value"] = Json::Value(timeout);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "classLabel";
      _log_arg_element["value"] = Json::Value(classLabel);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(timeout);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(classLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 33 /* idletimerAddInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->idletimerAddInterface(ifName, timeout, classLabel);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("idletimerAddInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::idletimerRemoveInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "timeout";
      _log_arg_element["value"] = Json::Value(timeout);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "classLabel";
      _log_arg_element["value"] = Json::Value(classLabel);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(timeout);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(classLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 34 /* idletimerRemoveInterface */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->idletimerRemoveInterface(ifName, timeout, classLabel);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("idletimerRemoveInterface");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::strictUidCleartextPenalty(int32_t uid, int32_t policyPenalty) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "policyPenalty";
      _log_arg_element["value"] = Json::Value(policyPenalty);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(policyPenalty);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 35 /* strictUidCleartextPenalty */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->strictUidCleartextPenalty(uid, policyPenalty);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("strictUidCleartextPenalty");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::clatdStart(const ::std::string& ifName, const ::std::string& nat64Prefix, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "nat64Prefix";
      _log_arg_element["value"] = Json::Value(nat64Prefix);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nat64Prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 36 /* clatdStart */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->clatdStart(ifName, nat64Prefix, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8FromUtf16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("clatdStart");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return);
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::clatdStop(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 37 /* clatdStop */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->clatdStop(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("clatdStop");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdEnabled(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 38 /* ipfwdEnabled */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdEnabled(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdEnabled");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdGetRequesterList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 39 /* ipfwdGetRequesterList */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdGetRequesterList(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdGetRequesterList");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
    for (const auto& v: *_aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdEnableForwarding(const ::std::string& requester) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "requester";
      _log_arg_element["value"] = Json::Value(requester);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(requester);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 40 /* ipfwdEnableForwarding */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdEnableForwarding(requester);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdEnableForwarding");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdDisableForwarding(const ::std::string& requester) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "requester";
      _log_arg_element["value"] = Json::Value(requester);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(requester);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 41 /* ipfwdDisableForwarding */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdDisableForwarding(requester);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdDisableForwarding");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdAddInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "fromIface";
      _log_arg_element["value"] = Json::Value(fromIface);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "toIface";
      _log_arg_element["value"] = Json::Value(toIface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(fromIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(toIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 42 /* ipfwdAddInterfaceForward */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdAddInterfaceForward(fromIface, toIface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdAddInterfaceForward");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdRemoveInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "fromIface";
      _log_arg_element["value"] = Json::Value(fromIface);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "toIface";
      _log_arg_element["value"] = Json::Value(toIface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(fromIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(toIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 43 /* ipfwdRemoveInterfaceForward */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdRemoveInterfaceForward(fromIface, toIface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("ipfwdRemoveInterfaceForward");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetInterfaceQuota(const ::std::string& ifName, int64_t bytes) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "bytes";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(bytes));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 44 /* bandwidthSetInterfaceQuota */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetInterfaceQuota(ifName, bytes);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthSetInterfaceQuota");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveInterfaceQuota(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 45 /* bandwidthRemoveInterfaceQuota */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveInterfaceQuota(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthRemoveInterfaceQuota");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetInterfaceAlert(const ::std::string& ifName, int64_t bytes) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "bytes";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(bytes));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 46 /* bandwidthSetInterfaceAlert */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetInterfaceAlert(ifName, bytes);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthSetInterfaceAlert");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveInterfaceAlert(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 47 /* bandwidthRemoveInterfaceAlert */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveInterfaceAlert(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthRemoveInterfaceAlert");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetGlobalAlert(int64_t bytes) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "bytes";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(bytes));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 48 /* bandwidthSetGlobalAlert */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetGlobalAlert(bytes);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthSetGlobalAlert");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthAddNaughtyApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 49 /* bandwidthAddNaughtyApp */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthAddNaughtyApp(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthAddNaughtyApp");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveNaughtyApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 50 /* bandwidthRemoveNaughtyApp */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveNaughtyApp(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthRemoveNaughtyApp");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthAddNiceApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 51 /* bandwidthAddNiceApp */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthAddNiceApp(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthAddNiceApp");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveNiceApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 52 /* bandwidthRemoveNiceApp */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveNiceApp(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("bandwidthRemoveNiceApp");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStart(const ::std::vector<::std::string>& dhcpRanges) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "dhcpRanges";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: dhcpRanges) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(dhcpRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 53 /* tetherStart */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStart(dhcpRanges);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherStart");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStop() {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 54 /* tetherStop */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStop();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherStop");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherIsEnabled(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 55 /* tetherIsEnabled */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherIsEnabled(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherIsEnabled");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceAdd(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 56 /* tetherInterfaceAdd */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceAdd(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherInterfaceAdd");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceRemove(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 57 /* tetherInterfaceRemove */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceRemove(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherInterfaceRemove");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 58 /* tetherInterfaceList */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceList(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherInterfaceList");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
    for (const auto& v: *_aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherDnsSet(int32_t netId, const ::std::vector<::std::string>& dnsAddrs) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "dnsAddrs";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: dnsAddrs) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(dnsAddrs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 59 /* tetherDnsSet */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherDnsSet(netId, dnsAddrs);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherDnsSet");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherDnsList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 60 /* tetherDnsList */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherDnsList(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherDnsList");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
    for (const auto& v: *_aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destination";
      _log_arg_element["value"] = Json::Value(destination);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "nextHop";
      _log_arg_element["value"] = Json::Value(nextHop);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 61 /* networkAddRoute */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddRoute(netId, ifName, destination, nextHop);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkAddRoute");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destination";
      _log_arg_element["value"] = Json::Value(destination);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "nextHop";
      _log_arg_element["value"] = Json::Value(nextHop);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 62 /* networkRemoveRoute */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveRoute(netId, ifName, destination, nextHop);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRemoveRoute");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destination";
      _log_arg_element["value"] = Json::Value(destination);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "nextHop";
      _log_arg_element["value"] = Json::Value(nextHop);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 63 /* networkAddLegacyRoute */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddLegacyRoute(netId, ifName, destination, nextHop, uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkAddLegacyRoute");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "destination";
      _log_arg_element["value"] = Json::Value(destination);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "nextHop";
      _log_arg_element["value"] = Json::Value(nextHop);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 64 /* networkRemoveLegacyRoute */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveLegacyRoute(netId, ifName, destination, nextHop, uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRemoveLegacyRoute");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkGetDefault(int32_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 65 /* networkGetDefault */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkGetDefault(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkGetDefault");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return);
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetDefault(int32_t netId) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 66 /* networkSetDefault */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetDefault(netId);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkSetDefault");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkClearDefault() {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 67 /* networkClearDefault */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkClearDefault();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkClearDefault");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetPermissionForNetwork(int32_t netId, int32_t permission) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "permission";
      _log_arg_element["value"] = Json::Value(permission);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 68 /* networkSetPermissionForNetwork */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetPermissionForNetwork(netId, permission);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkSetPermissionForNetwork");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetPermissionForUser(int32_t permission, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "permission";
      _log_arg_element["value"] = Json::Value(permission);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 69 /* networkSetPermissionForUser */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetPermissionForUser(permission, uids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkSetPermissionForUser");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkClearPermissionForUser(const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 70 /* networkClearPermissionForUser */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkClearPermissionForUser(uids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkClearPermissionForUser");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::trafficSetNetPermForUids(int32_t permission, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "permission";
      _log_arg_element["value"] = Json::Value(permission);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 71 /* trafficSetNetPermForUids */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->trafficSetNetPermForUids(permission, uids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("trafficSetNetPermForUids");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetProtectAllow(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 72 /* networkSetProtectAllow */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetProtectAllow(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkSetProtectAllow");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetProtectDeny(int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 73 /* networkSetProtectDeny */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetProtectDeny(uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkSetProtectDeny");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCanProtect(int32_t uid, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 74 /* networkCanProtect */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCanProtect(uid, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkCanProtect");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(*_aidl_return? "true" : "false");
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetFirewallType(int32_t firewalltype) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "firewalltype";
      _log_arg_element["value"] = Json::Value(firewalltype);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(firewalltype);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 75 /* firewallSetFirewallType */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetFirewallType(firewalltype);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallSetFirewallType");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetInterfaceRule(const ::std::string& ifName, int32_t firewallRule) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "firewallRule";
      _log_arg_element["value"] = Json::Value(firewallRule);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(firewallRule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 76 /* firewallSetInterfaceRule */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetInterfaceRule(ifName, firewallRule);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallSetInterfaceRule");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetUidRule(int32_t childChain, int32_t uid, int32_t firewallRule) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "childChain";
      _log_arg_element["value"] = Json::Value(childChain);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "firewallRule";
      _log_arg_element["value"] = Json::Value(firewallRule);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(childChain);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(firewallRule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 77 /* firewallSetUidRule */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetUidRule(childChain, uid, firewallRule);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallSetUidRule");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallEnableChildChain(int32_t childChain, bool enable) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "childChain";
      _log_arg_element["value"] = Json::Value(childChain);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "enable";
      _log_arg_element["value"] = Json::Value(enable? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(childChain);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 78 /* firewallEnableChildChain */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallEnableChildChain(childChain, enable);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallEnableChildChain");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceGetList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 79 /* interfaceGetList */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceGetList(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceGetList");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
    for (const auto& v: *_aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceGetCfg(const ::std::string& ifName, ::android::net::InterfaceConfigurationParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 80 /* interfaceGetCfg */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceGetCfg(ifName, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceGetCfg");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetCfg(const ::android::net::InterfaceConfigurationParcel& cfg) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(cfg);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 81 /* interfaceSetCfg */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetCfg(cfg);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceSetCfg");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetIPv6PrivacyExtensions(const ::std::string& ifName, bool enable) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "enable";
      _log_arg_element["value"] = Json::Value(enable? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 82 /* interfaceSetIPv6PrivacyExtensions */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetIPv6PrivacyExtensions(ifName, enable);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceSetIPv6PrivacyExtensions");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceClearAddrs(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 83 /* interfaceClearAddrs */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceClearAddrs(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceClearAddrs");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetEnableIPv6(const ::std::string& ifName, bool enable) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "enable";
      _log_arg_element["value"] = Json::Value(enable? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 84 /* interfaceSetEnableIPv6 */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetEnableIPv6(ifName, enable);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceSetEnableIPv6");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetMtu(const ::std::string& ifName, int32_t mtu) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "mtu";
      _log_arg_element["value"] = Json::Value(mtu);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mtu);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 85 /* interfaceSetMtu */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetMtu(ifName, mtu);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("interfaceSetMtu");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherAddForward(const ::std::string& intIface, const ::std::string& extIface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "intIface";
      _log_arg_element["value"] = Json::Value(intIface);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "extIface";
      _log_arg_element["value"] = Json::Value(extIface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(intIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(extIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 86 /* tetherAddForward */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherAddForward(intIface, extIface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherAddForward");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherRemoveForward(const ::std::string& intIface, const ::std::string& extIface) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "intIface";
      _log_arg_element["value"] = Json::Value(intIface);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "extIface";
      _log_arg_element["value"] = Json::Value(extIface);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(intIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(extIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 87 /* tetherRemoveForward */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherRemoveForward(intIface, extIface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherRemoveForward");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setTcpRWmemorySize(const ::std::string& rmemValues, const ::std::string& wmemValues) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "rmemValues";
      _log_arg_element["value"] = Json::Value(rmemValues);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "wmemValues";
      _log_arg_element["value"] = Json::Value(wmemValues);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(rmemValues);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(wmemValues);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 88 /* setTcpRWmemorySize */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setTcpRWmemorySize(rmemValues, wmemValues);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("setTcpRWmemorySize");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::registerUnsolicitedEventListener(const ::android::sp<::android::net::INetdUnsolicitedEventListener>& listener) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::INetdUnsolicitedEventListener::asBinder(listener));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 89 /* registerUnsolicitedEventListener */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->registerUnsolicitedEventListener(listener);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("registerUnsolicitedEventListener");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallAddUidInterfaceRules(const ::std::string& ifName, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 90 /* firewallAddUidInterfaceRules */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallAddUidInterfaceRules(ifName, uids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallAddUidInterfaceRules");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallRemoveUidInterfaceRules(const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uids";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: uids) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 91 /* firewallRemoveUidInterfaceRules */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallRemoveUidInterfaceRules(uids);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("firewallRemoveUidInterfaceRules");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::trafficSwapActiveStatsMap() {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 92 /* trafficSwapActiveStatsMap */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->trafficSwapActiveStatsMap();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("trafficSwapActiveStatsMap");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getOemNetd(::android::sp<::android::IBinder>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 93 /* getOemNetd */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getOemNetd(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readStrongBinder(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("getOemNetd");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStartWithConfiguration(const ::android::net::TetherConfigParcel& config) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(config);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 94 /* tetherStartWithConfiguration */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStartWithConfiguration(config);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherStartWithConfiguration");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getFwmarkForNetwork(int32_t netId, ::android::net::MarkMaskParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 95 /* getFwmarkForNetwork */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getFwmarkForNetwork(netId, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("getFwmarkForNetwork");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 96 /* networkAddRouteParcel */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddRouteParcel(netId, routeInfo);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkAddRouteParcel");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkUpdateRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 97 /* networkUpdateRouteParcel */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkUpdateRouteParcel(netId, routeInfo);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkUpdateRouteParcel");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "netId";
      _log_arg_element["value"] = Json::Value(netId);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 98 /* networkRemoveRouteParcel */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveRouteParcel(netId, routeInfo);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("networkRemoveRouteParcel");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadRuleAdd(const ::android::net::TetherOffloadRuleParcel& rule) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(rule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 99 /* tetherOffloadRuleAdd */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadRuleAdd(rule);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherOffloadRuleAdd");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadRuleRemove(const ::android::net::TetherOffloadRuleParcel& rule) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(rule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 100 /* tetherOffloadRuleRemove */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadRuleRemove(rule);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherOffloadRuleRemove");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 101 /* tetherOffloadGetStats */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadGetStats(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherOffloadGetStats");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadSetInterfaceQuota(int32_t ifIndex, int64_t quotaBytes) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifIndex";
      _log_arg_element["value"] = Json::Value(ifIndex);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "quotaBytes";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(quotaBytes));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ifIndex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(quotaBytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 102 /* tetherOffloadSetInterfaceQuota */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadSetInterfaceQuota(ifIndex, quotaBytes);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherOffloadSetInterfaceQuota");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadGetAndClearStats(int32_t ifIndex, ::android::net::TetherStatsParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetd::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifIndex";
      _log_arg_element["value"] = Json::Value(ifIndex);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ifIndex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 103 /* tetherOffloadGetAndClearStats */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadGetAndClearStats(ifIndex, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetd");
    _log_transaction["method_name"] = Json::Value("tetherOffloadGetAndClearStats");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetd::logFunc(_log_transaction);
  }
  return _aidl_status;
}

int32_t BpNetd::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 16777214 /* getInterfaceVersion */, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        cached_version_ = reply.readInt32();
      }
    }
  }
  return cached_version_;
}

std::string BpNetd::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 16777213 /* getInterfaceHash */, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        reply.readUtf8FromUtf16(&cached_hash_);
      }
    }
  }
  return cached_hash_;
}

}  // namespace net

}  // namespace android
#include <android/net/BnNetd.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

BnNetd::BnNetd()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnNetd::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* isAlive */:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(isAlive(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("isAlive");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* firewallReplaceUidChain */:
  {
    ::std::string in_chainName;
    bool in_isWhitelist;
    ::std::vector<int32_t> in_uids;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_chainName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_isWhitelist);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_chainName";
        _log_arg_element["value"] = Json::Value(in_chainName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_isWhitelist";
        _log_arg_element["value"] = Json::Value(in_isWhitelist? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallReplaceUidChain(in_chainName, in_isWhitelist, in_uids, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallReplaceUidChain");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 2 /* bandwidthEnableDataSaver */:
  {
    bool in_enable;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_enable";
        _log_arg_element["value"] = Json::Value(in_enable? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthEnableDataSaver(in_enable, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthEnableDataSaver");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 3 /* networkCreatePhysical */:
  {
    int32_t in_netId;
    int32_t in_permission;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_permission";
        _log_arg_element["value"] = Json::Value(in_permission);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCreatePhysical(in_netId, in_permission));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkCreatePhysical");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 4 /* networkCreateVpn */:
  {
    int32_t in_netId;
    bool in_secure;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_secure);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_secure";
        _log_arg_element["value"] = Json::Value(in_secure? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCreateVpn(in_netId, in_secure));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkCreateVpn");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 5 /* networkDestroy */:
  {
    int32_t in_netId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkDestroy(in_netId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkDestroy");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 6 /* networkAddInterface */:
  {
    int32_t in_netId;
    ::std::string in_iface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_iface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_iface";
        _log_arg_element["value"] = Json::Value(in_iface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddInterface(in_netId, in_iface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkAddInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 7 /* networkRemoveInterface */:
  {
    int32_t in_netId;
    ::std::string in_iface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_iface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_iface";
        _log_arg_element["value"] = Json::Value(in_iface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveInterface(in_netId, in_iface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRemoveInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 8 /* networkAddUidRanges */:
  {
    int32_t in_netId;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddUidRanges(in_netId, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkAddUidRanges");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 9 /* networkRemoveUidRanges */:
  {
    int32_t in_netId;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveUidRanges(in_netId, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRemoveUidRanges");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 10 /* networkRejectNonSecureVpn */:
  {
    bool in_add;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_add);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_add";
        _log_arg_element["value"] = Json::Value(in_add? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRejectNonSecureVpn(in_add, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRejectNonSecureVpn");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 11 /* socketDestroy */:
  {
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    ::std::vector<int32_t> in_exemptUids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_exemptUids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_exemptUids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_exemptUids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(socketDestroy(in_uidRanges, in_exemptUids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("socketDestroy");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 12 /* tetherApplyDnsInterfaces */:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherApplyDnsInterfaces(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherApplyDnsInterfaces");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 13 /* tetherGetStats */:
  {
    ::std::vector<::android::net::TetherStatsParcel> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherGetStats(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherGetStats");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 14 /* interfaceAddAddress */:
  {
    ::std::string in_ifName;
    ::std::string in_addrString;
    int32_t in_prefixLength;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addrString);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_prefixLength);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_addrString";
        _log_arg_element["value"] = Json::Value(in_addrString);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_prefixLength";
        _log_arg_element["value"] = Json::Value(in_prefixLength);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceAddAddress(in_ifName, in_addrString, in_prefixLength));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceAddAddress");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 15 /* interfaceDelAddress */:
  {
    ::std::string in_ifName;
    ::std::string in_addrString;
    int32_t in_prefixLength;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addrString);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_prefixLength);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_addrString";
        _log_arg_element["value"] = Json::Value(in_addrString);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_prefixLength";
        _log_arg_element["value"] = Json::Value(in_prefixLength);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceDelAddress(in_ifName, in_addrString, in_prefixLength));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceDelAddress");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 16 /* getProcSysNet */:
  {
    int32_t in_ipversion;
    int32_t in_which;
    ::std::string in_ifname;
    ::std::string in_parameter;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ipversion);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_which);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifname);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_parameter);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ipversion";
        _log_arg_element["value"] = Json::Value(in_ipversion);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_which";
        _log_arg_element["value"] = Json::Value(in_which);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifname";
        _log_arg_element["value"] = Json::Value(in_ifname);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_parameter";
        _log_arg_element["value"] = Json::Value(in_parameter);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getProcSysNet(in_ipversion, in_which, in_ifname, in_parameter, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("getProcSysNet");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return);
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8AsUtf16(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 17 /* setProcSysNet */:
  {
    int32_t in_ipversion;
    int32_t in_which;
    ::std::string in_ifname;
    ::std::string in_parameter;
    ::std::string in_value;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ipversion);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_which);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifname);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_parameter);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_value);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ipversion";
        _log_arg_element["value"] = Json::Value(in_ipversion);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_which";
        _log_arg_element["value"] = Json::Value(in_which);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifname";
        _log_arg_element["value"] = Json::Value(in_ifname);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_parameter";
        _log_arg_element["value"] = Json::Value(in_parameter);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_value";
        _log_arg_element["value"] = Json::Value(in_value);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setProcSysNet(in_ipversion, in_which, in_ifname, in_parameter, in_value));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("setProcSysNet");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 18 /* ipSecSetEncapSocketOwner */:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    int32_t in_newUid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_newUid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_newUid";
        _log_arg_element["value"] = Json::Value(in_newUid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecSetEncapSocketOwner(in_socket, in_newUid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecSetEncapSocketOwner");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 19 /* ipSecAllocateSpi */:
  {
    int32_t in_transformId;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    int32_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_sourceAddress";
        _log_arg_element["value"] = Json::Value(in_sourceAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destinationAddress";
        _log_arg_element["value"] = Json::Value(in_destinationAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAllocateSpi(in_transformId, in_sourceAddress, in_destinationAddress, in_spi, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecAllocateSpi");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return);
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 20 /* ipSecAddSecurityAssociation */:
  {
    int32_t in_transformId;
    int32_t in_mode;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_underlyingNetId;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    ::std::string in_authAlgo;
    ::std::vector<uint8_t> in_authKey;
    int32_t in_authTruncBits;
    ::std::string in_cryptAlgo;
    ::std::vector<uint8_t> in_cryptKey;
    int32_t in_cryptTruncBits;
    ::std::string in_aeadAlgo;
    ::std::vector<uint8_t> in_aeadKey;
    int32_t in_aeadIcvBits;
    int32_t in_encapType;
    int32_t in_encapLocalPort;
    int32_t in_encapRemotePort;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_underlyingNetId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_authAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_authKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_authTruncBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_cryptAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_cryptKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_cryptTruncBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_aeadAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_aeadKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_aeadIcvBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapType);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapLocalPort);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapRemotePort);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mode";
        _log_arg_element["value"] = Json::Value(in_mode);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_sourceAddress";
        _log_arg_element["value"] = Json::Value(in_sourceAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destinationAddress";
        _log_arg_element["value"] = Json::Value(in_destinationAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_underlyingNetId";
        _log_arg_element["value"] = Json::Value(in_underlyingNetId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markValue";
        _log_arg_element["value"] = Json::Value(in_markValue);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markMask";
        _log_arg_element["value"] = Json::Value(in_markMask);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_authAlgo";
        _log_arg_element["value"] = Json::Value(in_authAlgo);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_authKey";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_authKey) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_authTruncBits";
        _log_arg_element["value"] = Json::Value(in_authTruncBits);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_cryptAlgo";
        _log_arg_element["value"] = Json::Value(in_cryptAlgo);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_cryptKey";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_cryptKey) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_cryptTruncBits";
        _log_arg_element["value"] = Json::Value(in_cryptTruncBits);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_aeadAlgo";
        _log_arg_element["value"] = Json::Value(in_aeadAlgo);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_aeadKey";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_aeadKey) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_aeadIcvBits";
        _log_arg_element["value"] = Json::Value(in_aeadIcvBits);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_encapType";
        _log_arg_element["value"] = Json::Value(in_encapType);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_encapLocalPort";
        _log_arg_element["value"] = Json::Value(in_encapLocalPort);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_encapRemotePort";
        _log_arg_element["value"] = Json::Value(in_encapRemotePort);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddSecurityAssociation(in_transformId, in_mode, in_sourceAddress, in_destinationAddress, in_underlyingNetId, in_spi, in_markValue, in_markMask, in_authAlgo, in_authKey, in_authTruncBits, in_cryptAlgo, in_cryptKey, in_cryptTruncBits, in_aeadAlgo, in_aeadKey, in_aeadIcvBits, in_encapType, in_encapLocalPort, in_encapRemotePort, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecAddSecurityAssociation");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 21 /* ipSecDeleteSecurityAssociation */:
  {
    int32_t in_transformId;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_sourceAddress";
        _log_arg_element["value"] = Json::Value(in_sourceAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destinationAddress";
        _log_arg_element["value"] = Json::Value(in_destinationAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markValue";
        _log_arg_element["value"] = Json::Value(in_markValue);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markMask";
        _log_arg_element["value"] = Json::Value(in_markMask);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecDeleteSecurityAssociation(in_transformId, in_sourceAddress, in_destinationAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecDeleteSecurityAssociation");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 22 /* ipSecApplyTransportModeTransform */:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    int32_t in_transformId;
    int32_t in_direction;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_direction";
        _log_arg_element["value"] = Json::Value(in_direction);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_sourceAddress";
        _log_arg_element["value"] = Json::Value(in_sourceAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destinationAddress";
        _log_arg_element["value"] = Json::Value(in_destinationAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecApplyTransportModeTransform(in_socket, in_transformId, in_direction, in_sourceAddress, in_destinationAddress, in_spi));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecApplyTransportModeTransform");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 23 /* ipSecRemoveTransportModeTransform */:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecRemoveTransportModeTransform(in_socket));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecRemoveTransportModeTransform");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 24 /* ipSecAddSecurityPolicy */:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    ::std::string in_tmplSrcAddress;
    ::std::string in_tmplDstAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplSrcAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplDstAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_selAddrFamily";
        _log_arg_element["value"] = Json::Value(in_selAddrFamily);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_direction";
        _log_arg_element["value"] = Json::Value(in_direction);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_tmplSrcAddress";
        _log_arg_element["value"] = Json::Value(in_tmplSrcAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_tmplDstAddress";
        _log_arg_element["value"] = Json::Value(in_tmplDstAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markValue";
        _log_arg_element["value"] = Json::Value(in_markValue);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markMask";
        _log_arg_element["value"] = Json::Value(in_markMask);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_tmplSrcAddress, in_tmplDstAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecAddSecurityPolicy");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 25 /* ipSecUpdateSecurityPolicy */:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    ::std::string in_tmplSrcAddress;
    ::std::string in_tmplDstAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplSrcAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplDstAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_selAddrFamily";
        _log_arg_element["value"] = Json::Value(in_selAddrFamily);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_direction";
        _log_arg_element["value"] = Json::Value(in_direction);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_tmplSrcAddress";
        _log_arg_element["value"] = Json::Value(in_tmplSrcAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_tmplDstAddress";
        _log_arg_element["value"] = Json::Value(in_tmplDstAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_spi";
        _log_arg_element["value"] = Json::Value(in_spi);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markValue";
        _log_arg_element["value"] = Json::Value(in_markValue);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markMask";
        _log_arg_element["value"] = Json::Value(in_markMask);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecUpdateSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_tmplSrcAddress, in_tmplDstAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecUpdateSecurityPolicy");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 26 /* ipSecDeleteSecurityPolicy */:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_transformId";
        _log_arg_element["value"] = Json::Value(in_transformId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_selAddrFamily";
        _log_arg_element["value"] = Json::Value(in_selAddrFamily);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_direction";
        _log_arg_element["value"] = Json::Value(in_direction);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markValue";
        _log_arg_element["value"] = Json::Value(in_markValue);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_markMask";
        _log_arg_element["value"] = Json::Value(in_markMask);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecDeleteSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecDeleteSecurityPolicy");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 27 /* ipSecAddTunnelInterface */:
  {
    ::std::string in_deviceName;
    ::std::string in_localAddress;
    ::std::string in_remoteAddress;
    int32_t in_iKey;
    int32_t in_oKey;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_localAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_remoteAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_iKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_oKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_deviceName";
        _log_arg_element["value"] = Json::Value(in_deviceName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_localAddress";
        _log_arg_element["value"] = Json::Value(in_localAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_remoteAddress";
        _log_arg_element["value"] = Json::Value(in_remoteAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_iKey";
        _log_arg_element["value"] = Json::Value(in_iKey);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_oKey";
        _log_arg_element["value"] = Json::Value(in_oKey);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddTunnelInterface(in_deviceName, in_localAddress, in_remoteAddress, in_iKey, in_oKey, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecAddTunnelInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 28 /* ipSecUpdateTunnelInterface */:
  {
    ::std::string in_deviceName;
    ::std::string in_localAddress;
    ::std::string in_remoteAddress;
    int32_t in_iKey;
    int32_t in_oKey;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_localAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_remoteAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_iKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_oKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_deviceName";
        _log_arg_element["value"] = Json::Value(in_deviceName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_localAddress";
        _log_arg_element["value"] = Json::Value(in_localAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_remoteAddress";
        _log_arg_element["value"] = Json::Value(in_remoteAddress);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_iKey";
        _log_arg_element["value"] = Json::Value(in_iKey);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_oKey";
        _log_arg_element["value"] = Json::Value(in_oKey);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_interfaceId";
        _log_arg_element["value"] = Json::Value(in_interfaceId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecUpdateTunnelInterface(in_deviceName, in_localAddress, in_remoteAddress, in_iKey, in_oKey, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecUpdateTunnelInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 29 /* ipSecRemoveTunnelInterface */:
  {
    ::std::string in_deviceName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_deviceName";
        _log_arg_element["value"] = Json::Value(in_deviceName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecRemoveTunnelInterface(in_deviceName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipSecRemoveTunnelInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 30 /* wakeupAddInterface */:
  {
    ::std::string in_ifName;
    ::std::string in_prefix;
    int32_t in_mark;
    int32_t in_mask;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mark);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_prefix";
        _log_arg_element["value"] = Json::Value(in_prefix);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mark";
        _log_arg_element["value"] = Json::Value(in_mark);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mask";
        _log_arg_element["value"] = Json::Value(in_mask);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(wakeupAddInterface(in_ifName, in_prefix, in_mark, in_mask));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("wakeupAddInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 31 /* wakeupDelInterface */:
  {
    ::std::string in_ifName;
    ::std::string in_prefix;
    int32_t in_mark;
    int32_t in_mask;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mark);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_prefix";
        _log_arg_element["value"] = Json::Value(in_prefix);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mark";
        _log_arg_element["value"] = Json::Value(in_mark);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mask";
        _log_arg_element["value"] = Json::Value(in_mask);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(wakeupDelInterface(in_ifName, in_prefix, in_mark, in_mask));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("wakeupDelInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 32 /* setIPv6AddrGenMode */:
  {
    ::std::string in_ifName;
    int32_t in_mode;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mode";
        _log_arg_element["value"] = Json::Value(in_mode);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setIPv6AddrGenMode(in_ifName, in_mode));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("setIPv6AddrGenMode");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 33 /* idletimerAddInterface */:
  {
    ::std::string in_ifName;
    int32_t in_timeout;
    ::std::string in_classLabel;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timeout);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_classLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_timeout";
        _log_arg_element["value"] = Json::Value(in_timeout);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_classLabel";
        _log_arg_element["value"] = Json::Value(in_classLabel);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(idletimerAddInterface(in_ifName, in_timeout, in_classLabel));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("idletimerAddInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 34 /* idletimerRemoveInterface */:
  {
    ::std::string in_ifName;
    int32_t in_timeout;
    ::std::string in_classLabel;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timeout);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_classLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_timeout";
        _log_arg_element["value"] = Json::Value(in_timeout);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_classLabel";
        _log_arg_element["value"] = Json::Value(in_classLabel);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(idletimerRemoveInterface(in_ifName, in_timeout, in_classLabel));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("idletimerRemoveInterface");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 35 /* strictUidCleartextPenalty */:
  {
    int32_t in_uid;
    int32_t in_policyPenalty;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_policyPenalty);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_policyPenalty";
        _log_arg_element["value"] = Json::Value(in_policyPenalty);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(strictUidCleartextPenalty(in_uid, in_policyPenalty));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("strictUidCleartextPenalty");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 36 /* clatdStart */:
  {
    ::std::string in_ifName;
    ::std::string in_nat64Prefix;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nat64Prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_nat64Prefix";
        _log_arg_element["value"] = Json::Value(in_nat64Prefix);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(clatdStart(in_ifName, in_nat64Prefix, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("clatdStart");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return);
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8AsUtf16(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 37 /* clatdStop */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(clatdStop(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("clatdStop");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 38 /* ipfwdEnabled */:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdEnabled(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdEnabled");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 39 /* ipfwdGetRequesterList */:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdGetRequesterList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdGetRequesterList");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
      for (const auto& v: _aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 40 /* ipfwdEnableForwarding */:
  {
    ::std::string in_requester;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_requester);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_requester";
        _log_arg_element["value"] = Json::Value(in_requester);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdEnableForwarding(in_requester));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdEnableForwarding");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 41 /* ipfwdDisableForwarding */:
  {
    ::std::string in_requester;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_requester);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_requester";
        _log_arg_element["value"] = Json::Value(in_requester);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdDisableForwarding(in_requester));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdDisableForwarding");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 42 /* ipfwdAddInterfaceForward */:
  {
    ::std::string in_fromIface;
    ::std::string in_toIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_fromIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_toIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_fromIface";
        _log_arg_element["value"] = Json::Value(in_fromIface);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_toIface";
        _log_arg_element["value"] = Json::Value(in_toIface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdAddInterfaceForward(in_fromIface, in_toIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdAddInterfaceForward");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 43 /* ipfwdRemoveInterfaceForward */:
  {
    ::std::string in_fromIface;
    ::std::string in_toIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_fromIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_toIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_fromIface";
        _log_arg_element["value"] = Json::Value(in_fromIface);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_toIface";
        _log_arg_element["value"] = Json::Value(in_toIface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdRemoveInterfaceForward(in_fromIface, in_toIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("ipfwdRemoveInterfaceForward");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 44 /* bandwidthSetInterfaceQuota */:
  {
    ::std::string in_ifName;
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_bytes";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_bytes));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetInterfaceQuota(in_ifName, in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthSetInterfaceQuota");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 45 /* bandwidthRemoveInterfaceQuota */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveInterfaceQuota(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthRemoveInterfaceQuota");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 46 /* bandwidthSetInterfaceAlert */:
  {
    ::std::string in_ifName;
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_bytes";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_bytes));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetInterfaceAlert(in_ifName, in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthSetInterfaceAlert");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 47 /* bandwidthRemoveInterfaceAlert */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveInterfaceAlert(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthRemoveInterfaceAlert");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 48 /* bandwidthSetGlobalAlert */:
  {
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_bytes";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_bytes));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetGlobalAlert(in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthSetGlobalAlert");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 49 /* bandwidthAddNaughtyApp */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthAddNaughtyApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthAddNaughtyApp");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 50 /* bandwidthRemoveNaughtyApp */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveNaughtyApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthRemoveNaughtyApp");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 51 /* bandwidthAddNiceApp */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthAddNiceApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthAddNiceApp");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 52 /* bandwidthRemoveNiceApp */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveNiceApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("bandwidthRemoveNiceApp");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 53 /* tetherStart */:
  {
    ::std::vector<::std::string> in_dhcpRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_dhcpRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_dhcpRanges";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_dhcpRanges) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStart(in_dhcpRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherStart");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 54 /* tetherStop */:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStop());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherStop");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 55 /* tetherIsEnabled */:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherIsEnabled(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherIsEnabled");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 56 /* tetherInterfaceAdd */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceAdd(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherInterfaceAdd");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 57 /* tetherInterfaceRemove */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceRemove(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherInterfaceRemove");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 58 /* tetherInterfaceList */:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherInterfaceList");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
      for (const auto& v: _aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 59 /* tetherDnsSet */:
  {
    int32_t in_netId;
    ::std::vector<::std::string> in_dnsAddrs;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_dnsAddrs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_dnsAddrs";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_dnsAddrs) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherDnsSet(in_netId, in_dnsAddrs));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherDnsSet");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 60 /* tetherDnsList */:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherDnsList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherDnsList");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
      for (const auto& v: _aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 61 /* networkAddRoute */:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destination";
        _log_arg_element["value"] = Json::Value(in_destination);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_nextHop";
        _log_arg_element["value"] = Json::Value(in_nextHop);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddRoute(in_netId, in_ifName, in_destination, in_nextHop));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkAddRoute");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 62 /* networkRemoveRoute */:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destination";
        _log_arg_element["value"] = Json::Value(in_destination);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_nextHop";
        _log_arg_element["value"] = Json::Value(in_nextHop);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveRoute(in_netId, in_ifName, in_destination, in_nextHop));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRemoveRoute");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 63 /* networkAddLegacyRoute */:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destination";
        _log_arg_element["value"] = Json::Value(in_destination);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_nextHop";
        _log_arg_element["value"] = Json::Value(in_nextHop);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddLegacyRoute(in_netId, in_ifName, in_destination, in_nextHop, in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkAddLegacyRoute");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 64 /* networkRemoveLegacyRoute */:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_destination";
        _log_arg_element["value"] = Json::Value(in_destination);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_nextHop";
        _log_arg_element["value"] = Json::Value(in_nextHop);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveLegacyRoute(in_netId, in_ifName, in_destination, in_nextHop, in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRemoveLegacyRoute");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 65 /* networkGetDefault */:
  {
    int32_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkGetDefault(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkGetDefault");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return);
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 66 /* networkSetDefault */:
  {
    int32_t in_netId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetDefault(in_netId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkSetDefault");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 67 /* networkClearDefault */:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkClearDefault());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkClearDefault");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 68 /* networkSetPermissionForNetwork */:
  {
    int32_t in_netId;
    int32_t in_permission;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_permission";
        _log_arg_element["value"] = Json::Value(in_permission);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetPermissionForNetwork(in_netId, in_permission));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkSetPermissionForNetwork");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 69 /* networkSetPermissionForUser */:
  {
    int32_t in_permission;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_permission";
        _log_arg_element["value"] = Json::Value(in_permission);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetPermissionForUser(in_permission, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkSetPermissionForUser");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 70 /* networkClearPermissionForUser */:
  {
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkClearPermissionForUser(in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkClearPermissionForUser");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 71 /* trafficSetNetPermForUids */:
  {
    int32_t in_permission;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_permission";
        _log_arg_element["value"] = Json::Value(in_permission);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(trafficSetNetPermForUids(in_permission, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("trafficSetNetPermForUids");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 72 /* networkSetProtectAllow */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetProtectAllow(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkSetProtectAllow");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 73 /* networkSetProtectDeny */:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetProtectDeny(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkSetProtectDeny");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 74 /* networkCanProtect */:
  {
    int32_t in_uid;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCanProtect(in_uid, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkCanProtect");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(_aidl_return? "true" : "false");
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 75 /* firewallSetFirewallType */:
  {
    int32_t in_firewalltype;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewalltype);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_firewalltype";
        _log_arg_element["value"] = Json::Value(in_firewalltype);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetFirewallType(in_firewalltype));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallSetFirewallType");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 76 /* firewallSetInterfaceRule */:
  {
    ::std::string in_ifName;
    int32_t in_firewallRule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewallRule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_firewallRule";
        _log_arg_element["value"] = Json::Value(in_firewallRule);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetInterfaceRule(in_ifName, in_firewallRule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallSetInterfaceRule");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 77 /* firewallSetUidRule */:
  {
    int32_t in_childChain;
    int32_t in_uid;
    int32_t in_firewallRule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_childChain);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewallRule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_childChain";
        _log_arg_element["value"] = Json::Value(in_childChain);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_firewallRule";
        _log_arg_element["value"] = Json::Value(in_firewallRule);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetUidRule(in_childChain, in_uid, in_firewallRule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallSetUidRule");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 78 /* firewallEnableChildChain */:
  {
    int32_t in_childChain;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_childChain);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_childChain";
        _log_arg_element["value"] = Json::Value(in_childChain);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_enable";
        _log_arg_element["value"] = Json::Value(in_enable? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallEnableChildChain(in_childChain, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallEnableChildChain");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 79 /* interfaceGetList */:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceGetList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceGetList");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      _log_transaction["_aidl_return"] = Json::Value(Json::arrayValue);
      for (const auto& v: _aidl_return) _log_transaction["_aidl_return"].append(Json::Value(v));
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 80 /* interfaceGetCfg */:
  {
    ::std::string in_ifName;
    ::android::net::InterfaceConfigurationParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceGetCfg(in_ifName, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceGetCfg");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 81 /* interfaceSetCfg */:
  {
    ::android::net::InterfaceConfigurationParcel in_cfg;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_cfg);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetCfg(in_cfg));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceSetCfg");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 82 /* interfaceSetIPv6PrivacyExtensions */:
  {
    ::std::string in_ifName;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_enable";
        _log_arg_element["value"] = Json::Value(in_enable? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetIPv6PrivacyExtensions(in_ifName, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceSetIPv6PrivacyExtensions");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 83 /* interfaceClearAddrs */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceClearAddrs(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceClearAddrs");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 84 /* interfaceSetEnableIPv6 */:
  {
    ::std::string in_ifName;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_enable";
        _log_arg_element["value"] = Json::Value(in_enable? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetEnableIPv6(in_ifName, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceSetEnableIPv6");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 85 /* interfaceSetMtu */:
  {
    ::std::string in_ifName;
    int32_t in_mtu;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mtu);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_mtu";
        _log_arg_element["value"] = Json::Value(in_mtu);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetMtu(in_ifName, in_mtu));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("interfaceSetMtu");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 86 /* tetherAddForward */:
  {
    ::std::string in_intIface;
    ::std::string in_extIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_intIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_extIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_intIface";
        _log_arg_element["value"] = Json::Value(in_intIface);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_extIface";
        _log_arg_element["value"] = Json::Value(in_extIface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherAddForward(in_intIface, in_extIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherAddForward");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 87 /* tetherRemoveForward */:
  {
    ::std::string in_intIface;
    ::std::string in_extIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_intIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_extIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_intIface";
        _log_arg_element["value"] = Json::Value(in_intIface);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_extIface";
        _log_arg_element["value"] = Json::Value(in_extIface);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherRemoveForward(in_intIface, in_extIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherRemoveForward");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 88 /* setTcpRWmemorySize */:
  {
    ::std::string in_rmemValues;
    ::std::string in_wmemValues;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_rmemValues);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_wmemValues);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_rmemValues";
        _log_arg_element["value"] = Json::Value(in_rmemValues);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_wmemValues";
        _log_arg_element["value"] = Json::Value(in_wmemValues);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setTcpRWmemorySize(in_rmemValues, in_wmemValues));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("setTcpRWmemorySize");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 89 /* registerUnsolicitedEventListener */:
  {
    ::android::sp<::android::net::INetdUnsolicitedEventListener> in_listener;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_listener);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(registerUnsolicitedEventListener(in_listener));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("registerUnsolicitedEventListener");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 90 /* firewallAddUidInterfaceRules */:
  {
    ::std::string in_ifName;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallAddUidInterfaceRules(in_ifName, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallAddUidInterfaceRules");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 91 /* firewallRemoveUidInterfaceRules */:
  {
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uids";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_uids) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallRemoveUidInterfaceRules(in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("firewallRemoveUidInterfaceRules");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 92 /* trafficSwapActiveStatsMap */:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(trafficSwapActiveStatsMap());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("trafficSwapActiveStatsMap");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 93 /* getOemNetd */:
  {
    ::android::sp<::android::IBinder> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getOemNetd(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("getOemNetd");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeStrongBinder(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 94 /* tetherStartWithConfiguration */:
  {
    ::android::net::TetherConfigParcel in_config;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_config);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStartWithConfiguration(in_config));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherStartWithConfiguration");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 95 /* getFwmarkForNetwork */:
  {
    int32_t in_netId;
    ::android::net::MarkMaskParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getFwmarkForNetwork(in_netId, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("getFwmarkForNetwork");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 96 /* networkAddRouteParcel */:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkAddRouteParcel");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 97 /* networkUpdateRouteParcel */:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkUpdateRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkUpdateRouteParcel");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 98 /* networkRemoveRouteParcel */:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_netId";
        _log_arg_element["value"] = Json::Value(in_netId);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("networkRemoveRouteParcel");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 99 /* tetherOffloadRuleAdd */:
  {
    ::android::net::TetherOffloadRuleParcel in_rule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_rule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadRuleAdd(in_rule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherOffloadRuleAdd");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 100 /* tetherOffloadRuleRemove */:
  {
    ::android::net::TetherOffloadRuleParcel in_rule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_rule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadRuleRemove(in_rule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherOffloadRuleRemove");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 101 /* tetherOffloadGetStats */:
  {
    ::std::vector<::android::net::TetherStatsParcel> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadGetStats(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherOffloadGetStats");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 102 /* tetherOffloadSetInterfaceQuota */:
  {
    int32_t in_ifIndex;
    int64_t in_quotaBytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ifIndex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_quotaBytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifIndex";
        _log_arg_element["value"] = Json::Value(in_ifIndex);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_quotaBytes";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_quotaBytes));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadSetInterfaceQuota(in_ifIndex, in_quotaBytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherOffloadSetInterfaceQuota");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 103 /* tetherOffloadGetAndClearStats */:
  {
    int32_t in_ifIndex;
    ::android::net::TetherStatsParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ifIndex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetd::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifIndex";
        _log_arg_element["value"] = Json::Value(in_ifIndex);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadGetAndClearStats(in_ifIndex, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetd");
      _log_transaction["method_name"] = Json::Value("tetherOffloadGetAndClearStats");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetd::logFunc(_log_transaction);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214 /* getInterfaceVersion */:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(INetd::VERSION);
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213 /* getInterfaceHash */:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(INetd::HASH);
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

int32_t BnNetd::getInterfaceVersion() {
  return INetd::VERSION;
}

std::string BnNetd::getInterfaceHash() {
  return INetd::HASH;
}

std::function<void(const Json::Value&)> BnNetd::logFunc;

}  // namespace net

}  // namespace android
