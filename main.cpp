#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <android/net/INetd.h>
#include <utils/Log.h>

using namespace android;
using namespace android::net;

int main() {
    // 初始化 Binder 进程状态
    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();

    // 获取 ServiceManager
    sp<IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("Failed to get ServiceManager");
        return -1;
    }

    // 获取 netd 服务
    sp<IBinder> binder = sm->getService(String16("netd"));
    if (binder == nullptr) {
        ALOGE("Failed to get netd service");
        return -1;
    }

    // 将 IBinder 转换为 INetd 接口
    sp<INetd> netd = interface_cast<INetd>(binder);
    if (netd == nullptr) {
        ALOGE("Failed to cast netd service to INetd");
        return -1;
    }

    // 调用 networkGetDefault 函数
    int result;
    ::android::binder::Status status = netd->networkGetDefault(&result);
    if (!status.isOk()) {
        ALOGE("networkGetDefault call failed with status: %s", status.toString8().string());
        return -1;
    }
    ALOGI("networkGetDefault result: %d", result);

    return 0;
}
