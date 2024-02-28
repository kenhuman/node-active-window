#include "node-active-window.h"

NodeActiveWindow::NodeActiveWindow(Napi::Env, Napi::Object exports)
{
    DefineAddon(exports, {InstanceMethod("getForegroundWindowName", &NodeActiveWindow::getForegroundWindowName, napi_enumerable),
                          InstanceMethod("hasForegroundWindowChanged", &NodeActiveWindow::hasForegroundWindowChanged, napi_enumerable)});
}

Napi::Value NodeActiveWindow::getForegroundWindowName(const Napi::CallbackInfo &info)
{
    HWND activeWindow = GetForegroundWindow();
    this->lastForegroundWindow = activeWindow;

    int titleSize = GetWindowTextLengthW(activeWindow) + 1;
    LPWSTR title = new WCHAR[titleSize];
    GetWindowTextW(activeWindow, title, titleSize);

    std::wstring buffer(title);
    std::string windowTitle = std::string(buffer.begin(), buffer.end());

    return Napi::String::New(info.Env(), windowTitle);
}

Napi::Value NodeActiveWindow::hasForegroundWindowChanged(const Napi::CallbackInfo &info)
{
    HWND activeWindow = GetForegroundWindow();
    return Napi::Boolean::New(info.Env(), activeWindow != this->lastForegroundWindow);
}

NODE_API_ADDON(NodeActiveWindow);