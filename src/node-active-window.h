#include <napi.h>

#include <windows.h>

class NodeActiveWindow : public Napi::Addon<NodeActiveWindow>
{
public:
    NodeActiveWindow(Napi::Env env, Napi::Object exports);

    Napi::Value getForegroundWindowName(const Napi::CallbackInfo &info);
    Napi::Value hasForegroundWindowChanged(const Napi::CallbackInfo &info);

private:
    HWND lastForegroundWindow;
};