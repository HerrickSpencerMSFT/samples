//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace com::microsoft::maker::Blinky;

// Note: Unlike an Interface implementation, which provides a single handler for each member, the event
// model allows for 0 or more listeners to be registered. The EventAdapter implementation deals with this
// difference by implementing a last-writer-wins policy. The lack of any return value (i.e., 0 listeners)
// is handled by returning a null result.

// Methods
IAsyncOperation<BlinkyStartResult^>^ BlinkyServiceEventAdapter::StartAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new BlinkyStartCalledEventArgs(info);
    AllJoynHelpers::DispatchEvent([=]() {
        StartCalled(this, args);
    });
    return BlinkyStartCalledEventArgs::GetResultAsync(args);
}

IAsyncOperation<BlinkyStopResult^>^ BlinkyServiceEventAdapter::StopAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new BlinkyStopCalledEventArgs(info);
    AllJoynHelpers::DispatchEvent([=]() {
        StopCalled(this, args);
    });
    return BlinkyStopCalledEventArgs::GetResultAsync(args);
}

// Property Reads
IAsyncOperation<BlinkyGetVersionResult^>^ BlinkyServiceEventAdapter::GetVersionAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new BlinkyGetVersionRequestedEventArgs(info);
    AllJoynHelpers::DispatchEvent([=]() {
        GetVersionRequested(this, args);
    });
    return BlinkyGetVersionRequestedEventArgs::GetResultAsync(args);
}

IAsyncOperation<BlinkyGetBlinkIntervalResult^>^ BlinkyServiceEventAdapter::GetBlinkIntervalAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new BlinkyGetBlinkIntervalRequestedEventArgs(info);
    AllJoynHelpers::DispatchEvent([=]() {
        GetBlinkIntervalRequested(this, args);
    });
    return BlinkyGetBlinkIntervalRequestedEventArgs::GetResultAsync(args);
}

IAsyncOperation<BlinkyGetIsBlinkingResult^>^ BlinkyServiceEventAdapter::GetIsBlinkingAsync(_In_ AllJoynMessageInfo^ info)
{
    auto args = ref new BlinkyGetIsBlinkingRequestedEventArgs(info);
    AllJoynHelpers::DispatchEvent([=]() {
        GetIsBlinkingRequested(this, args);
    });
    return BlinkyGetIsBlinkingRequestedEventArgs::GetResultAsync(args);
}

// Property Writes
IAsyncOperation<BlinkySetBlinkIntervalResult^>^ BlinkyServiceEventAdapter::SetBlinkIntervalAsync(_In_ AllJoynMessageInfo^ info, _In_ double value)
{
    auto args = ref new BlinkySetBlinkIntervalRequestedEventArgs(info, value);
    AllJoynHelpers::DispatchEvent([=]() {
        SetBlinkIntervalRequested(this, args);
    });
    return BlinkySetBlinkIntervalRequestedEventArgs::GetResultAsync(args);
}

